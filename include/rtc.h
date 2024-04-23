#ifndef __RTC_H__
#define __RTC_H__

#include "types.h"
#include "cmos.h"

#define RTC_BASE_FREQ 32768

// Addresses for RTC Registers in CMOS
enum RTC_Register
{
    RTC_SECOND_REG =        CMOS_REG_RTC_SECOND,
    RTC_MINUTE_REG =        CMOS_REG_RTC_MINUTE,
    RTC_HOUR_REG =          CMOS_REG_RTC_HOUR,
    RTC_WEEKDAY_REG =       CMOS_REG_RTC_WEEKDAY,
    RTC_DAYOFMONTH_REG =    CMOS_REG_RTC_DAYOFMONTH,
    RTC_MONTH_REG =         CMOS_REG_RTC_MONTH,
    RTC_YEAR_REG =          CMOS_REG_RTC_YEAR,
    RTC_CENTURY_REG =       CMOS_REG_RTC_CENTURY,

    RTC_STATUS_A_REG =      CMOS_REG_RTC_STATUS_A,
    RTC_STATUS_B_REG =      CMOS_REG_RTC_STATUS_B
};

enum RTC_Day
{
    RTC_SUN =       1,
    RTC_MON =       2,
    RTC_TUE =       3,
    RTC_WED =       4,
    RTC_THU =       5,
    RTC_FRI =       6,
    RTC_SAT =       7
};

enum RTC_Month
{
    RTC_JAN =       1,
    RTC_FEB =       2,
    RTC_MAR =       3,
    RTC_APR =       4,
    RTC_MAY =       5,
    RTC_JUN =       6,
    RTC_JUL =       7,
    RTC_AUG =       8,
    RTC_SEP =       9,
    RTC_OCT =       10,
    RTC_NOV =       11,
    RTC_DEC =       12
};


u8_t RTC_GetSeconds(void);
u8_t RTC_GetMinutes(void);
u8_t RTC_GetHours(void);
u8_t RTC_GetWeekday(void);
u8_t RTC_GetDayOfMonth(void);
u8_t RTC_GetMonth(void);
u8_t RTC_GetYear(void);
u8_t RTC_GetCentury(void);

u8_t RTC_GetStatusA(void);
u8_t RTC_GetStatusB(void);

#endif