#include <stdio.h>
#include <stdlib.h>


typedef struct ListElement {
    struct ListElement* next;
    int value;
} ListElement;

typedef struct List {
    ListElement* anchor;
} List;




int getFirstAboveX(List* list, int x){
    
    ListElement* anchor = list->anchor;
    int verify;
    while(anchor->next!=NULL){
        verify = anchor->value; 
        if( verify> x ){
            return verify;
        }
        anchor = anchor->next;
    }
}


void insert_element (List* listHead, int value, int position){
    ListElement* list = listHead->anchor;
    ListElement* newElement = malloc(sizeof(ListElement));
    int count = 0;
    while(list->next!=NULL){
        if(count == position) {
            ListElement* old = list;
            // store the adress after one
            newElement->next  = list->next;
            newElement->value = value; 
            // store the previous with the new one    
            old->next = newElement;

            list = old->next;  
        }
        else {
            list = list->next;
        }
        
        count ++;
    }
    list = listHead->anchor;
    while(list->next !=NULL){
        printf("The values are %d\n", list->value);
        list = list->next;
    }
}

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
int values = 3;
int *dere_values = &values;
int **second_dere = &dere_values;
*second_dere+=2;
printf("%p/n", values);


List* list = malloc(sizeof(List));
list->anchor = malloc(sizeof(ListElement));
list->anchor->value = 5;
list->anchor->next = NULL;
// printf("%d", getNthAboveX(list, 3, 1));
getFirstAboveX(list, 4);

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

insert_element(listHead, 89, 2);
ListElement* fourth = malloc(sizeof(ListElement));
fourth->value = 7;
third->next = fourth;
getSize(listHead);

}