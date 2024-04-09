#ifndef __PIT_H__
#define __PIT_H__

#include "../dev/types.h"

#define PIT_OSC_FREQ 1193182 // Base oscilator frequency of PIT

// enums for PIT operating modes 

#define PIT_OPMODE_0 0  // Interupt on Terminal Count
#define PIT_OPMODE_1 1  // Hardware Re-triggerable One-Shot
#define PIT_OPMODE_2 2  // Rate Generator
#define PIT_OPMODE_3 3  // Square Wave Generator
#define PIT_OPMODE_4 4  // Software Triggered Strobe
#define PIT_OPMODE_5 5  // Hardware Triggered Strobe

// PIT channel enums

#define PIT_CH0 0
#define PIT_CH1 1
#define PIT_CH2 2

// PIT I/O ports

#define PIT_PORT_CH0_DATA   0x40
#define PIT_PORT_CH1_DATA   0x41
#define PIT_PORT_CH2_DATA   0x42
#define PIT_PORT_MC_REG     0x43 // to Mode/Command Register

// typedef struct PIT_ReadBack
// {
//     u8_t
//         BCD : 1,
//         operatingMode : 3,
//         accessMode : 2,
//         nullCount : 1,
//         outputPin : 1;
// } PIT_ReadBack_t;

void PIT_setReloadValue(u8_t channel, u16_t val);
u16_t PIT_getCurrentCount(u8_t channel);

void PIT_latchCount(u8_t channel);

void PIT_writeMCReg(u8_t data);


#endif