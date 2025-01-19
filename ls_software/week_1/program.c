#include <stdio.h>

int main() {
  int a, b;

  // This part here reads two numbers from the user
  printf("Enter two numbers: ");
  scanf("%d %d", &a, &b);

  // Here some computation happens
  int c = 0;
  while (a >= b) {
    a = a - b;
    c = c + 1;
  }

  // RESULT ENTER 10 and 5 result in 2
  // RESULT ENTER 20 3 result in 6 
  // IF THE USER ENTER A CHAR OR A DOUBLE

  // This prints the result
  printf("The magic result is %d\n", c);
}
