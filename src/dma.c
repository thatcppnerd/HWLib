#include "../include/dma.h"

void DMA_SetStartAddress(int channel, u16_t addr)
{
    if(channel > DMA4)
    {
        outb(0x00 + channel * 2)
    }
}