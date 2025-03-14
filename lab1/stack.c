#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void init(Stack *stack, int size) {
  stack->items = (int *)malloc(size * sizeof(int));
  stack->top_elem = -1;
  stack->size = size;
  stack->is_empty = true;
};

bool is_empty(Stack *stack) {
  if (stack->top_elem == -1) {
    stack->is_empty = true;
  }
  return stack->is_empty;
};

bool is_full(Stack *stack) { return stack->top_elem == stack->size - 1; };

int peek(Stack *stack) {
  if (is_empty(stack) == false) {
    return stack->items[stack->top_elem];
  } else {
    return -1;
  }
}

void push(Stack *stack, int value) {
  if (is_full(stack)) {
    return;
  }
  stack->is_empty = false;
  stack->top_elem++;
  stack->items[stack->top_elem] = value;
};

int pop(Stack *stack) {
  if (is_empty(stack)) {
    return -1;
  }
  int temp_value = stack->items[stack->top_elem];
  stack->top_elem--;
  return temp_value;
};