#ifndef __ISA_H__
#define __ISA_H__

#include "types.h"


const u8_t ISA_Key[32] =
{
    0x6A, 0xB5, 0xDA, 0xED, 0xF6, 0xFB, 0x7D, 0xBE,
    0xDF, 0x6F, 0x37, 0x1B, 0x0D, 0x86, 0xC3, 0x61,
    0xB0, 0x58, 0x2C, 0x16, 0x8B, 0x45, 0xA2, 0xD1,
    0xE8, 0x74, 0x3A, 0x9D, 0xCE, 0xE7, 0x73, 0x39
};

// Current value
const u16_t ISA_DATA_READ;

enum ISA_Ports
{
    ISA_ADDRESS =       0x279,
    ISA_DATA_WRITE =    0xA79
};

enum ISA_ControlSpaceRegs
{
    ISA_SET_READ_DATA =     0x00,
    ISA_SERIAL_ISOLATION =  0x01,
    ISA_CONFIG_CTL =        0x02,
    ISA_WAKE =              0x03,
    ISA_RESOURCE_DATA =     0x04,
    ISA_STATUS =            0x05,
    ISA_CARD_SEL_NUM =      0x06,
    ISA_LOGICAL_DEVICE =    0x07
};

#define ISA_GetDataReadPort() (ISA_DATA_READ)
void    ISA_SetDataReadPort(u16_t port);

// TODO: Serial Isolation Funcs

#endif