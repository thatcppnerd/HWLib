#include "../include/hash.h"

hash_t dumbass_hash(ubyte_t* data, int len)
{
    hash_t hash;

    // plan to make hash

    // First set all bytes to first character
    // Rotate bits by 1
    // Then do the same with the second character, but start at the 
    // second byte of the hash and continue to last byte
    // when at character 5, add all bytes with 5th character,
    // on char 6, add all bytes with current char, excluding last character

    for(int a = 0 ; a < len ; a++)
    {
        if((a % 8) <= 4)
        {
            for(int b = a % 4 ; b < 4 ; b++)
            {
                ((ubyte_t*)hash)[b] += data[a];
            }
        }
        else
        {
            for(int b = 0 ; b < 4 - (a % 4) ; b++)
            {
                ((ubyte_t*)hash)[b] += data[a];
            }
        }
        
    }
}