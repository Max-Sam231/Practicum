#include "../pool_allocator.h"
#include <assert.h>

void test_pool_init() {
  int size_chank = 32;
  int count_chank = 5;
  PoolAllocator *alloc = (PoolAllocator *)pool_init(size_chank, count_chank);

  assert(alloc != NULL);
  assert(alloc->pool != NULL);
  assert(alloc->size_chank == size_chank);
  assert(alloc->count_chank == count_chank);
  assert(alloc->free_head == count_chank);

  for (int i = 0; i < count_chank; ++i) {
    void *expected_block = (char *)alloc->pool + i * size_chank;
    assert(alloc->free_blocks[i] == expected_block);
  }

  pool_deinit(alloc);
}

void test_pool_alloc_and_free() {
  int size_chank = 16;
  int count_chank = 3;
  PoolAllocator *alloc = (PoolAllocator *)pool_init(size_chank, count_chank);

  void *blocks[count_chank];
  for (int i = 0; i < count_chank; ++i) {
    blocks[i] = pool_alloc(alloc);
    assert(blocks[i] != NULL);

    char *block_pos = (char *)blocks[i];
    char *pool_start = (char *)alloc->pool;
    char *pool_end = pool_start + size_chank * count_chank;
    assert(block_pos >= pool_start && block_pos < pool_end);
  }

  void *overflow_block = pool_alloc(alloc);
  assert(overflow_block == NULL);

  pool_free(alloc, blocks[1]);
  void *reused_block = pool_alloc(alloc);
  assert(reused_block == blocks[1]);

  pool_deinit(alloc);
}

void test_pool_free_order() {
  int size_chank = 8;
  int count_chank = 2;
  PoolAllocator *alloc = (PoolAllocator *)pool_init(size_chank, count_chank);

  void *first = pool_alloc(alloc);
  void *second = pool_alloc(alloc);
  pool_free(alloc, second);
  pool_free(alloc, first);

  void *check_first = pool_alloc(alloc);
  assert(check_first == first);
  void *check_second = pool_alloc(alloc);
  assert(check_second == second);

  pool_deinit(alloc);
}

int main() {
  test_pool_init();
  test_pool_alloc_and_free();
  test_pool_free_order();
  return 0;
}
