#ifndef __PCI_H__
#define __PCI_H__

#include "../../dev/types.h"

#include "header.h"

#pragma region MACROS

#define PCI_CONFIG_ADDRESS  0xCF8
#define PCI_CONFIG_DATA     0xCFC

#define PCI_CONFIG_REG(reg) (reg * 4)

#ifdef __cplusplus
extern "C"
{
#endif

#pragma endregion MACROS

typedef u32_t PCI_ConfigAddr_t;

u32_t PCI_CreateConfigAddress(u8_t bus, u8_t slot, u8_t func, u8_t offset);


u8_t PCI_ReadConfig8(u8_t bus, u8_t slot, u8_t func, u8_t offset);
u16_t PCI_ReadConfig16(u8_t bus, u8_t slot, u8_t func, u8_t offset);
u32_t PCI_ReadConfig32(u8_t bus, u8_t slot, u8_t func, u8_t offset);

void PCI_WriteConfig8(u8_t bus, u8_t slot, u8_t func, u8_t offset, u8_t data);
void PCI_WriteConfig16(u8_t bus, u8_t slot, u8_t func, u8_t offset, u16_t data);
void PCI_WriteConfig32(u8_t bus, u8_t slot, u8_t func, u8_t offset, u32_t data);


u16_t PCI_GetVendorID(u8_t bus, u8_t slot);
u16_t PCI_GetDeviceID(u8_t bus, u8_t slot);
u16_t PCI_GetCommandReg(u8_t bus, u8_t slot);
void PCI_SetCommandReg(u8_t bus, u8_t slot, u16_t data);
u16_t PCI_GetStatus(u8_t bus, u8_t slot);

u8_t PCI_GetRevisionID(u8_t bus, u8_t slot);
u8_t PCI_GetProgIF(u8_t bus, u8_t slot);
u8_t PCI_GetSubclass(u8_t bus, u8_t slot);
u8_t PCI_GetClassCode(u8_t bus, u8_t slot);

u8_t PCI_GetCacheLineSize(u8_t bus, u8_t slot);
u8_t PCI_GetHeaderType(u8_t bus, u8_t slot);
u8_t PCI_GetLatencyTimer(u8_t bus, u8_t slot);
u8_t PCI_GetBIST(u8_t bus, u8_t slot);

#pragma region HEADER0
u8_t PCI_H0_GetBAR0(u8_t bus, u8_t slot);
u8_t PCI_H0_GetBAR1(u8_t bus, u8_t slot);
u8_t PCI_H0_GetBAR2(u8_t bus, u8_t slot);
u8_t PCI_H0_GetBAR3(u8_t bus, u8_t slot);
u8_t PCI_H0_GetBAR4(u8_t bus, u8_t slot);
u8_t PCI_H0_GetBAR5(u8_t bus, u8_t slot);

u32_t PCI_H0_GetCISPointer(u8_t bus, u8_t slot);
u16_t PCI_H0_GetSubsystemVendorID(u8_t bus, u8_t slot);
u16_t PCI_H0_GetSubsystemID(u8_t bus, u8_t slot);
u32_t PCI_H0_GetExpansionROMBaseAddress(u8_t bus, u8_t slot);
void PCI_H0_SetExpansionROMBaseAddress(u8_t bus, u8_t slot, u32_t data);
u8_t PCI_H0_GetCapabilitiesPointer(u8_t bus, u8_t slot);
u8_t PCI_H0_GetInterruptLine(u8_t bus, u8_t slot);
void PCI_H0_SetInterruptLine(u8_t bus, u8_t slot);
u8_t PCI_H0_GetInterruptPin(u8_t bus, u8_t slot);
u8_t PCI_H0_GetMinGrant(u8_t bus, u8_t slot);
u8_t PCI_H0_GetMaxLatency(u8_t bus, u8_t slot);
#pragma endregion HEADER0


#pragma region HEADER1
#pragma endregion HEADER1

#pragma region HEADER2
#pragma endregion HEADER2


#ifdef __cplusplus
}
#endif


#endif