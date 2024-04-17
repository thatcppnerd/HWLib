#ifndef __TYPES_H__
#define __TYPES_H__


// basic size types

typedef signed char         i8_t;
typedef signed short        i16_t;
typedef signed int          i32_t;

typedef unsigned char       u8_t;
typedef unsigned short      u16_t;
typedef unsigned int        u32_t;


typedef signed char         schar_t;
typedef signed short        sshort_t;
typedef signed int          sint_t;

typedef unsigned char       uchar_t;
typedef unsigned short      ushort_t;
typedef unsigned int        uint_t;

#ifdef __x86_64__
typedef signed long         i64_t;
typedef unsigned long       u64_t;

typedef signed long         slong_t;
typedef unsigned long       ulong_t;
#endif


// Function Attributes 

#define NORETURN __attribute__((noreturn))
#define ALWAYSINLINE __attribute__((always_inline))
#define PACKED __attribute__((packed))

#endif