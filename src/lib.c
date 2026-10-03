#include "../include/include.h"
#include "../include/types.h"
#include <unistd.h>

#define ALIGN(n) (((n) + 7) & ~(7))

Header *head = NULL;

void *handle_first_malloc_call(char *heap_start, u64 size) {
  heap_start = sbrk(0);
  sbrk(KiB(4));
  head = (Header *)heap_start;

  head->amount_of_blocks = 2;
  head->amount_of_pages = 1;

  head->lock = 0;

  BlockHeader *block = (BlockHeader *)(heap_start + sizeof(Header));

  block->prev = NULL;
  block->in_use = 1;
  block->length = ALIGN(size);

  block->next = (BlockHeader *)((char *)(block + 1) + block->length);
  block->next->next = NULL;

  return (void *)(block + 1);
}

// u64 get_block_size(u64 size_in_bytes, char *heap_start) {
//   u64 block_size = size_in_bytes;
//
//   BlockHeader *trav_blocks = (BlockHeader *)(heap_start + sizeof(Header));
//
//   return block_size;
// }

void *add_block(BlockHeader *prev, u64 size) {
  BlockHeader *block =
      (BlockHeader *)((char *)prev + sizeof(BlockHeader) + prev->length);

  prev->next = block;

  block->prev = prev;
  block->next = NULL;
  block->in_use = 1;
  block->length = ALIGN(size);

  return (void *)(block + 1);
}

void *find_good_block(char *heap_start, u64 size) {
  BlockHeader *trav_block = (BlockHeader *)(heap_start + sizeof(Header));

  while (trav_block->in_use && trav_block->next) {
    trav_block = trav_block->next;
  }
  if (!trav_block->next) {
    // all blocks are in use
    return add_block(trav_block, size);
  } else {
    // found freed block
  }
}

void *my_malloc(u64 size_in_bytes) {
  static char *heap_start = NULL;

  if (!heap_start) {
    return handle_first_malloc_call(heap_start, size_in_bytes);
  }

  void *mem_ptr = NULL;

  return mem_ptr;
}

void free_mem(void *ptr) { return; }
