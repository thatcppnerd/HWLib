#ifndef __PCSPKR_H__
#define __PCSPKR_H__

#include "types.h"
#include "ps2.h"
#include "pit.h"


void PCSPKR_Enable(void);
void PCSPKR_Disable(void);

void PCSPKR_SetFreq(unsigned int freq);



#endif