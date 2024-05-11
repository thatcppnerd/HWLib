#ifndef __MACROS_H__
#define __MACROS_H__

#include "asm.h"

#define io_wait() outb(0x80, 0)

#define ERR_VAL -1

#endif