#include "../include/dev/dev.h"

inline void ALWAYSINLINE outb(u16_t port, u8_t val)
{
    register u16_t dx asm("%dx") = port;

    asm volatile("outb %0, %1 \n" : : "a"(val), "d"(dx));
}

inline void ALWAYSINLINE outw(u16_t port, u16_t val)
{
    register u16_t dx asm("%dx") = port;

    asm volatile("outw %0, %1 \n" : : "a"(val), "d"(port));
}

inline void ALWAYSINLINE outdw(u16_t port, u32_t val)
{
    register u32_t eax asm("%eax") = val;
    asm volatile("outl %0, %1 \n" : : "a"(val), "d"(port));
}

inline u8_t ALWAYSINLINE inb(u16_t port)
{
    register volatile u8_t al asm("%al");
    asm volatile("inb %0, %%al\n" : : "d"(port) : "al" );

    return al;
}

inline u16_t ALWAYSINLINE inw(u16_t port)
{
    register volatile u16_t ax asm("%ax");
    asm volatile("inw %0, %%ax\n" : : "d"(port) : "ax" );

    return ax;
}

inline u32_t ALWAYSINLINE indw(u16_t port)
{
    register volatile u32_t eax asm("%eax");
    asm volatile("inl %0, %%eax\n" : : "d"(port) : "eax");

    return eax;
}

inline void ALWAYSINLINE cli()
{
    asm volatile ("cli;");
}

inline void ALWAYSINLINE sti()
{
    asm volatile ("sti;");
}