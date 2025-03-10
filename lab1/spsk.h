#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
  int current;
  struct Item *next;
} Item;

Item *CreateItem(int data);
void PushStart(Item **startElem, int data);
void PushEnd(Item **startElem, int data);
void PushMiddle(Item **startElem, int data, int index);
void PopItem(Item **startElem, int value);
Item *FindItem(Item *startElem, int index);
int CountElem(Item *startElem);
