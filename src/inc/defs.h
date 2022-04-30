#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdint.h>

typedef union _Address_t
{
   uint32_t address;

   struct
   {
       uint32_t block_address   : 8;
       uint32_t page_address    : 8;
       uint32_t offset          : 8;
       uint32_t reserved        : 8;
   };
} Address_t;


#define FILE_SIZE       (16*1024)
#define FILE_READ_CHUNK (1024)

#define SUCCESS         (1)
#define FAILURE         (0)

#define ASSERT(expr)    assert(expr)
