#ifndef __STEERINGANGLE__
#define __STEERINGANGLE__

// #include <Arduino.h>
#include "../Sensor/Sensor.h"
#include "../../types.h"

class SteeringAngle : public Sensor {
  public:
  SteeringAngle(uint8 pin);

  void begin();
  void read();

  private:
  uint8 pin;
};

#endif