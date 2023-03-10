#pragma once
#include <Arduino.h>


template <typename T_DATA, typename T_PREAMBLE = uint16_t, typename T_CHECKSUM = uint16_t, T_PREAMBLE V_PREAMBLE = 0x6969>
class Encoder
{

private:
    Stream *serial;
    bool _f_available;

    size_t _num_to_send;
    struct
    {
        T_PREAMBLE preamble;
        T_DATA data;
        T_CHECKSUM checksum;
    } _packet;


    void packet_t_send(T_DATA dat)
    {
        _packet.data = dat;
        _packet.preamble = V_PREAMBLE;
        _packet.checksum = calculate_cksum(&_packet.data);
    }

    // need to have space to write it to, and data to write -- check these two
    // then write a single byte while having those conditions 
    void fifo() 
    {
        while(Serial.availableForWrite() > 0) {
            bytes = Serial.availableForWrite();
            value = Serial.readString();

            Serial.println(value);
            Serial.println(bytes);
        }
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