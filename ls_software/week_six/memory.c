#include <stdio.h>
#include <stdlib.h>


int main (){
int counter [0];
int *arrrr;
printf("The values is %d\n", counter);


int memo = 1;
printf("The content is %d\n", memo);
printf("The addreess is %ls\n", &memo);
int *values = memo;
printf("The values is %d\n", &values);

int arr [3] = {1,2,3};
printf("The size of the array is %lu\n", sizeof(arr));
printf("The address of 0 array is  %d\n", &arr[0]);
printf("The address of 1  array %d\n", &arr[1]);
printf("The address of 2  array %d\n", &arr[2]);
int text;
printf("The size of my text is %d\n", sizeof(text));
int *dynamic = malloc(2* text);
printf("The address of my text is %d\n", dynamic);
printf("The size of my dynamic is %d\n", sizeof(dynamic));
// the result is similar to an array
dynamic [15] = 2;
printf("The value of my dynamic is %d\n", dynamic[15]);
free(dynamic);
dynamic = NULL;
printf("The size of my dynamic is %d\n", sizeof(dynamic));

}