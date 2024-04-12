#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
    char data[50]; // Stores the prediction
    struct node* next; // Pointer to the next node
};

extern struct node* head;

struct node* createNode(); // Creates a new node
void insertNode(char prediction[]); // Inserts a new node
void printLinkedlist(struct node* p); // Prints the linked list
void freeList(struct node** head); // Frees the linked list

#endif // LINKEDLIST_H
