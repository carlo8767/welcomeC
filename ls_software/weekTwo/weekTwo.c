#include <stdio.h>
#include <stdlib.h>


int main (){


    int promoteA = 9, promoteB = 2;
    double ts = 5.00;
    // 5 with the fact is define as double is promote to double 
    double resultPromotion = ts / promoteB;
    printf("%lf\n", resultPromotion );
    printf("%lf\n", resultPromotion );


    int aa = 5, nn = 3;
    int resultss = aa + nn * 2 - aa / nn;
    printf("The result is %d\n ", aa/nn);
     


    char not_valid [] = "";
    int value = 99;
    // the order of the operations is from right to left
    value += (10 / 10);
    printf("%d\n", value);
    value = 99;
    // AT LINE 14 The value is still 99 POST INCREMENT
    printf("%d\n", value++);
    printf("%d\n", ++value);
    // ORDEER OPERATIONS
    int order = value + 10/5;
     printf("%d\n", order);
    // INT DIVSION THE DECIMAL PART WILL TRUNCATED
    printf("%d\n", 102/50);
    // INT DIVSION THE DECIMAL PART WILL TRUNCATED
    double result = 102;
    printf("%lf\n", result/50);
    // SOME FLAG IN ACTION
     double decimal_two_spaces = 102;
    printf("%.2lf\n", decimal_two_spaces);
    printf("+:%.2lf\n",decimal_two_spaces);
    printf("insert two number \n");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("The sum is %d\n", a + b);
    int x, y = 4;
    double z;
    printf("Enter values:\n ");
    scanf("%lf %d", &z, &x);
    printf("z minus is %2lf\n", z - x );
    return 0;
}
