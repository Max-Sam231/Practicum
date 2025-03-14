#include <stdbool.h>

typedef struct {
  int *items;
  int top_elem;
  int size;
  bool is_empty;
} Stack;

void init(Stack *stack, int size);
bool is_empty(Stack *stack);
bool is_full(Stack *stack);
int peek(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);