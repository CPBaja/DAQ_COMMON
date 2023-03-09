#pragma once
#include <Arduino.h>

/**
 * Constructs the T datatype byte-by-byte.
 * b is the byte to add with this call, len
 * manages and stores the index of reconstruction.
 * Returns if reconstruction has finished
 */
template <typename T>
inline bool rx(T *t, size_t *len, uint8_t b)
{
    ((uint8_t *)t)[*len++] = b;
    return *len >= sizeof(T);
}

/**
 * Same as `rx` but also resets the length variable when finished.
 * Should be used when multiple reconstructions happen in a sequence.
 */
template <typename T>
inline bool rxr(T *t, size_t *len, uint8_t b)
{
    if (rx(t, len, b))
    {
        *len = 0;
        return true;
    }
    else
        return false;
}

template <typename T_DATA, typename T_PREAMBLE = uint16_t, typename T_CHECKSUM = uint16_t, T_PREAMBLE V_PREAMBLE = 0x6969>
class Decoder
{
private:
    Stream *serial;

    bool _f_available;
    packet_t _last_packet;

    size_t _len;
    struct
    {
        T_PREAMBLE preamble;
        T_DATA data;
        T_CHECKSUM checksum;
    } _packet;

    enum
    {
        INIT,
        RX,
    } _state;

    /**
     * Shifts the data in packet.preamble once to the left, and decrements the length
     * to effectively shift the preamble. Designed to quickly "scroll" through the stream
     * to find a preamble if sync is lost.
     */
    void shift_preamble()
    {
        memcpy(&_packet, &_packet + 1, sizeof(_packet.preamble) - 1);
        _len--;
    }

    /**
     * Checks checksum and copys data from in buffer to held buffer if valid.
     * Returns if data was successfully received.
     */
    bool finalize_data()
    {
        if (calculate_cksum(&_packet.data) != _packet.checksum)
            return false;

        _last_packet = _packet;
        _f_available = true;
        return true;
    }

    bool parse_fsm(uint8_t b)
    {
        switch (_state)
        {
        case INIT:
            if (rx(&_packet.preamble, &_len, b))
            {
                if (_packet.preamble == V_PREAMBLE)
                    _state = RX;

                else
                    shift_preamble();
            }
            return false;

        case RX:
            if (rxr(&_packet, &_len, b))
            {
                _state = INIT;
                return finalize_data();
            }
            return false;
        }
    }

public:
    Decoder(Stream *serial)
    {
        this->serial = serial;
    }

    bool available()
    {
        while (serial->available())
            _f_available |= parse_fsm(serial->read());

        return _f_available;
    }

    const T_DATA *read()
    {
        _f_available = false;
        return &_last_packet.data;
    }
};