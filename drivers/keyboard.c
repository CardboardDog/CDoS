#include "keyboard.h"
#include "rw_io.h"
const uint8 blank_key = 0;

uint8 text_map[106] = {
    blank_key,
    'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    '0',
    '.',
    ',',
    '/',
    ';',
    '\'',
    '[',
    ']',
    '\\',
    '`',
    '-',
    '=',
    ' ',
    blank_key,
    blank_key,
    blank_key,
    blank_key,
    // shift
    blank_key,
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    'M',
    'N',
    'O',
    'P',
    'Q',
    'R',
    'S',
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    'Z',
    '!',
    '@',
    '#',
    '$',
    '%',
    '^',
    '&',
    '*',
    '(',
    ')',
    '>',
    '<',
    '?',
    ':',
    '"',
    '{',
    '}',
    '|',
    '~',
    '_',
    '+',
    ' ',
    blank_key,
    blank_key,
    blank_key,
    blank_key
};
uint8 key_map[53]={0};
uint32 key_shift = 0;
void initiate_keyboard(){
    key_shift = 0;
}
void check_keys(){
    uint8 scan = read_byte(0x60);
    // possibly the ugliest code ever written
    if((scan&128)==128){
        // key up
        if(scan == 0x8F | scan == 0xB9)key_map[KEY_TAB]=0;
        if(scan == 0x8E)key_map[KEY_BACKSPACE]=0;
        if(scan == 0x9C)key_map[KEY_RETURN]=0;
        if(scan == 0x9D)key_map[KEY_CONTROL]=0;
        if(scan == 0x9E)key_map[KEY_A]=0;
        if(scan == 0xB0)key_map[KEY_B]=0;
        if(scan == 0xAE)key_map[KEY_C]=0;
        if(scan == 0xA0)key_map[KEY_D]=0;
        if(scan == 0x92)key_map[KEY_E]=0;
        if(scan == 0xA1)key_map[KEY_F]=0;
        if(scan == 0xA2)key_map[KEY_G]=0;
        if(scan == 0xA3)key_map[KEY_H]=0;
        if(scan == 0x97)key_map[KEY_I]=0;
        if(scan == 0xA4)key_map[KEY_J]=0;
        if(scan == 0xA5)key_map[KEY_K]=0;
        if(scan == 0xA6)key_map[KEY_L]=0;
        if(scan == 0xB2)key_map[KEY_M]=0;
        if(scan == 0xB1)key_map[KEY_N]=0;
        if(scan == 0x98)key_map[KEY_O]=0;
        if(scan == 0x99)key_map[KEY_P]=0;
        if(scan == 0x90)key_map[KEY_Q]=0;
        if(scan == 0x93)key_map[KEY_R]=0;
        if(scan == 0x9F)key_map[KEY_S]=0;
        if(scan == 0x94)key_map[KEY_T]=0;
        if(scan == 0x96)key_map[KEY_U]=0;
        if(scan == 0xAF)key_map[KEY_V]=0;
        if(scan == 0x91)key_map[KEY_W]=0;
        if(scan == 0xAD)key_map[KEY_X]=0;
        if(scan == 0x95)key_map[KEY_Y]=0;
        if(scan == 0xAC)key_map[KEY_Z]=0;
        if(scan == 0xAA | scan == 0xB6)key_shift=0;
        if(scan == 0x82)key_map[KEY_ONE]=0;
        if(scan == 0x83)key_map[KEY_TWO]=0;
        if(scan == 0x84)key_map[KEY_THREE]=0;
        if(scan == 0x85)key_map[KEY_FOUR]=0;
        if(scan == 0x86)key_map[KEY_FIVE]=0;
        if(scan == 0x87)key_map[KEY_SIX]=0;
        if(scan == 0x88)key_map[KEY_SEVEN]=0;
        if(scan == 0x89)key_map[KEY_EIGHT]=0;
        if(scan == 0x8A)key_map[KEY_NINE]=0;
        if(scan == 0x8B)key_map[KEY_ZERO]=0;
        if(scan == 0xB4)key_map[KEY_DOT]=0;
        if(scan == 0xB3)key_map[KEY_COMMA]=0;
        if(scan == 0xB5)key_map[KEY_FORWARD_SLASH]=0;
        if(scan == 0xA7)key_map[KEY_SEMI_COLON]=0;
        if(scan == 0xA8)key_map[KEY_SINGLE_QUOTE]=0;
        if(scan == 0x9A)key_map[KEY_SQUARE_BRACKET_OPEN]=0;
        if(scan == 0x9B)key_map[KEY_SQUARE_BRACKET_CLOSE]=0;
        if(scan == 0xAB)key_map[KEY_BACK_SLASH]=0;
        if(scan == 0xA9)key_map[KEY_BACKTICK]=0;
        if(scan == 0x8C)key_map[KEY_MINUS]=0;
        if(scan == 0x8D)key_map[KEY_EQUAL]=0;
    }else{
        // key down
        if(scan == 0x0F | scan == 0x39)key_map[KEY_TAB]=1;
        if(scan == 0x0E)key_map[KEY_BACKSPACE]=1;
        if(scan == 0x1C)key_map[KEY_RETURN]=1;
        if(scan == 0x1D)key_map[KEY_CONTROL]=1;
        if(scan == 0x1E)key_map[KEY_A]=1;
        if(scan == 0x30)key_map[KEY_B]=1;
        if(scan == 0x2E)key_map[KEY_C]=1;
        if(scan == 0x20)key_map[KEY_D]=1;
        if(scan == 0x12)key_map[KEY_E]=1;
        if(scan == 0x21)key_map[KEY_F]=1;
        if(scan == 0x22)key_map[KEY_G]=1;
        if(scan == 0x23)key_map[KEY_H]=1;
        if(scan == 0x17)key_map[KEY_I]=1;
        if(scan == 0x24)key_map[KEY_J]=1;
        if(scan == 0x25)key_map[KEY_K]=1;
        if(scan == 0x26)key_map[KEY_L]=1;
        if(scan == 0x32)key_map[KEY_M]=1;
        if(scan == 0x31)key_map[KEY_N]=1;
        if(scan == 0x18)key_map[KEY_O]=1;
        if(scan == 0x19)key_map[KEY_P]=1;
        if(scan == 0x10)key_map[KEY_Q]=1;
        if(scan == 0x13)key_map[KEY_R]=1;
        if(scan == 0x1F)key_map[KEY_S]=1;
        if(scan == 0x14)key_map[KEY_T]=1;
        if(scan == 0x16)key_map[KEY_U]=1;
        if(scan == 0x2F)key_map[KEY_V]=1;
        if(scan == 0x11)key_map[KEY_W]=1;
        if(scan == 0x2D)key_map[KEY_X]=1;
        if(scan == 0x15)key_map[KEY_Y]=1;
        if(scan == 0x2C)key_map[KEY_Z]=1;
        if(scan == 0x2A | scan == 0x36)key_shift=1;
        if(scan == 0x02)key_map[KEY_ONE]=1;
        if(scan == 0x03)key_map[KEY_TWO]=1;
        if(scan == 0x04)key_map[KEY_THREE]=1;
        if(scan == 0x05)key_map[KEY_FOUR]=1;
        if(scan == 0x06)key_map[KEY_FIVE]=1;
        if(scan == 0x07)key_map[KEY_SIX]=1;
        if(scan == 0x08)key_map[KEY_SEVEN]=1;
        if(scan == 0x09)key_map[KEY_EIGHT]=1;
        if(scan == 0x0A)key_map[KEY_NINE]=1;
        if(scan == 0x0B)key_map[KEY_ZERO]=1;
        if(scan == 0x34)key_map[KEY_DOT]=1;
        if(scan == 0x33)key_map[KEY_COMMA]=1;
        if(scan == 0x35)key_map[KEY_FORWARD_SLASH]=1;
        if(scan == 0x27)key_map[KEY_SEMI_COLON]=1;
        if(scan == 0x28)key_map[KEY_SINGLE_QUOTE]=1;
        if(scan == 0x1A)key_map[KEY_SQUARE_BRACKET_OPEN]=1;
        if(scan == 0x1B)key_map[KEY_SQUARE_BRACKET_CLOSE]=1;
        if(scan == 0x2B)key_map[KEY_BACK_SLASH]=1;
        if(scan == 0x29)key_map[KEY_BACKTICK]=1;
        if(scan == 0x0C)key_map[KEY_MINUS]=1;
        if(scan == 0x0D)key_map[KEY_EQUAL]=1;
    }
}
//585