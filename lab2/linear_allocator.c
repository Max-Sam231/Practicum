#include "linear_allocator.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

linear_allocator *linear_allocator_init(size_t size) {

  linear_allocator *allocator =
      (linear_allocator *)malloc(sizeof(linear_allocator));

  if (allocator == NULL)
    return NULL;

  allocator->memory_block = (void *)malloc(size);
  allocator->total_size = size;
  allocator->offset = 0;

  return allocator;
}

void *linear_allocator_alloc(linear_allocator *allocator, size_t size) {
  if (!allocator) {
    return NULL;
  }

  if (allocator->total_size < allocator->offset + size) {
    return NULL;
  }
  if (size == 0) {
    return NULL;
  }

  void *addres = (char *)allocator->memory_block + allocator->offset;
  allocator->offset += size;

  return addres;
}

void linear_allocator_reset(linear_allocator *allocator) {
  if (allocator == NULL) {
    return;
  }

  allocator->offset = 0;
}

void linear_allocator_deinit(linear_allocator *allocator) {
  if (allocator == NULL) {
    return;
  }

  if (allocator->memory_block != NULL) {
    free(allocator->memory_block);
  }

  free(allocator);
}
