#ifndef _STACKLIB_
#define _STACKLIB_



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Stack {
  int *array;
  int size;
  int fill_level;

}stack_t;


stack_t* make_stack (){
  stack_t* stack_init = (stack_t*) malloc(sizeof(stack_t));
  stack_init->array =  (int*)malloc(sizeof(int [0]));
  stack_init->size =0;
  stack_init->fill_level = 0;
  return stack_init;
}

void destroy_stack (stack_t* stack ){
  free(stack->array);
  free(stack);
  stack = NULL;
}

int size (stack_t* stack){
  return stack->size;
}

void push (stack_t* stack, int value){
  stack->size += 1;
  stack->array = (int*)realloc( stack->array, sizeof(int[stack->size]));
  stack->fill_level = stack->fill_level+1;
  int index =  stack->fill_level-1;
  stack->array[index] = value;
}


int pop (stack_t* stack){
    int fill_levels = stack->fill_level;
    int values_remove = stack->array[fill_levels-1];
    stack->fill_level = fill_levels-1;
    stack->size = fill_levels-1;
    // YOU DO NOT NEED REALLOC BECAUSE WITH FILL LEVEL YOU 
    // HIDE THE CONTENT OF THE LAST INDEX
    stack->array = (int*)realloc(stack->array, sizeof(int[stack->size]));
    return values_remove;
}

int peek (stack_t* stack){
    int peek_index = stack->fill_level;
    int peek_value = stack->array[peek_index-1];
    return peek_value;
}


// TASK: Define a struct for the stack and introduce the type alias stack_t

// TASK: Implement the required functions make_stack, destroy_stack, size, push,
// and pop.

// Do not modify below!

void fail(char msg[]) {
  printf("%s", msg);
  exit(1);
}
#endif