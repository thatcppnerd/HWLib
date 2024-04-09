#ifndef __PIC_H__
#define __PIC_H__

#include "../dev/asm.h"

// Ports for both PICs

#define PIC0 0x20
#define PIC1 0xA0

#define PIC0_CMD PIC0
#define PIC0_DATA (PIC0 + 1)

#define PIC1_CMD PIC1
#define PIC1_DATA (PIC1 + 1)

// PIC Commands

#define PIC_CMD_INIT 0x11 // Initialization Command
#define PIC_CMD_EOI 0x20 // End Of Interrupt

typedef enum PIC_Select
{
    PIC_SEL_MASTER = 0,
    PIC_SEL_SLAVE = 1
} PIC_Select_t;

void PIC_SetMask(PIC_Select_t select, u8_t mask);
void PIC_SetMasks(u8_t mask0, u8_t mask1);
u8_t PIC_GetMask(PIC_Select_t select);

void PIC_Remap(u8_t base0, u8_t base1);

#endif