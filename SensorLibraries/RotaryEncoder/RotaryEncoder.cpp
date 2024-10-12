#include "RotaryEncoder.h"

RotaryPot::RotaryPot(uint8 pin) {
    this->pin = pin;
}

void RotaryPot::begin() {
    pinMode(pin, INPUT);
}

void RotaryPot::read() {
    // analogRead(pin) and 4096 were both multiplied by 10 so convert as needed
    Sensor::cached = ((525*((analogRead(pin)*10)-4096))/16384);
}
