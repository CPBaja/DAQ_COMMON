#ifndef __CAN_ADDRESS__
#define __CAN_ADDRESS__

#include "types.h"
const uint16 ECVT_DATA1 = 0x0;
const uint16 ECVT_DATA2 = 0x1;
const uint16 ECVT_DATA3 = 0x2;
const uint16 ECVT_DATA4 = 0x3;
const uint16 ECVT_DATA5 = 0x4;
const uint16 ECVT_DATA6 = 0x5;
const uint16 ECVT_DATA7 = 0x6;
const uint16 ECVT_DATA8 = 0x7;
const uint16 ECVT_DATA9 = 0x8;
const uint16 ECVT_DATA10 = 0x9;
const uint16 ECVT_DATA11 = 0xA;
const uint16 ECVT_DATA12 = 0xB;
const uint16 ECVT_DATA13 = 0xC;
const uint16 ECVT_DATA14 = 0xD;
const uint16 ECVT_DATA15 = 0xE;
const uint16 ECVT_DATA16 = 0xF;

const uint16 SAS_DATA1 = 0x20;  // bl, br, fl, fr pwm values
const uint16 SAS_DATA2 = 0x21;  // Current sas state
const uint16 SAS_DATA3 = 0x22;
const uint16 SAS_DATA4 = 0x23;

const uint16 CLUTCH_DATA1 = 0x10;
const uint16 CLUTCH_DATA2 = 0x11;
const uint16 CLUTCH_DATA3 = 0x12;
const uint16 CLUTCH_DATA4 = 0x13;

const uint16 IO = 0x3FF;

const uint16 VOLTAGES = 0x400;
const uint16 CURRENTS = 0x401;
const uint16 ELEC_DATA3 = 0x402;  // Solenoid current and battery percentage

const uint16 FRONT_BREAKOUT_DATA1 = 0x403;  // flPot, frPot, steeringRotPot, gearboxShaftSpeed
const uint16 FRONT_BREAKOUT_DATA2 = 0x404;  // flWheelSpeed, frWheelSpeed, fBrakePressure, rBrakePressure

const uint16 REAR_BREAKOUT_DATA1 = 0x405;  // blPot, brPot, throttlePosition
const uint16 REAR_BREAKOUT_DATA2 = 0x406;  // gearboxTemp, spoolTemp, fuelGauge

const uint16 SAS_BUTTONS = 0x24;  // Hard button, soft button

const uint16 IMU_DATA1 = 0x407;  // x, y and z acceleration, heading
const uint16 IMU_DATA2 = 0x408;  // Pitch, yaw, roll
const uint16 IMU_DATA3 = 0x409;  // Latitude and longitude

#endif
