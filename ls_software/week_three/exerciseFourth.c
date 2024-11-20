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

int verify_input () {
    printf("enter five number for a new pin\n");
    int count = 3;
    int pin [] = {};
    int pin_input =0;
    char  args ;
    while (count > -1){
        if(!(scanf("%d\n", &pin_input))){
            printf("Please enter only number");
        }
        else {
            count -= 1;
            pin [count] = pin_input;
        }
    }
    return 0;
}

int main() {
  int value = 4;
  if(value !=5){
    printf("This is 1\n");
  }

  if(!(true * false )){
    printf("This is 1\n");
  }
  bool verify = true;
   if(verify != (true * true )){
      printf("This is 1\n");
  }
  else {
     printf("This is 0\n");
  }

  verify_input();
}
