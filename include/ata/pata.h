#ifndef __ATA_PARALLEL__H__
#define __ATA_PARALLEL__H__

#include "../types.h"

#include "defs.h"


void PATA_400ns(int bus);

ATA_Error_t     PATA_GetError(int bus);
ATA_Status_t    PATA_GetStatus(int bus);

void    PATA_Nop(int bus);
void    PATA_CasheFlush(int bus);
void    PATA_SoftwareReset(int bus);
void    PATA_Identify(int bus, int drive);

int     PATA_ReadSectorsPIO(int bus, int drive, LBA_t lba, u8_t count, void* dest);
int     PATA_ReadSectorsDMA(int bus, int drive, LBA_t lba, u8_t count, void* dest);
int     PATA_WriteSectorsPIO(int bus, int drive, LBA_t lba, u8_t count, void* src);
int     PATA_WriteSectorsDMA(int bus, int drive, LBA_t lba, u8_t count, void* src);







#endif