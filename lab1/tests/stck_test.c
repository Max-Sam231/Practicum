#include "../stck.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_init_stack() {
  Stack stack;
  Init(&stack, 10);
  assert(stack.topElem == -1);
  printf("test_init_stack passed\n");
  free(stack.items);
}

void test_empty_stack() {
  Stack stack;
  Init(&stack, 10);
  assert(Empty(&stack) == true);
  printf("test_empty_stack passed\n");
  free(stack.items);
}

void test_full_stack() {
  Stack stack;
  int size = 10;
  Init(&stack, size);
  for (int i = 0; i < size; i++) {
    Push(&stack, i);
  }
  assert(Full(&stack) == true);
  printf("test_full_stack passed\n");
  free(stack.items);
}

void test_peek_stack() {
  Stack stack;
  Init(&stack, 10);
  Push(&stack, 10);
  assert(Peek(&stack) == 10);
  printf("test_peek_stack passed\n");
  free(stack.items);
}

void test_push_stack() {
  Stack stack;
  Init(&stack, 10);
  Push(&stack, 20);
  assert(stack.topElem == 0);
  assert(stack.items[stack.topElem] == 20);
  printf("test_push_stack passed\n");
  free(stack.items);
}

void test_pop_stack() {
  Stack stack;
  Init(&stack, 10);
  Push(&stack, 30);
  Pop(&stack);
  assert(stack.topElem == -1);
  printf("test_pop_stack passed\n");
  free(stack.items);
}

void test_pop_empty_stack() {
  Stack stack;
  Init(&stack, 10);
  Pop(&stack);
  assert(stack.topElem == -1);
  printf("test_pop_empty_stack passed\n");
  free(stack.items);
}

void test_peek_empty_stack() {
  Stack stack;
  Init(&stack, 10);
  assert(Peek(&stack) == -1);
  printf("test_peek_empty_stack passed\n");
  free(stack.items);
}

void test_push_full_stack() {
  Stack stack;
  int size = 10;
  Init(&stack, size);
  for (int i = 0; i < size; i++) {
    Push(&stack, i);
  }
  Push(&stack, 11);
  assert(stack.topElem == size - 1);
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
