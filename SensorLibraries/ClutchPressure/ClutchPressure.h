#ifndef __CLUTCHPRESS__
#define __CLUTCHPRESS__

//#include <Arduino.h>
#include "../Sensor/Sensor.h"
#include "../../types.h"

class ClutchPressure : public Sensor{
public: 
    ClutchPressure(int8 pin);

    void begin();
    void read();

private: 
    int8 pin;
};
#endif