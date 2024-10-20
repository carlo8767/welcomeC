#include <stdio.h>

int main (){
const int multiplicator = 2;
printf("-> Please input a number\n");
int input_number;
scanf("%d", &input_number);
int double_input = input_number * multiplicator;
printf("--> %d times %d is %d\n ", input_number, multiplicator, double_input);
}
