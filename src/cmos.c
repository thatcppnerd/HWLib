#include "../include/cmos.h"

u8_t CMOS_ReadData(u8_t index)
{
	cli();
	outb(CMOS_INDEX, index);
	io_wait();
	sti();
	return inb(CMOS_DATA);
}

void CMOS_WriteData(u8_t index, u8_t data)
{
	cli();
	outb(CMOS_INDEX, index);
	io_wait();
	outb(CMOS_DATA, data);
	sti();
}

