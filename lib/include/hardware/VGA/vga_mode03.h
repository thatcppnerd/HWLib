#ifndef __VGA_MODE03_H__
#define __VGA_MODE03_H__

#include "../../dev/types.h"

#define VGA_M03_ROWS

enum vga_m03_color_val
{
    VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15
};

typedef union vga_m03_color
{	
	u8_t byte;
	u8_t fg : 4, bg : 4;
} vga_m03_color_t;

typedef struct vga_m03_char
{
	unsigned char chr;
	vga_m03_color_t color;
} vga_m03_char_t;

#define vga_mode03_color_byte(bg, fg) (bg * 16 + fg)




#endif