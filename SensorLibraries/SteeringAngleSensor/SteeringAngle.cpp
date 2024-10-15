#include "SteeringAngle.h"

#define POT_MAX       4095
#define CENTER_OFFSET 180
#define ANGLE_MAX     360

SteeringAngle::SteeringAngle(uint8 pin) { 
  this->pin = pin; 
  }

void SteeringAngle::begin() { 
  pinMode(this->pin, INPUT); 
  }

void SteeringAngle::read() {
  Sensor::cached =
      ((analogRead(this->pin) * ANGLE_MAX) / POT_MAX) - CENTER_OFFSET;
}
