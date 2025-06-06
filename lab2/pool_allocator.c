#include "pool_allocator.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void *pool_init(int size_chank, int count_chank) {
  PoolAllocator *allocator = (PoolAllocator *)malloc(sizeof(PoolAllocator));
  if (!allocator)
    return NULL;

  allocator->pool = NULL;
  allocator->free_blocks = NULL;

  allocator->pool = malloc((size_t)size_chank * (size_t)count_chank);
  if (!allocator->pool) {
    free(allocator);
    return NULL;
  }

  allocator->free_blocks =
      (void **)malloc((size_t)count_chank * sizeof(void *));
  if (!allocator->free_blocks) {
    free(allocator->pool);
    free(allocator);
    return NULL;
  }

  for (int i = 0; i < count_chank; ++i) {
    allocator->free_blocks[i] = (char *)allocator->pool + i * size_chank;
  }

  allocator->count_chank = count_chank;
  allocator->size_chank = size_chank;
  allocator->free_head = count_chank;

  return allocator;
}

void *pool_alloc(void *allocator) {
  PoolAllocator *alloc = (PoolAllocator *)allocator;
  if (!alloc || alloc->free_head <= 0)
    return NULL;

  alloc->free_head--;
  return alloc->free_blocks[alloc->free_head];
}

void pool_free(void *allocator, void *block) {
  PoolAllocator *alloc = (PoolAllocator *)allocator;
  if (!alloc || !block || alloc->free_head >= alloc->count_chank)
    return;

  alloc->free_blocks[alloc->free_head] = block;
  alloc->free_head++;
}

void pool_deinit(void *allocator) {
  PoolAllocator *alloc = (PoolAllocator *)allocator;
  if (!alloc)
    return;

  free(alloc->free_blocks);
  free(alloc->pool);
  free(allocator);
}

