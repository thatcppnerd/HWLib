#include "../include/fdc.h" 


u8_t FDC_GetStatusRegA(int fdc_no)
{
    switch(fdc_no)
    {
        case FDC0: return inb(FDC0_STATUS_REG_A); break;
        case FDC1: return inb(FDC1_STATUS_REG_A); break;
        case FDC2: return inb(FDC2_STATUS_REG_A); break;
        default: break;
    }

    return ERR_VAL;
}

u8_t FDC_GetStatusRegB(int fdc_no)
{
    switch(fdc_no)
    {
        case FDC0: return inb(FDC0_STATUS_REG_B); break;
        case FDC1: return inb(FDC1_STATUS_REG_B); break;
        case FDC2: return inb(FDC2_STATUS_REG_B); break;
        default: break;
    }

    return ERR_VAL;
}

void FDC_SetDigitalOutputReg(int fdc_no, u8_t data)
{
    switch(fdc_no)
    {
        case FDC0: outb(FDC0_DIGITAL_OUTPUT_REG, data); break; 
        case FDC1: outb(FDC1_DIGITAL_OUTPUT_REG, data); break; 
        case FDC2: outb(FDC2_DIGITAL_OUTPUT_REG, data); break; 
        default: break;
    }
}

u8_t FDC_GetDigitalOutputReg(int fdc_no)
{
    switch(fdc_no)
    {
        case FDC0: return inb(FDC0_DIGITAL_OUTPUT_REG); break; 
        case FDC1: return inb(FDC1_DIGITAL_OUTPUT_REG); break; 
        case FDC2: return inb(FDC2_DIGITAL_OUTPUT_REG); break; 
        default: break;
    }

    return ERR_VAL;
}

void FDC_SetTapeDriveReg(int fdc_no, u8_t data)
{
    switch(fdc_no)
    {
        case FDC0: outb(FDC0_DIGITAL_INPUT_REG, data); break; 
        case FDC1: outb(FDC1_DIGITAL_INPUT_REG, data); break; 
        case FDC2: outb(FDC2_DIGITAL_INPUT_REG, data); break; 
        default: break;
    }
}

u8_t FDC_GetTapeDriveReg(int fdc_no)
{
    switch(fdc_no)
    {
        case FDC0: return inb(FDC0_TAPE_DRIVE_REG); break; 
        case FDC1: return inb(FDC1_TAPE_DRIVE_REG); break; 
        case FDC2: return inb(FDC2_TAPE_DRIVE_REG); break; 
        default: break;
    }

    return ERR_VAL;
}

u8_t FDC_GetMainStatusReg(int fdc_no)
{
    switch(fdc_no)
    {
        case FDC0: return inb(FDC0_MAIN_STATUS_REG); break; 
        case FDC1: return inb(FDC1_MAIN_STATUS_REG); break; 
        case FDC2: return inb(FDC2_MAIN_STATUS_REG); break; 
        default: break;
    }

    return ERR_VAL;
}

void FDC_SetDatarateSelectReg(int fdc_no, u8_t data)
{
    switch(fdc_no)
    {
        case FDC0: outb(FDC0_DATARATE_SELECT_REG, data); break; 
        case FDC1: outb(FDC1_DATARATE_SELECT_REG, data); break; 
        case FDC2: outb(FDC2_DATARATE_SELECT_REG, data); break; 
        default: break;
    }
}

void FDC_SetFIFOReg(int fdc_no, u16_t data)
{
    switch(fdc_no)
    {
        case FDC0: outb(FDC0_FIFO_REG, data); break; 
        case FDC1: outb(FDC1_FIFO_REG, data); break; 
        case FDC2: outb(FDC2_FIFO_REG, data); break; 
        default: break;
    }
}

u16_t FDC_GetFIFOReg(int fdc_no)
{
    switch(fdc_no)
    {
        case FDC0: return inb(FDC0_FIFO_REG); break; 
        case FDC1: return inb(FDC1_FIFO_REG); break; 
        case FDC2: return inb(FDC2_FIFO_REG); break; 
        default: break;
    }

    return ERR_VAL;
}

void FDC_SetDigitalInputReg(int fdc_no, u8_t data)
{
    switch(fdc_no)
    {
        case FDC0: outb(FDC0_DIGITAL_INPUT_REG, data); break; 
        case FDC1: outb(FDC1_DIGITAL_INPUT_REG, data); break; 
        case FDC2: outb(FDC2_DIGITAL_INPUT_REG, data); break; 
        default: break;
    }
}

u8_t FDC_GetDigitalInputReg(int fdc_no)
{
    switch(fdc_no)
    {
        case FDC0: return inb(FDC0_DIGITAL_INPUT_REG); break; 
        case FDC1: return inb(FDC1_DIGITAL_INPUT_REG); break; 
        case FDC2: return inb(FDC2_DIGITAL_INPUT_REG); break; 
        default: break;
    }

    return ERR_VAL;
}

void FDC_SetConfiguationControlReg(int fdc_no, u8_t data)
{
    switch(fdc_no)
    {
        case FDC0: outb(FDC0_CONFIGURATION_CONTROL_REG, data); break; 
        case FDC1: outb(FDC1_CONFIGURATION_CONTROL_REG, data); break; 
        case FDC2: outb(FDC2_CONFIGURATION_CONTROL_REG, data); break; 
        default: break;
    }
}

u8_t FDC_GetConfigurationControlReg(int fdc_no)
{
    switch(fdc_no)
    {
        case FDC0: return inb(FDC0_DIGITAL_OUTPUT_REG); break; 
        case FDC1: return inb(FDC1_DIGITAL_OUTPUT_REG); break; 
        case FDC2: return inb(FDC2_DIGITAL_OUTPUT_REG); break; 
        default: break;
    }

    return ERR_VAL;
}

void FDC_ToggleDriveMotor(int fdc_no, int drv_no, int mode)
{
    switch(fdc_no)
    {
        case FDC0: 
            switch(drv_no)
            {
                case DRV0: outb(FDC0_DIGITAL_OUTPUT_REG, inb(FDC0_DIGITAL_OUTPUT_REG) | FDC_DOR_MOTA); break; 
                case DRV1: outb(FDC0_DIGITAL_OUTPUT_REG, inb(FDC0_DIGITAL_OUTPUT_REG) | FDC_DOR_MOTB); break;
                case DRV2: outb(FDC0_DIGITAL_OUTPUT_REG, inb(FDC0_DIGITAL_OUTPUT_REG) | FDC_DOR_MOTC); break;
                case DRV3: outb(FDC0_DIGITAL_OUTPUT_REG, inb(FDC0_DIGITAL_OUTPUT_REG) | FDC_DOR_MOTD); break;
                default: break;
            }
        break; 
        
        case FDC1: 
            switch(drv_no)
            {
                case DRV0: outb(FDC1_DIGITAL_OUTPUT_REG, inb(FDC1_DIGITAL_OUTPUT_REG) | FDC_DOR_MOTA); break; 
                case DRV1: outb(FDC1_DIGITAL_OUTPUT_REG, inb(FDC1_DIGITAL_OUTPUT_REG) | FDC_DOR_MOTB); break;
                case DRV2: outb(FDC1_DIGITAL_OUTPUT_REG, inb(FDC1_DIGITAL_OUTPUT_REG) | FDC_DOR_MOTC); break;
                case DRV3: outb(FDC1_DIGITAL_OUTPUT_REG, inb(FDC1_DIGITAL_OUTPUT_REG) | FDC_DOR_MOTD); break;
                default: break;
            }
        break; 
        
        case FDC2: 
            switch(drv_no)
            {
                case DRV0: outb(FDC2_DIGITAL_OUTPUT_REG, inb(FDC2_DIGITAL_OUTPUT_REG) | FDC_DOR_MOTA); break; 
                case DRV1: outb(FDC2_DIGITAL_OUTPUT_REG, inb(FDC2_DIGITAL_OUTPUT_REG) | FDC_DOR_MOTB); break;
                case DRV2: outb(FDC2_DIGITAL_OUTPUT_REG, inb(FDC2_DIGITAL_OUTPUT_REG) | FDC_DOR_MOTC); break;
                case DRV3: outb(FDC2_DIGITAL_OUTPUT_REG, inb(FDC2_DIGITAL_OUTPUT_REG) | FDC_DOR_MOTD); break;
                default: break;
            }
        break; 
        
        default: break;
    }
}

void FDC_SetDataRate(int fdc_no, int rate)
{
    if(0x03 < (unsigned int)rate) return; 
    switch(fdc_no)
    {
        case FDC0: outb(FDC0_DATARATE_SELECT_REG, rate & 0x03); break;
        case FDC1: outb(FDC1_DATARATE_SELECT_REG, rate & 0x03); break;
        case FDC2: outb(FDC2_DATARATE_SELECT_REG, rate & 0x03); break;
        default: break;
    }
}
