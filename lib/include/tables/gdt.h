#ifndef __GDT_H__
#define __GDT_H__

#include "types.h"
#include "dev.h"


#pragma pack(1, push)

typedef struct PACKED GDT_Access
{
    u8_t a : 1,
            rw : 1,
            dc : 1,
            e : 1,
            s : 1,
            dpl : 2,
            p : 1; 
}GDT_Access_t;

typedef struct PACKED GDT_Entry
{
    u16_t limit_lw; // low word of limit
    u16_t base_lw; // low word of base address
    u8_t base_lbhw; // low byte of high word of base address
    GDT_Access_t access;

    u8_t 
        flags : 4,
        limit_hn : 4;  // high(est) nibble of limit

    u8_t base_hbhw;
} PACKED GDT_Entry_t;

typedef struct PACKED gdt
{
    GDT_Entry_t offset[256]; // Max. number of Entries is 8192, but no malloc yet :(
} PACKED gdt_t;

typedef struct PACKED gdt_desc
{
    u16_t size;
    gdt_t* gdt;
} PACKED gdt_desc_t;

#pragma pack(pop)

GDT_Entry_t GDT_GetEntry(gdt_t* gdt, u16_t index);
void GDT_SetEntry(gdt_t* gdt, u16_t index, GDT_Entry_t entry);

#define GDT_Load(src) asm volatile( "lgdt %0\n" : :"m" (src) )
#define GDT_Store(dest) asm volatile( "sgdt %0\n" : "=m" (dest) )


#endif