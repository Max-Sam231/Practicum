#include <stdbool.h>

typedef struct {
  int *items;
  int topElem;
  int size;
} Stack;

void Init(Stack *stack, int size);
bool Empty(Stack *stack);
bool Full(Stack *stack);
int Peek(Stack *stack);
void Push(Stack *stack, int value);
void Pop(Stack *stack);
