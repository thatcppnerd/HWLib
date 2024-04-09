#ifndef __HEADER_H__
#define __HEADER_H__

#include "../../dev/types.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct PCI_HeaderBase
{
    u16_t vendorID;
    u16_t deviceID;
    
    u16_t command;
    u16_t status;

    u8_t revisionID;
    u8_t progIF;
    u8_t subclass;
    u8_t class;

    u8_t cacheLineSize;
    u8_t latencyTimer;
    u8_t headerType;
    u8_t BIST;
} PCI_HeaderBase_t;

#ifdef __cplusplus
}
#endif

#endif 