#include <stdio.h>
#include <stdlib.h>



int main () {

int size = 1;
int *dynamic = malloc(1* size);
printf("The address of my text is %p\n", dynamic);
printf("The size of my dynamic is %ld\n", sizeof(int *));

int array [] = {1,2,3};
printf("The address is  %p\n", &array [0]);
printf("The address is  %p\n", &array [1]);
}