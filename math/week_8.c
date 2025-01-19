#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct ListElement {
	int data;
	struct ListElement* next;
} ListElement;

typedef struct List {
    ListElement* head;
} List;

ListElement* new_list_element(int value, ListElement* ptr) {
    ListElement* new_element = malloc(sizeof(ListElement));
    new_element->data = value;
    new_element->next = ptr;
    return new_element;
}

List* new_list() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void free_list(List* list) {
    ListElement* head = list->head;
    list->head = NULL;
    ListElement* previous = NULL;
    while (head != NULL) {
        previous = head;
        head = head->next;
        free(previous);
    }
    free(list);
}

int size (List* list) {
    ListElement* current = list->head;
    int count =0;
    // INSIDE SIZE THERE IS A MISTAKE CARLO
    while(current !=NULL) {
        count = current->data;
        current = current->next;

    }
    return count;
}


void append (List* list, int value) {
    ListElement* current = list->head;
    if (current == NULL) {
            current = new_list_element(value,NULL);
            list->head = current;
        return;
    }
    while(current->next !=NULL) {
        current = current->next;
    }
    ListElement* new_element = new_list_element(value, NULL);
    current->next = new_element;
}

int get(List* list, int pos) {
    if ((pos < 0) || (pos >= size(list))) {
        return 0;
    }
    ListElement* current = list->head;
    for (int i = 0; i < pos; i++) {
        current = current->next;
    }
    return current->data;
}

void insert(List* list, int pos, int value) {
    // WRONG METHOD SIZE
    if ((list == NULL )|| (pos < 0) || (pos >size(list))) {
        return;
    }
    ListElement* current = list->head;
    if (pos == 0) {
          list->head = new_list_element(value, current);
        return;
    }
    for(int i = 0; i < pos-1; i++) {
        current = current->next;
    }
    ListElement* holder = current->next;
    ListElement* new_element = new_list_element(value,holder);
    current->next = new_element;
    return;
}

void remove_from(List* list, int pos) {
    if ((list == NULL )||(pos < 0) || (pos >=size(list))) {
        return;
    }
    ListElement* current = list->head;
    // Special case: element at beginning of list
    if (pos == 0) {
        list->head = current->next;
        current->next = NULL;
        free(current);
        return;
    }
    // find element before the one to remove
    for(int i = 0; i < pos-1; i++) {
        current = current->next;
    }
    // remove element from list, but safe it first to free memory
    ListElement* to_remove = current->next;
    current->next = (current->next)->next;
    free(to_remove);
}

void print_list(List* list) {
    if (list == NULL) {
        printf("NULL\n");
    }
    ListElement* curr = list->head;
    printf("[");
    while(curr != NULL) {
        printf("(%p, %d)", curr->next, curr->data);
        if (curr->next != NULL) {
            printf(", ");
        }
        curr = curr->next;
    }
    printf("]\n");
}


// CARLO
int sum_list (List* list) {
     ListElement* first = list->head;
     int sum = 0;
     if(first->next!=NULL){
        sum += first->data; 
     }
    while (first->next!=NULL){
        first = first->next;
        sum += first->data; 
        
    }
    return sum;
}


/* CARLO
void concat(List* list1, List* list2) {
    // SIZE VERIFICATION
    int value = second_size(list1);
    // int second_value = second_size(list2);

    List* new_head = malloc(sizeof(List));
    new_head->head = list1->head;
    int size_head = second_size(new_head);
    ListElement* concat = list2->head;

    // APPEND JUST THE HEAD DATA
    concat = list2->head;
    concat->next = list2->head->next;
    // CONCATENATE OTHER DATA
    append(new_head, concat->data);
    while(concat->next!=NULL){
        value  = second_size(new_head)+1;
        append(new_head, concat->data);
        concat = concat->next;
    }
    int final_size_head = second_size(new_head);
}
*/

// CARLO
void second_concat(List* list1, List* list2) {
    List* new_head = malloc(sizeof(List));
    new_head->head = list1->head;
    ListElement* listElement = new_head->head;
    while (listElement->next!=NULL){
        listElement = listElement->next;
    } 
    listElement->next = list2->head->next;
}



int second_size (List* list) {
    ListElement* current = list->head;
    int count =0;
    // INSIDE SIZE THERE IS A MISTAKE CARLO
    while(current !=NULL) {
        count+=1;
        current = current->next;
    

    }
    return count;
}


List* init(int array[], int length) {
    List* init = new_list();
 
    for(int i=0; i<length; i++){
        int value = array[i];
        append(init, value); 
    }
    return init;
}

void reverse(List* list) {
}



int main() {
    List* list = new_list();
    append(list, 1);
    append(list, 2);
    append(list, 3);
    append(list, 4); 
    insert(list, 1, 5);
    insert(list, 3, 6); 
    insert(list, 0, 7);
    int size_value = size (list);
    insert(list, size_value,8);
 //Test sum:
 // printf("Sum: %d", sum(list));
  int verify_sum  = sum_list(list);
  assert((verify_sum == 36) && "Sum is not 36\n");
  printf("Assertion passed\n");

 //Test concatenation
   List* list2 = new_list();
    append(list2, 255);
    second_concat(list, list2);
    printf("concatenation:\n");
    print_list(list);

// Test init:
    int test[] = {14,15,2,4};
    List* list3= init(test, 4);
   print_list(list3);

// Test reverse
//    printf("reverse:\n");
//    reverse(list);
//    print_list(list);
//
//    printf("reverse:\n");
//    reverse(list);
//    print_list(list);

}
