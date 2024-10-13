#include <stdio.h> 
#include <stdlib.h>

// LINE COMMENT
/*BLOCK COMMENT*/




int main(void) {


int a, b;
a = 3;
a = 2 * a + a;
b = a * (1 - 1) - 2 * a;
printf(" The value of b is : %d\n", b);




int number, sum = 0, digit;
printf("Enter a number: ");
scanf("%d", &number);
while (number != 0) {
digit = number % 10;
sum = sum + digit;
number = number / 10;
}
printf("Result: %d\n", sum);
return 0;

}