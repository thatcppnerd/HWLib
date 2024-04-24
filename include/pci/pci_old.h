#ifndef __PCI_OLD_H__
#define __PCI_OLD_H__

#include "../types.h"
#include "../macros.h"

#include "config_space.h"

#if defined(__PCI_H__) || defined (__PCI_MMIO_H__)

enum PCI_Ports
{
    PCI_CONFIG_ADDRESS =        0xCF8,
    PCI_CONFIG_FORWARDING =     0xCFA,
    PCI_CONFIG_DATA =           0xCFC
};



#endif

#endif