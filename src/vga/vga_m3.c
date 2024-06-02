#include "../../include/vga/vga_m3.h"

void VGA_M3_SetChar(int x, int y, struct VGA_M3_Char chr)
{
    VGA_M3_FB[(y * VGA_M3_COLS) + x] = chr;
}

struct VGA_M3_Char VGA_M3_GetChar(int x, int y)
{
    return VGA_M3_FB[(y * VGA_M3_COLS) + x];
}


void VGA_M3_SetCharVal(int x, int y, char val)
{
    VGA_M3_FB[(y * VGA_M3_COLS) + x].chr = val;
}

char VGA_M3_GetCharVal(int x, int y)
{
    return VGA_M3_FB[(y * VGA_M3_COLS) + x].chr;
}

void VGA_M3_SetCharColor(int x, int y, u8_t color)
{
    VGA_M3_FB[(y * VGA_M3_COLS) + x].color = color;
}

u8_t VGA_M3_GetCharColor(int x, int y)
{
    return VGA_M3_FB[(y * VGA_M3_COLS) + x].color;
}

void VGA_M3_Print(int x, int y, const char* str, u8_t color)
{
    int c = 0;
    while(1)
    {
        VGA_M3_SetChar(x, y, (struct VGA_M3_Char){str[c], color});
        c++, x++;
        if(str[c] == '\0') break;
    }

    return;
}

void VGA_M3_ClearScreen(u8_t color)
{
    for(int a = 0 ; a < VGA_M3_ROWS * VGA_M3_COLS ; a++)
    {
        VGA_M3_FB[a] = (struct VGA_M3_Char){0, color};
    }
}
