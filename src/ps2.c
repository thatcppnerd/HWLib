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
    PS2_pollInputBuf(); // wait for an empty input buffer
    outb(PS2_CMD, cmd); // send command
}

u8_t PS2_readRAM(u8_t i)
{
    PS2_sendCommand(0x20 + i);
    PS2_pollOutputBuf(); // wait for data
    return PS2_readData();
}

void PS2_writeRAM(u8_t i, u8_t data)
{
    PS2_sendCommand(0x60 + i);
    PS2_pollInputBuf(); // wait for input buf empty
    PS2_sendData(data);
}


int PS2_testPort2(void)
{
    PS2_sendCommand(0xA9);
    PS2_pollOutputBuf();
    return PS2_readData();
}

int PS2_testController(void)
{
    PS2_sendCommand(0xAA);
    PS2_pollOutputBuf();
    return PS2_readData();
}

int PS2_testPort1(void)
{
    PS2_sendCommand(0xAB);
    PS2_pollOutputBuf();
    return PS2_readData();
}

void PS2_dumpRAM(void* buf)
{
    PS2_sendCommand(0xAC);

    // read all 32 bytes
    for(int a = 0 ; a < 0x20 ; a++)
    {
        PS2_pollOutputBuf();
        *buf++ = PS2_readData(); 
    }
}

u8_t PS2_readInputPort(void)
{
    PS2_sendCommand(0xC0);
    PS2_pollOutputBuf();
    return PS2_readData();
}

u8_t PS2_readOutputPort(void)
{
    PS2_sendCommand(0xD0);
    PS2_pollOutputBuf();
    return PS2_readData();
}

void PS2_write