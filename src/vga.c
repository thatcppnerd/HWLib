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

u8_t VGA_GetInputStatusReg0(void)
{
    register u8_t reg = inb(VGA_CRTC_ADDR);
    io_wait();

    return reg;
}

void VGA_SetFCReg(u8_t val)
{
    outb(VGA_FC, val);
    io_wait();
}

u8_t VGA_GetAttrIndexReg(void)
{
    inb(0x3DA); // set index/data port to index mode
    io_wait();

    register u8_t reg = inb(VGA_ATTR_INDEX);
    io_wait();

    return reg;
}

void VGA_SetAttrIndexReg(u8_t val)
{
    inb(0x3DA); // set index/data port to index mode
    io_wait();

    outb(VGA_ATTR_INDEX, val);
    io_wait();
}

u8_t VGA_GetAttrDataReg(void)
{
    inb(0x3DA); // set to index
    io_wait();

    inb(0x3DA); // set to data
    io_wait();

    register u8_t reg = inb(VGA_ATTR_DATA);
    io_wait();

    return reg;
}

void VGA_SetAttrDataReg(u8_t val)
{
    inb(0x3DA);
    io_wait();

    inb(0x3DA);
    io_wait();

    outb(VGA_ATTR_DATA, val);
    io_wait();
}


u8_t VGA_GetMiscOutputReg(void)
{
    register u8_t reg = inb(VGA_MISC_OUT_RD);
    io_wait();

    return reg;
}

void VGA_SetMiscOutputReg(u8_t val)
{
    outb(VGA_MISC_OUT_WR, val);
    io_wait();
}


