#include "../include/fdc.h" 


u8_t FDC_GetStatusRegA(int ctlr_no)
{
    switch(ctlr_no)
    {
        case FDC0: inb(FDC0_STATUS_REG_A); break;
        case FDC1: inb(FDC1_STATUS_REG_A); break;
        case FDC2: inb(FDC2_STATUS_REG_A); break;
        default: return ERR_VAL;
    }
}

u8_t FDC_GetStatusRegB(int ctlr_no)
{
    switch(ctlr_no)
    {
        case FDC0: inb(FDC0_STATUS_REG_B); break;
        case FDC1: inb(FDC1_STATUS_REG_B); break;
        case FDC2: inb(FDC2_STATUS_REG_B); break;
        default: return ERR_VAL;
    }
}
