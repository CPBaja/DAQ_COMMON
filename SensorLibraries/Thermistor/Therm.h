#ifndef __THERM__
#define __THERM__

//#include <Arduino.h>
#include "../Sensor/Sensor.h"
#include "../../types.h"

class Therm : public Sensor
{
public:
    Therm(uint8 pin, int16* thermLookup, int16 r_two);

    void begin();
    void read();

private:
    int16 r_two;
    uint8 pin;
    int16* thermLookup;
    int16 calcResistance();
};

#endif