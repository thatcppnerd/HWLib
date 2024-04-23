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

u8_t RTC_GetStatusA(void)
{
    return CMOS_ReadData(RTC_STATUS_A_REG);
}

u8_t RTC_GetStatusB(void)
{
    return CMOS_ReadData(RTC_STATUS_B_REG);
}