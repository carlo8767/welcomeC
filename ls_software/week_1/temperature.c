#include <stdio.h>
#include <stdbool.h>

int main() {
  double fahrenheit;
  printf("Enter Fahrenheit: ");
  // LONG DOUBLE SPECIFY
  scanf("%lf", &fahrenheit);
  double celsius;
  // ASSIGN THE CORRECT VALUE TO "celsius"

  celsius = (fahrenheit -32)/1.8;
  printf("Value in Celsius: %lf\n", celsius);
  return 0;
}
