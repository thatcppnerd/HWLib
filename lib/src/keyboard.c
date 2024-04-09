#include "../include/keyboard/keyboard.h"
#include "../include/dev/dev.h"



int KB_SetLEDs(u8_t state)
{
    while(1)
    {
        outb(PS2_PORT_CMD, KB_CMD_SET_LED); // send command
        io_wait();
        outb(PS2_PORT_DATA, state & 0x0F); // send new LED states
        io_wait();
        
        poll:
            if(inb(PS2_PORT_DATA) == KB_ACK)
            {
                return 0;
            }
            else goto poll;
    }
    return 0; // this code is dead but i hate warnings more
}

int KB_Echo()
{
    outb(PS2_PORT_CMD, KB_CMD_ECHO); // send cummand
    io_wait();

    poll:
        if(inb(PS2_PORT_DATA) == KB_ACK)
        {
            return 0;
        }
        else goto poll;

    return 0;
}

int KB_GetCurrentScancodeSet()
{
    outb(PS2_PORT_CMD, KB_CMD_SCANCODE); // send command
    io_wait();
    outb(PS2_PORT_DATA, 0x01); // specify subcommand
    io_wait();

    poll:
        if(inb(PS2_PORT_DATA) == KB_ACK)
        {
            while(1)
            {
                if(inb(PS2_PORT_DATA) != KB_ACK)
                {
                    switch(inb(PS2_PORT_DATA))
                    {
                        case 0x43: return 1; break;
                        case 0x41: return 2; break;
                        case 0x3F: return 3; break;
                        default:   return -1; break;
                    }
                }
            }
        }
        else goto poll;

    return 0;
}

int KB_IdentifyKeyboard()
{
    outb(PS2_PORT_CMD, KB_CMD_IDENTIFY_KEYBOARD);

    poll:
        if(inb(PS2_PORT_DATA) == KB_ACK)
        {
            while(1)
            {
                if(inb(PS2_PORT_DATA) != KB_ACK)
                {
                    return inb(PS2_PORT_DATA);
                }
            }
        }
        else goto poll;

    return 0;
}

int KB_SetTypematicRate(u8_t rate, u8_t delay)
{
    outb(PS2_PORT_CMD, KB_CMD_SET_TYPEMATIC_RATE);
    outb(PS2_PORT_DATA, ((delay & 0x03) << 5) | (rate & 0x1F));

    poll:
        if(inb(PS2_PORT_DATA) == KB_ACK)
        {
            return 0;
        }
        else goto poll;
    
    return 0;
}

int KB_EnableScan()
{
    outb(PS2_PORT_CMD, KB_CMD_ENABLE_SCAN);

    poll:
        if(inb(PS2_PORT_DATA) == KB_ACK)
        {
            return 0;
        }
        else goto poll;
}

int KB_DisableScan()
{
    outb(PS2_PORT_CMD, KB_CMD_DISABLE_SCAN);

    poll:
        if(inb(PS2_PORT_DATA) == KB_ACK)
        {
            return 0;
        }
        else goto poll;
}

int KB_SetDefaultParams()
{
    outb(PS2_PORT_CMD, KB_CMD_SET_DEFAULT_PARAMS);

    poll:
        if(inb(PS2_PORT_DATA) == KB_ACK)
        {
            return 0;
        }
        else if(inb(PS2_PORT_DATA) == KB_RESEND)
        {
            return -1; // fucc yu
        }
        else goto poll;
}

int KB_SetAllKeysTypematicOnly()
{

}