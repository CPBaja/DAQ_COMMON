#ifndef __ROTARYPOT__
#define __ROTARYPOT__

// #include <Arduino.h>
#include "../Sensor/Sensor.h"
#include "../../types.h"

class RotaryPot : public Sensor
{
public:
    RotaryPot(uint8 pin);

    void begin();
    void read();

private:
    uint8 pin;
};
#endif