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
#define PS2_OUTPUT_READ 0xD0            // PS/2 Output Port (Read port)
#define PS2_OUTPUT_WRITE 0xD1           // PS/2 Output Port (Write port)

// Commands for PS/2 Controller's command register

#define PS2_CMD_READ_CCB 0x20
#define PS2_CMD_WRITE_CCB 0x60
#define PS2_CMD_DISABLE_PORT2 0xA7
#define PS2_CMD_ENABLE_PORT2 0xA8
#define PS2_CMD_TEST_PORT2 0xA9
#define PS2_CMD_TEST_CTLR 0xAA
#define PS2_CMD_TEST_PORT1 0xAB
#define PS2_CMD_DUMP_RAM 0xAC
#define PS2_CMD_DISABLE_PORT1 0xAD
#define PS2_CMD_ENABLE_PORT1 0xAE
#define PS2_CMD_READ_INPUT 0xC0
#define PS2_CMD_CPY_IN_TO_STATUS_LN 0xC1 // Copy low nibble of input port to low nibble status
#define PS2_CMD_CPY_IN_TO_STATUS_HN 0xC2 // Copy high nibble of input port to high nibble status
#define PS2_CMD_READ_OUTPUT 0xD0
#define PS2_CMD_WRITE_OUTPUT 0xD1
#define PS2_CMD_WRITE_PORT1_OUT_BUF 0xD2
#define PS2_CMD_WRITE_PORT2_OUT_BUF 0xD3
#define PS2_CMD_WRITE_PORT2_IN_BUF 0xD4

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
        port1_int_enable : 1,
        port2_int_enable : 1,
        sys_flag : 1,
        zero1 : 1, 
        port1_clk_disable : 1,
        port2_clk_disable : 1,
        port1_port_translation : 1,
        zero2 : 1;
} PS2_ConfigByte_t;

// Enums

// System Control Port A 
enum PS2_CtlA_Flags
{
    PS2_CTLA_RESET =            0x01, // CPU Reset  
    PS2_CTLA_A20 =              0x02, // A20 Gate 
    
    // bit 2 is reserved

    PS2_CTLA_LOCK =             0x08, // Security Lock
    PS2_CTLA_WATCHDOG_TIMER =   0x10, // Watchdog Timer Status
    
    // bit 5 is reserved

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

u8_t PS2_readData(void);
void PS2_sendData(u8_t data);

u8_t PS2_getCtlA(void);
void PS2_setCtlA(u8_t val);

u8_t PS2_getCtlB(void);
void PS2_setCtlB(u8_t val);

u8_t PS2_getStatus();
void PS2_sendCommand(u8_t cmd);

u8_t PS2_getOutput(void);

u8_t PS2_readRAM(u8_t i);
void PS2_writeRAM(u8_t i, u8_t data);
#define PS2_getCtlConfigByte() PS2_readRAM(0)
#define PS2_setCtlConfigByte(data) PS2_writeRAM(0, data)



#endif