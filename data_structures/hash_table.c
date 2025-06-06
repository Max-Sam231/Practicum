Добавь в мой код обнаружение циклических ссылок С Обнаружение циклических ссылок
    Создайте ситуацию,
    где два объекта ссылаются друг на друга,
    но больше не используются в программе.Убедитесь,
    что память не освобождается автоматически из -
        за циклической зависимости.Добавьте функцию,
    которая обходит объекты и обнаруживает такие циклы.Создайте
        функцию для удаления неиспользуемых объектов

#define EXIT_FAILURE 3
#include "garbage.h"
#include "pool_allocator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    ref_count_t *
    create_ref(PoolAllocator *allocator, void *obj) {
  if (!allocator || !obj)
    return NULL;

  ref_count_t *ref = pool_alloc(allocator);

  if (!ref) {
    pool_free(allocator, obj);
    return NULL;
  }

  ref->count = 1;
  ref->object = obj;

  return ref;
}

void retain(ref_count_t *ref) {
  if (ref)
    ref->count++;
}

void release(PoolAllocator *allocator, ref_count_t *ref) {
  if (!ref || !allocator)
    return;

  ref->count--;
  if (ref->count == 0) {
    pool_free(allocator, ref->object);
    pool_free(allocator, ref);
  }
}

#ifndef REFCOUNT_GC_H
#define REFCOUNT_GC_H

#include "pool_allocator.h"

typedef struct {
  size_t count;
  void *object;
} ref_count_t;

ref_count_t *create_ref(PoolAllocator *allocator, void *obj);

void retain(ref_count_t *ref);

void release(PoolAllocator *allocator, ref_count_t *ref);

#endif

#include "garbage.c"
#include "garbage.h"
#include <assert.h>

void create_ref_test() {
  PoolAllocator *allocator = pool_init(sizeof(int), 1);
  assert(allocator);

  int *num = pool_alloc(allocator);
  *num = 10;

  ref_count_t *ref = create_ref(allocator, *num);
  assert(ref);
  assert(ref->count == 1);
  assert(ref->object == num);

  release(allocator, ref);
  pool_deinit(allocator);
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
}
