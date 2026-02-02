#include "AP_AILanding.h"
#include <GCS_MAVLink/GCS_MAVLink.h>
#include <stdio.h>

AP_AILanding *AP_AILanding::_singleton = nullptr;

AP_AILanding::AP_AILanding() : 
    _last_cmd_ms(0), 
    _pending_cmd(0), 
    _waiting_for_ack(false),
    _last_status_ms(0),
    _healthy(false)
{
    _singleton = this;
}

// ... (omitted code)

void AP_AILanding::handle_status_msg(const mavlink_message_t &msg) {
    if (msg.msgid == 52102) { // MAVLINK_MSG_ID_AI_LANDING_STATUS
        mavlink_ai_landing_status_t packet;
        mavlink_msg_ai_landing_status_decode(&msg, &packet);

        // Update internal state
        // target_lost: 0=Tracking, 1=Lost
        _ai_status = (packet.target_lost == 0) ? 1 : 0;
        
        // Update health status
        _last_status_ms = AP_HAL::millis();
        _healthy = true;
        
        // SITL Console Debug
        printf("AP_AILanding: Status Received (Lost=%u, Conf=%.2f)\n", packet.target_lost, packet.visual_confidence);

        // Forward to GCS
        for (uint8_t i=0; i<MAVLINK_COMM_NUM_BUFFERS; i++) {
            GCS_MAVLINK *chan = gcs().chan(i);
            if (chan == nullptr || !chan->is_active()) continue;
            mavlink_msg_ai_landing_status_send_struct(chan->get_chan(), &packet);
        }
    }
}

// ... (omitted accessor)

void AP_AILanding::update() {
    uint32_t now = AP_HAL::millis();

    if (_waiting_for_ack && (now - _last_cmd_ms > 1000)) {
        _waiting_for_ack = false;
        gcs().send_text(MAV_SEVERITY_ERROR, "AI Landing: Cmd %u Timeout!", _pending_cmd);
        _pending_cmd = 0;
    }
    
    // 300ms Timeout Check (Story 1.4)
    if (now - _last_status_ms > 300) {
        if (_healthy) {
            gcs().send_text(MAV_SEVERITY_WARNING, "AP: AI Landing: Status Timeout!");
            _healthy = false;
        }
    }
}

AP_AILanding *AP_AILanding::get_singleton() {
    if (_singleton == nullptr) {
        static AP_AILanding instance;
    }
    return _singleton;
}

void AP_AILanding::send_start_ai_landing(uint8_t stream_mode, float freq_hz) {
    gcs().send_text(MAV_SEVERITY_NOTICE, "AI Landing: Sending Start Cmd");
    printf("AP_AILanding: Sending Start Cmd\n"); // SITL Output

    for (uint8_t i=0; i<MAVLINK_COMM_NUM_BUFFERS; i++) {
        const GCS_MAVLINK *chan = gcs().chan(i);
        if (chan == nullptr || !chan->is_active()) continue;
        mavlink_msg_command_long_send(chan->get_chan(), 1, 211, 31020, 0, (float)stream_mode, freq_hz, 0, 0, 0, 0, 0);
    }
    _pending_cmd = 31020;
    _last_cmd_ms = AP_HAL::millis();
    _waiting_for_ack = true;
}

void AP_AILanding::handle_command_ack(const mavlink_command_ack_t &packet) {
    if (packet.command == _pending_cmd) {
        _waiting_for_ack = false;
        _pending_cmd = 0;
        gcs().send_text(MAV_SEVERITY_NOTICE, "AI Landing: ACK Received!");
        printf("AP_AILanding: ACK Received!\n"); // SITL Output
    }
}

void AP_AILanding::handle_msg(const mavlink_message_t &msg) {
    if (msg.msgid == 52100) { // MAVLINK_MSG_ID_AI_LANDING_CORRECTION
        mavlink_ai_landing_correction_t packet;
        mavlink_msg_ai_landing_correction_decode(&msg, &packet);

        // 1. 檢查 flags (bit0: yaw_valid, bit1: distance_valid)
        if (packet.flags & 0x03) {
            // SITL Console Debug
            printf("AP_AILanding: Valid Correction Received (Flags=%u)\n", packet.flags);

            // 2. 更新內部狀態 (儲存以供後續 Epic 2 使用)
            _last_correction = packet;
            _last_corr_ms = AP_HAL::millis();

            // 3. 原封轉送至地面站 (FR17)
            for (uint8_t i=0; i<MAVLINK_COMM_NUM_BUFFERS; i++) {
                GCS_MAVLINK *chan = gcs().chan(i);
                if (chan == nullptr || !chan->is_active()) continue;
                // 使用原封轉送邏輯
                mavlink_msg_ai_landing_correction_send_struct(chan->get_chan(), &packet);
            }
        } else {
            // SITL Console Debug (Rate limited)
            static uint32_t last_print_ms = 0;
            if (AP_HAL::millis() - last_print_ms > 2000) {
                 printf("AP_AILanding: Invalid Correction (Flags=%u)\n", packet.flags);
                 last_print_ms = AP_HAL::millis();
            }

            // 4. 旗標無效時發送警告 (限制頻率: 每 5 秒一次)
            static uint32_t last_warn_ms = 0;
            if (AP_HAL::millis() - last_warn_ms > 5000) {
                gcs().send_text(MAV_SEVERITY_WARNING, "AP: AI_LANDING_CORR_INVALID");
                last_warn_ms = AP_HAL::millis();
            }
        }
    }
}

// Accessor for AC_PrecLand (Story 2)
void AP_AILanding::handle_status_msg(const mavlink_message_t &msg) {
    if (msg.msgid == 52102) { // MAVLINK_MSG_ID_AI_LANDING_STATUS
        mavlink_ai_landing_status_t packet;
        mavlink_msg_ai_landing_status_decode(&msg, &packet);

        // Update internal state
        // target_lost: 0=Tracking, 1=Lost
        _ai_status = (packet.target_lost == 0) ? 1 : 0;
        
        // SITL Console Debug
        printf("AP_AILanding: Status Received (Lost=%u, Conf=%.2f)\n", packet.target_lost, packet.visual_confidence);

        // Forward to GCS
        for (uint8_t i=0; i<MAVLINK_COMM_NUM_BUFFERS; i++) {
            GCS_MAVLINK *chan = gcs().chan(i);
            if (chan == nullptr || !chan->is_active()) continue;
            mavlink_msg_ai_landing_status_send_struct(chan->get_chan(), &packet);
        }
    }
}

// Accessor for AC_PrecLand (Story 2)
bool AP_AILanding::get_correction_vector(Vector3f &correction_bf) const {
    if (_ai_status == 0) {
        return false;
    }
    correction_bf = _correction_bf;
    return true;
}

void AP_AILanding::update() {
    if (_waiting_for_ack && (AP_HAL::millis() - _last_cmd_ms > 1000)) {
        _waiting_for_ack = false;
        gcs().send_text(MAV_SEVERITY_ERROR, "AI Landing: Cmd %u Timeout!", _pending_cmd);
        _pending_cmd = 0;
    }
}

namespace AP { AP_AILanding *ailanding() { return AP_AILanding::get_singleton(); } };
