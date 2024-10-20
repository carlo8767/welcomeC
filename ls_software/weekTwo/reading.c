#include <stdio.h>
#include <stdlib.h>


int main() {
  int x, y;
  printf("Please enter two numbers:\n");
  scanf("%d %d", &x, &y);
  double average = (x - y) / 2;
  double maximum = 0.0;
  if (x > y) { // We haven't learnt "if" yet
    maximum = x;
  } else {
    maximum = y;
  }

  // Print the response
 // printf("The average of %d and %d is %lf\n", &x, &y, &average);
  printf("The maximum is %0.2lf\n", maximum);
  return 0;
}
