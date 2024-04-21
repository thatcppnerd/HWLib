#include "../include/pit.h"
#include "../include/asm.h"

void PIT_SetReloadValue(u8_t channel, u16_t val)
{
    outb(PIT_CH0_DATA + channel, val & 0x00FF);
    outb(PIT_CH0_DATA + channel, val >> 8);
    return;
}

u16_t PIT_GetCurrentCount(u8_t channel)
{
    u16_t count = 0;
    count = inb(PIT_CH0_DATA + channel);
    count |= inb(PIT_CH0_DATA + channel) << 8;
    return count;
}

void PIT_LatchCount(u8_t channel)
{
    PIT_SendCommand(channel << 6); // send "latch count" command to MC
    return;
}

inline void ALWAYSINLINE PIT_SendCommand(u8_t data)
{
    outb(PIT_CMD, data);
    return;
}
