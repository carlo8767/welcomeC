#include<stdio.h>
#include<stdlib.h>

// DECLARING A FUNCTION
void swapSumUp(int a, int b){
    a = 10;
    b = 5; 
    // PRINT WITH THE CORRECT FORMAT
   printf("%s""%d""\n", "This is the sum PASS BY VALUE!!! ", a+b);
}

void swapSumUpPointer(int *changeA, int *changeB) {
  *changeA = 10;
  *changeB = 9;
   return;
}
int main (void){
      // REMEMBER THAT C IS PASSWING BY VALUE 
    // AND IF YOU CREATE A COPY IT'S WILL CREATE A 
    int a = 10;
    int b = 11;
    swapSumUp(a, b);
    // POINT TO THE OBJECT BUT IT WILL CALL BEFORE 
    swapSumUpPointer(&a, &b);
    printf("%s""%d""\n","this is the sum POINT TO THE MEMORY!! ", a+b);
}