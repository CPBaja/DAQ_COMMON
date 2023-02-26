#ifndef _COLLECTION_
#define _COLLECTION_

#include<Arduino.h>
#include "../lib/types.h"
#include "data.h"


#include "LoadCell.h"
#include "EngineSpeed.h"
#include "WheelSpeed.h"
#include "BrakePressure.h"
#include "Thermistor.h"



#include <SD.h>


uint8 collect(struct car_data *data, LoadCell plc, LoadCell slc, EngineSpeed engineSpeed1, EngineSpeed engineSpeed2, WheelSpeed rearWheels);

uint8 collect_thermal(struct car_data *data);
uint8 collect_loadcell(struct car_data *data, LoadCell lcP, LoadCell lcS);
uint8 collect_brake_pressure(struct car_data *data);
uint8 collect_enginespeed(struct car_data *data, EngineSpeed esp1, EngineSpeed esp2);
uint8 collect_wheelspeed(struct car_data *data, WheelSpeed rearWheels);

void write(struct car_data *data, File file);

#endif