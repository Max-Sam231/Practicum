#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void init(Stack *stack, int size) {
  stack->items = (int *)malloc(size * sizeof(int));
  stack->top_elem = -1;
  stack->size = size;
}

bool is_empty(Stack *stack) { return stack->top_elem == -1; }

bool is_full(Stack *stack) { return stack->top_elem == stack->size - 1; }

int peek(Stack *stack, int *out) {
  if (is_empty(stack)) {
    return STACK_UNDERFLOW;
  }
  *out = stack->items[stack->top_elem];
  return 0;
}

int push(Stack *stack, int value) {
  if (is_full(stack)) {
    return STACK_OVERFLOW;
  }
  stack->top_elem++;
  stack->items[stack->top_elem] = value;
}

int pop(Stack *stack, int *out) {
  if (is_empty(stack)) {
    return STACK_UNDERFLOW;
  }
  *out = stack->items[stack->top_elem];
  stack->top_elem--;
  return 0;
}
