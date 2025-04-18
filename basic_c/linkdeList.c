#include <stdio.h>
#include <stdlib.h>

// Define the ListElement structure
typedef struct ListElement {
    int value;
    struct ListElement* next;
} ListElement;

// Define the List structure
typedef struct List {
    ListElement* head;
    ListElement* last;
} List;

// Function to append an element to the list
void append(List* list, int value) {
    ListElement* newNode = malloc(sizeof(ListElement));
    newNode->value = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        // First element in the list
        list->head = newNode;
        list->last = newNode;
    } else {
        // Append to the end
        list->last->next = newNode;
        list->last = newNode;
    }
}

// Function to print the list
void printList(List* list) {


    ListElement* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int original = 3;
    int* values = &original;
    printf("%d\n", *values);
    printf("%d\n", original );

    List myList = { NULL, NULL };

    append(&myList, 10);
    append(&myList, 20);
    append(&myList, 30);

    printList(&myList);
    return 0;
}
