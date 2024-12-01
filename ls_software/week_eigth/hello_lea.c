#include<stdio.h>
#include<string.h>



int main (){
      int a = 5;
  int *pointerss = &a;
  *pointerss += 5;
    char s [101];
    scanf("%s", s);
    printf("Hello %s!", s );
}