#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

bool is_empty(struct node* head) {
    return (head == NULL);
}

void allocate(struct node** head, int size) {
    if(size <= 0) return;

    for(int i = 0; i < size; i++) {
        struct node* new_node = malloc(sizeof(struct node));
        new_node->value = 0;
        new_node->is_node_empty = true; // Tandai kosong di awal
        new_node->next = NULL;

        if(*head == NULL) {
            *head = new_node;
        } else {
            struct node* cursor = *head;
            while(cursor->next != NULL) cursor = cursor->next;
            cursor->next = new_node;
        }
    }
}
void deallocate(struct node** head, int size) {
    for(int i=0; i != size; i++) {
        if((*head)->next == NULL) {
            free(*head);
            *head = NULL;
            return;
        }
    
        struct node* cursor = *head;
        while(cursor->next->next != NULL) {
            cursor=cursor->next;
        }
        free(cursor->next);
        cursor->next = NULL;
    }
}


void insert(struct node** head, int new_value, int position) {
    struct node* cursor = *head;

    // 1. Cari node di posisi yang dituju
    for(int i = 0; i != position; i++) {
        if(cursor->next == NULL) return; // Berhenti jika list tidak sepanjang itu
        cursor = cursor->next;
    }

    // 2. Jika node tersebut kosong, tinggal isi (Logika Overwrite)
    if(cursor->is_node_empty == true) {
        cursor->value = new_value;
        cursor->is_node_empty = false;
    } 
    // 3. JIKA SUDAH ADA ISINYA, MAKA GESER (Logika Shift/Oper Nilai)
    else {
        int value_yang_dioper = cursor->value; // Amankan nilai lama
        cursor->value = new_value;            // Masukkan nilai baru
        
        // Oper semua nilai ke kanan sampai ujung
        while(cursor->next != NULL) {
            cursor = cursor->next;
            
            int cadangan = cursor->value;    // Amankan nilai di node ini
            cursor->value = value_yang_dioper; // Isi dengan nilai kiriman dari kiri
            cursor->is_node_empty = false;   // Tandai sudah berisi
            
            value_yang_dioper = cadangan;    // Nilai cadangan siap dioper lagi
        }
    }
}

void delete_node(struct node** head, int position) {
    struct node* next_address;
    struct node* cursor = *head;
    if(position == 0) {
        if(cursor->next == NULL) {
            free(*head);
            *head = NULL;
            return;
        }
        next_address = cursor->next;
        free(*head);
        *head = next_address;
        return;
    }

    for(int i = 0; i != position-1; i++) {
        if(cursor->next == NULL) {
            return;
        }
        cursor=cursor->next;
    }

    if(cursor->next->next == NULL) {
        free(cursor->next);
        cursor->next = NULL;
        return;
    }
    next_address = cursor->next->next;
    free(cursor->next);
    cursor->next = next_address;
}

void destroy(struct node** head) {
    while(*head != NULL) {
        if((*head)->next == NULL) {
            free(*head);
            *head = NULL;
            return;
        }

        struct node* cursor = *head;
        while(cursor->next->next != NULL) {
            cursor=cursor->next;
        }
        free(cursor->next);
        cursor->next = NULL;
    }
}

void iterate(struct node* head) {
    int i = 0;
    for(struct node* cursor = head; cursor != NULL; cursor=cursor->next) {
        printf("#%d: %d\n", i, cursor->value);
        i++;
    }
}

int length(struct node* head) { // Gunakan struct node* bukan struct node**
    int len = 0;
    struct node* cursor = head;
    while(cursor != NULL) {
        if(cursor->is_node_empty == false) {
            len++;
        }
        cursor = cursor->next;
    }
    return len;
}

int search(struct node* head, int searched_value) {
    int amount = 0;
    for(struct node* cursor = head; cursor != NULL; cursor=cursor->next) {
        if(cursor->value == searched_value) {
            amount++;
        }
    }
    return amount;
}
