#include "../stck.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void TestInitStack() {
  Stack stack;
  Init(&stack, 10);
  assert(stack.topElem == -1);
  printf("TestInitStack passed\n");
  free(stack.items);
}

void TestEmptyStack() {
  Stack stack;
  Init(&stack, 10);
  assert(Empty(&stack) == true);
  printf("TestEmptyStack passed\n");
  free(stack.items);
}

void TestFullStack() {
  Stack stack;
  int size = 10;
  Init(&stack, size);
  for (int i = 0; i < size; i++) {
    Push(&stack, i);
  }
  assert(Full(&stack) == true);
  printf("TestFullStack passed\n");
  free(stack.items);
}

void TestPeekStack() {
  Stack stack;
  Init(&stack, 10);
  Push(&stack, 10);
  assert(Peek(&stack) == 10);
  printf("TestPeekStack passed\n");
  free(stack.items);
}

void TestPushStack() {
  Stack stack;
  Init(&stack, 10);
  Push(&stack, 20);
  assert(stack.topElem == 0);
  assert(stack.items[stack.topElem] == 20);
  printf("TestPushStack passed\n");
  free(stack.items);
}

void TestPopStack() {
  Stack stack;
  Init(&stack, 10);
  Push(&stack, 30);
  Pop(&stack);
  assert(stack.topElem == -1);
  printf("TestPopStack passed\n");
  free(stack.items);
}

void TestPopEmptyStack() {
  Stack stack;
  Init(&stack, 10);
  Push(&stack, -1);
  Push(&stack, 10);
  Pop(&stack);
  assert(Pop(&stack) == -1 && stack.isEmpty == false);
  assert(Pop(&stack) == -1);
  printf("TestPopEmptyStack passed\n");
  free(stack.items);
}

void TestPeekEmptyStack() {
  Stack stack;
  Init(&stack, 10);
  assert(Peek(&stack) == -1);
  printf("TestPeekEmptyStack passed\n");
  free(stack.items);
}

void TestPushFullStack() {
  Stack stack;
  int size = 10;
  Init(&stack, size);
  for (int i = 0; i < size; i++) {
    Push(&stack, i);
  }
  Push(&stack, 11);
  assert(stack.topElem == size - 1);
  printf("TestPushFullStack passed\n");
  free(stack.items);
}

int main() {
  TestInitStack();
  TestEmptyStack();
  TestFullStack();
  TestPeekStack();
  TestPushStack();
  TestPopStack();
  TestPopEmptyStack();
  TestPeekEmptyStack();
  TestPushFullStack();

  return 0;
}
