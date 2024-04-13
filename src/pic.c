#include "../include/pic.h"



inline void PIC_SetMask(int select, u8_t mask)
{
    if(select == PIC0) outb(PIC0_DATA, mask);
    else if(select == PIC1) outb(PIC1_DATA, mask);
    else return;
}

inline void PIC_SetMasks(u8_t mask0, u8_t mask1)
{
    outb(PIC0_DATA, mask0);
    outb(PIC1_DATA, mask1);
}

inline u8_t PIC_GetMask(int select)
{
    if(select == PIC0) return inb(PIC0_DATA);
    else if(select == PIC1) return inb(PIC1_DATA);
    else return 0;
}

void PIC_Remap(u8_t base0, u8_t base1)
{
    u8_t m0 = PIC_GetMask(PIC0);
    u8_t m1 = PIC_GetMask(PIC1);

    // Send init command
    outb(PIC0_CMD, PIC_INIT);
    outb(0x80, 0); // IO_WAIT(), you'll see lots of these

    outb(PIC1_CMD, PIC_INIT);
    outb(0x80, 0);

    // Send n
}

// void PIC_Init()
// {

// }