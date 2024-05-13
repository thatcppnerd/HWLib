#ifndef __ATA_ENUMS_H__
#define __ATA_ENUMS_H__

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
    ATA_REG_DRIVE_SEL_AND_LBA_EXTRA =   6,
    ATA_REG_DRIVE_SEL_AND_CHS_HEAD =    6,
    ATA_REG_STATUS =                    7,
    ATA_REG_CMD =                       7,

    ATA_REG_ALT_STATUS =                0,
    ATA_REG_DEVICE_CTL =                0,
    ATA_REG_DRIVE_ADDR =                1
};


#endif 