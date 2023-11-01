#include "kernel.h"
#include "drivers/c.h"
#include "drivers/rw_io.h"
#include "drivers/display.h"
void boot_kernel(){
    init_display();
    clear_color(BLACK);
    clear_display();
    display_text("Welcome to CDoS rv1!",WHITE);
    new_line();
    display_text("root.CDoS:> ",WHITE);
    show_cursor();
    set_cursor(cursor_i);
    while(1){
    }
}