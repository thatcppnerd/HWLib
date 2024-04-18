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


enum DMA_STATUS_Flags
{
    DMA_STATUS_TC0 =        0x01,
    DMA_STATUS_TC1 =        0x02,
    DMA_STATUS_TC2 =        0x04,
    DMA_STATUS_TC3 =        0x08,
    DMA_STATUS_REQ0 =       0x10,
    DMA_STATUS_REQ1 =       0x20,
    DMA_STATUS_REQ2 =       0x40,
    DMA_STATUS_REQ3 =       0x80
};

enum DMA_CMD_Flags
{
    DMA_CMD_MMT =       0x01,
    DMA_CMD_ADME =      0x02,
    DMA_CMD_COND =      0x04,
    DMA_CMD_COMP =      0x08,
    DMA_CMD_PRIO =      0x10,
    DMA_CMD_EXTW =      0x20,
    DMA_CMD_DRQP =      0x40,
    DMA_CMD_DACKP =     0x80
};

// for Single Channel Mask
enum DMA_SCMASK_Flags
{
    DMA_SCMASK_SEL0 =       0x01,
    DMA_SCMASK_SEL1 =       0x02,
    DMA_SCMASK_MASK_ON =    0x04
};

enum DMA_MODE_Flags
{
    DMA_MODE_SEL0 =     0x01,
    DMA_MODE_SEL1 =     0x02,
    DMA_MODE_TRA0 =     0x04,
    DMA_MODE_TRA1 =     0x08,
    DMA_MODE_AUTO =     0x10,
    DMA_MODE_DOWN =     0x20,
    DMA_MODE_MOD0 =     0x40,
    DMA_MODE_MOD1 =     0x80
};

// for Multi Channel Mask
enum DMA_MCMASK_Flags
{
    DMA_MCMASK_MASK0 =  0x01,
    DMA_MCMASK_MASK1 =  0x02,
    DMA_MCMASK_MASK2 =  0x04,
    DMA_MCMASK_MASK3 =  0x08
};

void DMA_SetStartAddressReg(int channel, u16_t addr);
void DMA_SetCountReg(int channel, u16_t count);
u8_t DMA_GetStatusReg(int select);
void DMA_SetCommandReg(int select, u8_t val);
void DMA_SetRequestReg(int select, u8_t val);
void DMA_SetSingleChannelMaskReg(int select, u8_t channel);
void DMA_SetModeReg(int select, u8_t mode);
void DMA_FlipFlopReset(int select);
u8_t DMA_GetIntermediateReg(int select);
void DMA_MasterReset(int select);
void DMA_MaskReset(int select);

u8_t DMA_GetMultiChannelMask(int select);
void DMA_SetMultiChannelMask(int select, u8_t mask);

void DMA_SetPageAddress(int channel, u8_t data);


#endif