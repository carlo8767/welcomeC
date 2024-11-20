#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int main() {
  // The following two lines get a (sort of) random number 0 - 9
  srand(time(NULL));
  int number = rand() % 10;
  int user_number;
  int control = 0;
  while(!control){
     printf("Please enter your guess: ");
    if(!scanf("%d", &user_number)){
         printf("Please enter a number");
      };
    // TASK: Read the guess of the user

    if(number == user_number){
      control = 1;
      printf("The number %d is the correct answer", number);
    }
    else{
      printf("The number %d is the correct answer", user_number);
    }
  }
 

  // TASK: Compare number and user_number, indicate whether the user is correct or not


  printf("My number was %d\n", number);
}
