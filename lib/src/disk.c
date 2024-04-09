#include "../include/disk.h"
#include "../include/asm.h"

int ata_read(chs_t location, ubyte_t n, void* addr)
{
    register udword_t dx asm("%dx");
    register ubyte_t al asm("%al");
    register ubyte_t ah asm("%ah");
    register uword_t ax asm("%ax");
    register udword_t eax asm("%eax");



    // Send head index
    outb(0x1F6, location.head & 0xA0);

    // Send sector count
    dx = 0x1F2;

    al = n;

    asm volatile("out %%al, %%dx\n" : : : "al", "dx");


    // Send sector index
    dx = 0x1F3;

    al = location.sector;

    asm volatile("out %%al, %%dx\n" : : : "al", "dx");


    // Send low byte of cylinder index
    dx = 0x1F4;

    al = (ubyte_t)location.cylinder;

    asm volatile("out %%al, %%dx\n" : : : "al", "dx");
    

    // Send high byte of cylinder index
    dx = 0x1F5;

    al = location.cylinder >> 8;

    asm volatile("out %%al, %%dx\n" : : : "al", "dx");


    // Send data to command port
    dx = 0x1F7;

    al = 0x20;

    asm volatile("out %%al, %%dx\n" : : : "al", "dx");


    return 0;
}

int ata_write(chs_t location, ubyte_t n, void* addr)
{

}
