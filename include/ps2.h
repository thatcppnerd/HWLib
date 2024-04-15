#ifndef __PS_2_H__
#define __PS_2_H__

#include "types.h"
#include "asm.h"

// Ports for PS/2 Controller

#define PS2_DATA 0x60
#define PS2_CTL_A 0x92
#define PS2_CTL_B 0x61
#define PS2_STATUS 0x64
#define PS2_CMD 0x64

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
typedef union PS2_ConfigByte
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
    
    u8_t byte;
} PS2_ConfigByte_t;

// Functions

u8_t PS2_getCtlA(void);
void PS2_setCtlA(u8_t val);

u8_t PS2_getCtlB(void);
void PS2_setCtlB(u8_t val);

u8_t PS2_getStatus();
void PS2_sendCmd(u8_t cmd);

u8_t PS2_readByte(u8_t n);
void PS2_writeByte(u8_t n, u8_t val);
void PS2_togglePort(u8_t port, u8_t toggle);

void PS2_enablePort1();
void PS2_disablePort1();
void PS2_enablePort2();
void PS2_disablePort2();

void PS2_testPort(u8_t port);
void PS2_testController();
void PS2_writeOutputBuffer();

// Enums
enum PS2_CtlA_Flags
{
    PS2_CTLA_
};

enum PS2_CtlB_Flags
{
    PS2_CTLB_SPKR_GATE =    0x01,
    PS2_CTLB_SPKR_DATA =    0x02,
    PS2_CTLB_PARITY_CHECK = 0x04,
    PS2_CTLB_CH_CHECK =     0x08
};

#endif