#include "SteeringAngle.h"

#define POT_MAX       1023
#define CENTER_OFFSET 180
#define ANGLE_MAX     360

steeringAnglePot::steeringAnglePot(int8 pin) { 
  this->pin = pin; 
  }

void steeringAnglePot::begin() { 
  pinMode(this->pin, INPUT); 
  }

void steeringAnglePot::read() {
  Sensor::cached =
      ((analogRead(this->pin) * ANGLE_MAX) / POT_MAX) - CENTER_OFFSET;
}
