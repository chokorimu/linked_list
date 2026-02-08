#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    bool is_node_empty;
    struct node* next;
};

void allocate(struct node** head, int size);
bool is_empty(struct node* head);
void deallocate(struct node** head, int size);
void insert(struct node** head, int new_value, int position);
void delete_node(struct node** head, int position);
void destroy(struct node** head);
void iterate(struct node** head);
int length(struct node** head);
int search(struct node** head, int searched_value);

#endif