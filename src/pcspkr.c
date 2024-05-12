#include "../include/pcspkr.h"

void PCSPKR_Enable(void)
{
    PS2_SetCtlB(PS2_GetCtlB() | PS2_CTLB_SPKR_GATE | PS2_CTLB_SPKR_DATA);
}

void PCSPKR_Disable(void)
{
    PS2_SetCtlB(PS2_GetCtlB() & 0xFC);
}

void PCSPKR_SetFreq(unsigned int freq)
{
    u16_t count = PIT_GetFrequencyCount(freq);

    PIT_SetReloadValue(PIT_CH2, count);
}