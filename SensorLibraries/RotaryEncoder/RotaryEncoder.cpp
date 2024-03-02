#include "RotaryEncoder.h"

RotaryPot::RotaryPot(uint8 pin) {
    this->pin = pin;
}

void RotaryPot::begin() {
    pinMode(pin, INPUT);
}

void RotaryPot::read() {
    Sensor::cached = (analogRead(pin)-102)*105/819;
}
