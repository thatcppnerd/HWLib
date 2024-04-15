#include "../include/ps2.h"

u8_t PS2_readData(void)
{
    return inb(PS2_DATA);
}

void PS2_sendData(u8_t data)
{
    outb(PS2_DATA, data);
}


u8_t PS2_getCtlA(void)
{
    return inb(PS2_CTLA);
}

void PS2_setCtlA(u8_t val)
{
    outb(PS2_CTLA, val);
}


u8_t PS2_getCtlB(void)
{
    return inb(PS2_CTLB);
}

void PS2_setCtlB(u8_t val)
{
    outb(PS2_CTLB, val);
}


u8_t PS2_getStatus()
{
    return inb(PS2_STATUS);
}

void PS2_sendCommand(u8_t cmd)
{
    outb(PS2_CMD, cmd);
}


u8_t PS2_readRAM(u8_t i)
{
    PS2_sendCommand(0x20 + i);
    while(PS2_getStatus() & 0x01); // wait for data
    return PS2_readData();
}

void PS2_writeRAM(u8_t i, u8_t data)
{
    PS2_sendCommand(0x60 + i);
    while(!(PS2_getStatus() & 0x02)); // wait for input buf opening
    PS2_sendData(data);
}