#ifndef __ATA_PARALLEL__H__
#define __ATA_PARALLEL__H__

#include "../types.h"

#include "defs.h"

u8_t PATA_current_bus = 0;
u8_t PATA_current_drive = 0;

int PATA_SendCommand(u8_t bus, u8_t drive, u8_t cmd);

int PATA_GetErrorReg();

int PATA_FlushCashe();


int PATA_ReadSectorPIO(u8_t bus, u8_t drive, LBA_t lba, void* dest);
int PATA_ReadSectorDMA(u8_t bus, u8_t drive, LBA_t lba, void* dest);

int PATA_WriteSectorPIO(u8_t bus, u8_t drive, LBA_t lba, void* src);
int PATA_WriteSectorDMA(u8_t bus, u8_t drive, LBA_t lba, void* src);

int PATA_ReadSectorsPIO(u8_t bus, u8_t drive, LBA_t lba, void* dest, u8_t count);
int PATA_ReadSectorsDMA(u8_t bus, u8_t drive, LBA_t lba, void* dest, u8_t count);

int PATA_WriteSectorsPIO(u8_t bus, u8_t drive, LBA_t lba, void* src, u8_t count);
int PATA_WriteSectorsDMA(u8_t bus, u8_t drive, LBA_t lba, void* src, u8_t count);







#endif