#include "RotarySpeed.h"

const uint32 TIMEOUT = 1000000;

RotarySpeed::RotarySpeed(uint8 pin, int8 triggers) {
	this->pin = pin;
	this->triggers = triggers;
	for (int8 i = 0; i < 2 * triggers; i++)
	{
		prevTime[i] = micros();
	}
	currTime = micros();
}

void RotarySpeed::setISR(void (*isr)())
{
	this->isr = isr;
}

void RotarySpeed::begin()
{
	pinMode(pin, INPUT);
	attachInterrupt(digitalPinToInterrupt(pin), isr, RISING);
}

void RotarySpeed::calc() {
	uint32 prev = currTime;
	uint32 curr = micros();

	// Reject high frequency
	if (curr - prev < 3500)
		return;

	prevTime[pos] = prev;
	currTime = curr;
	// Increment position
	pos++;
	if (pos >= 2 * triggers)
	{
		pos = 0;
	}
}

void RotarySpeed::read() {
	#ifdef __TEENSY__
	cli();
	#endif
	uint32 curr = currTime;
	uint32 prev = prevTime[pos];
	#ifdef __TEENSY__
	sei();
	#endif

	if (micros() - prev >= TIMEOUT)
	{
		Sensor::cached =  0;
	}

	// return 2000000 / (curr - prev); // Revolutions per Second (RPS)
	Sensor::cached = cache_num / (curr - prev); // Revolutions per Minute (RPM)
}