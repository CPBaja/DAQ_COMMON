#include "BrakePressure.h"

BrakePressure::BrakePressure(uint8 pin) {
    this->pin = pin;
}

void BrakePressure::begin() {
    pinMode(pin, INPUT);
}

void BrakePressure::read() {
    Sensor::cached = (analogRead(pin)-102)*1700/819;
}
