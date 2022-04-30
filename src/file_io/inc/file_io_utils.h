#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>
#include "file_names.h"


static inline FILE* file_open_write(char* fileName)
{
    return fopen(fileName, "wb");
}

static inline FILE* file_open_read(char* fileName)
{
    return fopen(fileName, "rb");
}

static inline void file_write(uint8_t* fileEntry, FILE* fptr, uint32_t fileSize)
{
    fwrite(fileEntry, fileSize, 1, fptr);
}

static inline void file_seek(FILE* fptr, uint32_t offset)
{
    fseek(fptr, offset, 0);
}

static inline void file_read(uint8_t* fileEntry, FILE* fptr, uint32_t fileSize)
{
    fread(fileEntry, fileSize, 1, fptr);
}

static inline void file_close(FILE* fptr)
{
    fclose(fptr);
}

static inline uint32_t IsAddressValid(uint32_t block_address, uint32_t page_address)
{
    if((block_address < BLOCK_MAX_CNT) && 
       (page_address < PAGE_MAX_CNT))
    {
        return 1;
    }
    else
    {
        return 0;
    }

}