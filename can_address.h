#ifndef __CAN_ADDRESS__
#define __CAN_ADDRESS__

#include "types.h"

const int16 SEND_DATA_ADDR = 1;
const int16 LAUNCH_CONTROL_BUTTON_ADDR = 2;
const int16 LOGGER_BUTTON_ADDR = 3;
const int16 MARKER_BUTTON_ADDR = 4;

const int16 ECVT_STATUS_LED_ADDR = 65;
const int16 ECVT_UPSHIFT_LED_ADDR = 66;
const int16 ECVT_DOWNSHIFT_LED_ADDR = 67;

const int16 FR_ROT_POT_ADDR = 129;
const int16 FL_ROT_POT_ADDR = 130;

const int16 SPARK_ADDR = 194;

const int16 FR_WHEEL_SPEED_ADDR = 257;
const int16 FL_WHEEL_SPEED_ADDR = 258;

const int16 GEAR_THERMAL_ADDR = 321;

const int16 FUEL_PRESSURE_ADDR = 385;

#endif
