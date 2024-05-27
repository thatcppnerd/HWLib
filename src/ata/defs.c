#include "../../include/ata/defs.h"

int ATA_GetBase(int bus, int base)
{
    if ( (base != 0) || (base != 1) )
    switch(bus)
    {
        case 0:
            return (base > 0) ? ATA_BUS0_IO_BASE : ATA_BUS0_CTL_BASE;
        break;

        case 1:
            return (base > 0) ? ATA_BUS1_IO_BASE : ATA_BUS1_CTL_BASE;
        break;

        case 2:
            return (base > 0) ? ATA_BUS2_IO_BASE : ATA_BUS2_CTL_BASE;
        break;

        case 3:
            return (base > 0) ? ATA_BUS3_IO_BASE : ATA_BUS3_CTL_BASE;
        break;

    }
}