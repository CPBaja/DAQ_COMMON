
#include "communication.h"

template <typename T>

int32 calculate_cksum(T *data) {
    int32 total = PREAMBLE;
    int32 cksum;

    for(uint16 i = 0; i < sizeof(data); i++) {
        total += data[i];
    }

    cksum = -total;
    return cksum;
}

template <typename T>
int32 check_cksum(T *packet) {
    int32 total = 0;

    for(uint16 i = 0; i < sizeof(packet); i++) {
        total += packet[i];
    }

    return total;
}