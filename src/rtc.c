#include "../include/rtc.h"

u8_t RTC_GetSeconds(void)
{
    return CMOS_ReadData(RTC_SECOND_REG);
}

u8_t RTC_GetMinutes(void)
{
    return CMOS_ReadData(RTC_MINUTE_REG);
}

u8_t RTC_GetHours(void)
{
    return CMOS_ReadData(RTC_HOUR_REG);
}

u8_t RTC_GetWeekday(void)
{
    return CMOS_ReadData(RTC_WEEKDAY_REG);
}

u8_t RTC_GetDayOfMonth(void)
{
    return CMOS_ReadData(RTC_DAYOFMONTH_REG);
}

u8_t RTC_GetMonth(void)
{
    return CMOS_ReadData(RTC_MONTH_REG);
}

u8_t RTC_GetYear(void)
{
    return CMOS_ReadData(RTC_YEAR_REG);
}

u8_t RTC_GetCentury(void)
{
    return CMOS_ReadData(RTC_CENTURY_REG);
}

void RTC_SetSeconds(u8_t sec)
{
    CMOS_WriteData(RTC_SECOND_REG, sec);
}

void RTC_SetMinutes(u8_t min)
{
    CMOS_WriteData(RTC_MINUTE_REG, min);
}

void RTC_SetHours(u8_t hr)
{
    CMOS_WriteData(RTC_HOUR_REG, hr);
}

void RTC_SetWeekday(u8_t wkday)
{
    CMOS_WriteData(RTC_WEEKDAY_REG, wkday);
}

void RTC_SetDayOfMonth(u8_t day)
{
    CMOS_WriteData(RTC_DAYOFMONTH_REG, day);
}

void RTC_SetMonth(u8_t month)
{
    CMOS_WriteData(RTC_MONTH_REG, month);
}

void RTC_SetYear(u8_t yr)
{
    CMOS_WriteData(RTC_YEAR_REG, yr);
}

void RTC_SetCentury(u8_t century)
{
    CMOS_WriteData(RTC_CENTURY_REG, century);
}

u8_t RTC_GetStatusA(void)
{
    return CMOS_ReadData(RTC_STATUS_A_REG);
}

u8_t RTC_GetStatusB(void)
{
    return CMOS_ReadData(RTC_STATUS_B_REG);
}