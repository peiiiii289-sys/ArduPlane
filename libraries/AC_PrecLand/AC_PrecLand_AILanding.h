#pragma once

#include "AC_PrecLand_config.h"

#if AC_PRECLAND_ENABLED

#include "AC_PrecLand_Backend.h"
#include <AP_AILanding/AP_AILanding.h>

/*
 * AC_PrecLand_AILanding: 
 * Backend to consume data from AP_AILanding library and feed it to AC_PrecLand controller.
 */
class AC_PrecLand_AILanding : public AC_PrecLand_Backend
{
public:
    // Constructor
    using AC_PrecLand_Backend::AC_PrecLand_Backend;

    // perform any required initialisation of backend
    void init() override;

    // retrieve updates from sensor
    void update() override;

    // provides a unit vector towards the target in body frame
    // returns same as have_los_meas()
    bool get_los_meas(Vector3f& vec_unit, uint8_t& frame) const;

    // returns distances to target in meters (0 means distance is not known)
    float distance_to_target() const;

    // handle_msg - parses a mavlink message from the companion computer
    // (Note: We might not need this if AP_AILanding handles the decoding, 
    //  but we can use it if we want to bypass AP_AILanding for some reason. 
    //  For now, we pull data FROM AP_AILanding singleton)
    void handle_msg(const mavlink_landing_target_t &packet, uint32_t timestamp_ms) override {};

private:
    // Helper to get fresh data from AP_AILanding Singleton
    const AP_AILanding* get_ailanding_source() const;
};

#endif // AC_PRECLAND_ENABLED
