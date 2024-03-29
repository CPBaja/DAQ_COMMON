#ifndef __DATA__
#define __DATA__

#include "types.h"

struct ecvt_data {
    int16 rwSpeed;
    int16 fBrakePressure;
    int16 rBrakePressure; // 10
    // Engine
    int8 eState;
    int16 eSpeed;
    int16 eControllerRatioOutput;
    int16 eRatioP;
    int16 eRatioI;
    int16 eRatioD;
    int16 eControllerOffsetOutput;
    int16 eOffsetP;
    int16 eOffsetI;
    int16 eOffsetD; // 29
    // Primary
    int8 pState;
    int32 pEncoder;
    int16 pLoadCellForce;
    int16 pMotorCurrent;
    int16 pControllerOutput; // 40
    int16 pP;
    int16 pI;
    int16 pD;
    // Secondary
    int8 sState;
    int32 sEncoder;
    int16 sLoadCellForce;
    int16 sMotorCurrent;
    int16 sControllerOutput;
    int16 sEncoderPID;
    int16 sEncoderP;
    int16 sEncoderI;
    int16 sEncoderD;
    int16 sLoadCellPID;
    int16 sLoadCellP;
    int16 sLoadCellI;
    int16 sLoadCellD; // 61

    // PID Setpoints
    int32 eRatioSetpoint;
    int32 eOffsetSetpoint;
    int32 pEncSetpoint;
    int32 sEncSetpoint;
    int32 slcSetpoint;

    // Sensors
    int16 engineSpark;
    int16 primaryTemp;
    int16 secondaryTemp;
    int16 irTemp;
    int16 fuelLevel;
    int16 throttlePosition;
} __attribute__((packed));

struct suspension_data {
    uint16 blPot;
    uint16 brPot;
    uint16 flPot;
    uint16 frPot;
} __attribute__((packed));

struct powertrain_data {
    uint16 gearboxTemp;
    uint16 gearboxShaftSpeed;
} __attribute__((packed));

struct electrons_data {
    uint16 voltageSenseBatt;
    uint16 voltageSense12;
    uint16 voltageSense5;
    uint16 voltageSense3V3;
    uint8 batteryPercent;
    uint16 currentSenseLvbattery;
    uint16 currentSenseBattery;
    uint16 currentSenseMotorP;
    uint16 currentSenseMotorS;
    uint16 currentSenseSolenoid;
} __attribute__((packed));

struct brakes_data {
    uint16 frWheelSpeed;
    uint16 flWheelSpeed;
} __attribute__((packed));

struct steering_data {
    uint16 steeringRotPot;
} __attribute((packed));

struct imu_data {
    int16 accelerationX;
    int16 accelerationY;
    int16 accelerationZ;
    int16 pitchRate;
    int16 yawRate;
    int16 rollRate;
    int16 gpsLatitude;
    int16 gpsLongitude;
    uint16 magnetometerHeading;
} __attribute((packed));

struct sas_data {
    uint8 blPWM;
    uint8 brPWM;
    uint8 flPWM;
    uint8 frPWM;
} __attribute__((packed));
 
struct car_data {
    uint32 time;
    struct ecvt_data ecvt;
    struct suspension_data sus;
    struct powertrain_data pt;
    struct electrons_data electrons;
    struct brakes_data brakes;
    struct steering_data steering;
    struct imu_data imu;
    struct sas_data sas;
    
    uint8 launch;
    uint8 logging;
    uint8 susSoft;
    uint8 susHard;
    uint8 spare;
    uint8 clutchMode;
} __attribute__((packed));

#endif