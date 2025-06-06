#ifndef REFCOUNT_GC_H
#define REFCOUNT_GC_H

#include "../memory/pool_allocator.h"

typedef void (*destructor_t)(void *);

typedef struct {
  size_t count;
  void *object;
  destructor_t destructor;
} ref_count_t;

ref_count_t *create_ref(PoolAllocator *allocator, void *obj,
                        destructor_t destructor);
void retain(ref_count_t *ref);
void release(PoolAllocator *allocator, ref_count_t *ref);

#endif
