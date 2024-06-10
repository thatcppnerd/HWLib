#include "../include/idt.h"

void IDT_LoadIDTR(IDTR_t idtr)
{
    asm volatile ("lidt %0;" : :"m" (idtr));
}

void IDT_StoreIDTR(IDTR_t* idtr)
{
    asm volatile ("sidt %0;" :"=m" (idtr));
}

void IDT_SetVector(IDT_t idt, u8_t vec, u16_t seg, IDT_Attr_t attr, void* func)
{
    idt[vec].off_lo = ( (u16_t*) &func ) [1]; // get least significant word
    idt[vec].off_hi = ( (u16_t*) &func ) [0]; // get most significant word
    
    idt[vec].seg    = seg;
    idt[vec].resv   = 0;
    idt[vec].attr   = attr;
}