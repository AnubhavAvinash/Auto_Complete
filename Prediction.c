#include "Trie.h" // Include the header file for the trie functions
#include "linkedList.h" // Include the header file for the linked list functions
#include <stdbool.h> // For bool type
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For POSIX getline
#include <assert.h> // For assert statements


// Function to check if a given node is the last node in the trie
bool isLastNode(struct trieNode* node)
{
    if (node == NULL) {
        return false;
    }
    // Check if any child node exists for the given node
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            return false;
        }
    }
    // If the node represents the end of a word, it is considered the last node
    return node->isWordEnd;
}

// Recursive function to generate suggestions for the given prefix
void suggestionsRec(struct trieNode* node, char* currPrefix, size_t prefixLen) {
    // If the current node represents the end of a word, insert the current prefix into the suggestion list
    if (node->isWordEnd) {
        insertNode(currPrefix);
    }

    // Traverse through all possible children of the current node
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            // Calculate the character corresponding to the current child node
            char child = 'a' + i;
            currPrefix[prefixLen] = child;
            currPrefix[prefixLen + 1] = '\0';
            suggestionsRec(node->children[i], currPrefix, prefixLen + 1);
        }
    }
}

// Function to generate auto suggestions for the given key
struct node* AutoSuggestions(const char key[])
{
    // Initialize the trie node pointer to the root of the trie
    struct trieNode* q = root;
    size_t length = strlen(key);

    // If the length of the key is less than 3, return the head of the linked list
    if (length < 3) {
        return head;
    }

    // If the key is not present in the trie, return the head of the linked list
    if (search(key, &q) < length) {
        return head;
    }
    // If the last node corresponding to the key is a leaf node, insert the key into the suggestion list
    if (isLastNode(q)) {
        insertNode(key);
        return head;
    }

    // Allocate memory for the prefix and duplicate the string in key into prefix
    char* prefix = strdup(key); 
    assert(prefix != NULL);
    // Generate suggestions recursively starting from the last node corresponding to the key
    suggestionsRec(q, prefix, length);
    free(prefix); // Free the allocated memory to avoid memory leaks
    return head; // Return head after printing suggestions
}
