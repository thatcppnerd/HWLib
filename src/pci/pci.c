#include "../../include/pci/pci.h"


u32_t PCI_CreateConfigAddress(u8_t bus, u8_t slot, u8_t func, u8_t offset)
{
    u32_t addr = (0x00000001 << 15);

    addr |= bus;
    addr <<= 5; // make space

    addr |= slot & 0x1F;
    addr <<= 3; // make space

    addr |= (func & 0x07);
    addr <<= 8; // make space

    addr |= offset;

    return addr;
}

u32_t PCI_Read32(u32_t addr)
{
    outdw(PCI_CONFIG_ADDRESS, addr);
    io_wait();
    return indw(PCI_CONFIG_DATA);
}