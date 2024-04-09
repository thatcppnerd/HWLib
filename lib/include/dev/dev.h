#ifndef __DEV_H__
#define __DEV_H__


#include "asm.h"

// Function attributes.

#define NORETURN __attribute__((noreturn))
#define ALWAYSINLINE __attribute__((always_inline))
#define PACKED __attribute__((packed))

// Halts program in an infinite loop.
#define HALT() 	asm("jmp .\n");

// Constants.

#define NULL (void*)0

#define HIGH 1
#define LOW 0

#define io_wait() inb(0x80)

#endif
