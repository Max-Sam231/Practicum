#include "../garbage_collection/garbage_collector.h"
#include "../memory/pool_allocator.h"
#include <assert.h>
#include <stdio.h>

void create_ref_test() {
  PoolAllocator *ref_allocator = pool_init(sizeof(ref_count_t), 1);
  assert(ref_allocator);

  PoolAllocator *obj_allocator = pool_init(sizeof(int), 1);
  assert(obj_allocator);

  int *num = pool_alloc(obj_allocator);
  assert(num);
  *num = 10;

  ref_count_t *ref = create_ref(ref_allocator, num);
  assert(ref);
  assert(ref->count == 1);
  assert(ref->object == num);

  release(ref_allocator, ref);
  pool_deinit(obj_allocator);
  pool_deinit(ref_allocator);
}

void retain_release_test() {
  PoolAllocator *allocator = pool_init(sizeof(int), 2);
  assert(allocator);

  int *num = pool_alloc(allocator);
  *num = 10;

  ref_count_t *ref = create_ref(allocator, num);
  assert(ref);
  assert(ref->count == 1);

  retain(ref);
  assert(ref->count == 2);

  release(allocator, ref);
  assert(ref->count == 1);

  release(allocator, ref);

  pool_deinit(allocator);
}

int main() {
  create_ref_test();
  retain_release_test();
  printf("Success");
}
