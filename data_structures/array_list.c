#include "array_list.h"
#include "../memory/linear_allocator.h"
#include <assert.h>
#include <string.h>

void arraylist_init(ArrayList *list, linear_allocator *allocator,
                    size_t element_size) {
  assert(list && allocator && element_size > 0);
  list->element_size = element_size;
  list->size = 0;
  list->capacity = 4;
  list->allocator = allocator;
  list->data = linear_allocator_alloc(allocator, list->capacity * element_size);
}

static void arraylist_grow(ArrayList *list) {
  assert(list && list->allocator);
  size_t new_capacity = list->capacity * 2;
  void *new_data = linear_allocator_alloc(list->allocator,
                                          new_capacity * list->element_size);
  if (!new_data)
    return;
  memcpy(new_data, list->data, list->size * list->element_size);
  list->data = new_data;
  list->capacity = new_capacity;
}

void arraylist_add(ArrayList *list, const void *data) {
  assert(list && data);
  if (list->size >= list->capacity) {
    arraylist_grow(list);
  }
  memcpy((char *)list->data + list->size * list->element_size, data,
         list->element_size);
  list->size++;
}

void arraylist_del(ArrayList *list) {
  assert(list && list->size > 0);
  list->size--;
}

void *arraylist_get(ArrayList *list, size_t index) {
  assert(list && index < list->size);
  return (char *)list->data + index * list->element_size;
}

void arraylist_set(ArrayList *list, size_t index, const void *data) {
  assert(list && index < list->size && data);
  memcpy((char *)list->data + index * list->element_size, data,
         list->element_size);
}

void arraylist_free(ArrayList *list) {
  assert(list && list->allocator);
  list->data = NULL;
  list->size = 0;
  list->capacity = 0;
  list->allocator = NULL;
}
