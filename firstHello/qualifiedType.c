 
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

bool volatile waitChange = true;
static int count = 0;
const int worldAnswer = 42;


int optimizationRestricted (int *restrict firstPointer ,  int *restrict secondPointer , int *restrict value){

  *firstPointer += *value;
  *secondPointer += *value;
  return *value;
}

int noOptimizationRestricted (int *firstPointer ,  int *secondPointer, int *value){
  *firstPointer  += *value;
  *secondPointer += *value;
  return *value;
}



void  verifySignedUnsigend (int signed firstNum , int unsigned secondNum){

  if(secondNum < firstNum){
     printf("%d"" is greater than %d\n",firstNum, secondNum);
  }
  else {
    printf("%d is greater than " "%d\n", secondNum, firstNum);
  }
}

int QualifiedSum (int  *a,  int * restrict c){
    *c += 10;
    *a += *c;
    return 0;
}

// WAIT CAN BE CHANGE FOR
// FACTOR
int changeWait (){
  waitChange = false;
}




int main (void){

  int firstPointer = 10;
  int secondPonter = 8;
  int restrictVal = 99;
  optimizationRestricted(&firstPointer, &secondPonter, &restrictVal);
  noOptimizationRestricted(&firstPointer, &secondPonter, &restrictVal);

  while(waitChange){
    changeWait();
  }
  int a = 10;
  int c = 9;
  QualifiedSum(&a,&c);
  printf("%d\n", c);
  verifySignedUnsigend(10, -10);
}

