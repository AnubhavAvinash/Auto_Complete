#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[50];
    struct node* next;
};

struct node* head = NULL;

struct node* createNode() {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        fprintf(stderr, "Failed to allocate memory for new node.\n");
        exit(1);
    }
    newNode->next = NULL;
    return newNode;
}

void insertNode(char prediction[]) {
    struct node* newNode = createNode();
    strcpy(newNode->data, prediction);
    if (head == NULL) {
        head = newNode;
    } else {
        struct node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printLinkedlist(struct node* p) {
    while (p != NULL) {
        printf("%s ", p->data);
        p = p->next;
    }
    printf("\n");
}

void freeList(struct node** head) {
    struct node* tmp;
    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    *head = NULL; // Set head to NULL after freeing all nodes
}

