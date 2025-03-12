#include "stck.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void Init(Stack *stack, int size) {
  stack->items = (int *)malloc(size * sizeof(int));
  stack->topElem = -1;
  stack->size = size;
  stack->isEmpty = true;
};

bool Empty(Stack *stack) {
  if (stack->topElem == -1) {
    stack->isEmpty = true;
  }
  return stack->isEmpty;
};

bool Full(Stack *stack) { return stack->topElem == stack->size - 1; };

int Peek(Stack *stack) {
  if (Empty(stack) == false) {
    return stack->items[stack->topElem];
  } else {
    return -1;
  }
}

void Push(Stack *stack, int value) {
  if (Full(stack)) {
    return;
  }
  stack->isEmpty = false;
  stack->topElem++;
  stack->items[stack->topElem] = value;
};

int Pop(Stack *stack) {
  if (Empty(stack)) {
    return -1;
  }
  int tempValue = stack->items[stack->topElem];
  stack->topElem--;
  return tempValue;
};
