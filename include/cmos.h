#ifndef __CMOS_H__
#define __CMOS_H__

// CMOS Ports

#define CMOS_INDEX  0x70
#define CMOS_DATA   0x71

u8_t CMOS_ReadData(u8_t index);
void CMOS_WriteData(u8_t index, u8_t data);

#endif