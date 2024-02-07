#ifndef __ROTARYPOT__
#define __ROTARYPOT__

//#include <Arduino.h>
#include "../Sensor/Sensor.h"
#include "../../types.h"

class RotaryPot : public Sensor{
public: 
    RotaryPot()

    void begin();
    void read();
    //int16 getCached();

private: 
    int8 pin;
    //int16 cachedPosition;
}
#endif