/*
 * Motor438725.cpp - Library for Maxon 438725 Motor driver
 * Created by Joe Keenan, February 2023
 * Released to Cal Poly Baja SAE
 */

#include <Arduino.h>
#include "Motor438725.h"

Motor438725::Motor438725(uint8_t PWM, uint8_t DIR, bool invert)
{
    this->PWM = PWM;
    this->DIR = DIR;
    this->invert = invert;
}

void Motor438725::begin()
{
    pinMode(PWM, OUTPUT);
    pinMode(DIR, OUTPUT);

    analogWriteFrequency(PWM, 4577.63671875);
}

void Motor438725::setDutyCycle(int16_t dutyCycle)
{
    bool negative = (dutyCycle < 0) ^ invert;

    // Normalize duty cycle
    dutyCycle = dutyCycle < 0 ? -dutyCycle : dutyCycle;

    // Saturate duty cycle
    dutyCycle = dutyCycle > 1000 ? 1000 : dutyCycle;

    // Scale duty cycle from 1000 to between 10% and 90% of 1023
    int16_t scaledDutyCycle = ((uint32_t)dutyCycle * 1023 * 4 / 5 + 102300) / 1000;

    // Write PWM
    analogWrite(PWM, scaledDutyCycle);

    // Write direction
    digitalWrite(DIR, negative);
}
