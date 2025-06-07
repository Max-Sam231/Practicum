#include "cycled_links.h"
#include "../memory/pool_allocator.h"
#include <stdio.h>

Object *create_object(PoolAllocator *allocator, void *data) {
  Object *obj = pool_alloc(allocator);
  if (!obj)
    return NULL;

  obj->ref_count = 1;
  obj->next_ref = NULL;
  obj->data = data;

  return obj;
}

void retain(Object *obj) {
  if (obj)
    obj->ref_count++;
}

void release(PoolAllocator *allocator, Object *obj) {
  if (!obj)
    return;

  obj->ref_count--;
  if (obj->ref_count == 0) {
    pool_free(allocator, obj);
  }
}

int detect_cycle(Object *obj1, Object *obj2) {
  if (!obj1 || !obj2)
    return 0;

  return obj1->next_ref == obj2 && obj2->next_ref == obj1;
}
