#include "Therm.h"

Therm::Therm(uint8 pin, int16* thermLookup, int16 r_two) {
    this->pin = pin;
    this->thermLookup = thermLookup;
    this->r_two = r_two;
}

void Therm::begin() {
    pinMode(pin, INPUT);
}

void Therm::read() {
    return thermLookup[calcResistance()];
}

int16 Therm::calcResistance() {
    return ((r_two)*(4095-analogRead(pin)))/analogRead(pin);
}