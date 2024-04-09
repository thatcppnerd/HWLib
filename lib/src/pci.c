#include "../include/hardware/pci/pci.h"
#include "../include/dev/asm.h"


u8_t PCI_ReadConfig8(u8_t bus, u8_t slot, u8_t func, u8_t offset)
{
    // Create configuration address
    u32_t addr = PCI_CreateConfigAddress(bus, slot, func, offset);

    // Write config addr
    outb(PCI_CONFIG_ADDRESS, addr);

    // Get register data
    return indw(PCI_CONFIG_DATA) >> 24;
}

u16_t PCI_ReadConfig16(u8_t bus, u8_t slot, u8_t func, u8_t offset)
{
    // Create configuration address
    u32_t addr = PCI_CreateConfigAddress(bus, slot, func, offset);

    // Write config addr
    outw(PCI_CONFIG_ADDRESS, addr);

    // Get register data
    return (u16_t)(indw(PCI_CONFIG_DATA));
}

u32_t PCI_ReadConfig32(u8_t bus, u8_t slot, u8_t func, u8_t offset)
{
    // Create configuration address
    u32_t addr = PCI_CreateConfigAddress(bus, slot, func, offset);

    // Write config addr
    outdw(PCI_CONFIG_ADDRESS, addr);

    // Get register data
    return indw(PCI_CONFIG_DATA);
}

void PCI_WriteConfig8(u8_t bus, u8_t slot, u8_t func, u8_t offset, u8_t data)
{
    // Create configuration address
    u32_t addr = PCI_CreateConfigAddress(bus, slot, func, offset);

    // Write config addr
    outdw(PCI_CONFIG_ADDRESS, addr);

    // Send data to register 
    outb(PCI_CONFIG_DATA, data);
}

void PCI_WriteConfig16(u8_t bus, u8_t slot, u8_t func, u8_t offset, u16_t data)
{
    // Create configuration address
    u32_t addr = PCI_CreateConfigAddress(bus, slot, func, offset);

    // Write config addr
    outdw(PCI_CONFIG_ADDRESS, addr);

    // Send data to register 
    outw(PCI_CONFIG_DATA, data);
}

void PCI_WriteConfig32(u8_t bus, u8_t slot, u8_t func, u8_t offset, u32_t data)
{
    // Create configuration address
    u32_t addr = PCI_CreateConfigAddress(bus, slot, func, offset);

    // Write config addr
    outdw(PCI_CONFIG_ADDRESS, addr);

    // Send data to register 
    outdw(PCI_CONFIG_DATA, data);
}

u32_t PCI_CreateConfigAddress(u8_t bus, u8_t slot, u8_t func, u8_t offset)
{
    return
    (
        0x80000000 | \
        (((u32_t)bus) << 16) | \
        (((u32_t)slot) << 11) | \
        (((u32_t)func) << 8) | \
        (u32_t)offset
    );
}

u16_t PCI_GetVendorID(u8_t bus, u8_t slot)
{
    return PCI_ReadConfig16(bus, slot, 0, PCI_CONFIG_REG(0));
}

u16_t PCI_GetDeviceID(u8_t bus, u8_t slot)
{
    return PCI_ReadConfig16(bus, slot, 0, PCI_CONFIG_REG(0) + 2);
}

u16_t PCI_GetCommandReg(u8_t bus, u8_t slot)
{
    return PCI_ReadConfig16(bus, slot, 0, PCI_CONFIG_REG(1));
}

void PCI_SetCommandReg(u8_t bus, u8_t slot, u16_t data)
{
    PCI_WriteConfig16(bus, slot, 0, PCI_CONFIG_REG(1), data);
}

u16_t PCI_GetStatus(u8_t bus, u8_t slot)
{
    return PCI_ReadConfig16(bus, slot, 0, PCI_CONFIG_REG(1) + 2);
}

u8_t PCI_GetRevisionID(u8_t bus, u8_t slot)
{
    return PCI_ReadConfig8(bus, slot, 0, PCI_CONFIG_REG(2));
}

u8_t PCI_GetProgIF(u8_t bus, u8_t slot)
{
    return PCI_ReadConfig8(bus, slot, 0, PCI_CONFIG_REG(2) + 1);
}

u8_t PCI_GetSubclass(u8_t bus, u8_t slot)
{
    return PCI_ReadConfig8(bus, slot, 0, PCI_CONFIG_REG(2) + 2);
}

u8_t PCI_GetClassCode(u8_t bus, u8_t slot)
{
    return PCI_ReadConfig8(bus, slot, 0, PCI_CONFIG_REG(2) + 3);
}

u8_t PCI_GetCacheLineSize(u8_t bus, u8_t slot)
{
    return PCI_ReadConfig8(bus, slot, 0, PCI_CONFIG_REG(3));
}

u8_t PCI_GetLatencyTimer(u8_t bus, u8_t slot)
{
    return PCI_ReadConfig8(bus, slot, 0, PCI_CONFIG_REG(3) + 1);
}

u8_t PCI_GetHeaderType(u8_t bus, u8_t slot)
{
    return PCI_ReadConfig8(bus, slot, 0, PCI_CONFIG_REG(3) + 2);
}

u8_t PCI_GetBIST(u8_t bus, u8_t slot)
{
    return PCI_ReadConfig8(bus, slot, 0, PCI_CONFIG_REG(3) + 3);
}