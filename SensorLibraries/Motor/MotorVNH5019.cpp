/*
 *	MotorVNH5019.cpp - Library for motors (adapted from DualVNH5019MotorShield library).
 *	Created by Rahul Goyal, July 2019.
 *	Released to Cal Poly Baja SAE. ;)
 */

#include <Arduino.h>
#include "MotorVNH5019.h"

MotorVNH5019::MotorVNH5019(int8_t PWM, int8_t INA, int8_t INB)
{
	this->PWM = PWM;
	this->INA = INA;
	this->INB = INB;
}

void MotorVNH5019::begin()
{
	pinMode(PWM, OUTPUT);
	pinMode(INA, OUTPUT);
	pinMode(INB, OUTPUT);

	analogWriteFrequency(PWM, 29296.875);
}

void MotorVNH5019::setDutyCycle(int16_t dutyCycle)
{
	// Determine direction
	bool negative = dutyCycle < 0;

	// Normalize duty cycle
	dutyCycle = dutyCycle < 0 ? -dutyCycle : dutyCycle;

	// Saturate duty cycle
	dutyCycle = dutyCycle > 1000 ? 1000 : dutyCycle;

	// Write PWM, scale 1000 to 1023
	analogWrite(PWM, dutyCycle * 1023 / 1000);

	// Coast (indpendent of direction)
	if (dutyCycle == 0)
	{
		digitalWrite(INA, LOW);
		digitalWrite(INB, LOW);
	}
	// Negative
	else if (negative)
	{
		digitalWrite(INA, LOW);
		digitalWrite(INB, HIGH);
	}
	// Positive
	else
	{
		digitalWrite(INA, HIGH);
		digitalWrite(INB, LOW);
	}
}
