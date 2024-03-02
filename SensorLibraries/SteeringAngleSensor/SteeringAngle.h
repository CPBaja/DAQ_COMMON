#ifndef __STEERINGANGLE__
#define __STEERINGANGLE__

// #include <Arduino.h>
#include "../Sensor/Sensor.h"
#include "../../types.h"

class steeringAnglePot : public Sensor {
  public:
  steeringAnglePot(int8 pin);

  void begin();
  void read();

  private:
  int8 pin;
};

#endif