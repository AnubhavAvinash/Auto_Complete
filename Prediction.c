#include "Trie.h" // Include the header file for the trie functions
#include "linkedList.h" // Include the header file for the linked list functions
#include <stdbool.h> // For bool type
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool isLastNode(struct trieNode* node) {
    if (node == NULL) {
        return false;
    }
    printf("Checking if node is the last node...\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            printf("Node has a child at index %d\n", i);
            return false;
        }
    }
    printf("Node is the last node.\n");
    return true;
}


void suggestionsRec(struct trieNode* node, char* currPrefix) {
    if (node == NULL) {
        return;
    }
    if (node->isWordEnd) {
        insertNode(currPrefix);
    }

    for (int level = 0; level < ALPHABET_SIZE; level++) {
        if (node->children[level]) {
            char child = 'a' + level;
            char* newPrefix = malloc(strlen(currPrefix) + 2); // +2 for the new char and null terminator
            if (newPrefix == NULL) {
                fprintf(stderr, "Failed to allocate memory for new prefix.\n");
                return;
            }
            strcpy(newPrefix, currPrefix);
            newPrefix[strlen(currPrefix)] = child;
            newPrefix[strlen(currPrefix) + 1] = '\0';
            suggestionsRec(node->children[level], newPrefix);
            free(newPrefix); // Free the allocated memory to avoid memory leaks
        }
    }
}

struct node* AutoSuggestions(char key[]) {
    printf("AutoSuggestions called with key: %s\n", key);
    int length = strlen(key);
    int index;
    if (length < 3) {
        return head; // Return head if the length of the key is less than 3
    }
    struct trieNode* q = root;
    if (q == NULL) {
        return head; // Return head if root is NULL
    }
    
    for (int i = 0; i < length; i++) {
        index = key[i] - 'a';
        if (!q->children[index]) {
            printf("%d\n", q->isWordEnd);
            return head;
        } // Return head if no string in the Trie has this prefix
        q = q->children[index];
    }


    if (isLastNode(q)) {
        insertNode(key);
        return head; // Return head if the prefix is present as a word but there is no subtree below the last matching node.
    }

    char* prefix = malloc(length + 1); // +1 for the null terminator
    if (prefix == NULL) {
        fprintf(stderr, "Failed to allocate memory for prefix.\n");
        return head; // Return head in case of memory allocation failure
    }
    strcpy(prefix, key);
    //suggestionsRec(q, prefix);
    free(prefix); // Free the allocated memory to avoid memory leaks
    return head; // Return head after printing suggestions
}
