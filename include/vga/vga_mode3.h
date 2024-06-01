#ifndef __VGA_MODE3_H__
#define __VGA_MODE3_H__

#include "../types.h"

#define VGA_M3_ROWS (25)
#define VGA_M3_COLS (40)

#define VGA_M3_FB   (VGA_M3_Char*)(0xB8000)

typedef struct VGA_M3_Char
{
    u8_t chr;
    u8_t fg : 4, bg : 4;
};







#endif