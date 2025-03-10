#include "../spsk.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void TestCreateItem() {
  Item *list = CreateItem(42);
  assert(list != NULL);
  assert(list->current == 42);
  assert(list->next == NULL);
  free(list);
  printf("TestCreateItem passed!\n");
}

void TestPushStart() {
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
  printf("TestPushStart passed!\n");
}

void TestPushEnd() {
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
  printf("TestPushEnd passed!\n");
}

void TestPushMiddle() {
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
  printf("TestPushMiddle passed!\n");
}

void TestPopItem() {
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
  printf("TestPopItem passed!\n");
}

void TestFindItem() {
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
  printf("TestFindItem passed!\n");
}

void TestCountElem() {
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
  printf("TestCountElem passed!\n");
}

void TestPopItemNotFound() {
  Item *list = NULL;
  PushEnd(&list, 10);
  PushEnd(&list, 20);

  PopItem(&list, 30);
  assert(list->current == 10);
  assert(list->next->current == 20);
  assert(list->next->next == NULL);

  free(list->next);
  free(list);
  printf("TestPopItemNotFound passed!\n");
}

int main() {
  TestCreateItem();
  TestPushStart();
  TestPushEnd();
  TestPushMiddle();
  TestPopItem();
  TestFindItem();
  TestCountElem();
  TestPopItemNotFound();

  return 0;
}