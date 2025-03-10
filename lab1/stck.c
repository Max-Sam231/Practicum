#include "stck.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void Init(Stack *stack, int size) {
  stack->items = (int *)malloc(size * sizeof(int));
  stack->topElem = -1;
  stack->size = size;
};

bool Empty(Stack *stack) { return stack->topElem == -1; };

bool Full(Stack *stack) { return stack->topElem == SIZE - 1; };

int Peek(Stack *stack) {
  if (Empty(stack) == false) {
    printf("%d\n", stack->items[stack->topElem]);
    return stack->items[stack->topElem];
  } else {
    printf("Стэк пуст\n");
    return -1;
  }
}

void Push(Stack *stack, int value) {
  if (Full(stack)) {
    printf("Стэк переполнен\n");
    return;
  }
  stack->topElem++;
  stack->items[stack->topElem] = value;
};

void Pop(Stack *stack) {
  if (Empty(stack)) {
    printf("Стэк пуст\n");
    return;
  }
  stack->topElem--;
};
