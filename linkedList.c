#include "Trie.h" // To inherit the free function to free the trie when the program exits
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing a node in the linked list
struct node {
    char* data; // Pointer to dynamically allocated data
    struct node* next; // Pointer to the next node in the linked list
};

// Global variable to store the head of the linked list
struct node* head = NULL;

// Function to create a new node
struct node* createNode(const char* data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the new node
    if (newNode == NULL) {
        // If memory allocation fails, print an error message and exit the program
        fprintf(stderr, "Failed to allocate memory for new node.\n");
        free_all(root);
        exit(1);
    }
    newNode->data = strdup(data); // Dynamically allocate memory for data
    if (newNode->data == NULL) {
        fprintf(stderr, "Failed to allocate memory for node data.\n");
        free(newNode);
        free_all(root);
        exit(1);
    }
    newNode->next = NULL; // Initialize the next pointer of the new node to NULL
    return newNode;
}

// Function to insert a new node with given prediction data into the linked list
void insertNode(const char* prediction)
{
    // Create a new node
    struct node* newNode = createNode(prediction);

    // Copy the prediction data into the data field of the new node
    if (head == NULL) {
        // If the linked list is empty, set the new node as the head
        head = newNode;
    } else {
        // If the linked list is not empty, traverse to the end and append the new node
        struct node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print all elements of the linked list
void printLinkedlist(struct node* p)
{
    // Traverse through the linked list and print the data of each node
    while (p != NULL) {
        printf("%s \n", p->data);
        p = p->next;
    }
}

// Function to free all nodes of the linked list
void freeList(struct node** head)
{
    struct node* tmp;
    // Traverse through the linked list and free each node
    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp->data); // Free dynamically allocated data
        free(tmp);
    }
    *head = NULL; // Set head to NULL after freeing all nodes
}
