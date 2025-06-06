#include "../data_structures/stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_init_stack() {
  Stack stack;
  init(&stack, 10);
  assert(stack.top_elem == -1);
  printf("test_init_stack passed\n");
  free(stack.items);
}

void test_empty_stack() {
  Stack stack;
  init(&stack, 10);
  assert(is_empty(&stack) == true);
  printf("test_empty_stack passed\n");
  free(stack.items);
}

void test_full_stack() {
  Stack stack;
  int size = 10;
  init(&stack, size);
  for (int i = 0; i < size; i++) {
    push(&stack, i);
  }
  assert(is_full(&stack) == true);
  printf("test_full_stack passed\n");
  free(stack.items);
}

void test_peek_stack() {
  Stack stack;
  int res;
  init(&stack, 10);
  push(&stack, 10);
  assert(peek(&stack, &res) == 0);
  assert(res == 10);
  printf("test_peek_stack passed\n");
  free(stack.items);
}

void test_push_stack() {
  Stack stack;
  init(&stack, 10);
  push(&stack, 20);
  assert(stack.top_elem == 0);
  assert(stack.items[stack.top_elem] == 20);
  printf("test_push_stack passed\n");
  free(stack.items);
}

void test_pop_stack() {
  Stack stack;
  int res;
  init(&stack, 10);
  push(&stack, 30);
  pop(&stack, &res);
  assert(stack.top_elem == -1);
  assert(res == 30);
  printf("test_pop_stack passed\n");
  free(stack.items);
}

void test_pop_empty_stack() {
  Stack stack;
  int res;
  init(&stack, 10);
  push(&stack, -1);
  push(&stack, 10);
  pop(&stack, &res);
  assert(pop(&stack, &res) == 0);
  assert(res == -1);
  assert(pop(&stack, &res) == STACK_UNDERFLOW);
  printf("test_pop_empty_stack passed\n");
  free(stack.items);
}

void test_peek_empty_stack() {
  Stack stack;
  int res;
  init(&stack, 10);
  assert(peek(&stack, &res) == STACK_UNDERFLOW);
  printf("test_peek_empty_stack passed\n");
  free(stack.items);
}

void test_push_full_stack() {
  Stack stack;
  int size = 10;
  init(&stack, size);
  for (int i = 0; i < size; i++) {
    push(&stack, i);
  }
  push(&stack, 11);
  assert(stack.top_elem == size - 1);
  printf("test_push_full_stack passed\n");
  free(stack.items);
}

int main() {
  test_init_stack();
  test_empty_stack();
  test_full_stack();
  test_peek_stack();
  test_push_stack();
  test_pop_stack();
  test_pop_empty_stack();
  test_peek_empty_stack();
  test_push_full_stack();

  return 0;
}
