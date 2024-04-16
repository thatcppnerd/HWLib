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

void DMA_SendCommand(int select, u8_t cmd)
{
    if(select == DMA0)
    {
        outb(DMA0_BASE + 0x10, cmd);
    }
    else if(select == DMA1)
    {
        outb(DMA1_BASE + 8, cmd);
    }
    else return;
}

void DMA_SendRequest(int select, u8_t req)
{
    if(select == DMA0)
    {
        outb(DMA0_BASE + 0x12, req);
    }
    else if(select == DMA1)
    {
        outb(DMA1_BASE + 9, req);
    }
    else return;
}

void DMA_SetMask(int select, u8_t mask)
{
    if(select == DMA0)
    {
        outb(DMA0_BASE + 0x14, mask);
    }
    else if(select == DMA1)
    {
        outb(DMA1_BASE + 0x0A, mask);
    }
    else return;
}

void DMA_SetMode(int select, u8_t mode)
{
    if(select == DMA0)
    {
        outb(DMA0_BASE + 0x16, mode);
    }
    else if(select == DMA1)
    {
        outb(DMA1_BASE + 0x0B, mode);
    }
    else return;
}

void DMA_FlipFlopReset(int select)
{
    if(select == DMA0)
    {
        outb(DMA0_BASE + 0x18, cmd);
    }
    else if(select == DMA1)
    {
        outb(DMA1_BASE + 0x0C, cmd);
    }
    else return;
}

u8_t DMA_GetIntermediate(int select)
{
    if(select == DMA0)
    {
        outb(DMA0_BASE + 0x1A, cmd);
    }
    else if(select == DMA1)
    {
        outb(DMA1_BASE + 0x0D, cmd);
    }
    else return;
}

void DMA_MasterReset(int select)
{
    if(select == DMA0)
    {
        outb(DMA0_BASE + 0x1A, cmd);
    }
    else if(select == DMA1)
    {
        outb(DMA1_BASE + 0x0D, cmd);
    }
    else return;
}

void DMA_MaskReset(int select)
{
    if(select == DMA0)
    {
        outb(DMA0_BASE + 0x1C, cmd);
    }
    else if(select == DMA1)
    {
        outb(DMA1_BASE + 0x0E, cmd);
    }
    else return;
}

void DMA_GetMultiChannelMask(int select)
{
    if(select == DMA0)
    {
        inb(DMA0_BASE + 0x1E);
    }
    else if(select == DMA1)
    {
        inb(DMA1_BASE + 0x0F);
    }
    else return;
}

void DMA_SetMultiChannelMask(int select, u8_t mask)
{
    if(select == DMA0)
    {
        outb(DMA0_BASE + 0x1E, mask);
    }
    else if(select == DMA1)
    {
        outb(DMA1_BASE + 0x0F, mask);
    }
    else return;
}

void DMA_SetPageAddress(int channel, u8_t data)
{
    if()
}