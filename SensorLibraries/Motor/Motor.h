/*
 *	Motor.h - Abstract class header for motors.
 *	Created by Rahul Goyal, April 2022.
 *	Released to Cal Poly Baja SAE. ;)
 */

#ifndef __MOTOR__
#define __MOTOR__

#include <Arduino.h>

class Motor
{
public:
	Motor();

	virtual void begin() = 0;
	virtual void setDutyCycle(int16_t dutyCycle) = 0;
};

#endif
