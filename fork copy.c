#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


void hello(){
  printf("hellon\n");
}

void world(){
 printf("hello\n");
}

void test(void *(callback ())){
  printf("execute\n");
  callback();
}


int main(){
  
  int val = 5;
  int *pointer = &val;
  int **pointer2 = &pointer;
  printf("val: %d\n", **pointer2);


  
}