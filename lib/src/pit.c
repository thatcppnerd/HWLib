#include "../include/hardware/pit.h"
#include "../include/dev/asm.h"

void PIT_setReloadValue(u8_t channel, u16_t val)
{
    outb(PIT_PORT_CH0_DATA + channel, val & 0x00FF);
    outb(PIT_PORT_CH0_DATA + channel, val >> 8);
    return;
}

u16_t PIT_getCurrentCount(u8_t channel)
{
    u16_t count = 0;
    count = inb(PIT_PORT_CH0_DATA + channel);
    count |= inb(PIT_PORT_CH0_DATA + channel) << 8;
    return count;
}

void ALWAYSINLINE PIT_latchCount(u8_t channel)
{
    PIT_writeMCReg(channel << 6); // send "latch count" command to MC
    return;
}

inline void ALWAYSINLINE PIT_writeMCReg(u8_t data)
{
    outb(PIT_PORT_MC_REG, data);
    return;
}
