#ifndef __SteeringAngle__
#define __SteeringAngle__

// #include <Arduino.h>
#include "../Sensor/Sensor.h"

class steeringAnglePot : public Sensor {
  public:
  steeringAnglePot(int8 pin);

  void begin();
  void read();
  int16 getCached();

  private:
  int8 pin;
};

#endif