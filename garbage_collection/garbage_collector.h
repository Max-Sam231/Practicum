#ifndef REFCOUNT_GC_H
#define REFCOUNT_GC_H
#include "../memory/pool_allocator.h"

typedef struct {
  size_t count;
  void *object;
} ref_count_t;

ref_count_t *create_ref(void *allocator, void *obj);

void retain(ref_count_t *ref);

void release(void *allocator, ref_count_t *ref);

#endif
