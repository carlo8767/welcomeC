#include <stdio.h>

int main () {
    int a, b;
    printf("-> please enter two number\n");
    scanf("%d %d",&a,&b);
    double fraction = (double)a/b;
    printf("--> The decimal representatin of %d %d\n--> the Integer part is %0.g\n--> and Decimal part is %g\n", a, b, fraction, fraction - (int)fraction);
    return 0;
}