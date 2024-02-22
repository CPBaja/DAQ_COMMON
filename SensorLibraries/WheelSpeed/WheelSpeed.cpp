/*
 *	WheelSpeed.cpp - Library for measuring wheel speed.
 *	Created by Rahul Goyal, July 2019.
 *	Released to Cal Poly Baja SAE. ;)
 */

#include "WheelSpeed.h"

const uint32_t TIMEOUT = 1000000;

// Constructor
/** This constructor accepts the number of triggers per revolution and stores
	it. prevTime and currTime are initialized to the system time. **/
    
WheelSpeed::WheelSpeed(int8 pin, int8 triggers) {
	// Initialize variables
	this->pin = pin;
	this->triggers = triggers;
	prevTime = micros();
	currTime = micros();
}

void WheelSpeed::setISR(void (*isr)()) {
	this->isr = isr;
}

void WheelSpeed::begin() {
	pinMode(pin, INPUT);
	attachInterrupt(digitalPinToInterrupt(pin), isr, RISING);
}

// Interrupt Service Routine Method
/** This function stores the value of currTime (from the previous call to this
	function by the interrupt service routine) in prevTime and currTime is
	updated to the system time. This information is used by the read method to
	calculate the wheel speed. **/
void WheelSpeed::calc() {
	prevTime = currTime;
	currTime = micros();
}

// Read Wheel Speed Method
/** This function uses the value of currTime and the value of prevTime to
	calculate the wheel speed and return it as an 16-bit integer. If the time
	difference exceeds the defined TIMEOUT constant (in microseconds), a value
	of zero is returned to indicate that wheel is not moving. **/
void WheelSpeed::read() {
	cli();
	uint32_t curr = currTime;
	uint32_t prev = prevTime;
	sei();

	if(micros() - prev >= TIMEOUT) {
		Sensor::cached = 0;
	}

	// return 1000000 / ((curr - prev) * triggers); // Revolutions per Second (RPS)
	Sensor::cached = 60000000 / ((curr - prev) * triggers); // Revolutions per Minute (RPM)
}
