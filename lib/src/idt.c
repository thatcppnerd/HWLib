#include "../include/tables/idt.h"

void idt_load(idtr_t src)
{
    asm volatile("lidt %0\n" : : "m" (src) );
    return;
}

void idt_store(idtr_t dest)
{
    asm volatile("sidt %0\n" : "=m" (dest) );
    return;
}

void idt_setVector(idt_t idt, idt_vec_t vector, u8_t attrib, void* funcaddr)
{
    idt[vector].attrib.byte = attrib;
    idt[vector].seg_select = 0x0008;
    idt[vector].offset_lw = (u16_t)funcaddr;
    idt[vector].offset_hw = (u16_t)((u32_t)funcaddr >> 16);
    idt[vector].reserved = 0x00;
}