#ifndef __DMA_H__
#define __DMA_H__

#include "types.h"
#include "asm.h"
#include "util.h"

// Macros for channel select

#define DMA_CH0 0
#define DMA_CH1 1
#define DMA_CH2 2
#define DMA_CH3 3
#define DMA_CH4 4
#define DMA_CH5 5
#define DMA_CH6 6
#define DMA_CH7 7

// Macros for chip select

#define DMA0 0
#define DMA1 1


// IO Ports

#define DMA0_BASE   0xC0 
#define DMA1_BASE   0x00

// Register flag enums

enum DMA_



void DMA_SetStartAddress(int channel, u16_t addr);
void DMA_SetCount(int channel);
u8_t DMA_GetStatus(int select);
void DMA_SendCommand(int select, u8_t cmd);
void DMA_SendRequest(int select, u8_t req);
void DMA_SetMask(int select, u8_t mask);
void DMA_SetMode(int select, u8_t mode);
void DMA_FlipFlopReset(int select);
u8_t DMA_GetIntermediate(int select);
void DMA_MasterReset(int select);
void DMA_MaskReset(int select);

u8_t DMA_GetMultiChannelMask(int select);
void DMA_SetMultiChannelMask(int select, u8_t mask);

void DMA_SetPageAddress(int channel, u8_t data);


#endif