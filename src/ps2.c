#include "../include/ps2.h"

u8_t PS2_ReadData(void)
{
    PS2_PollOutputBuf();
    return inb(PS2_DATA);
}

void PS2_SendData(u8_t data)
{
    PS2_PollInputBuf();
    outb(PS2_DATA, data);
}


u8_t PS2_GetCtlA(void)
{
    return inb(PS2_CTLA);
}

void PS2_SetCtlA(u8_t val)
{
    outb(PS2_CTLA, val);
}


u8_t PS2_GetCtlB(void)
{
    return inb(PS2_CTLB);
}

void PS2_SetCtlB(u8_t val)
{
    outb(PS2_CTLB, val);
}


u8_t PS2_GetStatus()
{
    return inb(PS2_STATUS);
}

void PS2_SendCommand(u8_t cmd)
{
    PS2_pollInputBuf(); // wait for an empty input buffer
    outb(PS2_CMD, cmd); // send command
}

u8_t PS2_ReadRAM(u8_t i)
{
    PS2_SendCommand(0x20 + i);
    return PS2_ReadData();
}

void PS2_WriteRAM(u8_t i, u8_t data)
{
    PS2_SendCommand(0x60 + i);
    PS2_sendData(data);
}


int PS2_TestPort2(void)
{
    PS2_SendCommand(0xA9);
    return PS2_ReadData();
}

int PS2_TestController(void)
{
    PS2_SendCommand(0xAA);
    return PS2_ReadData();
}

int PS2_TestPort1(void)
{
    PS2_SendCommand(0xAB);
    return PS2_ReadData();
}

void PS2_DumpRAM(void* buf)
{
    PS2_SendCommand(0xAC);

    // read all 32 bytes
    for(int a = 0 ; a < 0x20 ; a++)
    {
        *(u8_t*)buf++ = PS2_ReadData(); 
    }
}

u8_t PS2_ReadInputPort(void)
{
    PS2_SendCommand(0xC0);
    return PS2_ReadData();
}

u8_t PS2_ReadOutputPort(void)
{
    PS2_SendCommand(0xD0);
    return PS2_ReadData();
}

void PS2_WriteOutputPort(u8_t val)
{
    PS2_SendCommand(0xD1);
    PS2_sendData(val);
}

void PS2_PulseLine(u8_t mask)
{
    mask &= 0x0F; // only keep low 4 bits
    PS2_SendCommand(0xF0 | mask);
}