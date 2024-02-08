#include "RotaryEncoder.h"

RotaryPot::RotaryPot(int8 pin) {
    this->pin = pin;
}

void RotaryPot::begin() {
    pinMode(pin, INPUT);
}

void RotaryPot::read() {
    RotaryPot::cached = (analogRead(pin)-102)*(105/819);
}
