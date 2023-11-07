#ifndef CDOS_RW_IO
#define CDOS_RW_IO
#include "../c.h"
uint8 read_byte(uint16 address);
void write_byte(uint16 address,uint8 value);
#endif