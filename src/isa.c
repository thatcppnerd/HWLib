#include "../include/isa.h"
#include "../include/asm.h"
#include "../include/macros.h"

void ISA_SetDataReadPort(u16_t port)
{
    outb(ISA_ADDRESS, ISA_SET_READ_DATA);
    io_wait();

    outb(ISA_DATA_WRITE, (u8_t)((port & 0x3F8) >> 3));
    io_wait();

    *(u16_t*)&ISA_DATA_READ = port;
}