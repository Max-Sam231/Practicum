#ifndef POOL_ALLOCATOR_H
#define POOL_ALLOCATOR_H
#include <stdlib.h>

typedef struct {
  int free_head;
  void **free_blocks;
  int count_chank;
  int size_chank;
  void *pool;
} PoolAllocator;

void *pool_init(int size_chank, int count_chank);
void *pool_alloc(void *allocator);
void pool_free(void *allocator, void *block);
void pool_deinit(void *allocator);
#endif
