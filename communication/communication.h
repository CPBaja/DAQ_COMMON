

#ifndef __COMMUNICATION__
#define __COMMUNICATION__

#include "types.h"
#include "data.h"

const uint16 TOTAL_STRUCT_SIZE = sizeof(struct car_data);

const uint16 PREAMBLE = 0x6969;
const sbyte VERSION = 0x00;

int16 calculate_cksum(struct car_data *data);



#endif
