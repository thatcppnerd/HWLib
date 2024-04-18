#include "../include/dma.h"

void DMA_SetStartAddressReg(int channel, u16_t addr)
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

void DMA_SetCountReg(int channel, u16_t count)
{
    if(channel < DMA_CH4) // on slave DMA
    {
        outb((DMA0_BASE + 1) + channel * 2, count & 0xFF); // low byte
        outb((DMA0_BASE + 1) + channel * 2, (count >> 8) & 0xFF); // high byte
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

u8_t DMA_GetStatusReg(int select)
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

void DMA_SetCommandReg(int select, u8_t val)
{
    if(select == DMA0)
    {
        outb(DMA0_BASE + 0x10, val);
    }
    else if(select == DMA1)
    {
        outb(DMA1_BASE + 8, val);
    }
    else return;
}

void DMA_SetRequestReg(int select, u8_t val)
{
    if(select == DMA0)
    {
        outb(DMA0_BASE + 0x12, val);
    }
    else if(select == DMA1)
    {
        outb(DMA1_BASE + 9, val);
    }
    else return;
}

void DMA_SetSingleChannelMaskReg(int select, u8_t channel)
{
    if(select == DMA0)
    {
        outb(DMA0_BASE + 0x14, channel);
    }
    else if(select == DMA1)
    {
        outb(DMA1_BASE + 0x0A, channel);
    }
    else return;
}

void DMA_SetModeReg(int select, u8_t mode)
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

u8_t DMA_GetMultiChannelMask(int select)
{
    if(select == DMA0)
    {
        return inb(DMA0_BASE + 0x1E);
    }
    else if(select == DMA1)
    {
        return inb(DMA1_BASE + 0x0F);
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