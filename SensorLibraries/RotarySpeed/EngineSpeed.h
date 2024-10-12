/*
 *	EngineSpeed.h - Library header for measuring engine speed.
 *	Created by Rahul Goyal, July 2019.
 *  Released to Cal Poly Baja SAE. ;)
 */

#ifndef __ENGINESPEED__
#define __ENGINESPEED__

// #include <Arduino.h>
#include "RotarySpeed.h"

class EngineSpeed : public RotarySpeed
{
public:
	// Constructor
	EngineSpeed(uint8_t pin, int8_t triggers);
private:
	int32 cache_num = 120000000;
};

#endif 