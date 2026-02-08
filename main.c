#include <stdio.h>
#include "linked_list.h"
#include "array.h"

int main() {
    struct node* head = NULL; // Pastikan baris ini ada!
    allocate(&head, 5);
    insert(&head, 200, 0); //{0, 0, 200, 0, 0}
    insert(&head, 400, 1); //{0, 0, 200, 400, 0}
    insert(&head, 300, 1); //{0, 0, 200, 300, 400} ------> pinginnya hasilnya gitu
    iterate(&head);
    printf("length=%d\n", length(&head));
    return 0;
}
