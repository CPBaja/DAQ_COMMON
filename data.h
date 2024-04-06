#ifndef __DATA__
#define __DATA__

#include "types.h"

struct ecvt_data {
    uint32 time;
    int8 errors;
    // Engine
    int8 eState;
    int16 eControllerRatioOutput;
    int32 eRatioSetpoint;
    int16 eRatioP;
    int16 eRatioI;
    int16 eRatioI2;
    int16 eControllerTorqueOutput;
    int32 eTorqueSetpoint;
    int16 eTorqueP;
    int16 eTorqueI;
    int16 eTorqueD;
    // Primary
    int8 pState;
    int16 pSpeed;
    int32 pEncoderCounts;
    int16 pClampingForce;
    int16 pMotorCurrent;
    int16 pControllerOutput;
    int32 pPositionSetpoint;
    int16 pPositionPID;
    int16 pPositionP;
    int16 pPositionI;
    int16 pPositionD;
    int32 pClampingSetpoint;
    int16 pClampingPID;
    int16 pClampingP;
    int16 pClampingI;
    int16 pClampingD;
    // Secondary
    int8 sState;
    int16 sSpeed;
    int32 sEncoderCounts;
    int16 sClampingForce;
    int16 sMotorCurrent;
    int16 sControllerOutput;
    int32 sPositionSetpoint;
    int16 sPositionPID;
    int16 sPositionP;
    int16 sPositionI;
    int16 sPositionD;
    int32 sClampingSetpoint;
    int16 sClampingPID;
    int16 sClampingP;
    int16 sClampingI;
    int16 sClampingD;
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

struct front_breakout {
    uint16 flPot;
    uint16 frPot;
    uint16 steeringRotPot;
    uint16 frWheelSpeed;
    uint16 flWheelSpeed;
    int16 fBrakePressure;
    int16 rBrakePressure;
    uint16 gearboxShaftSpeed;
} __attribute__((packed));
 
struct rear_breakout {
    uint16 throttlePosition;
    uint16 blPot;
    uint16 brPot;
    uint16 gearboxTemp;
    uint16 spoolTemp;
    uint16 fuelGauge;
} __attribute__((packed));

struct car_data {
    struct ecvt_data ecvt;
    struct electrons_data electrons;
    struct imu_data imu;
    struct sas_data sas;
    struct front_breakout front;
    struct rear_breakout rear;
    
    uint8 launch;
    uint8 logging;
    uint8 susSoft;
    uint8 susHard;
    uint8 spare;
    uint8 clutchMode;
} __attribute__((packed));

#endif