#include "display.h"
uint16* display_buffer;
uint32 cursor_i;
uint8 display_color = 0;
uint32 line;
void clear_display(){
    int i;
    for(i=0;i<DISP_BUFFER_SIZE;i++){
        display_buffer[i]=get_char(0,BLACK,display_color);
    }
}
void display_text(char* string, uint8 color){
    int i = 0;
    while(string[i]){
        display_buffer[cursor_i] = get_char(string[i],color,display_color);
        i++;
        cursor_i++;
    }
}
void clear_color(uint8 color){
    display_color = color;
}
uint16 get_char(uint8 character, uint8 text_color, uint8 base_color){
    uint16 chr = (((base_color << 4)|text_color) << 8)|character;
}
void new_line(){
    cursor_i=(line+1)*80;
    line++;
}
void init_display(){
    cursor_i=0;
    line=0;
    display_buffer=VGA_ADDRESS;
    clear_color(BLACK);
    clear_display();
}