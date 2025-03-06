#include <stdbool.h>

#define SIZE 10

typedef struct {
  int items[SIZE];
  int topElem;
} Stack;

void Init(Stack *stack);
bool Empty(Stack *stack);
bool Full(Stack *stack);
int Peek(Stack *stack);
void Push(Stack *stack, int value);
void Pop(Stack *stack);
