#include "destructor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ref_count_t *create_ref(PoolAllocator *allocator, void *obj,
                        destructor_t destructor) {
  if (!allocator || !obj)
    return NULL;

  ref_count_t *ref = pool_alloc(allocator);
  if (!ref)
    return NULL;

  ref->count = 1;
  ref->object = obj;
  ref->destructor = destructor;

  return ref;
}

void retain(ref_count_t *ref) {
  if (ref)
    ref->count++;
}

void release(PoolAllocator *allocator, ref_count_t *ref) {
  if (!ref || !allocator)
    return;

  ref->count--;

  if (ref->count == 0) {
    if (ref->destructor) {
      ref->destructor(ref->object);
    } else {
      pool_free(allocator, ref->object);
    }

    pool_free(allocator, ref);
  }
}
