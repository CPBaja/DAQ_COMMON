#pragma once
#include <Arduino.h>

template <typename T_DATA, typename T_PREAMBLE = uint16_t, typename T_CHECKSUM = uint16_t, T_PREAMBLE V_PREAMBLE = 0x6969>
class Encoder
{

private:
    Stream &serial;
    bool _f_available;

    size_t _bytes_sent;

    union
    {
        packet_t data;
        uint8_t buf[];
    } _packet;
    
    void packet_t_send(T_DATA dat)
    {
        _packet.data.data = dat;
        _packet.data.preamble = V_PREAMBLE;
        _packet.data.checksum = calculate_cksum(&dat);
        _bytes_sent = 0;
    }

    // need to have space to write it to, and data to write -- check these two
    // then write a single byte while having those conditions 
    void fifo() 
    {
        if((_bytes_sent < sizeof(_packet)) && (serial.availableForWrite() > 0)) {
            serial.write(_packet.buf[_bytes_sent++]);
        }
    }

    // loop all functions to send the car data to user!
    // 1. Transmit & copy car_data struct
    // 2. Place data into packet_t struct & compute checksum
    // 3. Check if there is buffer space & place next byte of struct into serial
    void loop()
    {
        fifo();
    }


public:
    Encoder(Stream &s): serial(s)
    {
    }
};