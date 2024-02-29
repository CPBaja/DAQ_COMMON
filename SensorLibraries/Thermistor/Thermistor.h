#ifndef __THERMISTOR__
#define __THERMISTOR__

//#include <Arduino.h>
#include "../Sensor/Sensor.h"
#include "../../types.h"

class Thermistor : public Sensor
{
public:
    Thermistor(int8 pin);

    void begin();
    void read();

private:   
    int8 pin; 
    virtual int16 thermLookup[1024]; 
    int16 bitsToTemp(uint16 bits);
}