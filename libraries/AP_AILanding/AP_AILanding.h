#pragma once
#include <AP_HAL/AP_HAL.h>
#include <GCS_MAVLink/GCS.h>

class AP_AILanding {
public:
    AP_AILanding();
    static AP_AILanding *get_singleton();

    // Story 1.2
    void send_start_ai_landing(uint8_t stream_mode, float freq_hz);
    void handle_command_ack(const mavlink_command_ack_t &packet);
    void update();

    // Story 1.3 / 1.4 Message Handlers
    void handle_msg(const mavlink_message_t &msg);
    void handle_status_msg(const mavlink_message_t &msg);

    // Story 2 Accessors
    bool get_correction_vector(Vector3f &correction_bf) const;
    uint32_t last_update_ms() const { return _last_update_ms; }
    bool is_target_lost() const { return _ai_status == 0; }

private:
    static AP_AILanding *_singleton;
    
    // Command handling
    uint32_t _last_cmd_ms;
    uint16_t _pending_cmd;
    bool _waiting_for_ack;

    // Data storage (Story 1.3/2)
    mavlink_ai_landing_correction_t _last_correction;
    uint32_t _last_corr_ms;
    
    Vector3f _correction_bf; // Body Frame correction (x=fwd, y=right, z=down)
    uint32_t _last_update_ms;
    uint8_t _ai_status; // 0=Lost, 1=Tracking
    
    // Health monitoring (Story 1.4)
    uint32_t _last_status_ms;
    bool _healthy;
};

namespace AP { AP_AILanding *ailanding(); };
