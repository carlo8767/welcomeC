#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>





void resulted (int x){
  printf("The sum is %d\n", x);
}


void addition (int a, int b, void *(callback)(int)){
  int resultSum = a + b;
  (*callback)(resultSum);
}

int main() {
  addition(3,5, resulted);
  int head = 8;
  int *pointers = &head;
  int child = head;

  head = 9;
  printf("%d , %d ", child, *pointers);

  double n = 5.0;

  int a = 5, b = 3;
  int zz = 1;
  printf("The division between %d %d  equals %d\n", zz, b, zz/b);
  a = a * 3;
  b = a + b + b;
  printf("%d\n", b);
  fork();
  printf("Hello\r\n");
  return 0;
}