#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing a node in the linked list
struct node {
    char* data; // Pointer to dynamically allocated data
    struct node* next; // Pointer to the next node in the linked list
};

// Global variable to store the head of the linked list
extern struct node* head;

// Function prototypes for the linked list operations
struct node* createNode(const char* data); // Create a new node with given data
void insertNode(const char* prediction); // Insert a new node with given prediction data into the linked list
void printLinkedlist(struct node* p); // Print all elements of the linked list
void freeList(struct node** head); // Free all nodes of the linked list

#endif // LINKEDLIST_H
