#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "pool_allocator.h"

typedef struct Item {
  const char *key;
  void *value;
  int is_occupied;
} Item;

typedef struct {
  size_t capacity;
  size_t value_size;
  Item *items;
  PoolAllocator *allocator;
} HashTable;

void hashtable_init(HashTable *table, size_t capacity, size_t value_size,
                    PoolAllocator *allocator);

void hashtable_insert(HashTable *table, const char *key, void *value);

void *hashtable_get(HashTable *table, const char *key);

void hashtable_del(HashTable *table, const char *key);

void hashtable_free(HashTable *table);

#endif
