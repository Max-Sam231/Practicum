#include "../garbage_collection/cycled_links.h"
#include "../memory/pool_allocator.h"
#include <assert.h>
#include <stdio.h>

void test_cycle_detection() {
  PoolAllocator *pool = pool_init(sizeof(Object), 2);
  assert(pool != NULL);

  Object *obj1 = create_object(pool, NULL);
  Object *obj2 = create_object(pool, NULL);
  assert(obj1 != NULL && obj2 != NULL);

  assert(obj1->ref_count == 1);
  assert(obj2->ref_count == 1);
  assert(obj1->next_ref == NULL);
  assert(obj2->next_ref == NULL);

  obj1->next_ref = obj2;
  obj2->next_ref = obj1;

  assert(detect_cycle(obj1, obj2) == 1);

  retain(obj1);
  retain(obj2);

  assert(obj1->ref_count == 2);
  assert(obj2->ref_count == 2);

  release(pool, obj1);
  release(pool, obj2);

  assert(obj1->ref_count == 1);
  assert(obj2->ref_count == 1);

  release(pool, obj1);
  release(pool, obj2);

  Object *obj3 = create_object(pool, NULL);
  Object *obj4 = create_object(pool, NULL);
  assert(obj3 != NULL && obj4 != NULL);

  // Очистка
  release(pool, obj3);
  release(pool, obj4);
  pool_deinit(pool);
}

void test_no_cycle_detection() {
  PoolAllocator *pool = pool_init(sizeof(Object), 2);
  assert(pool != NULL);

  Object *obj1 = create_object(pool, NULL);
  Object *obj2 = create_object(pool, NULL);
  assert(obj1 != NULL && obj2 != NULL);

  assert(detect_cycle(obj1, obj2) == 0);

  release(pool, obj1);
  release(pool, obj2);
  pool_deinit(pool);
}

int main() {
  test_cycle_detection();
  test_no_cycle_detection();

  return 0;
}
