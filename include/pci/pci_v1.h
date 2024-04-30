#ifndef __PCI_V1_H__
#define __PCI_V1_H__

#include "../types.h"
#include "../macros.h"

#include "config_space.h"

#if !(defined(__PCI_V2_H__) || defined(__PCI_V3_H__))

enum PCI_Ports
{
    PCI_CONFIG_ADDRESS =        0xCF8,
    PCI_CONFIG_FORWARDING =     0xCFA,
    PCI_CONFIG_DATA =           0xCFC
};

u16_t PCI_CreateConfigPort(u8_t device, u8_t offset);

#else
#pragma message("WARNING: Use of multiple PCI versions detected.")
#endif

#endif