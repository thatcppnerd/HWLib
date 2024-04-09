#ifndef __ACPI_H__
#define __ACPI_H__

#include "../dev/types.h"
#include "../dev/dev.h"

typedef struct PACKED SDTHeader
{
    char signature[4];
    u32_t length;
    u8_t revision;
    u8_t checksum;
    char OEMID[6];
    char OEMTableID[8];
    u32_t OEMRevision;
    u32_t creatorID;
    u32_t creatorRevision;
} PACKED SDTHeader_t;

typedef struct PACKED GAS // Generic Address Structure
{
    u8_t addrSpace;
    u8_t bitWidth;
    u8_t bitOffset;
    u8_t accessSize;

    #ifdef __x86_64__
    u64_t addr;
    #else
    u32_t addrHigh, addrLow;
    #endif
} GAS_t;


typedef struct PACKED RSDT
{
    SDTHeader_t header;
    void* entry[];
} RSDT_t;

typedef struct PACKED RSDP
{
    char signature[8];
    u8_t checksum;
    char OEMID[6];
    u8_t revision;
    RSDT_t RSDTAddr;
} RSDP_t;

typedef struct PACKED FADT
{
    SDTHeader_t header;
    u32_t firmwareCtrl;
    void* DSDTAddr;

    u8_t intModel; // only used in ACPI v1.0, set to 0x01

    u8_t preferredPwrMngmntProfile;
    u16_t SCI_Interrupt; // int vector used by acpi (Global System Interrupt)
    u32_t SMICmdPort; // IO port addr used by acpi
    u8_t ACPIEnable; // Value that SMICmdPort will 
    u8_t ACPIDisable;
    u8_t S4BIOSReq;
    u8_t PSTATECtl;

    u32_t PM1a_EventBlk;
    u32_t PM1b_EventBlk;
    u32_t PM1a_CtlBlk;
    u32_t PM1b_CtlBlk;
    u32_t PM2CtlBlk;
    u32_t PMTimerBlk;
    
    u32_t GPE0_Blk;
    u32_t GPE1_Blk;

    u8_t PM1EventLen;
    u8_t PM1CtlLen;
    u8_t PM2CtlLen;
    u8_t PMTimerLen;

    u8_t GPE0_Len;
    u8_t GPE1_Len;
    u8_t GPE1_Base;

    u8_t CStateCtl;
    u16_t worstC2Latency;
    u16_t worstC3Latency;
    u16_t flushSize;
    u16_t flushStride;
    u8_t dutyOffset;
    u8_t dutyWidth;
    u8_t dayAlarm;
    u8_t monthAlarm;
    u8_t century;

    u16_t bootArchFlags;

    u8_t reserved2;
    u32_t flags;



} FADT_t;

void ACPI_enable();
void ACPI_disable();

void ACPI_cmd();

#endif