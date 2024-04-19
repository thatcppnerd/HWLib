#define __FDC_H__
#ifndef __FDC_H__

#include "types.h"
#include "asm.h"

// CHS Limits

#define FDC_SPT     18  // Sectors Per Track
#define FDC_TPH     80  // Tracks Per Head
#define FDC_HPD     2   // Heads Per Disk

enum FDC_Ports
{
    // for FDC0

    FDC0_STATUS_A =          0x3F0,
    FDC0_STATUS_B =          0x3F1,
    FDC0_DIGITAL_OUTPUT =    0x3F2,
    FDC0_TAPE_DRV =          0x3F3,
    FDC0_MAIN_STATUS =       0x3F4,
    FDC0_DATARATE_SELECT =   0x3F4,
    FDC0_FIFO =              0x3F5,
    FDC0_DIGITAL_INPUT =     0x3F7,
    FDC0_CONFIG_CTL =        0x3F7,

    // for FDC1

    FDC1_STATUS_A =          0x3F0,
    FDC1_STATUS_B =          0x3F1,
    FDC1_DIGITAL_OUTPUT =    0x3F2,
    FDC1_TAPE_DRV =          0x3F3,
    FDC1_MAIN_STATUS =       0x3F4,
    FDC1_DATARATE_SELECT =   0x3F4,
    FDC1_FIFO =              0x3F5,
    FDC1_DIGITAL_INPUT =     0x3F7,
    FDC1_CONFIG_CTL =        0x3F7
};

enum

int FDC_ReadSectorsPIO(u8_t cyl, u8_t head, u8_t sector, u32_t count, void* dest);
int FDC_WriteSectorsPIO(u8_t cyl, u8_t head, u8_t sector, u32_t count, void* src);

int FDC_ReadSectorsDMA(u8_t cyl, u8_t head, u8_t sector, u32_t count, void* dest);
int FDC_WriteSectorsDMA(u8_t cyl, u8_t head, u8_t sector, u32_t count, void* src);

#endif