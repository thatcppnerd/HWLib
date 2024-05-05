#ifndef __VGA_H__
#define __VGA_H__

#include "types.h"

enum VGA_Ports
{   
    VGA_CRTC_ADDR =             0x3B4,
    VGA_CRTC_DATA =             0x3B5,

    VGA_IN_STAT1_ALT =          0x3BA, // Read
    VGA_FC_ALT1 =               0x3BA, // Write

    VGA_ATTR_INDEX =            0x3C0,
    VGA_ATTR_DATA =             0x3C0,

    VGA_ATTR_DATA_READ =        0x3C1,

    VGA_IN_STATUS0 =            0x3C2, // Read
    VGA_MISC_OUT_WR =           0x3C2, // Write

    VGA_SEQ_ADDR =              0x3C4,
    VGA_SEQ_DATA =              0x3C5,

    VGA_DAC_MASK =              0x3C6,

    VGA_DAC_STATE =             0x3C7, // Read
    VGA_DAC_ADDR_RM =           0x3C7, // Write

    VGA_DAC_ADDR_WM =           0x3C8,

    VGA_DAC_DATA =              0x3C9,

    VGA_FC_ALT2 =               0x3CA, // Read

    VGA_MISC_OUT_RD =           0x3CC, // Read

    VGA_GC_ADDR =               0x3CE,
    VGA_GC_DATA =               0x3CF,

    VGA_CRTC_ADDR_ALT =         0x3D4,
    VGA_CRTC_DATA_ALT =         0x3D5,

    VGA_IN_STATUS1 =            0x3DA, // Read
    VGA_FC =                    0x3DA // Write
};

enum VGA_GC_RegIndices
{
    VGA_GC_SR_REG =         0x00,
    VGA_GC_SR_ENABLE =      0x01,
    VGA_GC_COL_CMP =        0x02,
    VGA_GC_DATA_ROT =       0x03,
    VGA_GC_READ_MAP_SEL =   0x04,
    VGA_GC_GR_MODE =        0x05,
    VGA_GC_MISC_GR =        0x06,
    VGA_GC_COL_DONT_CARE =  0x07,
    VGA_GC_BIT_MASK =       0x08
};

enum VGA_SEQ_RegIndices
{
    VGA_SEQ_RESET =         0x00,
    VGA_SEQ_CLK_MODE =      0x01,
    VGA_SEQ_MAP_MASK =      0x02,
    VGA_SEQ_CHR_MAP_SEL =   0x03,
    VGA_SEQ_MEM_MODE =      0x04
};

enum VGA_ATTR_RegIndices
{
    VGA_ATTR_PAL0 =             0x00,
    VGA_ATTR_PAL1 =             0x01,
    VGA_ATTR_PAL2 =             0x02,
    VGA_ATTR_PAL3 =             0x03,
    VGA_ATTR_PAL4 =             0x04,
    VGA_ATTR_PAL5 =             0x05,
    VGA_ATTR_PAL6 =             0x06,
    VGA_ATTR_PAL7 =             0x07,
    VGA_ATTR_PAL8 =             0x08,
    VGA_ATTR_PAL9 =             0x09,
    VGA_ATTR_PAL10 =            0x0A,
    VGA_ATTR_PAL11 =            0x0B,
    VGA_ATTR_PAL12 =            0x0C,
    VGA_ATTR_PAL13 =            0x0D,
    VGA_ATTR_PAL14 =            0x0E,
    VGA_ATTR_PAL15 =            0x0F,

    VGA_ATTR_MODE_CTL =         0x10,
    VGA_ATTR_OVRSCN_COL =       0x11,
    VGA_ATTR_COL_PLN_ENABLE =   0x12,
    VGA_ATTR_HORI_PAN_REG =     0x13,
    VGA_ATTR_COL_SEL =          0x14
};  

enum VGA_CRTC_RegIndices
{
    VGA_CRTC_HORI_TOTAL =       0x00,
    VGA_CRTC_END_HORI_DSP =     0x01,
    VGA_CRTC_START_HORI_BNK =   0x02,
    VGA_CRTC_END_HORI_BNK =     0x03,
    VGA_CRTC_START_HORI_RTRC =  0x04,
    VGA_CRTC_END_HORI_RTRC =    0x05,
    VGA_CRTC_VERT_TOTAL =       0x06,
    VGA_CRTC_OVFLW =            0x07,
    VGA_CRTC_PRESET_ROW_SCN =   0x08,
    VGA_CRTC_MAX_SCNLNE =       0x09,
    VGA_CRTC_CRSR_START =       0x0A,
    VGA_CRTC_CRSR_END =         0x0B,
    VGA_CRTC_START_ADDR_HI =    0x0C,
    VGA_CRTC_START_ADDR_LO =    0x0D,
    VGA_CRTC_CRSR_LOC_HI =      0x0E,
    VGA_CRTC_CRSR_LOC_LO =      0x0F,
    VGA_CRTC_VERT_RTRC_START =  0x10,
    VGA_CRTC_VERT_RTRC_END =    0x11,
    VGA_CRTC_VERT_DSP_END =     0x12,
    VGA_CRTC_OFFSET =           0x13,
    VGA_CRTC_UNDERLINE_LOC =    0x14,
    VGA_CRTC_START_VBNK =       0x15,
    VGA_CRTC_END_VBNK =         0x16,
    VGA_CRTC_MODE_CTL =         0x17,
    VGA_CRTC_LN_CMP =           0x18  
};


u8_t VGA_GetCRTCAddrReg(void);
void VGA_SetCRTCAddrReg(u8_t addr);

u8_t VGA_GetInputStatusReg0(void);

void VGA_SetFCReg(u8_t val);

u8_t VGA_GetAttrIndexReg(void);
void VGA_SetAttrIndexReg(u8_t val);

u8_t VGA_GetAttrDataReg(void);
void VGA_SetAttrDataReg(u8_t val);

u8_t VGA_GetAttrDataReadReg(void);
void VGA_SetAttrDataReadReg(u8_t val);

u8_t VGA_GetMiscOutputReg(void);
void VGA_SetMiscOutputReg(u8_t val);

u8_t VGA_GetSequencerAddressReg(void);
void VGA_SetSequencerAddressReg(u8_t val);

u8_t VGA_GetDACMaskReg(void);
void VGA_SetDACMaskReg(u8_t mask);

u8_t VGA_GetDACState(void);

void VGA_SetDACReadmodeAddrReg(u8_t val);

u8_t VGA_GetDACWritemodeAddrReg(void);
void VGA_SetDACWritemodeAddrReg(u8_t val);

u8_t VGA_GetDACDataReg(void);
void VGA_SetDACDataReg(u8_t val);

u8_t VGA_GetGraphicsControlAddressReg(void);
void VGA_SetGraphicsControlAddressReg(u8_t val);
u8_t VGA_GetInputStatusReg1(void);
void VGA_SetFeatureControl(u8_t val);





u8_t VGA_ReadRegister(u8_t index);
void VGA_WriteRegister(u8_t index, u8_t val);


#endif