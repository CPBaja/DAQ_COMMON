/*
 *	MotorVNH5019.h - Library header for motors (adapted from DualVNH5019MotorShield library).
 *	Created by Rahul Goyal, July 2019.
 *	Released to Cal Poly Baja SAE. ;)
 */

#ifndef __MOTORVNH5019__
#define __MOTORVNH5019__

#include <Arduino.h>
#include "Motor.h"

class MotorVNH5019 : public Motor
{
public:
	MotorVNH5019(uint8_t PWM, uint8_t INA, uint8_t INB);

	void begin();
	void setDutyCycle(int16_t dutyCycle);

private:
	int8_t PWM;
	int8_t INA;
	int8_t INB;
};

#endif
