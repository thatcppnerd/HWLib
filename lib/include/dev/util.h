#ifndef __UTIL_H__
#define __UTIL_H__

// signed int to ASCII
void itoa(signed int n, char* dest);

// int to BIN(as ASCII string)
void itoa_bin(unsigned int n, char* dest, unsigned int len);

// int to HEX(as ASCII string)
void itoa_hex(signed int n, char* dest, unsigned int len);


// uint to ASCII
void uitoa(unsigned int n, char* dest);

// uint to BIN
void uitoa_bin(unsigned int n, char* dest);

// uint to HEX
void uitoa_hex(unsigned int n, char* dest);



// ASCII to int
int atoi(const char* src);




int strlen(const char* s);

#endif