#include<stdio.h>
#include<stdlib.h>

// DECLARING A FUNCTION
void swapSumUp(int a, int b){
    a = 10;
    b = 5;
    printf("%d\n",a+b);
}


int main (void){
      // REMEMBER THAT C IS PASSWING BY VALUE 
    // AND IF YOU CREATE A COPY IT'S WILL CREATE A 
    int a = 10;
    int b = 11;
    swapSumUp(a,b);
    printf("%d\n C is pass by value", a+b);
    int array[10], secondArray[10];
 
}