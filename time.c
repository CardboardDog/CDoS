#include "time.h"
// todo: fix later
void sleep(uint32 ms){
    uint32 i_m;
    for(i_m=0;i_m<ms;i_m++){
        asm volatile("pause");
    }
}