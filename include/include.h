#ifndef INCLUDE_H
#define INCLUDE_H

#include "types.h"

typedef struct block {
  // u8 marker;
  struct block *prev;
  struct block *next;
  b8 in_use;
  u32 length;
} BlockHeader;

typedef struct {
  b8 lock; // simple lock for multi-threading support
  u16 amount_of_pages;
  u32 amount_of_blocks;
} Header;

void *my_malloc(u64 size_in_bytes);

void free_mem(void *ptr);

#endif
