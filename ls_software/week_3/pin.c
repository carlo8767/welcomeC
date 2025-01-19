#include <stdio.h>
#include <stdbool.h>

// This function computes how many digits a number has
int digits(int number) {
  int digits = 0;
  while (number > 0) {
    digits += 1;
    number /= 10;
  }
  return digits;
}

int main() {
  // TASK: Read a number from the user
}
