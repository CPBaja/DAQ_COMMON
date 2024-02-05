/*
 *  Sensor.cpp - Abstract class for sensors.
 *  Created by Shaina Bagri, January 2021.
 *  Modified by Joe Keenan, February 2024
 *  Released to Cal Poly Baja SAE. ;)
 */

#include "Sensor.h"

Sensor::Sensor() {

}

int16 Sensor::getCached() {
    return cached;
}