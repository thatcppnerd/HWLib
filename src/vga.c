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

u8_t VGA_GetCRTCDataReg(void)
{
    register u8_t reg;
    if(VGA_GetMiscOutputReg() & 0x01)
    {
        reg = inb(VGA_CRTC_DATA_COLOR);
    }
    else
    {
        reg = inb(VGA_CRTC_DATA_MONO);
    }
    io_wait();

    return reg;
}

void VGA_SetCRTCDataReg(u8_t data)
{
    if(VGA_GetMiscOutputReg() & 0x01)
    {
        outb(VGA_CRTC_DATA_COLOR, data);
    }
    else
    {
        outb(VGA_CRTC_DATA_MONO, data);
    }
    io_wait();
}


u8_t VGA_GetInputStatusReg0(void)
{
    register u8_t reg = inb(VGA_INPUT_STATUS0);
    io_wait();

    return reg;
}

u8_t VGA_GetInputStatusReg1(void)
{
    register u8_t reg; 

    if(VGA_GetMiscOutputReg() & 0x01)
    {
        reg = inb(VGA_INPUT_STATUS1_COLOR);
    }
    else
    {
        reg = inb(VGA_INPUT_STATUS1_MONO);
    }
    io_wait();

    return reg;
}

u8_t VGA_GetFeatureCtlReg(void)
{
    register u8_t reg = inb(VGA_FEATURE_CTL_READ);
    io_wait();

    return reg;
}

void VGA_SetFeatureCtlReg(u8_t val)
{
    if(VGA_GetMiscOutputReg() & 0x01)
    {
        outb(VGA_FEATURE_CTL_WRITE_COLOR, val);
    }
    else
    {
        outb(VGA_FEATURE_CTL_WRITE_MONO, val);
    }
    io_wait();
}

u8_t VGA_GetMiscOutputReg(void)
{
    register u8_t reg = inb(VGA_MISC_OUT_READ);
    io_wait();

    return reg;
}


u8_t VGA_GetAttribCtlIndexReg(void)
{
    VGA_GetInputStatusReg1(); // reset flip-flop

    register u8_t reg = inb(VGA_ATTR_INDEX);
    io_wait();

    return reg;
}

void VGA_SetAttribCtlIndexReg(u8_t val)
{
    VGA_GetInputStatusReg1();

    outb(VGA_ATTR_INDEX, val);
    io_wait();
}

u8_t VGA_GetAttribCtlDataReg(void)
{
    VGA_GetInputStatusReg1();

    register u8_t reg = inb(VGA_ATTR_DATA_READ);
    io_wait();

    return reg;   
}

void VGA_SetAttribCtlDataReg(u8_t val)
{
    VGA_GetInputStatusReg1();

    outb(VGA_ATTR_INDEX, inb(VGA_ATTR_INDEX)); // switch to data mode 
    io_wait();

    outb(VGA_ATTR_DATA_WRITE, val); // write data
     
    io_wait();
}

u8_t VGA_GetAttribCtlReg(u8_t index)
{
    VGA_GetInputStatusReg1(); // reset flip-flop to index mode
    
    outb(VGA_ATTR_INDEX, index);
    io_wait();

    register u8_t reg = inb(VGA_ATTR_DATA_READ);
    io_wait();

    return reg;
}

void VGA_SetAttribCtlReg(u8_t index, u8_t val)
{
    VGA_GetInputStatusReg1();

    outb(VGA_ATTR_INDEX, index);
    io_wait();

    outb(VGA_ATTR_DATA_WRITE, val);
    io_wait();
}


u8_t VGA_GetSequencerAddrReg(void)
{
    register u8_t reg = inb(VGA_SEQ_ADDR);
    io_wait();

    return reg;
}

void VGA_SetSequencerAddrReg(u8_t val)
{
    outb(VGA_SEQ_ADDR, val);
    io_wait();
}

u8_t VGA_GetSequencerDataReg(void)
{
    register u8_t reg = inb(VGA_SEQ_DATA);
    io_wait();

    return reg;
}

void VGA_SetSequencerDataReg(u8_t reg)
{
    outb(VGA_SEQ_DATA, reg);
    io_wait();
}


u8_t VGA_GetDACState(void)
{
    register u8_t reg = inb(VGA_DAC_STATE);
    io_wait();

    return reg;
}

void VGA_SetDACState(u8_t val)
{
    outb(VGA_DAC_STATE, val);
    io_wait();
}

u8_t VGA_GetDACMaskReg(void)
{
    register u8_t reg = inb(VGA_DAC_STATE);
    io_wait();

    return reg;
}

u8_t VGA_GetDACAddrReg(void)
{
    register u8_t reg = inb(VGA_DAC_ADDR_READ);
    io_wait();

    return reg;
}

void VGA_SetDACAddrReg(u8_t val)
{
    outb(VGA_DAC_ADDR_WRITE, val);
    io_wait();
}

u8_t VGA_GetDACDataReg(void)
{
    register u8_t reg = inb(VGA_DAC_DATA);
    io_wait();

    return reg;
}

void VGA_SetDACDataReg(u8_t val)
{
    outb(VGA_DAC_DATA, val);
    io_wait();
}


u8_t VGA_GetGraphicsCtlAddrReg(void)
{
    register u8_t reg = inb(VGA_GRCTL_ADDR);
    io_wait();

    return reg;
}

void VGA_SetGraphicsCtlAddrReg(u8_t val)
{
    outb(VGA_GRCTL_ADDR, val);
    io_wait();
}

u8_t VGA_GetGraphicsCtlDataReg(void)
{
    register u8_t reg = inb(VGA_GRCTL_DATA);
    io_wait();

    return reg;
}

void VGA_SetGraphicsCtlDataReg(u8_t val)
{
    outb(VGA_GRCTL_DATA, val);
    io_wait();
}





