// TASK: Add the correct includes (stack and util)

#include <stdlib.h>

typedef struct stack {
  int top;    // Where is the first free element
  int size;   // Size of the array
  int *array; // Store the data
} stack_t;

stack_t *make_stack() {
  stack_t *s = malloc(sizeof(struct stack));
  s->top = 0;
  s->size = 8;
  s->array = malloc(sizeof(int[s->size]));
  return s;
}

void print_stack(struct stack *s) {
  printf("STACK ");
  // TASK: Use the print function we defined in util!
}

void push(stack_t *s, int v) {
  if (s->top == s->size) {
    s->size *= 2;
        s->array = realloc(s->array, sizeof(int[s->size])));
  }
  s->array[s->top] = v;
  s->top += 1;
}

int pop(stack_t *s) {
  if (s->top == 0) {
    exit(1);
  }
  int v = s->array[s->top];
  s->top -= 1;
  return v;
}
