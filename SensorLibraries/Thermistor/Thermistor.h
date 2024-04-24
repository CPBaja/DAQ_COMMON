#ifndef __THERMISTOR__
#define __THERMISTOR__

//#include <Arduino.h>
#include "../Sensor/Sensor.h"
#include "../../types.h"

class Thermistor : public Sensor
{
public:
    Thermistor(uint8 pin);

    void begin();
    void read();

private:   
    uint8 pin; 
    int16 thermLookup[1024]; 
    int16 bitsToTemp(uint16 bits);
};

#endif