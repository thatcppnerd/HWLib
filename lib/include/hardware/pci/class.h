#ifndef __CLASS_H__ 
#define __CLASS_H__


enum PCI_Class
{
    PCI_CLASS_UNCLASSIFIED = 0x00,
    PCI_CLASS_MSC = 0x01, // Mass Storage Controller
    PCI_CLASS_NET_CTLR = 0x02, // Network Controller
    PCI_CLASS_DISPLAY_CTLR = 0x03, // Display Controller
    PCI_CLASS_MM_CTLR = 0x04, // Multimedia Controller
    PCI_CLASS_MEM_CTLR = 0x05, // Memory Controller
    PCI_CLASS_BRIDGE = 0x06,
    PCI_CLASS_SC_CTLR = 0x07, // Simple Communication Controller
    PCI_CLASS_BSP = 0x08, // Base System Peripheral
    PCI_CLASS_ID_CTLR = 0x09, // Input Device Controller
    PCI_CLASS_DOCK_STATION = 0x0A, // Docking Station
    PCI_CLASS_PROCESSOR = 0x0B,
    PCI_CLASS_SB_CTLR = 0x0C, // Serial Bus Controller
    PCI_CLASS_WIRELESS_CTLR = 0x0D, // Wireless Controller
    PCI_CLASS_INTELLIGENT_CTLR = 0x0E, // Intelligent Controller
    PCI_CLASS_SATCOMM_CTLR = 0x0F, // Satelite Communication Controller
    PCI_CLASS_ENCRYPTION_CTLR = 0x10, // Encryption Controller
    PCI_CLASS_SIGPROC_CTLR = 0x11, // Signal Proccessing Controller
    PCI_CLASS_PROC_ACCEL = 0x12, // Processing Accelerator
    PCI_CLASS_NONESS_INST = 0x13, // Non-essestial Instrumentation
    PCI_CLASS_COPROC = 0x40, 
    PCI_CLASS_VENDOR_SPECIFIED = 0xFF // Vendor-Specified Class
};

enum PCI_Unclassified_Subclass
{
    PCI_NON_VGA_COMPAT = 0x00,
    PCI_VGA_COMPAT = 0x01
};

enum PCI_MSC_Subclass
{
    PCI_SCSI_CTLR = 0x00,
    PCI_IDE_CTLR = 0x01,
    PCI_FPY_CTLR = 0x02,
    PCI_IPI_BUS_CTLR = 0x03,
    PCI_RAID_CTLR = 0x04,
    PCI_ATA_CTLR = 0x05,
    PCI_SATA_CTLR = 0x06,
    PCI_SERIAL_SCSI_CTLR = 0x07,
    PCI_NONVOL_MEM_CTLR = 0x08,
    PCI_MSC_OTHER = 0x80
};

enum PCI_NET_CTLR_Subclass
{
    PCI_ETH_CTLR = 0x00, // Ethernet Controller
    PCI_TOKENRING_CTLR = 0x01,
    PCI_FDDI_CTLR = 0x02,
    PCI_ATM_CTLR = 0x03,
    PCI_ISDN_CTLR = 0x04,
    PCI_WF_CTLR = 0x05, // WorldFip Controller
    PCI_PICMG_MULTICOMP_CTLR = 0x06, // PICMG 2.14 Multi-Computing Controller
    PCI_NET_INFBND_CTLR = 0x07, // Infiniband Controller
    PCI_FABRIC_CTLR = 0x08,
    PCI_NET_CTLR_OTHER = 0x80
};

enum PCI_DISPLAY_CTLR_Subclass
{
    PCI_VGA_COMPAT_CTLR = 0x00,
    PCI_XGA_CTLR = 0x01,
    PCI_3D_CTLR = 0x02,
    PCI_DISPLAY_CTLR_OTHER = 0x80
};

enum PCI_MM_CTLR_Subclass
{
    PCI_VIDEO_CTLR = 0x00,
    PCI_AUDIO_CTLR = 0x01,
    PCI_COMP_TELEPHONY_DEVICE = 0x02,
    PCI_AUDIO_DEVICE = 0x04,
    PCI_MM_CTLR_OTHER = 0x80
};

enum PCI_MEM_CTLR_Subclass
{
    PCI_RAM_CTLR = 0x00,
    PCI_FLASH_CTLR = 0x01,
    PCI_MEM_CTLR_OTHER = 0x80
};

enum PCI_BRIDGE_Subclass
{
    PCI_HOST_BRG = 0x00,
    PCI_ISA_BRG = 0x01,
    PCI_EISA_BRG = 0x02,
    PCI_MCA_BRG = 0x03,
    PCI_TO_PCI_BRG = 0x04,
    PCI_PCMICA_BRG = 0x05,
    PCI_NUBUS_BRG = 0x06,
    PCI_CARDBUS_BRG = 0x07,
    PCI_RACEWAY_BRG = 0x08,
    PCI_TO_PCI_OTHER_BRG = 0x09,
    PCI_INFBND_TO_PCIHST_BRG = 0x0A, // InfiniBand to PCI Host Bridge
    PCI_BRIDGE_OTHER = 0x80
};

enum PCI_SC_CTLR_Subclass
{
    PCI_SERIAL_CTLR = 0x00,
    PCI_PARALLEL_CTLR = 0x01,
    PCI_MULTIPORT_SERIAL_CTLR = 0x02,
    PCI_MODEM = 0x03,
    PCI_IEEE_488_CTLR = 0x04,
    PCI_SMRT_CARD_CTLR = 0x05,
    PCI_SC_CTLR_OTHER = 0x80
};

enum PCI_BSP_Subclass
{
    PCI_PIC = 0x00,
    PCI_DMA_CTLR = 0x01,
    PCI_TIMER = 0x02,
    PCI_RTC_CTLR = 0x03,
    PCI_PCI_HOTPLUG_CTLR = 0x04,
    PCI_SD_HOST_CTLR = 0x05,
    PCI_IOMMU = 0x06,
    PCI_OTHER = 0x80
};

enum PCI_ID_CTLR_Subclass
{
    PCI_KB_CTLR = 0x00,
    PCI_DIGITIZER_PEN = 0x01,
    PCI_MOUSE_CTLR = 0x02,
    PCI_SCANNER_CTLR = 0x03,
    PCI_GAMEPORT_CTLR = 0x04,
    PCI_ID_CTLR_OTHER = 0x80
};

enum PCI_DOCK_STATION_Subclass
{
    PCI_GENERIC = 0x00,
    PCI_DOCK_STATION_OTHER = 0x80
};

enum PCI_PROCESSOR_Subclass
{
    PCI_386 = 0x00,
    PCI_486 = 0x01,
    PCI_PENTIUM = 0x02,
    PCI_PENTIUM_PRO = 0x03,
    PCI_ALPHA = 0x10,
    PCI_POWERPC = 0x20,
    PCI_MIPS = 0x30,
    PCI_PROC_COPROC = 0x40,
    PCI_PROCESSOR_OTHER = 0x80
};

enum PCI_SB_CTLR_Subclass
{
    PCI_FIREWIRE_CTLR = 0x00,
    PCI_ACCESS_BUS_CTLR = 0x01,
    PCI_SSA = 0x03,
    PCI_USB_CTLR = 0x04,
    PCI_FIBRE_CHANNEL = 0x05,
    PCI_SMBUS_CTLR = 0x06,
    PCI_SB_CTLR_INFBND_CTLR = 0x07,
};

#endif