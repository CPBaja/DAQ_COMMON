
#include "communication.h"

int16 calculate_cksum(struct car_data *data) {
    int32 total = PREAMBLE + VERSION;
    int32 cksum;

    uint8 *dataArray = (uint8 *)data;

    for(uint16 i = 0; i < sizeof(dataArray); i++) {
        total += dataArray[i];
    }

    cksum = -total;
    return cksum;
}