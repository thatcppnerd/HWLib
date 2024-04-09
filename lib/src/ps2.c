#include "../include/hardware/ps2.h"

u8_t PS2_getCtlA(void)
{
    return inb(PS2_PORT_CTL_A);
}

void PS2_setCtlA(u8_t val)
{
    outb(PS2_PORT_CTL_A, val);
}

u8_t PS2_getCtlB(void)
{
    return inb(PS2_PORT_CTL_B);
}

void PS2_setCtlB(u8_t val)
{
    outb(PS2_PORT_CTL_B, val);
}

u8_t PS2_getStatus()
{
    return inb(PS2_PORT_STATUS);
}

void PS2_sendCmd(u8_t cmd)
{
    outb(PS2_PORT_CMD, cmd);
}