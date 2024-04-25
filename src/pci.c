#include "../include/pci/pci.h"

#include "../include/pci/macros.h"
#include "../include/pci/asm.h"

u32_t PCI_CreateConfigAddress(u8_t bus, u8_t slot, u8_t func, u8_t offset)
{
    u32_t addr = 0;

    addr |= bus;

    addr <<= 5; // make space
    addr |= slot & 0x1F;

    addr <<= 3; // make space
    addr |= (func & 0x07);

    addr <<= 8; // make space
    addr |= offset;

    addr |= 0x80000000;

    return addr;
}

void PCI_SetConfigAddress(u32_t addr)
{
    outdw(PCI_CONFIG_ADDRESS, addr);
    io_wait();
}

u32_t PCI_GetConfigData(void)
{
    u32_t data = outdw(PCI_CONFIG_DATA);
    io_wait();
    return data;
}

void PCI_SetConfigData(u32_t data)
{
    outdw(PCI_CONFIG_DATA, data);
    io_wait();
}

u32_t PCI_SetConfigAddress();

u8_t PCI_Read8(u32_t addr)
{
    outdw(PCI_CONFIG_ADDRESS, addr - (addr % 4));
    io_wait();
    
    u32_t tmp = indw(PCI_CONFIG_DATA);

    return *((u8_t*)(&tmp + (addr % 4)));
}

u16_t PCI_Read16(u32_t addr)
{
    outdw(PCI_CONFIG_ADDRESS, addr - (addr % 4));
    io_wait();

    u32_t tmp = indw(PCI_CONFIG_DATA);

    return *((u16_t*)(&tmp + (addr % 3)));
}

u32_t PCI_Read32(u32_t addr)
{
    outdw(PCI_CONFIG_ADDRESS, addr);
    io_wait();
    return indw(PCI_CONFIG_DATA);
}


void PCI_Write8(u32_t addr, u8_t val)
{
    u32_t newReg = PCI_Read32(addr - (addr % 4));

    outdw(PCI_CONFIG_ADDRESS, addr - (addr % 4));
    io_wait();
    
    ((u8_t*)&newReg)[addr % 4] = val;

    outdw(PCI_CONFIG_DATA, newReg);
    io_wait();
}

void PCI_Write16(u32_t addr, u16_t val)
{
    u32_t newReg = PCI_Read32(addr - (addr % 4));

    outdw(PCI_CONFIG_ADDRESS, addr - (addr % 4));
    io_wait();

    ((u16_t*)&newReg)[(addr / 2) % 2] = val;

    outdw(PCI_CONFIG_DATA, newReg);
    
}

void PCI_Write32(u32_t addr, u32_t val)
{
    outdw(PCI_CONFIG_ADDRESS, addr);
    io_wait();
    outdw(PCI_CONFIG_DATA, val);
}