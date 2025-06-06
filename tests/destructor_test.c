#include "../garbage_collection/destructor.h"
#include "../memory/pool_allocator.h"
#include <assert.h>
#include <stdio.h>

typedef struct {
  int value;
} TestObject;

int destroyed_flag = 0;

void test_destructor(void *obj) { destroyed_flag = 1; }

void test_destructor_called() {
  size_t obj_size = sizeof(TestObject);
  size_t ref_size = sizeof(ref_count_t);
  size_t max_size = (obj_size > ref_size) ? obj_size : ref_size;

  PoolAllocator *allocator = pool_init(max_size, 4);
  assert(allocator != NULL);

  TestObject *obj = pool_alloc(allocator);
  assert(obj != NULL);
  obj->value = 42;

  ref_count_t *ref = create_ref(allocator, obj, test_destructor);
  assert(ref != NULL);
  assert(ref->count == 1);
  assert(destroyed_flag == 0);

  release(allocator, ref);
  assert(destroyed_flag == 1);

  pool_deinit(allocator);
}

void test_no_destructor() {
  size_t obj_size = sizeof(TestObject);
  size_t ref_size = sizeof(ref_count_t);
  size_t max_size = (obj_size > ref_size) ? obj_size : ref_size;

  PoolAllocator *allocator = pool_init(max_size, 4);
  assert(allocator != NULL);

  TestObject *obj = pool_alloc(allocator);
  assert(obj != NULL);
  obj->value = 42;

  ref_count_t *ref = create_ref(allocator, obj, NULL);
  assert(ref != NULL);
  assert(ref->count == 1);

  release(allocator, ref);
  pool_deinit(allocator);
}

void test_multiple_references() {
  destroyed_flag = 0;

  size_t obj_size = sizeof(TestObject);
  size_t ref_size = sizeof(ref_count_t);
  size_t max_size = (obj_size > ref_size) ? obj_size : ref_size;

  PoolAllocator *allocator = pool_init(max_size, 4);
  assert(allocator != NULL);

  TestObject *obj = pool_alloc(allocator);
  assert(obj != NULL);
  obj->value = 42;

  ref_count_t *ref = create_ref(allocator, obj, test_destructor);
  assert(ref != NULL);
  assert(ref->count == 1);

  retain(ref);
  assert(ref->count == 2);

  release(allocator, ref);
  assert(destroyed_flag == 0);

  release(allocator, ref);
  assert(destroyed_flag == 1);

  pool_deinit(allocator);
}

void test_null_handling() {
  PoolAllocator allocator;
  release(&allocator, NULL);
  release(NULL, NULL);
}

int main() {
  test_destructor_called();
  test_no_destructor();
  test_multiple_references();
  test_null_handling();

  printf("Success\n");
  return 0;
}
