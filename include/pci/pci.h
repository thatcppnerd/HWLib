#ifndef __PCI_H__
#define __PCI_H__

#include "../types.h"
#include "../macros.h"

enum PCI_Ports
{
    PCI_CONFIG_ADDRESS =        0xCF8,
    PCI_CONFIG_DATA =           0xCFC
};

u32_t   PCI_CreateConfigAddress(u8_t bus, u8_t slot, u8_t func, u8_t offset);

u8_t    PCI_Read8(u32_t addr);
u16_t   PCI_Read16(u32_t addr);
u32_t   PCI_Read32(u32_t addr);

void   PCI_Write8(u32_t addr, u8_t val);
void   PCI_Write16(u32_t addr, u16_t val);
void   PCI_Write32(u32_t addr, u32_t val);


#endif