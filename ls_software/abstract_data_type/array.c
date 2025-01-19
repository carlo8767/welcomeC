#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Person {
  char name [10];
  int age;
  char nationality [10];
} People;


// EXERCISE THREE
void print_array () {
  int number[10] = {1024,1023,3,4,5,6,769,8,9,10};
  
  for(int i=0; i<10;i++){
    int* pointer = number+i;
    printf("The order is %d\n", *pointer);
  }
}

void order_array_point (int number [] ){
  for(int i =0; i<10; i++){
    int* smaller = number+i;
    for(int n = i+1;n < 10; n++){
      int* bigger = number+n;
      if (*bigger < *smaller){
         int smaller_value = *bigger;
         int bigger_value = *smaller;
         number [i] =  smaller_value;
         number [n] = bigger_value;
      }
    }
  }
   for(int i =0; i<10; i++){
     printf("The order element is %d\n",number [i] );
   }  

}




void order_array (int number [] ){
  for(int i =0; i<10; i++){
    int smaller = number [i];
    for(int n = i+1;n < 10; n++){
      int bigger  = number [n];
      if (bigger < smaller){
         number [i] = bigger;
         number [n] = smaller;
         smaller = bigger;
      }
    }
  }
   for(int i =0; i<10; i++){
     printf("The order element is %d\n",number [i] );
   }  

}

People* set_People (int size ) {
  People *point = malloc(size*sizeof(People));
  return point;
}

People* new_person ( char name [10], int age, char nationality [10]){
  People *point = malloc(sizeof(People));
  strncpy(point->name, name, 10);
  strncpy(point->nationality, nationality, 10);
  point->age = age;
  return point;
}

void freePeople ( People *people){
    free(people->name);
    free(people->nationality);
}



int main (){

 // People* pointer = new_person("Pippo", 19, "Ghana");
 // freePeople(pointer);
  int number[10] = {99,33,15,4,54,6,8,88,9,10};
  order_array_point(number);



 

}