template <typename T>
#pragma once

class Encoder
{
    bool f_available;
    T data;
    T transmitting;

    Encoder()
    {
    }

    T* data() {
        return data;
    }
};