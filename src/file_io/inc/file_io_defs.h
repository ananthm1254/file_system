#pragma once

#include<stdint.h>
#include<defs.h>

typedef struct _EraseMsg_t {
    Address_t address;
    uint32_t respQId;
} EraseMsg_t;

typedef struct _WriteMsg_t {
    Address_t address;
    uint8_t* buffPtr;
    uint32_t respQId;
} WriteMsg_t;

typedef struct _ReadeMsg_t {
    Address_t address;
    uint8_t* buffPtr;
    uint32_t respQId;
} ReadMsg_t;

uint32_t FileErase(EraseMsg_t *eraseMsg);
uint32_t FileWrite(WriteMsg_t *writeMsg);
uint32_t FileRead(ReadMsg_t *readMsg);