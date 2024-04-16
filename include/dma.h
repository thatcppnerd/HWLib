#ifndef __DMA_H__
#define __DMA_H__

#include "types.h"

// Macros for channel select

#define DMA0 0
#define DMA1 1
#define DMA2 2
#define DMA3 3
#define DMA4 4
#define DMA5 5
#define DMA6 6
#define DMA7 7


void DMA_SetStartAddress(int channel, u16_t addr);

#endif