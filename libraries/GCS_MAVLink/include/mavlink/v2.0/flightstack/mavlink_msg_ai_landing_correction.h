#pragma once
// MESSAGE AI_LANDING_CORRECTION PACKING

#define MAVLINK_MSG_ID_AI_LANDING_CORRECTION 52100


typedef struct __mavlink_ai_landing_correction_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp*/
 float roll_err; /*< [rad] Roll error*/
 float pitch_err; /*< [rad] Pitch error*/
 float yaw_err; /*< [rad] Yaw error*/
 float distance; /*< [m] Distance*/
 float confidence; /*<  Confidence*/
 uint8_t frame; /*<  0: CAMERA*/
 uint8_t flags; /*<  Flags*/
} mavlink_ai_landing_correction_t;

#define MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN 26
#define MAVLINK_MSG_ID_AI_LANDING_CORRECTION_MIN_LEN 26
#define MAVLINK_MSG_ID_52100_LEN 26
#define MAVLINK_MSG_ID_52100_MIN_LEN 26

#define MAVLINK_MSG_ID_AI_LANDING_CORRECTION_CRC 167
#define MAVLINK_MSG_ID_52100_CRC 167



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AI_LANDING_CORRECTION { \
    52100, \
    "AI_LANDING_CORRECTION", \
    8, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ai_landing_correction_t, time_boot_ms) }, \
         { "roll_err", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_ai_landing_correction_t, roll_err) }, \
         { "pitch_err", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_ai_landing_correction_t, pitch_err) }, \
         { "yaw_err", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_ai_landing_correction_t, yaw_err) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_ai_landing_correction_t, distance) }, \
         { "confidence", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_ai_landing_correction_t, confidence) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_ai_landing_correction_t, frame) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_ai_landing_correction_t, flags) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AI_LANDING_CORRECTION { \
    "AI_LANDING_CORRECTION", \
    8, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ai_landing_correction_t, time_boot_ms) }, \
         { "roll_err", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_ai_landing_correction_t, roll_err) }, \
         { "pitch_err", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_ai_landing_correction_t, pitch_err) }, \
         { "yaw_err", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_ai_landing_correction_t, yaw_err) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_ai_landing_correction_t, distance) }, \
         { "confidence", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_ai_landing_correction_t, confidence) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_ai_landing_correction_t, frame) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_ai_landing_correction_t, flags) }, \
         } \
}
#endif

/**
 * @brief Pack a ai_landing_correction message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp
 * @param roll_err [rad] Roll error
 * @param pitch_err [rad] Pitch error
 * @param yaw_err [rad] Yaw error
 * @param distance [m] Distance
 * @param confidence  Confidence
 * @param frame  0: CAMERA
 * @param flags  Flags
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ai_landing_correction_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, float roll_err, float pitch_err, float yaw_err, float distance, float confidence, uint8_t frame, uint8_t flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, roll_err);
    _mav_put_float(buf, 8, pitch_err);
    _mav_put_float(buf, 12, yaw_err);
    _mav_put_float(buf, 16, distance);
    _mav_put_float(buf, 20, confidence);
    _mav_put_uint8_t(buf, 24, frame);
    _mav_put_uint8_t(buf, 25, flags);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN);
#else
    mavlink_ai_landing_correction_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll_err = roll_err;
    packet.pitch_err = pitch_err;
    packet.yaw_err = yaw_err;
    packet.distance = distance;
    packet.confidence = confidence;
    packet.frame = frame;
    packet.flags = flags;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AI_LANDING_CORRECTION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_MIN_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_CRC);
}

/**
 * @brief Pack a ai_landing_correction message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp
 * @param roll_err [rad] Roll error
 * @param pitch_err [rad] Pitch error
 * @param yaw_err [rad] Yaw error
 * @param distance [m] Distance
 * @param confidence  Confidence
 * @param frame  0: CAMERA
 * @param flags  Flags
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ai_landing_correction_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t time_boot_ms, float roll_err, float pitch_err, float yaw_err, float distance, float confidence, uint8_t frame, uint8_t flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, roll_err);
    _mav_put_float(buf, 8, pitch_err);
    _mav_put_float(buf, 12, yaw_err);
    _mav_put_float(buf, 16, distance);
    _mav_put_float(buf, 20, confidence);
    _mav_put_uint8_t(buf, 24, frame);
    _mav_put_uint8_t(buf, 25, flags);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN);
#else
    mavlink_ai_landing_correction_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll_err = roll_err;
    packet.pitch_err = pitch_err;
    packet.yaw_err = yaw_err;
    packet.distance = distance;
    packet.confidence = confidence;
    packet.frame = frame;
    packet.flags = flags;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AI_LANDING_CORRECTION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_MIN_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_MIN_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN);
#endif
}

/**
 * @brief Pack a ai_landing_correction message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp
 * @param roll_err [rad] Roll error
 * @param pitch_err [rad] Pitch error
 * @param yaw_err [rad] Yaw error
 * @param distance [m] Distance
 * @param confidence  Confidence
 * @param frame  0: CAMERA
 * @param flags  Flags
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ai_landing_correction_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,float roll_err,float pitch_err,float yaw_err,float distance,float confidence,uint8_t frame,uint8_t flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, roll_err);
    _mav_put_float(buf, 8, pitch_err);
    _mav_put_float(buf, 12, yaw_err);
    _mav_put_float(buf, 16, distance);
    _mav_put_float(buf, 20, confidence);
    _mav_put_uint8_t(buf, 24, frame);
    _mav_put_uint8_t(buf, 25, flags);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN);
#else
    mavlink_ai_landing_correction_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll_err = roll_err;
    packet.pitch_err = pitch_err;
    packet.yaw_err = yaw_err;
    packet.distance = distance;
    packet.confidence = confidence;
    packet.frame = frame;
    packet.flags = flags;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AI_LANDING_CORRECTION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_MIN_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_CRC);
}

/**
 * @brief Encode a ai_landing_correction struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ai_landing_correction C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ai_landing_correction_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ai_landing_correction_t* ai_landing_correction)
{
    return mavlink_msg_ai_landing_correction_pack(system_id, component_id, msg, ai_landing_correction->time_boot_ms, ai_landing_correction->roll_err, ai_landing_correction->pitch_err, ai_landing_correction->yaw_err, ai_landing_correction->distance, ai_landing_correction->confidence, ai_landing_correction->frame, ai_landing_correction->flags);
}

/**
 * @brief Encode a ai_landing_correction struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ai_landing_correction C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ai_landing_correction_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ai_landing_correction_t* ai_landing_correction)
{
    return mavlink_msg_ai_landing_correction_pack_chan(system_id, component_id, chan, msg, ai_landing_correction->time_boot_ms, ai_landing_correction->roll_err, ai_landing_correction->pitch_err, ai_landing_correction->yaw_err, ai_landing_correction->distance, ai_landing_correction->confidence, ai_landing_correction->frame, ai_landing_correction->flags);
}

/**
 * @brief Encode a ai_landing_correction struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param ai_landing_correction C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ai_landing_correction_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_ai_landing_correction_t* ai_landing_correction)
{
    return mavlink_msg_ai_landing_correction_pack_status(system_id, component_id, _status, msg,  ai_landing_correction->time_boot_ms, ai_landing_correction->roll_err, ai_landing_correction->pitch_err, ai_landing_correction->yaw_err, ai_landing_correction->distance, ai_landing_correction->confidence, ai_landing_correction->frame, ai_landing_correction->flags);
}

/**
 * @brief Send a ai_landing_correction message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp
 * @param roll_err [rad] Roll error
 * @param pitch_err [rad] Pitch error
 * @param yaw_err [rad] Yaw error
 * @param distance [m] Distance
 * @param confidence  Confidence
 * @param frame  0: CAMERA
 * @param flags  Flags
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ai_landing_correction_send(mavlink_channel_t chan, uint32_t time_boot_ms, float roll_err, float pitch_err, float yaw_err, float distance, float confidence, uint8_t frame, uint8_t flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, roll_err);
    _mav_put_float(buf, 8, pitch_err);
    _mav_put_float(buf, 12, yaw_err);
    _mav_put_float(buf, 16, distance);
    _mav_put_float(buf, 20, confidence);
    _mav_put_uint8_t(buf, 24, frame);
    _mav_put_uint8_t(buf, 25, flags);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AI_LANDING_CORRECTION, buf, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_MIN_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_CRC);
#else
    mavlink_ai_landing_correction_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll_err = roll_err;
    packet.pitch_err = pitch_err;
    packet.yaw_err = yaw_err;
    packet.distance = distance;
    packet.confidence = confidence;
    packet.frame = frame;
    packet.flags = flags;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AI_LANDING_CORRECTION, (const char *)&packet, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_MIN_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_CRC);
#endif
}

/**
 * @brief Send a ai_landing_correction message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ai_landing_correction_send_struct(mavlink_channel_t chan, const mavlink_ai_landing_correction_t* ai_landing_correction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ai_landing_correction_send(chan, ai_landing_correction->time_boot_ms, ai_landing_correction->roll_err, ai_landing_correction->pitch_err, ai_landing_correction->yaw_err, ai_landing_correction->distance, ai_landing_correction->confidence, ai_landing_correction->frame, ai_landing_correction->flags);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AI_LANDING_CORRECTION, (const char *)ai_landing_correction, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_MIN_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_CRC);
#endif
}

#if MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ai_landing_correction_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, float roll_err, float pitch_err, float yaw_err, float distance, float confidence, uint8_t frame, uint8_t flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, roll_err);
    _mav_put_float(buf, 8, pitch_err);
    _mav_put_float(buf, 12, yaw_err);
    _mav_put_float(buf, 16, distance);
    _mav_put_float(buf, 20, confidence);
    _mav_put_uint8_t(buf, 24, frame);
    _mav_put_uint8_t(buf, 25, flags);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AI_LANDING_CORRECTION, buf, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_MIN_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_CRC);
#else
    mavlink_ai_landing_correction_t *packet = (mavlink_ai_landing_correction_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->roll_err = roll_err;
    packet->pitch_err = pitch_err;
    packet->yaw_err = yaw_err;
    packet->distance = distance;
    packet->confidence = confidence;
    packet->frame = frame;
    packet->flags = flags;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AI_LANDING_CORRECTION, (const char *)packet, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_MIN_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_CRC);
#endif
}
#endif

#endif

// MESSAGE AI_LANDING_CORRECTION UNPACKING


/**
 * @brief Get field time_boot_ms from ai_landing_correction message
 *
 * @return [ms] Timestamp
 */
static inline uint32_t mavlink_msg_ai_landing_correction_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field roll_err from ai_landing_correction message
 *
 * @return [rad] Roll error
 */
static inline float mavlink_msg_ai_landing_correction_get_roll_err(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field pitch_err from ai_landing_correction message
 *
 * @return [rad] Pitch error
 */
static inline float mavlink_msg_ai_landing_correction_get_pitch_err(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field yaw_err from ai_landing_correction message
 *
 * @return [rad] Yaw error
 */
static inline float mavlink_msg_ai_landing_correction_get_yaw_err(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field distance from ai_landing_correction message
 *
 * @return [m] Distance
 */
static inline float mavlink_msg_ai_landing_correction_get_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field confidence from ai_landing_correction message
 *
 * @return  Confidence
 */
static inline float mavlink_msg_ai_landing_correction_get_confidence(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field frame from ai_landing_correction message
 *
 * @return  0: CAMERA
 */
static inline uint8_t mavlink_msg_ai_landing_correction_get_frame(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field flags from ai_landing_correction message
 *
 * @return  Flags
 */
static inline uint8_t mavlink_msg_ai_landing_correction_get_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Decode a ai_landing_correction message into a struct
 *
 * @param msg The message to decode
 * @param ai_landing_correction C-struct to decode the message contents into
 */
static inline void mavlink_msg_ai_landing_correction_decode(const mavlink_message_t* msg, mavlink_ai_landing_correction_t* ai_landing_correction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ai_landing_correction->time_boot_ms = mavlink_msg_ai_landing_correction_get_time_boot_ms(msg);
    ai_landing_correction->roll_err = mavlink_msg_ai_landing_correction_get_roll_err(msg);
    ai_landing_correction->pitch_err = mavlink_msg_ai_landing_correction_get_pitch_err(msg);
    ai_landing_correction->yaw_err = mavlink_msg_ai_landing_correction_get_yaw_err(msg);
    ai_landing_correction->distance = mavlink_msg_ai_landing_correction_get_distance(msg);
    ai_landing_correction->confidence = mavlink_msg_ai_landing_correction_get_confidence(msg);
    ai_landing_correction->frame = mavlink_msg_ai_landing_correction_get_frame(msg);
    ai_landing_correction->flags = mavlink_msg_ai_landing_correction_get_flags(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN? msg->len : MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN;
        memset(ai_landing_correction, 0, MAVLINK_MSG_ID_AI_LANDING_CORRECTION_LEN);
    memcpy(ai_landing_correction, _MAV_PAYLOAD(msg), len);
#endif
}
