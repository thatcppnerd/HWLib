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

// IO Ports

#define DMA_MASTER_BASE 0x00
#define DMA_SLAVE_BASE  0xC0


// Register flag enums

enum DMA_



void DMA_SetStartAddress(int channel, u16_t addr);
u8_t DMA_GetStatus(void);
void DMA_SendCommand(u8_t cmd);
void DMA_SendRequest(u8_t cmd);
void DMA_SetMask(u8_t mask);
void DMA_SetMode(u8_t mode);
void DMA_FlipFlopReset(void);
u8_t DMA_GetIntermediate(void);
void DMA_MasterReset(void);
void DMA_MaskReset(void);

u8_t DMA_GetMultiChannelMask(void);
void DMA_SetMultiChannelMas(u8_t mask);

void DMA_SetPageAddress(int channel, u8_t data);


#endif