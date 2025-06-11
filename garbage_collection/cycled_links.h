#ifndef CYCLED_LINKS
#define CYCLED_LINKS

#include "../memory/pool_allocator.h"

typedef struct Object {
  size_t ref_count;
  struct Object *next_ref;
  void *data;
} Object;

Object *create_object(PoolAllocator *allocator, void *data);
void retain(Object *obj);
void release(PoolAllocator *allocator, Object *obj);
int detect_cycle(Object *obj1, Object *obj2);

#endif
