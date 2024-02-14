#include "ClutchPressure.h"

ClutchPressure::ClutchPressure(int8 pin) {
    this->pin = pin;
}

void ClutchPressure::begin() {
    pinMode(pin, INPUT);
}
//psi * 100
void ClutchPressure::read() {
    Sensor::cached = (analogRead(pin)-102)*50000/819;
}
