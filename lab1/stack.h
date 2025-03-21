#include <stdbool.h>

#define STACK_OVERFLOW -1
#define STACK_UNDERFLOW -2

typedef struct {
  int *items;
  int top_elem;
  int size;
} Stack;

void init(Stack *stack, int size);
bool is_empty(Stack *stack);
bool is_full(Stack *stack);
int peek(Stack *stack, int *out);
int push(Stack *stack, int value);
int pop(Stack *stack, int *out);
