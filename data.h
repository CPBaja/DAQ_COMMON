#ifndef __DATA__
#define __DATA__

#include "types.h"


struct ecvt_data {
    int16 enginePID;
    int16 engineP;
    int16 engineI;
    int16 engineD;

    int16 secondary_encPID;
    int16 secondary_lcPID;
    int16 secondary_lcP;
    int16 secondary_lcI;
    int16 secondary_lcD;

    int8 state_primary;
    int8 state_secondary;
    int8 state_engine;

    uint16 encoder_primary;
    uint16 encoder_secondary;

    int16 primary_controller_out;
    int16 secondary_controller_out;
    
    uint16 engine_speed_1;
    uint16 engine_speed_2;
    uint16 engine_spark;
    uint16 rear_wheel_speed;
    uint16 loadcell_primary;
    uint16 loadcell_secondary;
    uint16 primary_temp;
    uint16 secondary_temp;
    uint16 ir_temp;
    uint16 fuel_level;
    uint16 brake_pressure_front;
    uint16 brake_pressure_rear;
    uint16 throttle_pressure;
    
    
    
    
} __attribute__((packed));

struct suspension_data {
    uint16 bl_pot;
    uint16 br_pot;
    uint16 fl_pot;
    uint16 fr_pot;
} __attribute__((packed));

struct powertrain_data {
    uint16 gearbox_temp;
    uint16 gearbox_shaft_speed;
} __attribute__((packed));

struct electrons_data {
    uint16 voltage_sense36;
    uint16 voltage_sense8_4;
    uint16 voltage_sense12;
    uint16 voltage_sense24_1;
    uint16 voltage_sense24_2;
    uint16 current_sense_lvbattery;
    uint16 current_sense_battery;
    uint16 current_sense_motor1;
    uint16 current_sense_motor2;
    uint16 current_sense_solenoid;
} __attribute__((packed));

struct brakes_data {
    uint16 fr_wheel_speed;
    uint16 fl_wheel_speed;
} __attribute__((packed));

struct steering_data {
    uint16 steering_rot_pot;
} __attribute((packed));

struct car_data {
    uint32 time;
    struct ecvt_data ecvt;
    struct suspension_data sus;
    struct powertrain_data pt;
    struct electrons_data electrons;
    struct brakes_data brakes;
    struct steering_data steering;
    uint8 marker;
} __attribute__((packed));

#endif