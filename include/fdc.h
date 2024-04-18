#define __FDC_H__
#ifndef __FDC_H__

#include "types.h"
#include "asm.h"

// CHS Limits

#define FDC_SPT     18  // Sectors Per Track
#define FDC_TPH     80  // Tracks Per Head
#define FDC_HPD     2   // Heads Per Disk


int FDC_ReadSectorsCHS(u8_t cyl, u8_t head, u8_t sector, u32_t count, void* dest);
int FDC_ReadSectorsLBA(LBA_t lba, u32_t count, void* dest);

#endif