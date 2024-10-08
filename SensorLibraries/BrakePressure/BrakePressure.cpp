#include "BrakePressure.h"

BrakePressure::BrakePressure(uint8 pin) {
    this->pin = pin;
}

void BrakePressure::begin() {
    pinMode(pin, INPUT);
}

void BrakePressure::read() {
    //TDH33
    //scale = x10
    Sensor::cached = ((analogRead(pin)*10) - 4096)*3000/32768;
}
