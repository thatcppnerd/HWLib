#include "../include/vga.h"
#include "../include/asm.h"
#include "../include/macros.h"

u8_t VGA_GetCRTCAddrReg(void)
{
    u8_t reg = inb(VGA_CRTC_ADDR);
    io_wait();

    return reg;
}

void VGA_SetCRTCAddrReg(u8_t addr)
{
    outb(VGA_CRTC_ADDR, addr);
    io_wait();
}

u8_t VGA_GetInputStatusReg(void)
{
    u8_t reg = inb(VGA_CRTC_ADDR);
    io_wait();

    return reg;
}

void VGA_SetFCReg(u8_t val)
{
    outb(VGA_FC, val);
    io_wait();
}

u8_t VGA_GetIndexReg(void)
{
    inb(0x3DA); // set index/data port to index mode
    io_wait();

    u8_t reg = inb(VGA_INDEX);
    io_wait();

    return reg;
}

void VGA_SetIndexReg(u8_t val)
{
    inb(0x3DA); // set index/data port to index mode
    io_wait();

    outb(VGA_INDEX, val);
    io_wait();
}

void VGA_