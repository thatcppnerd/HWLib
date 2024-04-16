#include "../include/dma.h"

void DMA_SetStartAddress(int channel, u16_t addr)
{
    if(channel < DMA_CH4) // on slave DMA
    {
        outb(DMA0_BASE + channel * 2, addr & 0xFF); // low byte
        outb(DMA0_BASE + channel * 2, (addr >> 8) & 0xFF); // high byte
        io_wait();
    }
    else if(channel >= DMA_CH4) // on master DMA
    {
        outb(DMA1_BASE + (channel - 4) * 2, addr & 0xFF); // low byte
        outb(DMA1_BASE + (channel - 4) * 4, (addr >> 8) & 0xFF); // high byte
        io_wait();
    }
    else return;
}

void DMA_SetCount(int channel, u16_t addr)
{
    if(channel < DMA_CH4) // on slave DMA
    {
        outb((DMA0_BASE + 1) + channel * 2, addr & 0xFF); // low byte
        outb((DMA0_BASE + 1) + channel * 2, (addr >> 8) & 0xFF); // high byte
        io_wait();
    }
    else if(channel >= DMA_CH4) // on master DMA
    {
        outb((DMA1_BASE + 2) + (channel - 4) * 4, addr & 0xFF); // low byte
        outb((DMA1_BASE + 2) + (channel - 4) * 4, (addr >> 8) & 0xFF); // high byte
        io_wait();
    }
    else return;
}

u8_t DMA_GetStatus(int select)
{
    if(select == DMA0)
    {
        return inb(DMA0_BASE + 0x10);
    }
    else if(select == DMA1)
    {
        return inb(DMA1_BASE + 8);
    }
    else return;
}
