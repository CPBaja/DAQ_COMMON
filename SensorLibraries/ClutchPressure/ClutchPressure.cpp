#include "ClutchPressure.h"

ClutchPressure::ClutchPressure(int8 pin) {
    this->pin = pin;
}

void ClutchPressure::begin() {
    pinMode(pin, INPUT_PULLDOWN);
}
//psi * 10
void ClutchPressure::read() {
    Sensor::cached = (analogRead(pin)-102)*5000/819;
}
