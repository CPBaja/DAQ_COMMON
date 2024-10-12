/*
 *	WheelSpeed.h - Library header for measuring wheel speed.
 *	Created by Rahul Goyal, July 2019.
 *	Released to Cal Poly Baja SAE. ;)
 */

#ifndef WheelSpeed_h
#define WheelSpeed_h

// #include <Arduino.h>
#include "RotarySpeed.h"

class WheelSpeed : public RotarySpeed {
public:
	// Constructor
	WheelSpeed(uint8_t pin, uint8_t triggers);
private:
	int32 cache_num = 60000000;
};

#endif
