#include <assert.h>
#include <stdint.h>
#include <string.h>

#include "hash_table.h"
#include "pool_allocator.h"

static int hash(const char *key) {
  uint32_t hash = 1365;
  int c;
  while ((c = *key++)) {
    hash = hash * 33 + c;
  }
  return hash;
}

void hashtable_init(HashTable *table, size_t capacity,
                    PoolAllocator *allocator) {
  assert(table && allocator && capacity > 0);
  table->capacity = capacity;
  table->allocator = allocator;

  table->items = (Item *)pool_alloc(allocator);
  assert(table->items);

  memset(table->items, 0, capacity * sizeof(Item));
}

void hashtable_insert(HashTable *table, const char *key, void *value) {
  PoolAllocator *allocator = table->allocator;

  size_t index = hash(key) % table->capacity;

  for (size_t i = 0; i < table->capacity; ++i) {
    size_t cur_index = (index + i) % table->capacity;
    Item *item = &table->items[cur_index];

    if (!item->is_occupied) {
      char *key_copy = (char *)pool_alloc(allocator);
      strcpy(key_copy, key);

      item->key = key_copy;
      item->value = value;
      item->is_occupied = 1;
      return;
    } else if (strcmp(item->key, key) == 0) {
      item->value = value;
      return;
    }
  }
}

void *hashtable_get(HashTable *table, const char *key) {
  size_t index = hash(key) % table->capacity;

  for (size_t i = 0; i < table->capacity; ++i) {
    size_t cur_index = (index + i) % table->capacity;
    Item *item = &table->items[cur_index];

    if (!item->is_occupied) {
      continue;
    }

    if (strcmp(item->key, key) == 0) {
      return item->value;
    }
  }
  return NULL;
}

void hashtable_del(HashTable *table, const char *key) {
  size_t index = hash(key) % table->capacity;

  for (size_t i = 0; i < table->capacity; ++i) {
    size_t cur_index = (index + i) % table->capacity;
    Item *item = &table->items[cur_index];

    if (!item->is_occupied)
      continue;

    if (strcmp(item->key, key) == 0) {
      item->is_occupied = 0;
      item->key = NULL;
      item->value = NULL;
      return;
    }
  }
}

void hashtable_free(HashTable *table) {
  if (!table || !table->items)
    return;

  for (size_t i = 0; i < table->capacity; ++i) {
    Item *item = &table->items[i];
    if (item->key) {
    }
  }

  free(table->items);
  table->items = NULL;
}
