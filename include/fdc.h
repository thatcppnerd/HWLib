#ifndef __FDC_H__
#define __FDC_H__

#include "types.h"
#include "asm.h"
#include "macros.h"


// FDC Select

#define FDC0    0
#define FDC1    1
#define FDC2    2

// Drive Select

#define DRV0    0
#define DRV1    1
#define DRV2    2
#define DRV3    3

// CHS Limits

#define FDC_SPT     18  // Sectors Per Track
#define FDC_TPH     80  // Tracks Per Head
#define FDC_HPD     2   // Heads Per Disk



enum FDC_Ports
{
    FDC0_IOBASE =                      0x3F0,
    FDC1_IOBASE =                      0x370,
    FDC2_IOBASE =                      0x360,


    FDC0_STATUS_REG_A =                 FDC0_IOBASE + 0,
    FDC0_STATUS_REG_B =                 FDC0_IOBASE + 1,
    FDC0_DIGITAL_OUTPUT_REG =           FDC0_IOBASE + 2,
    FDC0_TAPE_DRIVE_REG =               FDC0_IOBASE + 3,
    FDC0_MAIN_STATUS_REG =              FDC0_IOBASE + 4,
    FDC0_DATARATE_SELECT_REG =          FDC0_IOBASE + 4,
    FDC0_FIFO_REG =                     FDC0_IOBASE + 5,
    FDC0_DIGITAL_INPUT_REG =            FDC0_IOBASE + 7,
    FDC0_CONFIGURATION_CONTROL_REG =    FDC0_IOBASE + 7,

    FDC1_STATUS_REG_A =                 FDC1_IOBASE + 0,
    FDC1_STATUS_REG_B =                 FDC1_IOBASE + 1,
    FDC1_DIGITAL_OUTPUT_REG =           FDC1_IOBASE + 2,
    FDC1_TAPE_DRIVE_REG =               FDC1_IOBASE + 3,
    FDC1_MAIN_STATUS_REG =              FDC1_IOBASE + 4,
    FDC1_DATARATE_SELECT_REG =          FDC1_IOBASE + 4,
    FDC1_FIFO_REG =                     FDC1_IOBASE + 5,
    FDC1_DIGITAL_INPUT_REG =            FDC1_IOBASE + 7,
    FDC1_CONFIGURATION_CONTROL_REG =    FDC1_IOBASE + 7,

    FDC2_STATUS_REG_A =                 FDC2_IOBASE + 0,
    FDC2_STATUS_REG_B =                 FDC2_IOBASE + 1,
    FDC2_DIGITAL_OUTPUT_REG =           FDC2_IOBASE + 2,
    FDC2_TAPE_DRIVE_REG =               FDC2_IOBASE + 3,
    FDC2_MAIN_STATUS_REG =              FDC2_IOBASE + 4,
    FDC2_DATARATE_SELECT_REG =          FDC2_IOBASE + 4,
    FDC2_FIFO_REG =                     FDC2_IOBASE + 5,
    FDC2_DIGITAL_INPUT_REG =            FDC2_IOBASE + 7,
    FDC2_CONFIGURATION_CONTROL_REG =    FDC2_IOBASE + 7
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

// for Tape Drive Register(TDR)
enum FDC_TDR_Flags
{
    FDC_TDR_SEL0 =  0x01,
    FDC_TDR_SEL1 =  0x02,
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

// for Datarate Select Register(DSR)
enum FDC_DSR_Flags
{
    FDC_DSR_RATE0 =     0x01,
    FDC_DSR_RATE1 =     0x02
};

// for Digital Input Register(DIR)
enum FDC_DIR_Flags
{
    FDC_DIR_DISK_CHANGE =   0x80
};

enum FDC_CCR_Flags
{             
    FDC_CCR_RATE0 =     0x01,
    FDC_CCR_RATE1 =     0x02
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

enum FDC_Command_Flags
{
    FDC_CMD_SK =    0x20,
    FDC_CMD_MF =    0x40,
    FDC_CMD_MT =    0x80
};




u8_t FDC_GetStatusRegA(int fdc_no);
u8_t FDC_GetStatusRegB(int fdc_no);

void FDC_SetDigitalOutputReg(int fdc_no, u8_t data);
u8_t FDC_GetDigitalOutputReg(int fdc_no);

void FDC_SetTapeDriveReg(int fdc_no, u8_t data);
u8_t FDC_GetTapeDriveReg(int fdc_no);

u8_t FDC_GetMainStatusReg(int fdc_no);

void FDC_SetDatarateSelectReg(int fdc_no, u8_t data);

void FDC_SetFIFOReg(int fdc_no, u16_t data);
u16_t FDC_GetFIFOReg(int fdc_no);

void FDC_SetDigitalInputReg(int fdc_no, u8_t data);
u8_t FDC_GetDigitalInputReg(int fdc_no);

void FDC_SetConfigurationControlReg(int fdc_no, u8_t data);
u8_t FDC_GetConfigurationControlReg(int fdc_no);


void FDC_ToggleDriveMotor(int fdc_no, int drv_no, int mode);
void FDC_SetDatarate(int fdc_no, int rate);



#endif