#ifndef __DATA__
#define __DATA__

#include "types.h"


struct ecvt_data {
    // Engine
    int8 eState;
    int16 ePID;
    int16 eP;
    int16 eI;
    int16 eD;
    int16 eSpeed;
    
    // Primary
    int8 pState;
    int16 pControllerOutput;
    int32 pEncoder;
    int16 pLoadCellForce;
    int16 pMotorCurrent;
    
    // Secondary
    int8 sState;
    int16 sEncoderPID;
    int16 sLoadCellPID;
    int16 sLoadCellP;
    int16 sLoadCellI;
    int16 sLoadCellD;
    int16 sControllerOutput;
    int32 sEncoder;
    int16 sLoadCellForce;
    int16 sMotorCurrent;
    
    // Sensors
    int16 rwSpeed;
    int16 fBrakePressure;
    int16 rBrakePressure;
    int16 engineSpark;
    int16 primaryTemp;
    int16 secondaryTemp;
    int16 irTemp;
    int16 fuelLevel;
    int16 throttlePressure;
} __attribute__((packed));

struct suspension_data {
    uint16 bl_pot;
    uint16 br_pot;
    uint16 fl_pot;
    uint16 fr_pot;
} __attribute__((packed));

struct powertrain_data {
    uint16 gearbox emp;
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