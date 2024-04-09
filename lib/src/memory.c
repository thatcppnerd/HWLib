#include "../include/types.h"
#include "../include/memory.h"


int memcpy(void* src, void* dest, unsigned int n)
{
    int c = 0;

    while(n != c)
    {
        ((char*)dest)[c] = ((char*)src)[c];
        c++;
    }

    return 0;
}

int memset(void* src, unsigned int n, unsigned char val)
{
    int c = 0;
    while(c != n)
    {
        ((char*)src)[c] = val;
        c++;
    }

    return 0;
}