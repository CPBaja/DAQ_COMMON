#include "Thermistor.h"

Thermistor::Thermistor(uint8 pin) {
    this->pin = pin;
}

void Thermistor::begin() {
    pinMode(pin, INPUT);
}

void Thermistor::read() {
    Sensor::cached=bitsToTemp(analogRead(pin));
}

int16 Thermistor::bitsToTemp(uint16 bits) {
    return thermLookup[bits];
}