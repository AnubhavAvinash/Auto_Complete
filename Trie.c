#include <stdbool.h> // Include the standard library for the bool type
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For POSIX getline

#define ALPHABET_SIZE 26 // Define the size of the alphabet

struct trieNode {
    struct trieNode* children[ALPHABET_SIZE]; // Array to hold child nodes for each alphabet character
    bool isWordEnd; // Flag to mark the end of a word
};

struct trieNode* root = NULL; // Global variable to store the root of the trie

// Function to create a new trie node
struct trieNode* create_trieNode()
{
    struct trieNode* q = (struct trieNode*)malloc(sizeof(struct trieNode)); // Allocate memory for the new node
    if (q == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    q->isWordEnd = false; // Initialize isWordEnd flag to false
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        q->children[i] = NULL; // Initialize all children pointers to NULL
    }
    return q;
}

// Function to insert a word into the trie
void insert_trieNode(char key[])
{
    int length = strlen(key);
    if (root == NULL) {
        root = create_trieNode(); // Create root node if it doesn't exist
    }
    struct trieNode* q = root;
    for (int level = 0; key[level] != '\0'; level++) {
        int index = key[level] - 'a'; // Calculate index for current character
        if (index >= 0 && index < ALPHABET_SIZE) {
            if (q->children[index] == NULL) {
                q->children[index] = create_trieNode(); // Create a new node if it doesn't exist
            }
            q = q->children[index];
        }
    }
    q->isWordEnd = true; // Mark the last node as the end of a word
}

// Function to search for a word in the trie
int search(const char key[], struct trieNode** head)
{
    struct trieNode* q = root;
    size_t level = 0;
    for (; key[level] != '\0'; level++) {
        int index = key[level] - 'a'; // Calculate index for current character
        if (q->children[index] == NULL) {
            return level;
        }
        q = q->children[index];
    }
    *head = q; // Assign the last node visited to the head pointer
    return level; // Return the level reached in the trie
}

// Function to free all nodes in the trie
void free_all(struct trieNode* curs)
{
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (curs->children[i] != NULL) {
            free_all(curs->children[i]); // Recursively free child nodes
        }
    }
    free(curs); // Free the current node
}
