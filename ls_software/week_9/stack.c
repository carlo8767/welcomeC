#include <stdlib.h>
#include "stack.h"


int main() {
  stack_t *s = make_stack();
  if (size(s) != 0) {
    fail("Size is wrong!");
  }
  push(s, 1);
  push(s, 2);
  peek(s);
  if (size(s) != 2) {
    fail("Size is wrong!");
  }
  if (pop(s) != 2) {
    fail("Push / Pop is wrong!");
  }

  const int size = 100000;
  srand(0);
  int array[size];
  for (int i = 0; i < size; i++) {
    int value = rand();
    array[i] = value;
    push(s, value);
    if (pop(s) != value) {
      fail("Push / Pop is wrong!");
    }
    push(s, value);
  }
  for (int i = size - 1; i >= 0; i--) {
    if (pop(s) != array[i]) {
      fail("Push / Pop is wrong!");
    }
  }

  push(s, 1);
  push(s, 2);
  stack_t* new_stack =add_all(s);
  destroy_stack(s);
  destroy_stack(new_stack);
}
