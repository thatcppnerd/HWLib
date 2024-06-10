#ifndef __VGA_MODE3_H__
#define __VGA_MODE3_H__

#include "../types.h"

#define VGA_M3_ROWS (25)
#define VGA_M3_COLS (80)

#define VGA_M3_FB   ((volatile struct VGA_M3_Char*)0xB8000)

#define VGA_M3_ColorByte(bg, fg) ((bg << 4) | fg)

enum VGA_M3_ColorVal
{
    VGA_M3_BLACK            = 0,
    VGA_M3_BLUE             = 1,
    VGA_M3_GREEN            = 2,
    VGA_M3_CYAN             = 3,
    VGA_M3_RED              = 4,
    VGA_M3_MAGENTA          = 5,
    VGA_M3_BROWN            = 6,
    VGA_M3_LIGHT_GREY       = 7,
    VGA_M3_DARK_GREY        = 8,
    VGA_M3_LIGHT_BLUE       = 9,
    VGA_M3_LIGHT_GREEN      = 10,
    VGA_M3_LIGHT_CYAN       = 11,
    VGA_M3_LIGHT_RED        = 12,
    VGA_M3_LIGHT_MAGENTA    = 13,
    VGA_M3_LIGHT_BROWN      = 14,
    VGA_M3_WHITE            = 15
};

struct VGA_M3_Char
{
    u8_t chr;
    u8_t color; // hi nibble is bg, lo nibble is fg
};

void VGA_M3_SetChar(int x, int y, struct VGA_M3_Char chr);
struct VGA_M3_Char VGA_M3_GetChar(int x, int y); 

void VGA_M3_SetCharVal(int x, int y, char val);
char VGA_M3_GetCharVal(int x, int y);

void VGA_M3_SetCharColor(int x, int y, u8_t color);
u8_t VGA_M3_GetCharColor(int x, int y);

void VGA_M3_Print(int x, int y, const 
char* str, u8_t color);

void VGA_M3_ClearScreen(u8_t color);



#endif