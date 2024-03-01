#ifndef __CLUTCHPRESS__
#define __CLUTCHPRESS__

//#include <Arduino.h>
#include "../Sensor/Sensor.h"
#include "../../types.h"

class ClutchPressure : public Sensor{
public: 
    ClutchPressure(uint8 pin);

    void begin();
    void read();

private: 
    uint8 pin;
};
#endif