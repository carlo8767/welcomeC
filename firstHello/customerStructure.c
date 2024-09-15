#include <stdio.h> 
#include <stdlib.h>

struct Customer {
    char name [1][15];
    int age;
};


int main (){
    struct Customer firstCustomer = {"Carlo", 33};
   // strcpy(firstCustomer.name , "Egzona");
    printf("%s", firstCustomer.name[0]);
}