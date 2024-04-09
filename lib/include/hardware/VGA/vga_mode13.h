#ifndef __VGA_MODE13_H__
#define __VGA_MODE13_H__

#include "../../dev/types.h"

#define VGA_M13_XRES 320
#define VGA_M13_YRES 200

#define VGA_M13_FB_START ((u8_t*)0xA0000)


typedef enum vga_m13_color
{   
    VGA_M13_BLACK   = 0x00,
    VGA_M13_WHITE   = 0x0F,
    VGA_M13_RED     = 0x28,
    VGA_M13_GREEN   = 0x2F
} vga_m13_color_t;

typedef u8_t vga_m13_pixel_t;



#endif