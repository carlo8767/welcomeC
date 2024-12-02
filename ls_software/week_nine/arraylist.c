#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrayList.h"






int main (){



    int a = 2;
            int * c = &a;
    // This print the values inside the pointer
    printf("the value of b is %p\n", c);
    // This print the adresss
    printf("the value of b is %p\n", &c);
    // This print the value of a
    printf("the value of b is %d\n", *c);



    ArrayList *arrayList = malloc(sizeof(ArrayList));
    arrayList->length = 10;
    arrayList->free_index = 0;
    arrayList->data = malloc (sizeof(int [10]));
    ArrayList *second = deep_copy(arrayList);
    second->data[0] = 9;
    second->free_index = 1;
    int values = arrayList->data [0];
    printf("the value is %d", values);
}