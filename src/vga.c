#include "../include/vga.h"
#include "../include/asm.h"
#include "../include/macros.h"

u8_t VGA_GetCRTCAddrReg(void)
{
    register u8_t reg;

    if(VGA_GetMiscOutputReg() & 0x01)
    {
        reg = inb(VGA_CRTC_ADDR_COLOR);
    }
    else
    {
        reg = inb(VGA_CRTC_ADDR_MONO);
    }
    io_wait();

    return reg;
}

void VGA_SetCRTCAddrReg(u8_t addr)
{
    if(VGA_GetMiscOutputReg() & 0x01)
    {
        outb(VGA_CRTC_ADDR_COLOR, addr);
    }
    else
    {
        outb(VGA_CRTC_ADDR_MONO, addr);
    }
    io_wait();
}

u8_t VGA_GetCRTCDa