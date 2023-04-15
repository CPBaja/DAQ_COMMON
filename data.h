#ifndef __DATA__
#define __DATA__

#include "types.h"


struct ecvt_data {
    // Engine
    int8_t eState;
    int16_t ePID;
    int16_t eP;
    int16_t eI;
    int16_t eD;
    int16_t eSpeed;
    
    // Primary
    int8_t pState;
    int16_t pControllerOutput;
    int32_t pEncoder;
    int16_t pLoadCellForce;
    int16_t pMotorCurrent;
    
    // Secondary
    int8_t sState;
    int16_t sEncoderPID;
    int16_t sLoadCellPID;
    int16_t sLoadCellP;
    int16_t sLoadCellI;
    int16_t sLoadCellD;
    int16_t sControllerOutput;
    int32_t sEncoder;
    int16_t sLoadCellForce;
    int16_t sMotorCurrent;
    
    // Sensors
    int16_t rwSpeed;
    int16_t fBrakePressure;
    int16_t rBrakePressure;
    int16 engine_spark;
    int16 primary_temp;
    int16 secondary_temp;
    int16 ir_temp;
    int16 fuel_level;
    int16 throttle_pressure;
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
    
    struct ecvt_data ecvt;
    struct suspension_data sus;
    struct powertrain_data pt;
    struct electrons_data electrons;
    struct brakes_data brakes;
    struct steering_data steering;
    uint32 time;
    uint8 marker;
    uint8 launch;
    uint8 writing;
} __attribute__((packed));

#endif