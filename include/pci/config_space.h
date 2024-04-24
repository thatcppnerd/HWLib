#ifndef __CONFIG_SPACE_H__ 
#define __CONFIG_SPACE_H__

enum PCI_CFG_Offsets
{
    PCI_CFG_DEVICE_ID =         0x00,
    PCI_CFG_VENDOR_ID =         0x02,
    PCI_CFG_STATUS =            0x04,
    PCI_CFG_COMMAND =           0x06,
    PCI_CFG_CLASS =             0x08,
    PCI_CFG_SUBCLASS =          0x09,
    PCI_CFG_PROGIF =            0x0A,
    PCI_CFG_REVISION_ID =       0x0B,
    PCI_CFG_BIST =              0x0C,
    PCI_CFG_HEADER_TYPE =       0x0D,
    PCI_CFG_LATENCY_TIMER =     0x0E,
    PCI_CFG_CACHELINE_SIZE =    0x0F
};

enum PCI_CFG0_Offsets
{
    PCI_CFG0_BAR0 =                 0x10,
    PCI_CFG0_BAR1 =                 0x14,
    PCI_CFG0_BAR2 =                 0x18,
    PCI_CFG0_BAR3 =                 0x1C,
    PCI_CFG0_BAR4 =                 0x20,
    PCI_CFG0_BAR5 =                 0x24,
    PCI_CFG0_CARDBUS_CIS_PTR =      0x28,
    PCI_CFG0_SUBSYSTEM_ID =         0x2C,
    PCI_CFG0_SUBSYSTEM_VENDOR_ID =  0x2E,
    PCI_CFG0_EXP_ROM_BASE_ADDR =    0x30,
    PCI_CFG0_CAPABILITIES_PTR =     0x37,
    PCI_CFG0_MAX_LATENCY =          0x3C,
    PCI_CFG0_MIN_GRANT =            0x3D,
    PCI_CFG0_INT_PIN =              0x3E,
    PCI_CFG0_INT_LINE =             0x3F
};

enum PCI_CFG1_Offsets
{
    PCI_CFG1_BAR0 =                         0x10,
    PCI_CFG1_BAR1 =                         0x14,
    PCI_CFG1_SECONDARY_LATENCY_TIMER =      0x18,
    PCI_CFG1_SUBORDINATE_BUS_NUMBER =       0x19,
    PCI_CFG1_SECONDARY_BUS_NUMBER =         0x1A,
    PCI_CFG1_PRIMARY_BUS_NUMBER =           0x1B,
    PCI_CFG1_SECONDARY_STATUS =             0x1C,
    PCI_CFG1_IO_LIMIT =                     0x1E,
    PCI_CFG1_IO_BASE =                      0x1F,
    PCI_CFG1_MEM_LIMIT =                    0x20,
    PCI_CFG1_MEM_BASE =                     0x22,
    PCI_CFG1_PREFETCHABLE_MEM_LIMIT =       0x24,
    PCI_CFG1_PREFETCHABLE_MEM_BASE =        0x26,
    PCI_CFG1_PREFETCHABLE_BASE_HI =         0x28,
    PCI_CFG1_PREFETCHABLE_LIMIT_HI =        0x2C,
    PCI_CFG1_IO_LIMIT_HI =                  0x30,
    PCI_CFG1_IO_BASE_HI =                   0x32,
    PCI_CFG1_CAPABILITY_PTR =               0x37,
    PCI_CFG1_EXP_ROM_BASE_PTR =             0x38,
    PCI_CFG1_BRIDGE_CTL =                   0x3C,
    PCI_CFG1_INT_PIN =                      0x3E,
    PCI_CFG1_INT_LINE =                     0x3F
};

enum PCI_COMMAND_REG_Flags
{
    PCI_CMD_IO_SPACE =                  0x0001,
    PCI_CMD_MEM_SPACE =                 0x0002,
    PCI_CMD_BUSMASTER =                 0x0004,
    PCI_CMD_SPECIAL_CYCLE =             0x0008,
    PCI_CMD_MEM_WRITE_INVAL_ENABLED =   0x0010,
    PCI_CMD_VGA_PALETTE_SNOOP =         0x0020,
    PCI_CMD_PARITY_ERROR_RESPONSE =     0x0040,
    PCI_CMD_SERR_ENABLE =               0x0100,
    PCI_CMD_FAST_BACK_TO_BACK_ENABLE =  0x0200,
    PCI_CMD_INT_DISABLE =               0x0400    
};

enum PCI_STATUS_REG_Flags
{
    PCI_STATUS_INT_STATUS =                 0x0008,
    PCI_STATUS_CAPABILITES_LIST =           0x0010,
    PCI_STATUS_66MHZ_CAPABLE =              0x0020,
    PCI_STATUS_FAST_BACK_TO_BACK_CAPABLE =  0x0080,
    PCI_STATUS_MASTER_PARITY_ERROR =        0x0100,
    PCI_STATUS_DEVSEL_TIMING =              0x0200
};

#endif