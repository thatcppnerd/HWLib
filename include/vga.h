#ifndef __VGA_H__
#define __VGA_H__

#include "types.h"

enum VGA_Ports
{   
    VGA_CRTC_CTL_ADDR =         0x3B4,
    VGA_CRTC_CTL_DATA =         0x3B5,

    VGA_INPUT_STATUS1_ALT =     0x3BA, // Read
    VGA_FEATURE_CTL_ALT1 =      0x3BA, // Write

    VGA_INDEX =                 0x3C0,
    VGA_DATA =                  0x3C0,

    VGA_ATTRIB_DATA =           0x3C1,

    VGA_INPUT_STATUS0 =         0x3C2, // Read
    VGA_MISC_OUTPUT =           0x3C2, // Write

    VGA_SEQUENCER_ADDR =        0x3C4,

    VGA_SEQUENCER_DATA =        0x3C5,

    VGA_DAC_MASK =              0x3C6,

    VGA_DAC_STATE =             0x3C7, // Read
    VGA_DAC_ADDR_READMODE =     0x3C7, // Write

    VGA_DAC_ADDR_WRITEMODE =    0x3C8,

    VGA_DAC_DATA =              0x3C9,

    VGA_FEATURE_CTL_ALT2 =      0x3CA, // Read

    VGA_MISC_OUTPUT_ALT =       0x3CC, // Read

    VGA_GRAPHICS_CTL_ADDR =     0x3CE,
    VGA_GRAPHICS_CTL_DATA =     0x3CF,

    VGA_CRTC_CTL_ADDR_ALT =     0x3D4,
    VGA_CRTC_CTL_DATA_ALT =     0x3D5,

    VGA_INPUT_STATUS1 =         0x3DA, // Read
    VGA_FEATURE_CTL =           0x3DA // Write
};




#endif