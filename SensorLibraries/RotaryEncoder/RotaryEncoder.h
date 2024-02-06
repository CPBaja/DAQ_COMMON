#ifndef _ROTARYPOT_
#define _ROTARYPOT_

#include <Arduino.h>
#include "Sensor.h"
#include "../../lib/DAQ_Common/types.h"

class RotaryPot : public Sensor{
public: 
    RotaryPot()

    void begin();
    void read();
    int16 getCached();

private: 
    int8 pin;
    int16 cachedPosition;
}
#endif