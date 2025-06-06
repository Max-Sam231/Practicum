#include "garbage_collector.h"
#include "../memory/pool_allocator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ref_count_t *create_ref(void *allocator, void *obj) {
  if (!allocator || !obj)
    return NULL;

  PoolAllocator *alloc = (PoolAllocator *)allocator;

  ref_count_t *ref = pool_alloc(alloc);

  if (!ref) {
    pool_free(alloc, obj);
    return NULL;
  }

  ref->count = 1;
  ref->object = obj;

  return ref;
}

void retain(ref_count_t *ref) {
  if (ref)
    ref->count++;
}

void release(void *allocator, ref_count_t *ref) {
  if (!ref || !allocator)
    return;

  PoolAllocator *alloc = (PoolAllocator *)allocator;

  ref->count--;
  if (ref->count == 0) {
    pool_free(alloc, ref->object);
    pool_free(alloc, ref);
  }
}
