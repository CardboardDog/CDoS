#include "c.h"
#ifndef CDOS_KEYBOARD
#define CDOS_KEYBOARD
#define NONE 0
#define KEY_A 1
#define KEY_B 2
#define KEY_C 3
#define KEY_D 4
#define KEY_E 5
#define KEY_F 6
#define KEY_G 7
#define KEY_H 8
#define KEY_I 9
#define KEY_J 10
#define KEY_K 11
#define KEY_L 12
#define KEY_M 13
#define KEY_N 14
#define KEY_O 15
#define KEY_P 16
#define KEY_Q 17
#define KEY_R 18
#define KEY_S 19
#define KEY_T 20
#define KEY_U 21
#define KEY_V 22
#define KEY_W 23
#define KEY_X 24
#define KEY_Y 25
#define KEY_Z 26
#define KEY_ONE 27
#define KEY_TWO 28
#define KEY_THREE 29
#define KEY_FOUR 30
#define KEY_FIVE 31
#define KEY_SIX 32
#define KEY_SEVEN 33
#define KEY_EIGHT 34
#define KEY_NINE 35
#define KEY_ZERO 36
#define KEY_DOT 37
#define KEY_COMMA 38
#define KEY_FORWARD_SLASH 39
#define KEY_SEMI_COLON 40
#define KEY_SINGLE_QUOTE 41
#define KEY_SQUARE_BRACKET_OPEN 42
#define KEY_SQUARE_BRACKET_CLOSE 43
#define KEY_BACK_SLASH 44
#define KEY_BACKTICK 45
#define KEY_MINUS 46
#define KEY_EQUAL 47
#define KEY_TAB 48
#define KEY_CONTROL 49
#define KEY_RETURN 50
#define KEY_BACKSPACE 51
#define KEY_ESCAPE 52
extern uint8 key_map[53];
extern uint8 text_map[106];
extern uint32 key_shift;
void check_keys();
void initiate_keyboard();
#endif