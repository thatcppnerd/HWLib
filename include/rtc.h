#ifndef __RTC_H__
#define __RTC_H__

#define RTC_BASE_FREQ 32768

enum RTC_CMOSAddress
{
    RTC_SECOND_REG =    0x00,
    RTC_MINUTE_REG =    0x02,
     
    RTC_STATUS_REG_A =  0x0A,
    RTC_STATUS_REG_B =  0x0B,
    RTC_STATUS_REG_C =  0x0C
};

#endif