#ifndef __UTIL_H__
#define __UTIL_H__

#include "asm.h"

#define io_wait() outb(0x80, 0)

#define ERR_VAL -1

#endif