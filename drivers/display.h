#ifndef CDOS_DISPLAY
#define CDOS_DISPLAY
#include "../c.h"
// replace with enum?
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define GREY 7
#define DARK_GREY 8
#define BRIGHT_BLUE 9
#define BRIGHT_GREEN 10
#define BRIGHT_CYAN 11
#define BRIGHT_RED 12
#define BRIGHT_MAGENTA 13
#define YELLOW 14
#define WHITE 15
#define VGA_ADDRESS 0xB8000
#define DISP_BUFFER_SIZE 2200
extern uint16* display_buffer;
extern uint32 cursor_i;
extern uint8 display_color;
extern uint32 line;
void init_display();
uint16 get_char(uint8 character, uint8 text_color, uint8 base_color);
void clear_display();
void display_text(char* string, uint8 color);
void clear_color(uint8 color);
void new_line();
void move_cursor(uint16 x, uint16 y);
void set_display_char(uint8 character, uint8 color, uint16 x, uint16 y);
void display_char(uint8 chr, uint8 color);
void show_cursor();
void hide_cursor();
void set_cursor(uint32 position);
#endif