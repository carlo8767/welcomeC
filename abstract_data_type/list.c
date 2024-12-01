#include <stdio.h>
#include <stdlib.h>


typedef struct ListElement {
    struct ListElement* next;
    int value;
} ListElement;

typedef struct List {
    ListElement* anchor;
} List;


int getSize (List* listHead ){
    ListElement* listElement = listHead->anchor;
    int count = 0;
    while(listElement!=NULL){
       listElement = listElement->next;
       count ++;
    }
    return count;
} 

void printValue (List* listHead){
     ListElement* listElement = listHead->anchor;
    while(listElement!=NULL){
        int value = listElement->value;
        listElement = listElement->next;
        printf("The value is %d\n", value);
    }
}

int getFirstAboveX(List* list, int x){
    ListElement* listElement = list ->anchor;
    int value =0;
    while(listElement!=NULL){
        value = listElement -> value;
        listElement = listElement -> next;
    }
    return value;
}

int getNthAboveX(List* list, int x, int n){
    ListElement* element = list -> anchor;
    int values = -1;
    for(int i =0; i<=n ; i++){
        int verify = element->value;
        if(i == n){
             if(verify > x ){
            values = element->value;
            }
        }
        element = element -> next;
    }
    return values;
}

int main (){

List* list = malloc(sizeof(List));
list->anchor = malloc(sizeof(ListElement));
list->anchor->value = 5;
list->anchor->next = NULL;
printf("%d", getNthAboveX(list, 3, 1));

int *arr  = malloc(sizeof(int));
int *second_arr;
second_arr = arr;
 	

List* listHead = malloc(sizeof(List));
listHead->anchor = malloc(sizeof(ListElement));
listHead->anchor->value = 5;

ListElement* second = malloc(sizeof(ListElement));
second->value = 8;
listHead->anchor->next = second;

ListElement* third = malloc(sizeof(ListElement));
third->value = 9;
second->next  = third;

ListElement* fourth = malloc(sizeof(ListElement));
fourth->value = 7;
third->next = fourth;
getSize(listHead);
printValue(listHead);

}