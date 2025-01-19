#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H	1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef  struct list  {
int *data;
int length;
int free_index;
} ArrayList;


bool equalsArraylist ( ArrayList *arrayList, ArrayList *other_arrayList ) {
   bool verify = false;
   if(arrayList == other_arrayList){
        verify = true;
        return verify;
    }
    for (int i =0; i < arrayList->length; i++ ){
        int value = arrayList->data[i];
        int second_value = other_arrayList->data[i];

        if (value != second_value){
            verify = false;
            return verify;
        }
        else {
            verify = true;
        }
    }
    return verify;
    }


ArrayList *deep_copy (ArrayList *arrayList){
    ArrayList *deep_copy = (ArrayList*) malloc(sizeof(arrayList));
    deep_copy->free_index = arrayList->free_index;
    deep_copy->length = arrayList->length;
    deep_copy->data = (int*) malloc(sizeof(int[deep_copy->length]));
    for (int i = 0; i< arrayList->length; i++){
        deep_copy->data[i] = arrayList->data[i];
    }
    return deep_copy;
}

#endif /* <arrayList.h> included.  */