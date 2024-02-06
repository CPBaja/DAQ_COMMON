
#include "rotary_pot.h"

RotaryPot::RotaryPot(int8 pin) {
    this->pin = pin;
}

void RotaryPot::begin() {
    pinMode(pin, INPUT);
}

void RotaryPot::read() {
    cachedPosition = (analogRead(pin)-102)*(105/819);
}

int16 RotaryPot::getCached() {
    return cachedPosition;
}