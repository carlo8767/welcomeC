#include <stdio.h>
#include <stdlib.h>


int main () {


    int value = 1;

    int *a = &value;
    printf("The pointer value is %d\n", *a);
    printf("The pointer value is %p\n", a);
    int allocation;
    int *dynamicMemo = malloc(5*sizeof(int));
    printf("The memory allocated is %li\n", sizeof(dynamicMemo));
    free(dynamicMemo); 
    dynamicMemo = NULL;
    return 0;
}
