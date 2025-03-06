#include "../spsk.h"
#include <assert.h>
#include <stdio.h>

void test_CreateItem() {
  Item *item = CreateItem(42);
  assert(item != NULL);
  assert(item->current == 42);
  assert(item->next == NULL);
  free(item);
  printf("test_CreateItem passed!\n");
}

void test_PushStart() {
  Item *list = NULL;
  PushStart(&list, 10);
  assert(list != NULL);
  assert(list->current == 10);
  assert(list->next == NULL);

  PushStart(&list, 20);
  assert(list->current == 20);
  assert(list->next->current == 10);
  assert(list->next->next == NULL);

  free(list->next);
  free(list);
  printf("test_PushStart passed!\n");
}

void test_PushEnd() {
  Item *list = NULL;
  PushEnd(&list, 10);
  assert(list != NULL);
  assert(list->current == 10);
  assert(list->next == NULL);

  PushEnd(&list, 20);
  assert(list->current == 10);
  assert(list->next->current == 20);
  assert(list->next->next == NULL);

  free(list->next);
  free(list);
  printf("test_PushEnd passed!\n");
}

void test_PushMiddle() {
  Item *list = NULL;
  PushEnd(&list, 10);
  PushEnd(&list, 30);
  PushMiddle(&list, 20, 1);

  assert(list->current == 10);
  assert(list->next->current == 20);
  assert(list->next->next->current == 30);
  assert(list->next->next->next == NULL);

  free(list->next->next);
  free(list->next);
  free(list);
  printf("test_PushMiddle passed!\n");
}

void test_PopItem() {
  Item *list = NULL;
  PushEnd(&list, 10);
  PushEnd(&list, 20);
  PushEnd(&list, 30);

  PopItem(&list, 20);
  assert(list->current == 10);
  assert(list->next->current == 30);
  assert(list->next->next == NULL);

  PopItem(&list, 10);
  assert(list->current == 30);
  assert(list->next == NULL);

  PopItem(&list, 30);
  assert(list == NULL);

  free(list);
  printf("test_PopItem passed!\n");
}

void test_FindItem() {
  Item *list = NULL;
  PushEnd(&list, 10);
  PushEnd(&list, 20);
  PushEnd(&list, 30);

  Item *foundItem = FindItem(list, 1);
  assert(foundItem != NULL);
  assert(foundItem->current == 20);

  foundItem = FindItem(list, 5);
  assert(foundItem == NULL);

  free(list->next->next);
  free(list->next);
  free(list);
  printf("test_FindItem passed!\n");
}

void test_CountElem() {
  Item *list = NULL;
  assert(CountElem(list) == 0);

  PushEnd(&list, 10);
  assert(CountElem(list) == 1);

  PushEnd(&list, 20);
  PushEnd(&list, 30);
  assert(CountElem(list) == 3);

  free(list->next->next);
  free(list->next);
  free(list);
  printf("test_CountElem passed!\n");
}

void test_PopItem_NotFound() {
  Item *list = NULL;
  PushEnd(&list, 10);
  PushEnd(&list, 20);

  PopItem(&list, 30); // Элемент не найден
  assert(list->current == 10);
  assert(list->next->current == 20);
  assert(list->next->next == NULL);

  free(list->next);
  free(list);
  printf("test_PopItem_NotFound passed!\n");
}

int main() {
  test_CreateItem();
  test_PushStart();
  test_PushEnd();
  test_PushMiddle();
  test_PopItem();
  test_FindItem();
  test_CountElem();
  test_PopItem_NotFound();

  return 0;
}