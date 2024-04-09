#ifndef __DAC_H__
#define __DAC_H__

#include "../types.h"
#include "../asm.h"

#define DAC_MASK 0x3C6
#define DAC_PAL_INDEX 0x3C8
#define DAC_PAL_COLOR_INPUT 0x3C7
#define DAC_PAL_COLOR_OUTPUT 0x3C9

typedef struct DAC_PaletteColor
{
    u8_t r :6;
    u8_t g :6;
    u8_t b :6;
} DAC_PaletteColor_t;

void DAC_writePaletteColor(u8_t index, DAC_PaletteColor_t color);
DAC_PaletteColor_t DAC_readPaletteColor(u8_t index);



#endif