#ifndef __IDT_H__
#define __IDT_H__

#include "types.h"
#include "macros.h"


typedef struct PACKED IDT_GateDesc
{
    u16_t   off_lo;
    u16_t   seg_select;
    u8_t    resv;
    u8_t    attr;
    u16_t   off_hi;
} IDT_GateDesc_t;

typedef struct PACKED IDTR
{
    u16_t size;
    u32_t offset;
} IDTR_t;

enum idt_gatetype
{
    IDT_GATETYPE_TASK   = 0b0101,
    IDT_GATETYPE_INT16  = 0b0110,
    IDT_GATETYPE_TRAP16 = 0b0111,
    IDT_GATETYPE_INT32  = 0b1110,
    IDT_GATETYPE_TRAP32 = 0b1111
};


typedef IDT_GateDesc_t* IDT_t;

void IDT_LoadReg(IDTR_t idtr);
void IDT_StoreReg(IDTR_t* idtr);

void IDT_SetVector(IDT_t, u8_t vector, u8_t attr, void* func);



#endif