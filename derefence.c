#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>




int main(){
double e = 15;
double * var = &e;
double *a = var;
printf("%lf\n", *a);


  int number = 1;
  int *value = &number;
  int *dereferences = *value;
  printf("%d\n",dereferences); // PRINT THE VALUE OF NUMBER
  printf("%d\n",dereferences); // PRINT THE ADDRESS STORED IN VALUE
}