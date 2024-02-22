/*
 *	WheelSpeed.h - Library header for measuring wheel speed.
 *	Created by Rahul Goyal, July 2019.
 *	Released to Cal Poly Baja SAE. ;)
 */

#ifndef WheelSpeed_h
#define WheelSpeed_h

// #include <Arduino.h>
#include "../Sensor/Sensor.h"
#include "../../types.h"

class WheelSpeed : public Sensor {
public:
	// Constructor
	WheelSpeed(int8_t pin, int8_t triggers);

	// Methods
	void setISR(void (*isr)());
	void begin();
	void calc();
	void read();

private:
	int8 pin;
	int8 triggers;


	void (*isr)();

	volatile uint32_t prevTime;
	volatile uint32_t currTime;
};

#endif
