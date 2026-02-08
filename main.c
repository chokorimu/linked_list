#include <stdio.h>
#include "array.h"
#include "linked_list.h"

int main() {
    struct node* head = NULL;
    DynamicArray arr;
    
    allocate(&head, 5);
    initArray(&arr, 5);

    insert(&head, 200, 0);
    insert(&head, 300, 1);
    insert(&head, 400, 2);
    insert(&head, 500, 3);
    insert(&head, 600, 4);
    addArray(&arr, 200);
    addArray(&arr, 300);
    addArray(&arr, 400);
    addArray(&arr, 500);
    addArray(&arr, 600);

    printf("elemen linked_list:\n");
    iterate(&head);
    printf("panjang linked_list: %d\n", length(&head));
    printf("---\n");
    
    printf("elemen array:\n");
    iterateArray(&arr);
    printf("panjang array: %d\n", lengthArray(&arr));
    return 0;
}
