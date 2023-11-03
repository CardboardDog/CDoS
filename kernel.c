#include "kernel.h"
#include "drivers/c.h"
#include "drivers/rw_io.h"
#include "drivers/display.h"
#include "drivers/keyboard.h"
#include "time.h"
void boot_kernel(){
    init_display();
    clear_color(BLACK);
    clear_display();
    display_text("Welcome to CDoS rv1!",WHITE);
    new_line();
    display_text("root.CDoS:> ",WHITE);
    show_cursor();
    set_cursor(cursor_i);
    initiate_keyboard();
    int x_c=0;
    int y_c=0;
    int start_char=cursor_i;
    while(1){
        check_keys();
        int read_k;
        for(read_k=0;read_k<53;read_k++){
            if(key_map[read_k]==1){
                if(read_k==KEY_BACKSPACE){
                    if(cursor_i>start_char){
                        move_cursor((cursor_i-(line*80)-1),line);
                        display_text(" ",WHITE);
                        move_cursor((cursor_i-(line*80)-1),line);
                    }
                }else if(read_k == KEY_RETURN){
                    new_line();
                    display_text("root.CDoS:> ",WHITE);
                    set_cursor(cursor_i);
                    start_char=cursor_i;
                }else{
                    display_char(text_map[read_k+(53*key_shift)],RED);
                    set_cursor(cursor_i);
                }
            }
        }
        sleep((uint32)55000);
    }
}