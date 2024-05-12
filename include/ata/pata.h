#ifndef __ATA_H__
#define __ATA_H__

#include "types.h"

enum ATA_ErrorReg_Flags
{
    ATA_ERROR_AMNF =    0x01,
    ATA_ERROR_TKZKF =   0x02,
    ATA_ERROR_ABRT =    0x04,
    ATA_ERROR_MCR =     0x08,
    ATA_ERROR_IDNF =    0x10,
    ATA_ERROR_MC =      0x20,
    ATA_ERROR_UNC =     0x40,
    ATA_ERROR_BBK =     0x80
};

enum ATA_StatusReg_Flags
{
    ATA_STATUS_ERR =    0x01,
    ATA_STATUS_IDX =    0x02,
    ATA_STATUS_CORR =   0x04,
    ATA_STATUS_DRQ =    0x08,
    ATA_STATUS_SRV =    0x10,
    ATA_STATUS_DF =     0x20,
    ATA_STATUS_RDY =    0x40,
    ATA_STATUS_BSY =    0x80
};




#endif