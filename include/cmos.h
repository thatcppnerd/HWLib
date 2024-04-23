#ifndef __CMOS_H__
#define __CMOS_H__

#include "types.h"
#include "macros.h"
#include "asm.h"

// CMOS Ports

#define CMOS_INDEX  0x70
#define CMOS_DATA   0x71

enum CMOS_Register
{
    CMOS_REG_RTC_SECOND =       0x00,
    CMOS_REG_RTC_MINUTE =       0x02,
    CMOS_REG_RTC_HOURS =        0x04,
    CMOS_REG_RTC_WEEKDAY =      0x06,
    CMOS_REG_RTC_DAYOFMONTH =   0x07,
    CMOS_REG_RTC_MONTH =        0x08,
    CMOS_REG_RTC_YEAR =         0x09,
    CMOS_REG_RTC_STATUS_A =     0x0A,
    CMOS_REG_RTC_STATUS_B =     0x0B,

    CMOS_REG_FLOPPY_TYPE =      0x10,

    CMOS_REG_LOWMEM_SIZE_LO =   0x15,
    CMOS_REG_LOWMEM_SIZE_HI =   0x16,

    CMOS_REG_HIMEM_SIZE_LO =    0x17,
    CMOS_REG_HIMEM_SIZE_HI =    0x18,

    CMOS_REG_EXTMEM_SIZE_LO =   0x30,
    CMOS_REG_EXTMEM_SIZE_HI =   0x31,

    CMOS_REG_RTC_CENTURY =      0x32

};

u8_t CMOS_ReadData(u8_t index);
void CMOS_WriteData(u8_t index, u8_t data);

#endif
