#pragma once
// MESSAGE AI_FISH_DETECTION_RESULT PACKING

#define MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT 52101


typedef struct __mavlink_ai_fish_detection_result_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp*/
 float confidence[10]; /*<  Conf*/
 uint16_t image_width; /*< [px] Width*/
 uint16_t image_height; /*< [px] Height*/
 uint16_t bbox_x[10]; /*<  X*/
 uint16_t bbox_y[10]; /*<  Y*/
 uint16_t bbox_w[10]; /*<  W*/
 uint16_t bbox_h[10]; /*<  H*/
 uint8_t object_count; /*<  Count*/
 uint8_t class_id[10]; /*<  Class*/
} mavlink_ai_fish_detection_result_t;

#define MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN 139
#define MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_MIN_LEN 139
#define MAVLINK_MSG_ID_52101_LEN 139
#define MAVLINK_MSG_ID_52101_MIN_LEN 139

#define MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_CRC 141
#define MAVLINK_MSG_ID_52101_CRC 141

#define MAVLINK_MSG_AI_FISH_DETECTION_RESULT_FIELD_CONFIDENCE_LEN 10
#define MAVLINK_MSG_AI_FISH_DETECTION_RESULT_FIELD_BBOX_X_LEN 10
#define MAVLINK_MSG_AI_FISH_DETECTION_RESULT_FIELD_BBOX_Y_LEN 10
#define MAVLINK_MSG_AI_FISH_DETECTION_RESULT_FIELD_BBOX_W_LEN 10
#define MAVLINK_MSG_AI_FISH_DETECTION_RESULT_FIELD_BBOX_H_LEN 10
#define MAVLINK_MSG_AI_FISH_DETECTION_RESULT_FIELD_CLASS_ID_LEN 10

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AI_FISH_DETECTION_RESULT { \
    52101, \
    "AI_FISH_DETECTION_RESULT", \
    10, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ai_fish_detection_result_t, time_boot_ms) }, \
         { "image_width", NULL, MAVLINK_TYPE_UINT16_T, 0, 44, offsetof(mavlink_ai_fish_detection_result_t, image_width) }, \
         { "image_height", NULL, MAVLINK_TYPE_UINT16_T, 0, 46, offsetof(mavlink_ai_fish_detection_result_t, image_height) }, \
         { "object_count", NULL, MAVLINK_TYPE_UINT8_T, 0, 128, offsetof(mavlink_ai_fish_detection_result_t, object_count) }, \
         { "bbox_x", NULL, MAVLINK_TYPE_UINT16_T, 10, 48, offsetof(mavlink_ai_fish_detection_result_t, bbox_x) }, \
         { "bbox_y", NULL, MAVLINK_TYPE_UINT16_T, 10, 68, offsetof(mavlink_ai_fish_detection_result_t, bbox_y) }, \
         { "bbox_w", NULL, MAVLINK_TYPE_UINT16_T, 10, 88, offsetof(mavlink_ai_fish_detection_result_t, bbox_w) }, \
         { "bbox_h", NULL, MAVLINK_TYPE_UINT16_T, 10, 108, offsetof(mavlink_ai_fish_detection_result_t, bbox_h) }, \
         { "class_id", NULL, MAVLINK_TYPE_UINT8_T, 10, 129, offsetof(mavlink_ai_fish_detection_result_t, class_id) }, \
         { "confidence", NULL, MAVLINK_TYPE_FLOAT, 10, 4, offsetof(mavlink_ai_fish_detection_result_t, confidence) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AI_FISH_DETECTION_RESULT { \
    "AI_FISH_DETECTION_RESULT", \
    10, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ai_fish_detection_result_t, time_boot_ms) }, \
         { "image_width", NULL, MAVLINK_TYPE_UINT16_T, 0, 44, offsetof(mavlink_ai_fish_detection_result_t, image_width) }, \
         { "image_height", NULL, MAVLINK_TYPE_UINT16_T, 0, 46, offsetof(mavlink_ai_fish_detection_result_t, image_height) }, \
         { "object_count", NULL, MAVLINK_TYPE_UINT8_T, 0, 128, offsetof(mavlink_ai_fish_detection_result_t, object_count) }, \
         { "bbox_x", NULL, MAVLINK_TYPE_UINT16_T, 10, 48, offsetof(mavlink_ai_fish_detection_result_t, bbox_x) }, \
         { "bbox_y", NULL, MAVLINK_TYPE_UINT16_T, 10, 68, offsetof(mavlink_ai_fish_detection_result_t, bbox_y) }, \
         { "bbox_w", NULL, MAVLINK_TYPE_UINT16_T, 10, 88, offsetof(mavlink_ai_fish_detection_result_t, bbox_w) }, \
         { "bbox_h", NULL, MAVLINK_TYPE_UINT16_T, 10, 108, offsetof(mavlink_ai_fish_detection_result_t, bbox_h) }, \
         { "class_id", NULL, MAVLINK_TYPE_UINT8_T, 10, 129, offsetof(mavlink_ai_fish_detection_result_t, class_id) }, \
         { "confidence", NULL, MAVLINK_TYPE_FLOAT, 10, 4, offsetof(mavlink_ai_fish_detection_result_t, confidence) }, \
         } \
}
#endif

/**
 * @brief Pack a ai_fish_detection_result message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp
 * @param image_width [px] Width
 * @param image_height [px] Height
 * @param object_count  Count
 * @param bbox_x  X
 * @param bbox_y  Y
 * @param bbox_w  W
 * @param bbox_h  H
 * @param class_id  Class
 * @param confidence  Conf
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ai_fish_detection_result_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint16_t image_width, uint16_t image_height, uint8_t object_count, const uint16_t *bbox_x, const uint16_t *bbox_y, const uint16_t *bbox_w, const uint16_t *bbox_h, const uint8_t *class_id, const float *confidence)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint16_t(buf, 44, image_width);
    _mav_put_uint16_t(buf, 46, image_height);
    _mav_put_uint8_t(buf, 128, object_count);
    _mav_put_float_array(buf, 4, confidence, 10);
    _mav_put_uint16_t_array(buf, 48, bbox_x, 10);
    _mav_put_uint16_t_array(buf, 68, bbox_y, 10);
    _mav_put_uint16_t_array(buf, 88, bbox_w, 10);
    _mav_put_uint16_t_array(buf, 108, bbox_h, 10);
    _mav_put_uint8_t_array(buf, 129, class_id, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN);
#else
    mavlink_ai_fish_detection_result_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.image_width = image_width;
    packet.image_height = image_height;
    packet.object_count = object_count;
    mav_array_assign_float(packet.confidence, confidence, 10);
    mav_array_assign_uint16_t(packet.bbox_x, bbox_x, 10);
    mav_array_assign_uint16_t(packet.bbox_y, bbox_y, 10);
    mav_array_assign_uint16_t(packet.bbox_w, bbox_w, 10);
    mav_array_assign_uint16_t(packet.bbox_h, bbox_h, 10);
    mav_array_assign_uint8_t(packet.class_id, class_id, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_MIN_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_CRC);
}

/**
 * @brief Pack a ai_fish_detection_result message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp
 * @param image_width [px] Width
 * @param image_height [px] Height
 * @param object_count  Count
 * @param bbox_x  X
 * @param bbox_y  Y
 * @param bbox_w  W
 * @param bbox_h  H
 * @param class_id  Class
 * @param confidence  Conf
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ai_fish_detection_result_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint16_t image_width, uint16_t image_height, uint8_t object_count, const uint16_t *bbox_x, const uint16_t *bbox_y, const uint16_t *bbox_w, const uint16_t *bbox_h, const uint8_t *class_id, const float *confidence)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint16_t(buf, 44, image_width);
    _mav_put_uint16_t(buf, 46, image_height);
    _mav_put_uint8_t(buf, 128, object_count);
    _mav_put_float_array(buf, 4, confidence, 10);
    _mav_put_uint16_t_array(buf, 48, bbox_x, 10);
    _mav_put_uint16_t_array(buf, 68, bbox_y, 10);
    _mav_put_uint16_t_array(buf, 88, bbox_w, 10);
    _mav_put_uint16_t_array(buf, 108, bbox_h, 10);
    _mav_put_uint8_t_array(buf, 129, class_id, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN);
#else
    mavlink_ai_fish_detection_result_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.image_width = image_width;
    packet.image_height = image_height;
    packet.object_count = object_count;
    mav_array_memcpy(packet.confidence, confidence, sizeof(float)*10);
    mav_array_memcpy(packet.bbox_x, bbox_x, sizeof(uint16_t)*10);
    mav_array_memcpy(packet.bbox_y, bbox_y, sizeof(uint16_t)*10);
    mav_array_memcpy(packet.bbox_w, bbox_w, sizeof(uint16_t)*10);
    mav_array_memcpy(packet.bbox_h, bbox_h, sizeof(uint16_t)*10);
    mav_array_memcpy(packet.class_id, class_id, sizeof(uint8_t)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_MIN_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_MIN_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN);
#endif
}

/**
 * @brief Pack a ai_fish_detection_result message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp
 * @param image_width [px] Width
 * @param image_height [px] Height
 * @param object_count  Count
 * @param bbox_x  X
 * @param bbox_y  Y
 * @param bbox_w  W
 * @param bbox_h  H
 * @param class_id  Class
 * @param confidence  Conf
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ai_fish_detection_result_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint16_t image_width,uint16_t image_height,uint8_t object_count,const uint16_t *bbox_x,const uint16_t *bbox_y,const uint16_t *bbox_w,const uint16_t *bbox_h,const uint8_t *class_id,const float *confidence)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint16_t(buf, 44, image_width);
    _mav_put_uint16_t(buf, 46, image_height);
    _mav_put_uint8_t(buf, 128, object_count);
    _mav_put_float_array(buf, 4, confidence, 10);
    _mav_put_uint16_t_array(buf, 48, bbox_x, 10);
    _mav_put_uint16_t_array(buf, 68, bbox_y, 10);
    _mav_put_uint16_t_array(buf, 88, bbox_w, 10);
    _mav_put_uint16_t_array(buf, 108, bbox_h, 10);
    _mav_put_uint8_t_array(buf, 129, class_id, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN);
#else
    mavlink_ai_fish_detection_result_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.image_width = image_width;
    packet.image_height = image_height;
    packet.object_count = object_count;
    mav_array_assign_float(packet.confidence, confidence, 10);
    mav_array_assign_uint16_t(packet.bbox_x, bbox_x, 10);
    mav_array_assign_uint16_t(packet.bbox_y, bbox_y, 10);
    mav_array_assign_uint16_t(packet.bbox_w, bbox_w, 10);
    mav_array_assign_uint16_t(packet.bbox_h, bbox_h, 10);
    mav_array_assign_uint8_t(packet.class_id, class_id, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_MIN_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_CRC);
}

/**
 * @brief Encode a ai_fish_detection_result struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ai_fish_detection_result C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ai_fish_detection_result_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ai_fish_detection_result_t* ai_fish_detection_result)
{
    return mavlink_msg_ai_fish_detection_result_pack(system_id, component_id, msg, ai_fish_detection_result->time_boot_ms, ai_fish_detection_result->image_width, ai_fish_detection_result->image_height, ai_fish_detection_result->object_count, ai_fish_detection_result->bbox_x, ai_fish_detection_result->bbox_y, ai_fish_detection_result->bbox_w, ai_fish_detection_result->bbox_h, ai_fish_detection_result->class_id, ai_fish_detection_result->confidence);
}

/**
 * @brief Encode a ai_fish_detection_result struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ai_fish_detection_result C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ai_fish_detection_result_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ai_fish_detection_result_t* ai_fish_detection_result)
{
    return mavlink_msg_ai_fish_detection_result_pack_chan(system_id, component_id, chan, msg, ai_fish_detection_result->time_boot_ms, ai_fish_detection_result->image_width, ai_fish_detection_result->image_height, ai_fish_detection_result->object_count, ai_fish_detection_result->bbox_x, ai_fish_detection_result->bbox_y, ai_fish_detection_result->bbox_w, ai_fish_detection_result->bbox_h, ai_fish_detection_result->class_id, ai_fish_detection_result->confidence);
}

/**
 * @brief Encode a ai_fish_detection_result struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param ai_fish_detection_result C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ai_fish_detection_result_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_ai_fish_detection_result_t* ai_fish_detection_result)
{
    return mavlink_msg_ai_fish_detection_result_pack_status(system_id, component_id, _status, msg,  ai_fish_detection_result->time_boot_ms, ai_fish_detection_result->image_width, ai_fish_detection_result->image_height, ai_fish_detection_result->object_count, ai_fish_detection_result->bbox_x, ai_fish_detection_result->bbox_y, ai_fish_detection_result->bbox_w, ai_fish_detection_result->bbox_h, ai_fish_detection_result->class_id, ai_fish_detection_result->confidence);
}

/**
 * @brief Send a ai_fish_detection_result message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp
 * @param image_width [px] Width
 * @param image_height [px] Height
 * @param object_count  Count
 * @param bbox_x  X
 * @param bbox_y  Y
 * @param bbox_w  W
 * @param bbox_h  H
 * @param class_id  Class
 * @param confidence  Conf
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ai_fish_detection_result_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint16_t image_width, uint16_t image_height, uint8_t object_count, const uint16_t *bbox_x, const uint16_t *bbox_y, const uint16_t *bbox_w, const uint16_t *bbox_h, const uint8_t *class_id, const float *confidence)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint16_t(buf, 44, image_width);
    _mav_put_uint16_t(buf, 46, image_height);
    _mav_put_uint8_t(buf, 128, object_count);
    _mav_put_float_array(buf, 4, confidence, 10);
    _mav_put_uint16_t_array(buf, 48, bbox_x, 10);
    _mav_put_uint16_t_array(buf, 68, bbox_y, 10);
    _mav_put_uint16_t_array(buf, 88, bbox_w, 10);
    _mav_put_uint16_t_array(buf, 108, bbox_h, 10);
    _mav_put_uint8_t_array(buf, 129, class_id, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT, buf, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_MIN_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_CRC);
#else
    mavlink_ai_fish_detection_result_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.image_width = image_width;
    packet.image_height = image_height;
    packet.object_count = object_count;
    mav_array_assign_float(packet.confidence, confidence, 10);
    mav_array_assign_uint16_t(packet.bbox_x, bbox_x, 10);
    mav_array_assign_uint16_t(packet.bbox_y, bbox_y, 10);
    mav_array_assign_uint16_t(packet.bbox_w, bbox_w, 10);
    mav_array_assign_uint16_t(packet.bbox_h, bbox_h, 10);
    mav_array_assign_uint8_t(packet.class_id, class_id, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT, (const char *)&packet, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_MIN_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_CRC);
#endif
}

/**
 * @brief Send a ai_fish_detection_result message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ai_fish_detection_result_send_struct(mavlink_channel_t chan, const mavlink_ai_fish_detection_result_t* ai_fish_detection_result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ai_fish_detection_result_send(chan, ai_fish_detection_result->time_boot_ms, ai_fish_detection_result->image_width, ai_fish_detection_result->image_height, ai_fish_detection_result->object_count, ai_fish_detection_result->bbox_x, ai_fish_detection_result->bbox_y, ai_fish_detection_result->bbox_w, ai_fish_detection_result->bbox_h, ai_fish_detection_result->class_id, ai_fish_detection_result->confidence);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT, (const char *)ai_fish_detection_result, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_MIN_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_CRC);
#endif
}

#if MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ai_fish_detection_result_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, uint16_t image_width, uint16_t image_height, uint8_t object_count, const uint16_t *bbox_x, const uint16_t *bbox_y, const uint16_t *bbox_w, const uint16_t *bbox_h, const uint8_t *class_id, const float *confidence)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint16_t(buf, 44, image_width);
    _mav_put_uint16_t(buf, 46, image_height);
    _mav_put_uint8_t(buf, 128, object_count);
    _mav_put_float_array(buf, 4, confidence, 10);
    _mav_put_uint16_t_array(buf, 48, bbox_x, 10);
    _mav_put_uint16_t_array(buf, 68, bbox_y, 10);
    _mav_put_uint16_t_array(buf, 88, bbox_w, 10);
    _mav_put_uint16_t_array(buf, 108, bbox_h, 10);
    _mav_put_uint8_t_array(buf, 129, class_id, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT, buf, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_MIN_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_CRC);
#else
    mavlink_ai_fish_detection_result_t *packet = (mavlink_ai_fish_detection_result_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->image_width = image_width;
    packet->image_height = image_height;
    packet->object_count = object_count;
    mav_array_assign_float(packet->confidence, confidence, 10);
    mav_array_assign_uint16_t(packet->bbox_x, bbox_x, 10);
    mav_array_assign_uint16_t(packet->bbox_y, bbox_y, 10);
    mav_array_assign_uint16_t(packet->bbox_w, bbox_w, 10);
    mav_array_assign_uint16_t(packet->bbox_h, bbox_h, 10);
    mav_array_assign_uint8_t(packet->class_id, class_id, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT, (const char *)packet, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_MIN_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_CRC);
#endif
}
#endif

#endif

// MESSAGE AI_FISH_DETECTION_RESULT UNPACKING


/**
 * @brief Get field time_boot_ms from ai_fish_detection_result message
 *
 * @return [ms] Timestamp
 */
static inline uint32_t mavlink_msg_ai_fish_detection_result_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field image_width from ai_fish_detection_result message
 *
 * @return [px] Width
 */
static inline uint16_t mavlink_msg_ai_fish_detection_result_get_image_width(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  44);
}

/**
 * @brief Get field image_height from ai_fish_detection_result message
 *
 * @return [px] Height
 */
static inline uint16_t mavlink_msg_ai_fish_detection_result_get_image_height(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  46);
}

/**
 * @brief Get field object_count from ai_fish_detection_result message
 *
 * @return  Count
 */
static inline uint8_t mavlink_msg_ai_fish_detection_result_get_object_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  128);
}

/**
 * @brief Get field bbox_x from ai_fish_detection_result message
 *
 * @return  X
 */
static inline uint16_t mavlink_msg_ai_fish_detection_result_get_bbox_x(const mavlink_message_t* msg, uint16_t *bbox_x)
{
    return _MAV_RETURN_uint16_t_array(msg, bbox_x, 10,  48);
}

/**
 * @brief Get field bbox_y from ai_fish_detection_result message
 *
 * @return  Y
 */
static inline uint16_t mavlink_msg_ai_fish_detection_result_get_bbox_y(const mavlink_message_t* msg, uint16_t *bbox_y)
{
    return _MAV_RETURN_uint16_t_array(msg, bbox_y, 10,  68);
}

/**
 * @brief Get field bbox_w from ai_fish_detection_result message
 *
 * @return  W
 */
static inline uint16_t mavlink_msg_ai_fish_detection_result_get_bbox_w(const mavlink_message_t* msg, uint16_t *bbox_w)
{
    return _MAV_RETURN_uint16_t_array(msg, bbox_w, 10,  88);
}

/**
 * @brief Get field bbox_h from ai_fish_detection_result message
 *
 * @return  H
 */
static inline uint16_t mavlink_msg_ai_fish_detection_result_get_bbox_h(const mavlink_message_t* msg, uint16_t *bbox_h)
{
    return _MAV_RETURN_uint16_t_array(msg, bbox_h, 10,  108);
}

/**
 * @brief Get field class_id from ai_fish_detection_result message
 *
 * @return  Class
 */
static inline uint16_t mavlink_msg_ai_fish_detection_result_get_class_id(const mavlink_message_t* msg, uint8_t *class_id)
{
    return _MAV_RETURN_uint8_t_array(msg, class_id, 10,  129);
}

/**
 * @brief Get field confidence from ai_fish_detection_result message
 *
 * @return  Conf
 */
static inline uint16_t mavlink_msg_ai_fish_detection_result_get_confidence(const mavlink_message_t* msg, float *confidence)
{
    return _MAV_RETURN_float_array(msg, confidence, 10,  4);
}

/**
 * @brief Decode a ai_fish_detection_result message into a struct
 *
 * @param msg The message to decode
 * @param ai_fish_detection_result C-struct to decode the message contents into
 */
static inline void mavlink_msg_ai_fish_detection_result_decode(const mavlink_message_t* msg, mavlink_ai_fish_detection_result_t* ai_fish_detection_result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ai_fish_detection_result->time_boot_ms = mavlink_msg_ai_fish_detection_result_get_time_boot_ms(msg);
    mavlink_msg_ai_fish_detection_result_get_confidence(msg, ai_fish_detection_result->confidence);
    ai_fish_detection_result->image_width = mavlink_msg_ai_fish_detection_result_get_image_width(msg);
    ai_fish_detection_result->image_height = mavlink_msg_ai_fish_detection_result_get_image_height(msg);
    mavlink_msg_ai_fish_detection_result_get_bbox_x(msg, ai_fish_detection_result->bbox_x);
    mavlink_msg_ai_fish_detection_result_get_bbox_y(msg, ai_fish_detection_result->bbox_y);
    mavlink_msg_ai_fish_detection_result_get_bbox_w(msg, ai_fish_detection_result->bbox_w);
    mavlink_msg_ai_fish_detection_result_get_bbox_h(msg, ai_fish_detection_result->bbox_h);
    ai_fish_detection_result->object_count = mavlink_msg_ai_fish_detection_result_get_object_count(msg);
    mavlink_msg_ai_fish_detection_result_get_class_id(msg, ai_fish_detection_result->class_id);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN? msg->len : MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN;
        memset(ai_fish_detection_result, 0, MAVLINK_MSG_ID_AI_FISH_DETECTION_RESULT_LEN);
    memcpy(ai_fish_detection_result, _MAV_PAYLOAD(msg), len);
#endif
}
