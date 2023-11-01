#include "kernel.h"
#include "c.h"
#include "rw_io.h"
#include "display.h"
void boot_kernel(){
    init_display();
    clear_color(BLACK);
    clear_display();
    display_text("hello world",WHITE);
    new_line();
    display_text("line #2",WHITE);
    new_line();
    display_text("green text",GREEN);
    set_display_char('1',RED,20,0);
    show_cursor();
    move_cursor(8,5);
    display_text("the quick brown fox jumps over the lazy dog",RED);
    set_cursor(cursor_i);
    show_cursor();
    while(1){
    }
}