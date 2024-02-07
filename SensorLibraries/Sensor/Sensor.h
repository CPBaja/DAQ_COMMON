/*
 *  Sensor.h - Abstract class header for sensors.
 *  Created by Shaina Bagri, January 2021.
 *  Modified by Joe Keenan, February 2024
 *  Released to Cal Poly Baja SAE. ;)
 */

#ifndef __SENSOR__
#define __SENSOR__

#include <Arduino.h>
#include "types.h"

class Sensor
{
public:
    Sensor();

    virtual void begin() = 0;
    virtual void read() = 0;
    int16 getCached();

private:
    int16 cached;
};

#endif
