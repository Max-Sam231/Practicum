#include "spsk.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Item *CreateItem(int data) {
  Item *newItem = (Item *)malloc(sizeof(Item));
  newItem->current = data;
  newItem->next = NULL;
  return newItem;
}

void PushStart(Item **startElem, int data) {
  Item *newItem = CreateItem(data);
  newItem->next = *startElem;
  *startElem = newItem;
}

void PushEnd(Item **startElem, int data) {
  Item *newItem = CreateItem(data);
  if (*startElem == NULL) {
    *startElem = newItem;
    return;
  }
  Item *tempStartElem = *startElem;
  while (tempStartElem->next != NULL) {
    tempStartElem = tempStartElem->next;
  }
  tempStartElem->next = newItem;
}

void PushMiddle(Item **startElem, int data, int index) {
  if (index <= 0) {
    return;
  }
  Item *newItem = CreateItem(data);
  Item *tempStartElem = *startElem;
  for (int i = 0; i < index - 1; i++) {
    if (tempStartElem == NULL) {
      return;
    }
    tempStartElem = tempStartElem->next;
  }
  newItem->next = tempStartElem->next;
  tempStartElem->next = newItem;
}

void PopItem(Item **startElem, int value) {
  Item *tempStartElem = *startElem;
  Item *prev = NULL;
  if (tempStartElem != NULL && tempStartElem->current == value) {
    *startElem = tempStartElem->next;
    free(tempStartElem);
    return;
  }
  while (tempStartElem != NULL && tempStartElem->current != value) {
    prev = tempStartElem;
    tempStartElem = tempStartElem->next;
  }
  if (tempStartElem == NULL) {
    return;
  }
  prev->next = tempStartElem->next;
  free(tempStartElem);
}

Item *FindItem(Item *startElem, int index) {
  int count = 0;
  Item *tempStartElem = startElem;
  while (tempStartElem != NULL) {
    if (count == index) {
      return tempStartElem;
    }
    count++;
    tempStartElem = tempStartElem->next;
  }
  return NULL;
}

int CountElem(Item *startElem) {
  int count = 0;
  Item *tempStartElem = startElem;
  while (tempStartElem != NULL) {
    count++;
    tempStartElem = tempStartElem->next;
  }
  return count;
}
