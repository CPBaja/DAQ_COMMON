#ifndef __ROTARYSPEED__
#define __ROTARYSPEED__

// #include <Arduino.h>
#include "../Sensor/Sensor.h"
#include "../../types.h"

class RotarySpeed : public Sensor
{
public:
	// Constructor
	RotarySpeed(uint8 pin, int8 triggers);

	// Methods
	void setISR(void (*isr)());
	void begin();
	void calc();
	void read();

protected:
	void (*isr)();
	volatile uint32 currTime;
	volatile uint32 prevTime[100];
	uint8 pin;
	uint8 triggers;
	volatile int8 pos = 0;
	int32 cache_num;
};

#endif