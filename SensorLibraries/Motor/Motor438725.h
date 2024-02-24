/*
 * Motor438725.h - Library header for Maxon 438725 Motor driver
 * Created by Joe Keenan, February 2023
 * Released to Cal Poly Baja SAE
 */

#ifndef __MOTOR438725__
#define __MOTOR438725__

#include <Arduino.h>
#include "Motor.h"

class Motor438725 : public Motor {

    public:
        Motor438725(uint8_t PWM, uint8_t DIR, bool invert);

        void begin();
        void setDutyCycle(int16_t dutyCycle);

    private:
        uint8_t PWM;
        uint8_t DIR;
        bool invert;
};

#endif