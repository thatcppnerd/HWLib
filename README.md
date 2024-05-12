# HWLib
PC Hardware Library

<!-- This doesn't change, no matter what. -->
HWLib is a library providing wrappers, functions, and utilities for PC components to aid in developing bare-metal/freestanding applications.


**WARNING:** This is only meant to be used to create bare-metal programs, this will not work on ANY OS.

## What's supported right now?
* PIT (i8253/i8254)
* PIC (i8259)
* PS/2 Controller (i8042)
* ISA DMA
* Floppy Disk Controller
* Legacy PCI (v2.0), other versions coming soon
* CMOS & RTC
* VGA
* PC Speaker