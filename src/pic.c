#include "../include/pic.h"
#include "../include/macros.h"


void PIC_SetMask(int select, u8_t mask)
{
    if(select == PIC0) outb(PIC0_DATA, mask);
    else if(select == PIC1) outb(PIC1_DATA, mask);
    else return;
    io_wait();
}

void PIC_SetMasks(u8_t mask0, u8_t mask1)
{
    outb(PIC0_DATA, mask0);
    io_wait();
    outb(PIC1_DATA, mask1);
    io_wait();
}

u8_t PIC_GetMask(int select)
{
    if(select == PIC0) return inb(PIC0_DATA);
    else if(select == PIC1) return inb(PIC1_DATA);
    else return ERR_VAL;
    io_wait();
}

void PIC_SendCommand(int select, u8_t cmd)
{
    if(select == PIC0) outb(PIC0_CMD, cmd);
    else if(select == PIC1) outb(PIC1_CMD, cmd);
    else return;
    io_wait();
}

void PIC_SendData(int select, u8_t data)
{
    if(select == PIC0) outb(PIC0_DATA, data);
    else if(select == PIC1) outb(PIC1_DATA, data);
    else return;
    io_wait();
}

u8_t PIC_ReadCommand(int select)
{
    if(select == PIC0) inb(PIC0_CMD);
    else if(select == PIC1) inb(PIC1_CMD);
    else return ERR_VAL;
    io_wait();
}

u8_t PIC_ReadData(int select)
{
    if(select == PIC0) inb(PIC0_DATA);
    else if(select == PIC1) inb(PIC1_DATA);
    else return ERR_VAL;
    io_wait();
}

u8_t PIC_ReadIRR(int select)
{
    if(select == PIC0)
    {
        outb(PIC0_CMD, PIC_READ_IRR);
        io_wait();
        return inb(PIC0_CMD);
    }
    else if(select == PIC1)
    {
        outb(PIC1_CMD, PIC_READ_IRR);
        io_wait();
        return inb(PIC1_CMD);
    }
    else return ERR_VAL;
}

u8_t PIC_ReadISR(int select)
{
    if(select == PIC0)
    {
        outb(PIC0_CMD, PIC_READ_ISR);
        io_wait();
        return inb(PIC0_CMD);
    }
    else if(select == PIC1)
    {
        outb(PIC1_CMD, PIC_READ_ISR);
        io_wait();
        return inb(PIC1_CMD);
    }
    else return ERR_VAL;
}

void PIC_Init(int select, u8_t icw1, u8_t icw2, u8_t icw3, u8_t icw4)
{
    u8_t mask = 0x00;

    if(select == PIC0)
    {
        mask = PIC_GetMask(PIC0);

        PIC_SendCommand(PIC0, icw1);
        PIC_SendData(PIC0, icw2);
        PIC_SendData(PIC0, icw3);
        PIC_SendData(PIC0, icw4);

        PIC_SetMask(PIC0, mask);
    }
    else if(select == PIC1)
    {
        mask = PIC_GetMask(PIC1);

        PIC_SendCommand(PIC1, icw1);
        PIC_SendData(PIC1, icw2);
        PIC_SendData(PIC1, icw3);
        PIC_SendData(PIC1, icw4);

        PIC_SetMask(PIC1, mask);
    }
    else return;
}

void PIC_Remap(u8_t base0, u8_t base1)
{
    u8_t m0 = PIC_GetMask(PIC0);
    u8_t m1 = PIC_GetMask(PIC1);

    // Send init command
    PIC_SendCommand(PIC0, PIC_INIT);
    PIC_SendCommand(PIC1, PIC_INIT);

    // Send vector offsets
    PIC_SendData(PIC0, m0);
    PIC_SendData(PIC1, m1);

    // Send cascade info
    PIC_SendData(PIC0, 4);
    PIC_SendData(PIC1, 2);

    // Send ICW4
    PIC_SendData(PIC0, 0x01);
    PIC_SendData(PIC1, 0x01);

    PIC_SetMasks(m0, m1);
}
