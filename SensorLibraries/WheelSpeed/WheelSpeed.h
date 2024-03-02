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
	WheelSpeed(uint8_t pin, uint8_t triggers);

	// Methods
	void setISR(void (*isr)());
	void begin();
	void calc();
	void read();

private:
	uint8 pin;
	uint8 triggers;


	void (*isr)();

	volatile uint32_t prevTime;
	volatile uint32_t currTime;
};

#endif
