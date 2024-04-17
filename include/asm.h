#ifndef __ASM_H__
#define __ASM_H__

#include "types.h"

#define mov(dest, src)  

#define push(src) asm("push %0" : :"a"(src))
#define pop(dest) asm("pop %0" : "=a"(dest))

// I/O Bus Access

void outb(u16_t port, u8_t val);
void outw(u16_t port, u16_t val);
void outdw(u16_t port, u32_t val);

u8_t inb(u16_t port);
u16_t inw(u16_t port);
u32_t indw(u16_t port);

// Interrupt Enable/Disable

void cli(void);
void sti(void);

void hlt(void);


#endif