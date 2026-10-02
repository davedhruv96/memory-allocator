#include "../include/include.h"
#include "../include/types.h"
#include <unistd.h>

header *head = NULL;

void init_blocks(char *heap_start) {
  
}

void handle_first_malloc_call(char *heap_start) {
  heap_start = sbrk(0);
  sbrk(KiB(4));
  head = (header *)heap_start;

  head->amount_of_blocks = 1;
  init_blocks(heap_start);
  head->amount_of_pages = 1;

  head->lock = 0;
}

u64 get_block_size(u64 size_in_bytes, char *heap_start) {
  u64 block_size = size_in_bytes;

  block *trav_blocks = (block *)(heap_start + sizeof(header));

  return block_size;
}

void *my_malloc(u64 size_in_bytes) {
  static char *heap_start = NULL;
  if (!heap_start) {
    handle_first_malloc_call(heap_start);
  }

  u64 block_size = get_block_size(size_in_bytes, heap_start);
}
