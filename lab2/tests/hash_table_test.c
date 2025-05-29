#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "../hash_table.h"
#include "../pool_allocator.h"

void setup(PoolAllocator *allocator, HashTable *table, size_t capacity) {
  *allocator = *(PoolAllocator *)pool_init(sizeof(Item), 1024);
  hashtable_init(table, capacity, allocator);
}

void test_insert_and_get(PoolAllocator *allocator, HashTable *table) {
  int val1 = 100;
  int val2 = 200;

  hashtable_insert(table, "key1", &val1);
  hashtable_insert(table, "key2", &val2);

  assert(hashtable_get(table, "key1") == &val1);
  assert(hashtable_get(table, "key2") == &val2);
}

void test_update_value(PoolAllocator *allocator, HashTable *table) {
  int val1 = 100;
  int val2 = 200;

  hashtable_insert(table, "key1", &val1);
  hashtable_insert(table, "key1", &val2);

  assert(hashtable_get(table, "key1") == &val2);
}

void test_delete_key(PoolAllocator *allocator, HashTable *table) {
  int val1 = 100;

  hashtable_insert(table, "key1", &val1);
  hashtable_del(table, "key1");

  assert(hashtable_get(table, "key1") == NULL);
}

void test_get_nonexistent_key(PoolAllocator *allocator, HashTable *table) {
  assert(hashtable_get(table, "nonexistent") == NULL);
}

void test_collision_handling(PoolAllocator *allocator, HashTable *table) {
  int val1 = 1;
  int val2 = 2;

  hashtable_insert(table, "keyA", &val1);
  hashtable_insert(table, "keyB", &val2);

  assert(hashtable_get(table, "keyA") == &val1);
  assert(hashtable_get(table, "keyB") == &val2);
}

int main() {
  PoolAllocator allocator;
  HashTable table;
  setup(&allocator, &table, 8);
  test_insert_and_get(&allocator, &table);
  test_update_value(&allocator, &table);
  test_delete_key(&allocator, &table);
  test_get_nonexistent_key(&allocator, &table);
  test_collision_handling(&allocator, &table);
  printf("Success");
  return 0;
}
