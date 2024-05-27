#ifndef __ATA_ENUMS_H__
#define __ATA_ENUMS_H__

#include "../types.h"

typedef union ATA_Error
{
    u8_t
        amnf    : 1,
        tkzkf   : 1,
        abrt    : 1,
        mcr     : 1,
        idnf    : 1,
        mc      : 1,
        unc     : 1,
        bbk     : 1;

    u8_t val;
} ATA_Error_t;

typedef union ATA_Status
{
    u8_t
        err     : 1,
        idx     : 1,
        corr    : 1,   
        drq     : 1,
        srv     : 1,
        df      : 1,  
        rdy     : 1,
        bsy     : 1;
    
    u8_t val;
} ATA_Status_t;

enum ATA_DeviceCtl_Flags
{
    ATA_DEVICE_CTL_NIEN =   0x02,
    ATA_DEVICE_CTL_SRST =   0x04,
    ATA_DEVICE_CTL_HOB =    0x80
};

enum ATA_Reg_Offsets
{
    // Bases

    ATA_BUS0_IO_BASE =  0x1F0,
    ATA_BUS0_CTL_BASE = 0x3F6,

    ATA_BUS1_IO_BASE =  0x170,
    ATA_BUS1_CTL_BASE = 0x376,

    ATA_BUS2_IO_BASE =  0x1E8,
    ATA_BUS2_CTL_BASE = 0x3E6,

    ATA_BUS3_IO_BASE =  0x168,
    ATA_BUS3_CTL_BASE = 0x366,


    ATA_REG_DATA =                      0,
    ATA_REG_ERROR =                     1,
    ATA_REG_FEATURES =                  1,
    ATA_REG_SECTOR_COUNT =              2,
    ATA_REG_LBA_LO =                    3,
    ATA_REG_CHS_SECTOR =                3,
    ATA_REG_LBA_MID =                   4,
    ATA_REG_CHS_TRACK_LO =              4,
    ATA_REG_LBA_HI =                    5,
    ATA_REG_CHS_TRACK_HI =              5,
    ATA_REG_DRIVE_HEAD =                6,
    ATA_REG_STATUS =                    7,
    ATA_REG_COMMAND =                   7,

    ATA_REG_ALT_STATUS =                0,
    ATA_REG_DEVICE_CTL =                0,
    ATA_REG_DRIVE_ADDR =                1
};

enum ATA_Command
{
    ATA_NOP =                   0x00,
    ATA_READ_PIO =              0x20,
    ATA_READ_PIO_NO_RETRY =     0x21,
    ATA_WRITE_PIO =             0x30,
    ATA_WRITE_PIO_NO_RETRY =    0x31,
    ATA_CACHE_FLUSH =           0xE7,
    ATA_IDENTIFY =              0xEC
};

#define ATA_BUS0    0
#define ATA_BUS1    1
#define ATA_BUS2    2
#define ATA_BUS3    3

#define ATA_IO_BASE     0
#define ATA_CTL_BASE    1

u16_t ATA_GetBase(int bus, int base);

#define ATA_MASTER  0
#define ATA_SLAVE   1

#endif 