#ifndef __VGA_H__
#define __VGA_H__

#include "types.h"

enum VGA_Ports
{   
    VGA_CRTC_ADDR =             0x3B4,
    VGA_CRTC_DATA =             0x3B5,

    VGA_IN_STAT1_ALT =          0x3BA, // Read
    VGA_FC_ALT1 =               0x3BA, // Write

    VGA_INDEX =                 0x3C0,
    VGA_DATA =                  0x3C0,

    VGA_ATTR_DATA =             0x3C1,

    VGA_IN_STAT0 =              0x3C2, // Read
    VGA_MISC_OUT =              0x3C2, // Write

    VGA_SEQ_ADDR =              0x3C4,
    VGA_SEQ_DATA =              0x3C5,

    VGA_DAC_MASK =              0x3C6,

    VGA_DAC_STATE =             0x3C7, // Read
    VGA_DAC_ADDR_RM =           0x3C7, // Write

    VGA_DAC_ADDR_WM =           0x3C8,

    VGA_DAC_DATA =              0x3C9,

    VGA_FC_ALT2 =               0x3CA, // Read

    VGA_MISC_OUT_ALT =          0x3CC, // Read

    VGA_GC_ADDR =               0x3CE,
    VGA_GC_DATA =               0x3CF,

    VGA_CRTC_ADDR_ALT =         0x3D4,
    VGA_CRTC_DATA_ALT =         0x3D5,

    VGA_IN_STAT1 =              0x3DA, // Read
    VGA_FC =                    0x3DA // Write
};

enum VGA_RegIndices
{
    VGA_GC_SET_RESET_REG =    0x00
};

u8_t VGA_GetCRTCAddressReg(void);
void VGA_SetCRTCAddressReg(u8_t addr);

u8_t VGA_GetInputStatusReg(void);

void VGA_SetFeatureControlReg(u8_t val);

u8_t VGA_GetIndexReg(void);
void VGA_SetIndexReg(u8_t val);

u8_t VGA_GetDataReg(void);
void VGA_SetDataReg(u8_t val);

u8_t VGA_GetAttribDataReg(void);
void VGA_SetAttribDataReg(u8_t val);

u8_t VGA_GetInputStatusReg0(void);
void VGA_SetMiscellaneousOutputReg(u8_t val);

u8_t VGA_GetSequencerAddressReg(void);
void VGA_SetSequencerAddressReg(u8_t val);

u8_t VGA_GetDACMaskReg(void);
void VGA_SetDACMaskReg(u8_t val);

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