#ifndef __SIZES_H__
#define __SIZES_H__


// basic size types

typedef signed char         i8_t;
typedef signed short        i16_t;
typedef signed int          i32_t;

typedef unsigned char       u8_t;
typedef unsigned short      u16_t;
typedef unsigned int        u32_t;

#ifdef __x86_64__
typedef signed long         i64_t;
typedef unsigned long       u64_t;
#endif

#endif