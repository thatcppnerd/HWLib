#ifndef __PCI_H__
#define __PCI_H__

#include "../types.h"

#include "config_space.h"

#if !(defined(__PCI_OLD_H__) || defined(__PCI_MMIO_H__))

enum PCI_Ports
{
    PCI_CONFIG_ADDRESS =        0xCF8,
    PCI_CONFIG_FORWARDING =     0xCFA,
    PCI_CONFIG_DATA =           0xCFC
};

u32_t   PCI_CreateConfigAddress(u8_t bus, u8_t slot, u8_t func, u8_t offset);

u32_t   PCI_GetConfigAddress(void);
void    PCI_SetConfigAddress(u32_t addr);

u32_t   PCI_GetConfigData(void);
void    PCI_SetConfigData(u32_t data);

u8_t    PCI_Read8(u32_t addr);
u16_t   PCI_Read16(u32_t addr);
u32_t   PCI_Read32(u32_t addr);

void    PCI_Write8(u32_t addr, u8_t val);
void    PCI_Write16(u32_t addr, u16_t val);
void    PCI_Write32(u32_t addr, u32_t val);


#else
#pragma error("WARNING: Use of multiple PCI versions detected.")
#endif

#endif