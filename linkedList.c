#include <stdio.h>
#include <stdlib.h>

// Structure of Linked Lists
typedef struct info {
    int data;
    struct info* next;
} info;

// Function to create a new node
info* createNode(int data)
{
    info* newNode = (info*)malloc(sizeof(info));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(info** vertex, int size)
{
    for (int i = 0; i < size; ++i) {
        info* temp = vertex[i];
        printf("%d -->\t", i);
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Driver Code
int main()
{
    int size = 6;

    // Pointer To Pointer Array
    info** vertex;

    // Array of pointers to info struct of size
    vertex = (info**)malloc(size * sizeof(info*));

    // Initialize pointer array to NULL
    for (int i = 0; i < size; ++i) {
        vertex[i] = NULL;
    }

    // Traverse the pointer array
    for (int i = 0; i < size; ++i) {
        info* prev = NULL;
        int s = 4;

        while (s--) {
            info* n = createNode(i * s);

            if (vertex[i] == NULL) {
                vertex[i] = n;
            } else {
                prev->next = n;
            }
            prev = n;
        }
    }

    // Print the array of linked list
    printList(vertex, size);

    // Free dynamically allocated memory
    for (int i = 0; i < size; ++i) {
        info* temp = vertex[i];
        while (temp != NULL) {
            info* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(vertex);

    return 0;
}
