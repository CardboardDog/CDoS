#include "rw_io.h"
uint8 read_byte(uint16 address){
    uint8 read_tmp;
    asm volatile("inb %1, %0":"=a"(read_tmp):"Nd"(address));
    return read_tmp;
}
void write_byte(uint16 address,uint8 value){
    asm volatile("outb %1, %0"::"dN"(address),"a"(value));
}