#include "../../include/interrupts/pcspkr.h"

int pcspkr_play_tone(u32_t freq, u32_t duration)
{
    u32_t retval;

    asm volatile
    (
        "mov $0x00, %%eax;"
        "mov %1, %%esi;"
        "mov %2, %%edi;"
        "int $0x25;"
        "mov %%eax, %0;"

        :"=m"(retval)
        :"m"(freq), "m"(duration)
        :"eax","esi","edi"
    );

    return retval;
}

void pcspkr_stop_tone(void)
{
    asm volatile
    (
        "mov $0x01, %%eax;"
        "int $0x25;"
        :
        :
        :"eax"
    );
}