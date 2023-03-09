#pragma once

class Encoder
{
    bool f_available;
    T data;
    T transmitting;

    packet_t packet;
    Encoder()
    {
    }

    T* data() {
        return data;
    }

    send_data(T_DATA dat) {
        packet.data = dat;

        //set preabmle
        //set version
        //calc checksum
    }
};