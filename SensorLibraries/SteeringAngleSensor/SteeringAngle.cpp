#include "SteeringAngle.h"

steeringAnglePot::steeringAnglePot(int8 pin)
{
    this->pin = pin
}

void steeringAnglePot::begin()
{
    pinMode(pin, INPUT);
}

void steeringAnglePot::read()
{
    Sensor::cached = (analogRead(pin))
}