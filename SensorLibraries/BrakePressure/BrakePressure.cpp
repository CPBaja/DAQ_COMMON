#include "ClutchPressure.h"

ClutchPressure::ClutchPressure(int8 pin) {
    this->pin = pin;
}

void ClutchPressure::begin() {
    pinMode(pin, INPUT);
}

void ClutchPressure::read() {
    Sensor::cached = (analogRead(pin)-102)*1700/819;
}
