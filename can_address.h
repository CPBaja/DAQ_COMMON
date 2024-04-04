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

const uint16 FL_SPEED = 0xBB8;
const uint16 FR_SPEED = 0xBB9;

const uint16 FR_SUS_POS = 0xBBA;
const uint16 FL_SUS_POS = 0xBBB;
const uint16 RR_SUS_POS = 0xBBC;
const uint16 RL_SUS_POS = 0xBBD;
const uint16 ST_POS = 0xBBE;

const uint16 CLUTCH_PRESS = 0xFA0;
const uint16 PROP_SPEED = 0xFA1;
const uint16 G_OIL_TEMP = 0xFA2;
const uint16 SPOOL_TEMP = 0xFA3;

const uint8 SAS_HARD = 0x1770;
const uint8 SAS_SOFT = 0x1771;

const uint16 IMU_ACCEL_X = 0x1B58;
const uint16 IMU_ACCEL_Y = 0x1B59;
const uint16 IMU_ACCEL_Z = 0x1B5A;
const uint16 IMU_PITCH = 0x1B5B;
const uint16 IMU_YAW = 0x1B5C;
const uint16 IMU_ROLL = 0x1B5D;
const uint16 IMU_LATITUDE = 0x1B5E;
const uint16 IMU_LONGITUDE = 0x1B5F;
const uint16 IMU_MAG_HEADING = 0x1B60;

#endif
