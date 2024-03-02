/*
 *	MotorG218v22.h - Library header for motors (adapted from DualG2HighPowerMotorShield library).
 *	Created by Rahul Goyal, April 2022.
 *	Released to Cal Poly Baja SAE. ;)
 */

#ifndef __MOTORG218v22__
#define __MOTORG218v22__

#include <Arduino.h>
#include "Motor.h"

class MotorG218v22 : public Motor
{
public:
	MotorG218v22(uint8_t PWM, uint8_t DIR, bool invert);

	void begin();
	void setDutyCycle(int16_t dutyCycle);

private:
	int8_t PWM;
	int8_t DIR;
	bool invert;
};

#endif
