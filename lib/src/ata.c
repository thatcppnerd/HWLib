#include "../include/hardware/ata.h"
#include "../include/dev/asm.h"

u8_t ata_getStatus()
{
    return inb(0x1F7);
}

u8_t ata_getError()
{
    return inb(0x1F1);
}

// on `bus`, select `drive` 
int	ATA_setSelectedDrive(ATA_bus_t bus, ATA_drive_t drive)
{	
	if(drive > 2) return 1;

	if(drive == ATA_getSelectedDrive(bus))
	{
		return 0;
	}

	if(bus == ATA_BUS0)
	{
		outb(ATA_BUS0_REG_DRVSEL, (inb(ATA_BUS0_REG_DRVSEL) & 0x10) | (ATA_getSelectedDrive(bus) * 0x10));
	}
	else if(bus == ATA_BUS1)
	{
		outb(ATA_BUS1_REG_DRVSEL, (inb(ATA_BUS1_REG_DRVSEL) & 0x10) | (ATA_getSelectedDrive(bus) * 0x10));
	}
	else
	{
		return 2;
	}

	return 0;
}

ATA_drive_t ATA_getSelectedDrive(ATA_bus_t bus)
{
	if(bus == ATA_BUS0) 
	{
		return ((inb(ATA_BUS0_REG_DRVSEL) & 0x10) >> 4);
	}
	else if(bus == ATA_BUS1)
	{
		return ((inb(ATA_BUS1_REG_DRVSEL) & 0x10) >> 4);
	}
	else return -1;
}


// generates (roughly) a 400 ns delay
void ATA_400ns_delay()
{
	// each read of status register is 30 ns long

	// 30 ns * 15 = 420 ns
	inb(0x1F7);
	inb(0x1F7);
	inb(0x1F7);
	inb(0x1F7);
	inb(0x1F7);

	inb(0x1F7);
	inb(0x1F7);
	inb(0x1F7);
	inb(0x1F7);
	inb(0x1F7);

	inb(0x1F7);
	inb(0x1F7);
	inb(0x1F7);
	inb(0x1F7);
	inb(0x1F7);

	return;

}

void ATA_softwareReset()
{
	outb(0x3F6, inb(0x3F6) | 0x04); // raise SRST

	// need 5 µs delay
	// 5000 ns / 400 ns = 13 DELAY FUNCTIONS
	
	ATA_400ns_delay();
	ATA_400ns_delay();
	ATA_400ns_delay();
	ATA_400ns_delay();
	ATA_400ns_delay();

	ATA_400ns_delay();
	ATA_400ns_delay();
	ATA_400ns_delay();
	ATA_400ns_delay();
	ATA_400ns_delay();

	ATA_400ns_delay();
	ATA_400ns_delay();
	ATA_400ns_delay();
	ATA_400ns_delay();
	ATA_400ns_delay();

	// okay these are 15 functions but it'll get the job done 

	outb(0x3F6, inb(0x3F6) - 0x04); // clear SRST

	return;
}

void ATA_flushCache()
{
	outb(0x1F7, ATA_CMD_CACHEFLUSH);

	u8_t status = 0;

	do
	{
		status = inb(0x1F7);
	}while(status & 0x80); // poll until BSY clears
}

u8_t ATA_pio_read(ATA_drive_t drive, LBA_t lba, u8_t count, void* dest)
{
	ata_pio_read_start:

    outb(0x1F7, 0x00); // clear command register
	ATA_400ns_delay();

	outb(0x1F6, 0xE0 | ((lba & 0x0F000000) >> 24) ); // select master drive on primary bus
		
	outb(0x1F1, 0);
	outb(0x1F1, 0);
	outb(0x1F2, 1); // sector count 
	outb(0x1F3, lba & 0x000000FF); // LBA address (Lo)
	outb(0x1F4, (lba & 0x0000FF00) >> 8); // LBA address (Mid)
	outb(0x1F5, (lba & 0x00FF0000) >> 16); // LBA address (Hi)

	outb(ATA_BUS0_REG_COMMAND, 0x20); // Send "READ SECTORS WITH RETRY" command
	ATA_400ns_delay();

    u8_t status = 0;
	u16_t check = 0;

    // poll status port until DRQ == HIGH and BSY == LOW
	do
	{
	    status = inb(ATA_BUS0_REG_STATUS);

        // detect fuck-ups
		if(status & 0x01 || status & 0x20)
		{
	 		// print error

			u8_t error_reg = inb(0x1F1);

			return error_reg; // return status of error register
		}

		if(status & 0x80 || !(status & 0x08)) 
		{
			if(count == 0xFFFF)
			{
				ATA_softwareReset();
				count = 0;

				goto ata_pio_read_start;

			}
			count++;
			continue;
		}
		break;
	}
	while(1);

    for(int a = 0 ; a < 256 ; a++)
    {
        ((u16_t*)dest)[a] = inw(0x1F0);
    }
	ATA_400ns_delay();

    return 0; // exit with no errors (thank fuck)
}

u8_t ATA_pio_write(ATA_drive_t drive, LBA_t lba, u8_t count, void* src)
{
	outb(0x1F7, 0x00); // clear command register
	
	outb(0x1F6, 0xE0 | ((lba & 0x0F000000) >> 24) ); // append extra bits of LBA
		
	outb(0x1F1, 0);
	outb(0x1F2, count); // sector count 
	outb(0x1F3, lba & 0x000000FF); // LBA address (Lo)
	outb(0x1F4, (lba & 0x0000FF00) >> 8); // LBA address (Mid)
	outb(0x1F5, (lba & 0x00FF0000) >> 16); // LBA address (Hi)

	outb(ATA_BUS0_REG_COMMAND, 0x30); // Send "READ SECTORS WITH RETRY" command

    u8_t status = 0;

    // poll status port until DRQ == HIGH and BSY == LOW
	do
	{
	    status = inb(ATA_BUS0_REG_STATUS);

        // detect fuck-ups
		if(status & 0x01 || status & 0x20)
		{
	 		// print error

			u8_t error_reg = inb(0x1F1);

			return error_reg; // return status of error register
		}
	}
	while(status & 0x80 || !(status & 0x08));

    for(int a = 0 ; a < 256 * count ; a++)
    {
        outw(0x1F0, ((u16_t*)src)[a]);
		ATA_400ns_delay();
    }
	ATA_400ns_delay();

	ATA_flushCache();





    return 0; // exit with no errors (thank fuck)
}