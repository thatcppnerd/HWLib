#include "../../include/ata/pata.h"
#include "../../include/macros.h"
#include "../../include/asm.h"

void PATA_400ns(int bus)
{
    u16_t io_base = ATA_GetBase(bus, ATA_IO_BASE);

    asm volatile
    (
        "movw %0, %%dx;"

        "inb %%dx, %%al;"
        "inb %%dx, %%al;"
        "inb %%dx, %%al;"
        "inb %%dx, %%al;"
        "inb %%dx, %%al;"

        "inb %%dx, %%al;"
        "inb %%dx, %%al;"
        "inb %%dx, %%al;"
        "inb %%dx, %%al;"
        "inb %%dx, %%al;"
        
        "inb %%dx, %%al;"
        "inb %%dx, %%al;"
        "inb %%dx, %%al;"
        "inb %%dx, %%al;"
        "inb %%dx, %%al;"
        
        :
        : "m" (io_base)
        : "dx", "al"
    );
}

ATA_Error_t PATA_GetError(int bus)
{
    return (ATA_Error_t)inb(ATA_GetBase(bus, ATA_IO_BASE) + ATA_REG_ERROR);
}

ATA_Status_t PATA_GetStatus(int bus)
{
    return (ATA_Status_t)inb(ATA_GetBase(bus, ATA_IO_BASE) + ATA_REG_STATUS);
}

void PATA_Nop(int bus)
{
    outb(ATA_GetBase(bus, ATA_IO_BASE), ATA_NOP);
}

void PATA_CacheFlush(int bus)
{
    u16_t io_base = ATA_GetBase(bus, ATA_IO_BASE);

    outb(io_base + ATA_REG_COMMAND, ATA_CACHE_FLUSH);

    // poll bsy

    while(PATA_GetStatus(bus).bsy);
}

void PATA_SoftwareReset(int bus)
{
    u16_t ctl_base = ATA_GetBase(bus, ATA_CTL_BASE);

    outb(ctl_base + ATA_REG_DEVICE_CTL, ATA_DEVICE_CTL_SRST);

    ATA_400ns();
	ATA_400ns();
	ATA_400ns();
	ATA_400ns();
	ATA_400ns();

	ATA_400ns();
	ATA_400ns();
	ATA_400ns();
	ATA_400ns();
	ATA_400ns();
    
	ATA_400ns();
	ATA_400ns();
	ATA_400ns();
	ATA_400ns();
	ATA_400ns();

    outb(ctl_base + ATA_REG_DEVICE_CTL, 0);
}

int PATA_ReadSectorsPIO(int bus, int drive, LBA_t lba, u8_t count, void* dest)
{
    // get bases
    register u16_t io_base = ATA_GetBase(bus, ATA_IO_BASE);
    register u16_t ctl_base = ATA_GetBase(bus, ATA_CTL_BASE);

    prsp_restart:

    PATA_Nop(bus);
        
    outb(io_base + ATA_REG_FEATURES, 0);
    outb(io_base + ATA_REG_SECTOR_COUNT, count);
    outb(io_base + ATA_REG_LBA_LO, lba & 0xFF);
    outb(io_base + ATA_REG_LBA_MID, (lba >> 8) & 0xFF);
    outb(io_base + ATA_REG_LBA_HI, (lba >> 16) & 0xFF);
    
    outb(io_base + ATA_REG_DRIVE_HEAD, 0xE0 | (drive != ATA_MASTER) ? 0x10 : 0x0 | (lba >> 24) & 0x0F);

    outb(io_base + ATA_REG_COMMAND, ATA_READ_PIO);
    ATA_400ns();



    u16_t timeout = 0;

    while(!PATA_GetStatus(bus).bsy) // wait for drive to respond with data
    {
        if(++timeout == 0) // check for hang
        {
            PATA_SoftwareReset(bus);
            
            goto prsp_restart; // NOOO
        }
    }

    // read data into memory
    for(int current_word = 0 ; current_word < 256 * (int)count ; current_word++)
    {
        ((u16_t*)dest)[current_word] = inw(io_base + ATA_REG_DATA);
    }

    return 0;
} 
