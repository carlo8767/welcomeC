 
  #include <stdio.h> 
  #include <stdlib.h>
  #include <stdbool.h>


int addPointers(int* a, int* b) {
    printf("The address is %p", a);
    int sum = *a+*b;
    return sum;
}


typedef struct Product {
  char name[20];
  int price;
} Product;



  int main (){
    int c = 3;
    int bb = 5;
    int *d = &c;
    int *f = &bb;
    addPointers(d, f);
  }