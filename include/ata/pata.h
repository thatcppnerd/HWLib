#ifndef __ATA_PARALLEL__H__
#define __ATA_PARALLEL__H__

#include "../types.h"

#include "defs.h"


int PATA_ReadSectorPIO(u8_t bus, u8_t drive, LBA_t lba, void* dest);
int PATA_ReadSectorDMA(u8_t bus, u8_t drive, LBA_t lba, void* dest);

int PATA_WriteSectorPIO(u8_t bus, u8_t drive, LBA_t lba, void* src);
int PATA_WriteSectorDMA(u8_t bus, u8_t drive, LBA_t lba, void* src);

int PATA_ReadSectorsPIO(u8_t bus, u8_t drive, LBA_t lba, void* dest, u8_t count);
int PATA_ReadSectorsDMA(u8_t bus, u8_t drive, LBA_t lba, void* dest, u8_t count);

int PATA_WriteSectorsPIO(u8_t bus, u8_t drive, LBA_t lba, void* src, u8_t count);
int PATA_WriteSectorsDMA(u8_t bus, u8_t drive, LBA_t lba, void* src, u8_t count);







#endif