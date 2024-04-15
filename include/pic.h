#ifndef __PIC_H__
#define __PIC_H__

#include "asm.h"

// Ports for both PICs

#define PIC0_BASE 0x20
#define PIC1_BASE 0xA0

#define PIC0_CMD PIC0_BASE
#define PIC0_DATA (PIC0_BASE + 1)

#define PIC1_CMD PIC1_BASE
#define PIC1_DATA (PIC1_BASE + 1)

// PIC Commands
#define PIC_INIT 0x11 // Initialization Command
#define PIC_EOI 0x20 // End Of Interrupt

// PIC Enums for functions
#define PIC0 0
#define PIC1 1

// PIC Functions

void PIC_SetMask(int select, u8_t mask);
void PIC_SetMasks(u8_t mask0, u8_t mask1);
u8_t PIC_GetMask(int select);

void PIC_SendCommand(int select, u8_t cmd);
void PIC_SendData(int select, u8_t data);

#define PIC_SendEOI(select) PIC_SendCommand(select, PIC_EOI)

void PIC_Init(int select, u8_t icw1, u8_t icw2, u8_t icw3, u8_t icw4);
void PIC_Remap(u8_t base0, u8_t base1);

#endif