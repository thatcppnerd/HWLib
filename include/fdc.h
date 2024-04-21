#ifndef __FDC_H__
#define __FDC_H__

#include "types.h"
#include "asm.h"

// CHS Limits

#define FDC_SPT     18  // Sectors Per Track
#define FDC_TPH     80  // Tracks Per Head
#define FDC_HPD     2   // Heads Per Disk


enum FDC_Ports
{
    // for FDC0

    FDC0_STATUS_A =         0x3F0,
    FDC0_STATUS_B =         0x3F1,
    FDC0_DIGITAL_OUTPUT =   0x3F2,
    FDC0_TAPE_DRV =         0x3F3,
    FDC0_MAIN_STATUS =      0x3F4,
    FDC0_DATARATE_SELECT =  0x3F4,
    FDC0_FIFO =             0x3F5,
    FDC0_DIGITAL_INPUT =    0x3F7,
    FDC0_CONFIG_CTL =       0x3F7,

    // for FDC1

    FDC1_STATUSA =          0x3F0,
    FDC1_STATUSB =          0x3F1,
    FDC1_DOR =              0x3F2, // Data Output Register
    FDC1_TAPE_DRV =         0x3F3,
    FDC1_MSR =              0x3F4, // Master Output Register
    FDC1_DATARATE_SELECT =  0x3F4,
    FDC1_FIFO =             0x3F5,
    FDC1_DIR =              0x3F7,
    FDC1_CONFIG_CTL =       0x3F7
};

// for Digital Output Register(DOR)
enum FDC_DOR_Flags
{
    FDC_DOR_SEL0 =      0x01,
    FDC_DOR_SEL1 =      0x02,
    FDC_DOR_RESET =     0x04,
    FDC_DOR_IRQ =       0x08,
    FDC_DOR_MOTA =      0x10,
    FDC_DOR_MOTB =      0x20,
    FDC_DOR_MOTC =      0x40,
    FDC_DOR_MOTD =      0x80
};

// for Master Status Register(MSR)
enum FDC_MSR_Flags
{
    FDC_MSR_ACTA =      0x01,
    FDC_MSR_ACTB =      0x02,
    FDC_MSR_ACTC =      0x04,
    FDC_MSR_ACTD =      0x08,
    FDC_MSR_CB =        0x10,
    FDC_MSR_NDMA =      0x20,
    FDC_MSR_DIO =       0x40,
    FDC_MSR_RQM =       0x80
};

enum FDC_Command
{
    FDC_CMD_READ_TRACK =                0x02,	
    FDC_CMD_SET_PARAMS =                0x03,
    FDC_CMD_SENSE_DRIVE_STATUS =        0x04,
    FDC_CMD_WRITE_DATA =                0x05,
    FDC_CMD_READ_DATA =                 0x06,
    FDC_CMD_RECALIBRATE =               0x07,
    FDC_CMD_SENSE_INTERRUPT =           0x08,
    FDC_CMD_WRITE_DELETED_DATA =        0x09,
    FDC_CMD_READ_ID =                   0x0A,
    FDC_CMD_READ_DELETED_DATA =         0x0C,
    FDC_CMD_FORMAT_TRACK =              0x0D,
    FDC_CMD_DUMPREG =                   0x0E,
    FDC_CMD_SEEK =                      0x0F,
    FDC_CMD_VERSION =                   0x10,
    FDC_CMD_SCAN_EQUAL =                0x11,
    FDC_CMD_PERPENDICULAR_MODE =        0x12,
    FDC_CMD_CONFIGURE =                 0x13,
    FDC_CMD_LOCK =                      0x14,
    FDC_CMD_VERIFY =                    0x16,
    FDC_CMD_SCAN_LOW_OR_EQUAL =         0x19,
    FDC_CMD_SCAN_HIGH_OR_EQUAL =        0x1D
};


int FDC_ReadSectorsPIO(u32_t lba, u32_t count, void* dest);
int FDC_WriteSectorsPIO(u32_t lba, u32_t count, void* src);

int FDC_ReadSectorsDMA(u32_t lba, u32_t count, void* dest);
int FDC_WriteSectorsDMA(u32_t lba, u32_t count, void* src);

void FDC_ToggleDriveMotor(int drvno, int mode);
void FDC_Reset();


#endif