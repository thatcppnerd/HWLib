#ifndef __IDT_H__
#define __IDT_H__

#include "../dev/types.h"
#include "../dev/dev.h"

#define IS_PRESENT 1
#define NO_PRESENT 0

#pragma pack(push, 1)

typedef union PACKED idt_gate_attrib
{
    u8_t
        gatetype : 4,
        : 1,
        dpl : 2,
        present : 1;
    u8_t byte;
} PACKED idt_gate_attrib_t;

typedef struct PACKED idt_gatedesc
{
    u16_t offset_lw;
    u16_t seg_select;
    u8_t reserved;
    idt_gate_attrib_t attrib;
    u16_t offset_hw;
} PACKED idt_gatedesc_t;

typedef idt_gatedesc_t* idt_t;
typedef u8_t idt_vec_t;

typedef struct PACKED idtr
{
    u16_t size;
    idt_gatedesc_t* offset; // pointer to entries
} PACKED idtr_t; 
#pragma pack(pop)

typedef enum idt_gatetype
{
    IDT_GATETYPE_TASK   = 0b0101,
    IDT_GATETYPE_INT16  = 0b0110,
    IDT_GATETYPE_TRAP16 = 0b0111,
    IDT_GATETYPE_INT32  = 0b1110,
    IDT_GATETYPE_TRAP32 = 0b1111
} idt_gatetype_t;


void idt_load(idtr_t idt);
void idt_store(idtr_t dest);

void idt_setVector(idt_t idt, idt_vec_t vector, u8_t attrib, void* funcaddr);

#endif