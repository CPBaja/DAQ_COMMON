
#include "communication.h"

template <typename T>

int16 calculate_cksum(T *data) {
    int32 total = PREAMBLE + VERSION;
    int32 cksum;

    for(uint16 i = 0; i < sizeof(data); i++) {
        total += data[i];
    }

    cksum = -total;
    return cksum;
}