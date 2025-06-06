#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "../memory/linear_allocator.h"

typedef struct {
  void *data;
  size_t capacity;
  size_t size;
  size_t element_size;
  linear_allocator *allocator;
} ArrayList;

void arraylist_init(ArrayList *list, linear_allocator *allocator,
                    size_t element_size);
void arraylist_add(ArrayList *list, const void *data);
void arraylist_del(ArrayList *list);
void *arraylist_get(ArrayList *list, size_t index);
void arraylist_set(ArrayList *list, size_t index, const void *data);
void arraylist_free(ArrayList *list);

#endif
