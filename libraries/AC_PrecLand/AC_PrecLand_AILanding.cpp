#include "AC_PrecLand_AILanding.h"

#if AC_PRECLAND_ENABLED

#include <AP_HAL/AP_HAL.h>

extern const AP_HAL::HAL& hal;

// perform any required initialisation of backend
void AC_PrecLand_AILanding::init()
{
    // Check if AP_AILanding is available?
    // Usually nothing critical to init here as AP_AILanding inits itself
}

// retrieve updates from sensor
void AC_PrecLand_AILanding::update()
{
    const AP_AILanding* ailanding = get_ailanding_source();
    if (ailanding == nullptr) {
        _los_meas.valid = false;
        return;
    }

    // Check if AI Landing has new data
    // We assume AP_AILanding updates its state via its own handle_msg
    // Here we just poll the latest state
    
    // Note: We need to check if data is fresh. 
    // Currently AP_AILanding doesn't expose "last_update_ms" publicly in a getter,
    // We might need to add an accessor for that in AP_AILanding.h later.
    
    // Story 2 Implementation:
    // 1. Get raw correction vector (x,y,z in Body Frame?) from AP_AILanding
    // 2. Convert to Unit Vector for LOS measurement
    
    
    // Example logic (Conceptual):
    /*
    Vector3f detection = ailanding->get_correction_vector();
    if (detection.is_zero()) {
        _los_meas.valid = false;
        return;
    }

    _los_meas.time_ms = AP_HAL::millis();
    _los_meas.vec_unit = detection.normalized();
    _los_meas.frame = AC_PrecLand::VectorFrame::BODY_FRD; // Correct Enum usage
    _los_meas.valid = true;
    _distance_to_target = detection.length();
    */
}

float AC_PrecLand_AILanding::distance_to_target() const
{
    return _distance_to_target;
}

const AP_AILanding* AC_PrecLand_AILanding::get_ailanding_source() const
{
    return AP::ailanding();
}

#endif // AC_PRECLAND_ENABLED
