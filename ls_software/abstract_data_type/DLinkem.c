
#include <stdio.h>
#include <stdlib.h>



typedef struct DListElement {
  struct DListElement* previous;
  int value;
  struct DListElement* next;
} DListElement;

typedef struct DList {
    DListElement* head;
    DListElement* tail;
} DList;

int getElementAboveX(DList* list, int x) {
    DListElement* dELement = list -> tail;
    int value = -1;
    while (dELement !=NULL){
        int verify =  dELement -> value;
        dELement = dELement -> previous;
        if(verify > x){  
             value = verify;
            break;
        }
    }
    return value;
}

int main (){
 	
DListElement* first = malloc(sizeof(DListElement));
first->value = 3;
first->previous = NULL;

DListElement* second = malloc(sizeof(DListElement));
second->value = 5;
second->previous=first;
second->next = NULL;

first->next = second;

DList* list = malloc(sizeof(DList));
list->head = first;
list->tail = second;

int value = getElementAboveX(list, 2);
printf("%d", value);
// expected 5
}