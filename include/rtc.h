#ifndef __RTC_H__
#define __RTC_H__

#define RTC_BASE_FREQ 32768

enum RTC_CMOSAddress
{
    RTC_STATUS_REG_A = 0x8A,
    RTC_STATUS_REG_B = 0x8B,
    RTC_STATUS_REG_C = 0x8C
};

#endif