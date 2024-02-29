/*
 *	MotorG218v22.cpp - Library for motors (adapted from DualG2HighPowerMotorShield library).
 *	Created by Rahul Goyal, April 2022.
 *	Released to Cal Poly Baja SAE. ;)
 */

#include <Arduino.h>
#include "MotorG218v22.h"

MotorG218v22::MotorG218v22(int8_t PWM, int8_t DIR, bool invert)
{
	this->PWM = PWM;
	this->DIR = DIR;
	this->invert = invert;
}

void MotorG218v22::begin()
{
	pinMode(PWM, OUTPUT);
	pinMode(DIR, OUTPUT);

	#ifdef __TEENSY__
	analogWriteFrequency(PWM, 29296.875);
	#endif
}

void MotorG218v22::setDutyCycle(int16_t dutyCycle)
{
	// Determine direction
	bool negative = (dutyCycle < 0) ^ invert;

	// Normalize duty cycle
	dutyCycle = dutyCycle < 0 ? -dutyCycle : dutyCycle;

	// Saturate duty cycle
	dutyCycle = dutyCycle > 1000 ? 1000 : dutyCycle;

	// Write PWM, scale 1000 to 1023
	analogWrite(PWM, dutyCycle * 1023 / 1000);

	// Write direction
	digitalWrite(DIR, negative);
}
