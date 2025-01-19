#include <stdio.h>
#include <stdbool.h>


int main() {
  double size = 10;
  int arr [10] = {};
  int num = 0;
  printf("Enter a number: ");
  scanf("%d", &num);
  if (num < 0){
    printf("Need a positive number!");
    num = 1;
    }
  // Here num is positive because of the check above
  for (int i = 0; i < size; i++) {
        arr[i] = (num - 1) * (i + 1);
      }

  double mult = 1;
  for (int i = 1; i < size; i += 1) {
         double operation = (double)arr[i - 1]; 
         mult *= operation;
      }
    printf("The result is %lf", mult);
    return 0;
}
