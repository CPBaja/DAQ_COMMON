/*
 *	AnalogSensor.cpp - Abstract class for analog sensors.
 *	Created by Rahul Goyal, April 2022.
 *  Released to Cal Poly Baja SAE. ;)
 */

#include "Thermistor.h"

Thermistor::Thermistor(int8 pin) {
    this->pin = pin;
}

void Thermistor::begin() {
    pinMode(pin, INPUT);
}

void Thermistor::read() {
    Sensor::cached=bitsToTemp(analogRead(pin));
}

int16 Thermistor::bitsToTemp(uint16 bits) {
    return thermLookup[bits]
}