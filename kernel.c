#include "kernel.h"
#include "c.h"
#include "display.h"
void boot_kernel(){
    init_display();
    clear_color(WHITE);
    clear_display();
    display_text("hello world",BLACK);
    new_line();
    display_text("line #2",BLACK);
    new_line();
    display_text("green text",GREEN);
}