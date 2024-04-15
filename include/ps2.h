#ifndef __PS_2_H__
#define __PS_2_H__

#include "types.h"
#include "asm.h"

// Ports for PS/2 Controller

#define PS2_DATA 0x60                   // PS/2 Data Port
#define PS2_CTLA 0x92                   // PS/2 System Control Port A
#define PS2_CTLB 0x61                   // PS/2 System Control Port B
#define PS2_STATUS 0x64                 // PS/2 Status Port
#define PS2_CMD 0x64                    // PS/2 Command Port


// Types for data structures in PS/2 Controller

typedef struct PS2_Status
{
    u8_t 
        out_buf : 1,
        in_buf : 1,
        sys : 1,
        cmd_data : 1,
        u1 : 1,
        u2 : 1,
        timeout : 1,
        parity : 1;
} PS2_Status_t;

// Wrapper for CCB(Controller Config Byte)
typedef struct PS2_ConfigByte
{
    u8_t
        port1_int : 1,
        port2_int : 1,
        system : 1,
        : 1, 
        port1_clk : 1,
        port2_clk : 1,
        port1_trans : 1,
        : 1;
} PS2_ConfigByte_t;

typedef struct PS2_Output
{
    u8_t
        sys_reset : 1,
        a20 : 1,
        port2_clk : 1,
        port2_data : 1,
        port1_full : 1,
        port2_full : 1,
        port1_clk : 1,
        port1_data : 1 
} PS2_Output_t;

// Enums

// System Control Port A 
enum PS2_CtlA_Flags
{
    PS2_CTLA_RESET =            0x01, // CPU Reset  
    PS2_CTLA_A20 =              0x02, // A20 Gate 
    PS2_CTLA_LOCK =             0x08, // Security Lock
    PS2_CTLA_WATCHDOG_TIMER =   0x10, // Watchdog Timer Status
    PS2_CTLA_HDD2 =             0x40, // HDD 2 Drive Activity
    PS2_CTLA_HDD1 =             0x80  // HDD 1 Drive Activity
};

// System Control Port B
enum PS2_CtlB_Flags
{
    PS2_CTLB_SPKR_GATE =    0x01, // PIT Ch.2 speaker input enabled
    PS2_CTLB_SPKR_DATA =    0x02, // Speaker Data Enable
    PS2_CTLB_PARITY_CHECK = 0x04, // Parity Data Enable
    PS2_CTLB_CH_CHECK =     0x08, // Chammel Check Enable
    PS2_CTLB_REFRESH =      0x10, // Refresh Request
    PS2_CTLB_TIMER2 =       0x20, // Timer 2 Output
    PS2_CTLB_CHANNEL =      0x40, // Channel Check 
    PS2_CTLB_PARITY =       0x80  // Parity Check
};


// Functions

#define PS2_pollInputBuf() while(PS2_getStatus() & 0x02)
#define PS2_pollOutputBuf() while(PS2_getStatus() ^ 0x01)

u8_t PS2_readData(void);
void PS2_sendData(u8_t data);

u8_t PS2_getCtlA(void);
void PS2_setCtlA(u8_t val);

u8_t PS2_getCtlB(void);
void PS2_setCtlB(u8_t val);

u8_t PS2_getStatus();
void PS2_sendCommand(u8_t cmd);

// PS2 Commands

u8_t PS2_readRAM(u8_t i);
void PS2_writeRAM(u8_t i, u8_t data);
#define PS2_getCtlConfigByte() PS2_readRAM(0)
#define PS2_setCtlConfigByte(data) PS2_writeRAM(0, data)

#define PS2_disablePort2() PS2_sendCommand(0xA7)
#define PS2_enablePort2() PS2_sendCommand(0xA8)
int PS2_testPort2(void);
int PS2_testController(void);
int PS2_testPort1(void);
void PS2_dumpRAM(void* buf);
#define PS2_disablePort1() PS2_sendCommand(0xAD)
#define PS2_enablePort1() PS2_sendCommand(0xAE)
u8_t PS2_readInputPort(void);

// skipping commands 0xC1 and 0xC2 bc they're weird

u8_t PS2_readOutputPort(void);
void PS2_writeOutputPort(u8_t val);


#endif