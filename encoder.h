#pragma once
#include <Arduino.h>
#include <communication/communication.h>

class Encoder
{
private:
    HardwareSerial *serial;
    size_t _len;
    packet_t _packet;


    // need packet_t struct, have a member in class of packet_t type
    // when someone wants to send car data out, need to:
    // 1. Place data into packet_t struct
    // 2. Compute checksum
    // 3. Assign version preamble to proper values
    void packet_t_send(T_DATA dat)
    {
        _packet.data = dat;
        _packet.preamble;

        if (calculate_cksum(&_packet.data) != _packet.checksum): 
        {
            return false;
        }
        return true;
    }
    // topping off teensy's fifo serial buffer
    // 1. Check if there is buffer space
    // 2. Place next byte of struct into the buffer
    void fifo() 
    {
        int buffer_size = Serial.availableForWrite();
        Serial.println(buffer_size);
    }
    // loop all functions to send the car data to user!
    // 1. Transmit & copy car_data struct
    // 2. Place data into packet_t struct & compute checksum
    // 3. Check if there is buffer space & place next byte of struct into serial
    void loop()
    {
        void packet_t_send(T_DATA dat);
        fifo();
    }
public:
    Encoder(HardwareSerial *serial)
    {
        this->serial = serial;
    }
};