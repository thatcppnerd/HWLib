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
        outb(DMA0_BASE + 0x18, 0xFF);
    }
    else if(select == DMA1)
    {
        outb(DMA1_BASE + 0x0C, 0xFF);
    }
    else return;
}

u8_t DMA_GetIntermediate(int select)
{
    if(select == DMA0)
    {
        return inb(DMA0_BASE + 0x1A);
    }
    else if(select == DMA1)
    {
        return inb(DMA1_BASE + 0x0D);
    }
    else return 0;
}

void DMA_MasterReset(int select)
{
    if(select == DMA0)
    {
        outb(DMA0_BASE + 0x1A, 0xFF);
    }
    else if(select == DMA1)
    {
        outb(DMA1_BASE + 0x0D, 0xFF);
    }
    else return;
}

void DMA_MaskReset(int select)
{
    if(select == DMA0)
    {
        outb(DMA0_BASE + 0x1C, 0xFF);
    }
    else if(select == DMA1)
    {
        outb(DMA1_BASE + 0x0E, 0xFF);
    }
    else return;
}

u8_t DMA_GetMultiChannelMaskReg(int select)
{
    if(select == DMA0)
    {
        return inb(DMA0_BASE + 0x1E);
    }
    else if(select == DMA1)
    {
        return inb(DMA1_BASE + 0x0F);
    }
    else return 0;
}

void DMA_SetMultiChannelMaskReg(int select, u8_t mask)
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

void DMA_SetPageAddressReg(int channel, u8_t addr)
{
    switch(channel)
    {
        case DMA0: outb(0x87, addr); break;
        case DMA1: outb(0x83, addr); break;
        case DMA2: outb(0x81, addr); break;
        case DMA3: outb(0x82, addr); break;
        
        case DMA4: outb(0x8F, addr); break;
        case DMA5: outb(0x8B, addr); break;
        case DMA6: outb(0x89, addr); break;
        case DMA7: outb(0x8A, addr); break;
        
        default: return;
    }
}

u8_t DMA_GetPageAddressReg(int channel)
{
    switch(channel)
    {
        case DMA0: return inb(0x87); break;
        case DMA1: return inb(0x83); break;
        case DMA2: return inb(0x81); break;
        case DMA3: return inb(0x82); break;
        
        case DMA4: return inb(0x8F); break;
        case DMA5: return inb(0x8B); break;
        case DMA6: return inb(0x89); break;
        case DMA7: return inb(0x8A); break;
        
        default: return 0;
    }
}