#ifndef __PIT_H__
#define __PIT_H__

#include "types.h"

#define PIT_OSC_FREQ 1193182 // Base oscilator frequency of PIT

// enums for PIT operating modes 

#define PIT_M0          0x00  // Interupt on Terminal Count
#define PIT_M1          0x01  // Hardware Re-triggerable One-Shot
#define PIT_M2          0x02  // Rate Generator
#define PIT_M3          0x03  // Square Wave Generator
#define PIT_M4          0x04  // Software Triggered Strobe
#define PIT_M5          0x05  // Hardware Triggered Strobe

// PIT channel enums

#define PIT_CH0         0x00
#define PIT_CH1         0x01
#define PIT_CH2         0x02

// PIT I/O ports

#define PIT_CH0_DATA    0x40
#define PIT_CH1_DATA    0x41
#define PIT_CH2_DATA    0x42
#define PIT_CMD         0x43 

// typedef struct PIT_ReadBack
// {
//     u8_t
//         BCD : 1,
//         operatingMode : 3,
//         accessMode : 2,
//         nullCount : 1,
//         outputPin : 1;
// } PIT_ReadBack_t;

void PIT_SetReloadValue(u8_t channel, u16_t val);
u16_t PIT_GetCurrentCount(u8_t channel);

void PIT_LatchCount(u8_t channel);

void PIT_SendCommand(u8_t data);


#endif