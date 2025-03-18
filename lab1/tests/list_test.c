#include "../list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_create_item() {
  Item *list = create_item(42);
  assert(list != NULL);
  assert(list->current == 42);
  assert(list->next == NULL);
  free(list);
  printf("test_create_item passed!\n");
}

void test_push_start() {
  Item *list = NULL;
  push_start(&list, 10);
  assert(list != NULL);
  assert(list->current == 10);
  assert(list->next == NULL);

  push_start(&list, 20);
  assert(list->current == 20);
  assert(list->next->current == 10);
  assert(list->next->next == NULL);

  free(list->next);
  free(list);
  printf("test_push_start passed!\n");
}

void test_push_end() {
  Item *list = NULL;
  push_end(&list, 10);
  assert(list != NULL);
  assert(list->current == 10);
  assert(list->next == NULL);

  push_end(&list, 20);
  assert(list->current == 10);
  assert(list->next->current == 20);
  assert(list->next->next == NULL);

  free(list->next);
  free(list);
  printf("test_push_end passed!\n");
}

void test_push_middle() {
  Item *list = NULL;
  push_end(&list, 10);
  push_end(&list, 30);
  push_middle(&list, 20, 1);

  assert(list->current == 10);
  assert(list->next->current == 20);
  assert(list->next->next->current == 30);
  assert(list->next->next->next == NULL);

  free(list->next->next);
  free(list->next);
  free(list);
  printf("test_push_middle passed!\n");
}

void test_delete_item() {
  Item *list = NULL;
  push_end(&list, 10);
  push_end(&list, 20);
  push_end(&list, 30);

  delete_item(&list, 20);
  assert(list->current == 10);
  assert(list->next->current == 30);
  assert(list->next->next == NULL);

  delete_item(&list, 10);
  assert(list->current == 30);
  assert(list->next == NULL);

  delete_item(&list, 30);
  assert(list == NULL);

  free(list);
  printf("test_pop_item passed!\n");
}

void test_find_item() {
  Item *list = NULL;
  push_end(&list, 10);
  push_end(&list, 20);
  push_end(&list, 30);

  Item *found_item = find_item(list, 1);
  assert(found_item != NULL);
  assert(found_item->current == 20);

  found_item = find_item(list, 5);
  assert(found_item == NULL);

  free(list->next->next);
  free(list->next);
  free(list);
  printf("test_find_item passed!\n");
}

void test_count_elem() {
  Item *list = NULL;
  assert(count_elem(list) == 0);

  push_end(&list, 10);
  assert(count_elem(list) == 1);

  push_end(&list, 20);
  push_end(&list, 30);
  assert(count_elem(list) == 3);

  free(list->next->next);
  free(list->next);
  free(list);
  printf("test_count_elem passed!\n");
}

void test_delete_item_not_found() {
  Item *list = NULL;
  push_end(&list, 10);
  push_end(&list, 20);

  delete_item(&list, 30);
  assert(list->current == 10);
  assert(list->next->current == 20);
  assert(list->next->next == NULL);

  free(list->next);
  free(list);
  printf("test_pop_item_not_found passed!\n");
}

int main() {
  test_create_item();
  test_push_start();
  test_push_end();
  test_push_middle();
  test_delete_item();
  test_find_item();
  test_count_elem();
  test_delete_item_not_found();
  return 0;
}