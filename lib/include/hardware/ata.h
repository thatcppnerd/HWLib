#ifndef __ATA_H__
#define __ATA_H__

#include "types.h"
#include "asm.h"

#pragma region ATA_macros

#define ATA_ERROR_AMNF      0x01
#define ATA_ERROR_TKZKF     0x02
#define ATA_ERROR_ABRT      0x04
#define ATA_ERROR_MCR       0x08
#define ATA_ERROR_IDNF      0x10
#define ATA_ERROR_MC        0x20
#define ATA_ERROR_UNC       0x40
#define ATA_ERROR_BBK       0x80

#define ATA_STATUS_ERR      0x01
#define ATA_STATUS_IDX      0x02
#define ATA_STATUS_CORR     0x04
#define ATA_STATUS_DRQ      0x08
#define ATA_STATUS_SRV      0x10
#define ATA_STATUS_DF       0x20
#define ATA_STATUS_RDY      0x40
#define ATA_STATUS_BSY      0x80


// ATA Primary Bus (BUS 0) Registers(I/O)

#define ATA_BUS0_REG_DATA             0x1F0
#define ATA_BUS0_REG_ERROR            0x1F1
#define ATA_BUS0_REG_FEATURES         0x1F1
#define ATA_BUS0_REG_SECTORCOUNT      0x1F2
#define ATA_BUS0_REG_LBA_LO           0x1F3
#define ATA_BUS0_REG_CHS_SECTOR       0x1F3
#define ATA_BUS0_REG_LBA_MID          0x1F4
#define ATA_BUS0_REG_CHS_TRACK_LOW    0x1F4
#define ATA_BUS0_REG_LBA_HI           0x1F5
#define ATA_BUS0_REG_CHS_TRACK_HIGH   0x1F5
#define ATA_BUS0_REG_DRVSEL           0x1F6
#define ATA_BUS0_REG_CHS_HEAD         0x1F6
#define ATA_BUS0_REG_LBA_EXTRA        0x1F6
#define ATA_BUS0_REG_STATUS           0x1F7
#define ATA_BUS0_REG_COMMAND          0x1F7

// ATA Primary Bus*(BUS 0) Registers(Control)

#define ATA_BUS0_REG_ALT_STATUS       0x3F6
#define ATA_BUS0_REG_DEVICE_CTRL      0x3F6
#define ATA_BUS0_REG_DRV_ADDRESS      0x3F7


// ATA Secondary Bus (BUS 1) Registers (I/O)

#define ATA_BUS1_REG_DATA               0x170
#define ATA_BUS1_REG_ERROR              0x171
#define ATA_BUS1_REG_FEATURES           0x171
#define ATA_BUS1_REG_SECTORCOUNT        0x172
#define ATA_BUS1_REG_LBA_LO             0x173
#define ATA_BUS1_REG_CHS_SECTOR         0x173
#define ATA_BUS1_REG_LBA_MID            0x174
#define ATA_BUS1_REG_CHS_TRACK_LOW      0x174
#define ATA_BUS1_REG_LBA_HI             0x175
#define ATA_BUS1_REG_CHS_TRACK_HIGH     0x175
#define ATA_BUS1_REG_DRVSEL             0x176
#define ATA_BUS1_REG_CHS_HEAD           0x176
#define ATA_BUS1_REG_LBA_EXTRA          0x176
#define ATA_BUS1_REG_STATUS             0x177
#define ATA_BUS1_REG_COMMAND            0x177

// ATA Secondary Bus (BUS 1) Registers(Control)

#define ATA_BUS1_REG_ALT_STATUS         0x3F6
#define ATA_BUS1_REG_DEVICE_CTRL        0x3F6
#define ATA_BUS1_REG_DRV_ADDRESS        0x3F7

#define ATA_BUS0            0
#define ATA_BUS1            1
#define ATA_BUS2            2
#define ATA_BUS3            3

#define ATA_DRIVE_MASTER    0
#define ATA_DRIVE_SLAVE     1

#pragma endregion ATA_macros

typedef udword_t    LBA_t;

typedef ubyte_t     ATA_error_t;
typedef ubyte_t     ATA_status_t;
typedef ubyte_t     ATA_drive_t;
typedef ubyte_t     ATA_bus_t;

typedef enum ATA_cmd
{
    ATA_CMD_NOP         = 0x00,
    ATA_CMD_CACHEFLUSH  = 0xE7,
    ATA_CMD_IDENTIFY    = 0xEC
} ATA_cmd_t;


/// @brief Wrapper for packet returned from IDENTIFY command
typedef struct ATA_identify_packet
{
    uword_t data [256];
} ATA_identify_packet_t;

/**
 * @brief Read Status Register of currently selected drive on `bus`.
 * @param bus Index of bus. (0 - 3)
 * @return The value of the Status Register of the currently selected drive on `bus`.
*/
ATA_status_t    ATA_getStatus(ATA_bus_t bus);

/**
 * @brief Read Error Register of currently selected drive on `bus`.
 * @param bus Index of bus. (0 - 3)
 * @return The value of the Error Register of the currently selected drive on 'bus'.
*/
ATA_error_t     ATA_getError(ATA_bus_t bus);



int             ATA_setSelectedDrive(ATA_bus_t bus, ATA_drive_t drive);
ATA_drive_t     ATA_getSelectedDrive(ATA_bus_t bus);

/// @brief Performs a software reset
void            ATA_softwareReset();

/// @brief Runs Cache Flush Command on ATA drive 
void            ATA_flushCache();
void            ATA_identify();

ubyte_t         ATA_pio_read(ATA_drive_t drive, LBA_t lba, ubyte_t count, void* dest);
ubyte_t         ATA_pio_write(ATA_drive_t drive, LBA_t lba, ubyte_t count, void* src);


// Generates delay for commands.
void            ATA_400ns_delay();

#endif