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

const uint16 SAS_DATA1 = 0x20;
const uint16 SAS_DATA2 = 0x21;
const uint16 SAS_DATA3 = 0x22;
const uint16 SAS_DATA4 = 0x23;

const uint16 CLUTCH_DATA1 = 0x10;
const uint16 CLUTCH_DATA2 = 0x11;
const uint16 CLUTCH_DATA3 = 0x12;
const uint16 CLUTCH_DATA4 = 0x13;

const uint16 IO = 0x3FF;

const uint16 VOLTAGES = 0x400;

const uint16 FL_SPEED = 0x64;
const uint16 FR_SPEED = 0x65;

const uint16 FR_SUS_POS = 0x66;
const uint16 FL_SUS_POS = 0x67;
const uint16 RR_SUS_POS = 0x68;
const uint16 RL_SUS_POS = 0x69;
const uint16 ST_POS = 0x6A;

const uint16 CLUTCH_PRESS = 0xC8;
const uint16 PROP_SPEED = 0xC9;
const uint16 G_OIL_TEMP = 0xCA;
const uint16 SPOOL_TEMP = 0xCB;

const uint8 SAS_HARD = 0x30;
const uint8 SAS_SOFT = 0x31;

const uint16 IMU_ACCEL_X = 0x190;
const uint16 IMU_ACCEL_Y = 0x191;
const uint16 IMU_ACCEL_Z = 0x192;
const uint16 IMU_PITCH = 0x193;
const uint16 IMU_YAW = 0x194;
const uint16 IMU_ROLL = 0x195;
const uint16 IMU_LATITUDE = 0x196;
const uint16 IMU_LONGITUDE = 0x197;
const uint16 IMU_MAG_HEADING = 0x198;

#endif
