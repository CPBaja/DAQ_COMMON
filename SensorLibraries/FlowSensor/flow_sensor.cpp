// #include "flow_sensor.h"

// FlowSensor::FlowSensor(int8 pin) {
//     this->pin = pin;
// }

// void FlowSensor::begin() {
//     pinMode(pin, INPUT);
// }

// void FlowSensor::read() {
//     Sensor::cached = bitsToFlowRate(analogRead(pin));
// }

// // int16 FlowSensor::getCached() {
// //     return cached;
// // }

// int16 FlowSensor::bitsToFlowRate(uint16 bits) {
//     return flowLookup[bits];
// }