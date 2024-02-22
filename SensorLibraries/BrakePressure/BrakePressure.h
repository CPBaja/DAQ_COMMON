#ifndef __BRAKEPRESS__
#define __BRAKEPRESS__

//#include <Arduino.h>
#include "../Sensor/Sensor.h"
#include "../../types.h"

class BrakePressure : public Sensor{
public: 
    BrakePressure(int8 pin);

    void begin();
    void read();

private: 
    int8 pin;
};
#endif