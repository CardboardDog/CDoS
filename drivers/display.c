#include "display.h"
#include "rw_io.h"
uint16* display_buffer;
uint32 cursor_i;
uint8 display_color = 0;
uint32 line;
void clear_display(){
    int i;
    for(i=0;i<DISP_BUFFER_SIZE;i++){
        display_buffer[i]=get_char(0,WHITE,display_color);
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
void move_cursor(uint16 x, uint16 y){
    cursor_i=(y*80)+x;
    write_byte(0x3D4,0x0F);
    write_byte(0x3D5, (uint8) (cursor_i & 0xFF));
    write_byte(0x3D4,0x0E);
    write_byte(0x3D5, (uint8) ((cursor_i >> 8) & 0xFF));
    line=y;
}
void set_cursor(uint32 position){
    write_byte(0x3D4,0x0F);
    write_byte(0x3D5, (uint8) (position & 0xFF));
    write_byte(0x3D4,0x0E);
    write_byte(0x3D5, (uint8) ((position >> 8) & 0xFF));
}
void set_display_char(uint8 character, uint8 color, uint16 x, uint16 y){
    display_buffer[(y*80)+x] = get_char(character,color,display_color);
}
void show_cursor(){
    write_byte(0x3D4,0x0A);
    write_byte(0x3D5,0x0);
    write_byte(0x3D4,0x0B);
    write_byte(0x3D5,(read_byte(0x3D5)&0xE0)|(uint8)15);
}
void hide_cursor(){
    write_byte(0x3D4,0x0A);
    write_byte(0x3D5,0x20);
}
void init_display(){
    cursor_i=0;
    line=0;
    display_buffer=VGA_ADDRESS;
    clear_color(BLACK);
    clear_display();
}
void display_char(uint8 chr, uint8 color){
    display_buffer[cursor_i] = get_char(chr,color,display_color);
    cursor_i++;
}