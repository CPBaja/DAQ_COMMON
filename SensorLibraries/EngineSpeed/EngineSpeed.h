/*
 *	EngineSpeed.h - Library header for measuring engine speed.
 *	Created by Rahul Goyal, July 2019.
 *  Released to Cal Poly Baja SAE. ;)
 */

#ifndef EngineSpeed_h
#define EngineSpeed_h

// #include <Arduino.h>
#include "../Sensor/Sensor.h"
#include "../../types.h"

class EngineSpeed : public Sensor
{
public:
	// Constructor
	EngineSpeed(int8_t pin, int8_t triggers);

	// Methods
	void setISR(void (*isr)());
	void begin();
	void calc();
	void read();

private:
	int8_t pin;
	int8_t triggers;

	void (*isr)();

	volatile uint32_t prevTime[100];
	volatile uint32_t currTime;
	volatile int8_t pos = 0;
};

#endif