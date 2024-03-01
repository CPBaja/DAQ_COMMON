/*
 *	EngineSpeed.cpp - Library for measuring engine speed.
 *	Created by Rahul Goyal, July 2019.
 *	Released to Cal Poly Baja SAE. ;)
 */

#include "EngineSpeed.h"

const uint32_t TIMEOUT = 1000000;

// Constructor
/** This constructor accepts the number of triggers per revolution and stores
	it. The appropriate number of positions in the prevTime array and currTime
	are initialized to the system time. **/
EngineSpeed::EngineSpeed(int8_t pin, int8_t triggers)
{
	// Initialize variables
	this->pin = pin;
	this->triggers = triggers;
	for (int8_t i = 0; i < 2 * triggers; i++)
	{
		prevTime[i] = micros();
	}
	currTime = micros();
}

void EngineSpeed::setISR(void (*isr)())
{
	this->isr = isr;
}

void EngineSpeed::begin()
{
	pinMode(pin, INPUT);
	attachInterrupt(digitalPinToInterrupt(pin), isr, RISING);
}

// Interrupt Service Routine Method
/** This function stores the value of currTime (from the previous call to this
	function by the interrupt service routine) in the appropriate position of
	the prevTime array and currTime is updated to the system time. Afterwards,
	the position is incremented to prepare for the next call to this function.
	If the position exceeds the twice the number of triggers per revolution
	(that is, one thermodynamic cycle of a four-stroke engine), then the
	position is reset to zero. This information is used by the read method to
	calculate the wheel speed. **/
void EngineSpeed::calc()
{
	uint32_t prev = currTime;
	uint32_t curr = micros();

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

// Read Engine Speed Method
/** This function uses the value of currTime and the value from the appropriate
	position of prevTime to calculate the engine speed and return it as an
	16-bit integer. If the time difference exceeds the defined TIMEOUT constant
	(in microseconds), a value of zero is returned to indicate that engine is
	turned off. **/
void EngineSpeed::read()
{
	#ifdef __TEENSY__
	cli();
	#endif
	uint32_t curr = currTime;
	uint32_t prev = prevTime[pos];
	#ifdef __TEENSY__
	sei();
	#endif

	if (micros() - prev >= TIMEOUT)
	{
		Sensor::cached =  0;
	}

	// return 2000000 / (curr - prev); // Revolutions per Second (RPS)
	Sensor::cached = 120000000 / (curr - prev); // Revolutions per Minute (RPM)
}