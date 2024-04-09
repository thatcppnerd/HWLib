#include "../include/hardware/pic.h"



inline void PIC_SetMask(PIC_Select_t select, u8_t mask)
{
    if(select == PIC_SEL_MASTER) outb(PIC0_DATA, mask);
    else if(select == PIC_SEL_SLAVE) outb(PIC1_DATA, mask);
    else return;
}

inline void PIC_SetMasks(u8_t mask0, u8_t mask1)
{
    outb(PIC0_DATA, mask0);
    outb(PIC1_DATA, mask1);
}

inline u8_t PIC_GetMask(PIC_Select_t select)
{
    if(select == PIC_SEL_MASTER) return inb(PIC0_DATA);
    else if(select == PIC_SEL_SLAVE) return inb(PIC1_DATA);
    else return 0;
}

void PIC_Remap(u8_t base0, u8_t base1)
{
    u8_t m0 = PIC_GetMask(PIC_SEL_MASTER);
    u8_t m1 = PIC_GetMask(PIC_SEL_SLAVE);

    // Send init command
    outb(PIC0_CMD, PIC_CMD_INIT);
    outb(0x80, 0); // IO_WAIT(), you'll see lots of these

    outb(PIC1_CMD, PIC_CMD_INIT);
    outb(0x80, 0);

    // Send n
}

void PIC_Init()
{

}