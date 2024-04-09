#include "../include/dev/util.h"
#include "../include/dev/dev.h"



void itoa(signed int n, char* dest)
{
    int len = 0;
    int sign_bit = (n < 0);

    if(sign_bit == HIGH) 
    {
        dest++; // shift pointer to make room for negative sign 
    }

    // In case number starts as 0
    if(n == 0) 
    {
        dest[0] = '0';
        len = 1;
    }
    else
    {

        while(n != 0)
        {
            if(sign_bit == LOW)
            {
                dest[len] = '0' + (n % 10);  // convert to character and store
            }
            else
            {
                dest[len] = '0' - (n % 10); // what the actual fuck
            }

            n /= 10; 
            len++;
        }
    }

    // reverse string if number is longer than 1 char

    if(len > 1)
    {
        for(int a = 0, b = len - 1 ; a < b ; a++, b--)
        {
            char tmp = dest[a];
            dest[a] = dest[b];
            dest[b] = tmp;
        }
    }

    if(sign_bit == HIGH)
    {   
        dest--; // shift dest pointer back
        dest[0] = '-';
        len++;
    }

    dest[len] = 0; // append null terminator
}

void itoa_bin(unsigned int n, char* dest, unsigned int len)
{
    int divisor = 1;
    
    // divisor = 2 to the power of len
    for (int a = 0 ; a < len - 1; a++)
    {
        divisor *= 2;
    }

    for (int a = 0 ; a < len ; a++)
    {
        if(n < divisor)
        {
            dest[a] = '0';
        }
        else
        {
            dest[a] = '1';
            n -= divisor;
        }

        divisor /= 2;
    }

    dest[len] = 0; // append null terminator
}

void itoa_hex(signed int n, char* dest, unsigned int len)
{
    
}


void uitoa(unsigned int n, char* dest)
{
    int len = 0;

    if(n == 0) 
    {
        dest[0] = '0';
        len = 1;
    }
    else
    {

        while(n != 0)
        {
            dest[len] = '0' + (n % 10);  // convert to character and store
            n /= 10; 
            len++;
        }
    }

    // reverse string if number is longer than 1 char

    if(len > 1)
    {
        for(int a = 0, b = len - 1 ; a < b ; a++, b--)
        {
            char tmp = dest[a];
            dest[a] = dest[b];
            dest[b] = tmp;
        }
    }

    dest[len] = 0; // append null terminator
}

int strlen(const char* s)
{
    register int len = 0;
    while(s[len] != 0)
    {
        len++;
    }
    return len;
}