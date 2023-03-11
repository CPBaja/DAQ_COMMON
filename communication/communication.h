

#ifndef __COMMUNICATION__
#define __COMMUNICATION__

#include "types.h"
#include "data.h"

const uint16 TOTAL_STRUCT_SIZE = sizeof(struct car_data);

const uint16 PREAMBLE = 0x6969;
const sbyte VERSION = 0x00;

int16 calculate_cksum(struct car_data *data);

typedef uint16 T_PREAMBLE;
typedef car_data T_DATA;
typedef int32 T_CHECKSUM;


struct packet_t {
    T_PREAMBLE preamble = PREAMBLE;
    T_DATA data;
    T_CHECKSUM checksum;
} __attribute ((packed));
#endif
