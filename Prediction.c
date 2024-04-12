#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // For bool type
#include "Trie.h" // Include the header file for the trie functions
#include "linkedList.h" // Include the header file for the linked list functions

bool isLastNode(struct trieNode* node) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (node->children[i])
            return false;
    return true;
}

void suggestionsRec(struct trieNode* node, char* currPrefix) {
    if (node->isWordEnd) {
        printf("%s\n", currPrefix);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            char child = 'a' + i;
            char* newPrefix = malloc(strlen(currPrefix) + 2); // +2 for the new char and null terminator
            if (newPrefix == NULL) {
                fprintf(stderr, "Failed to allocate memory for new prefix.\n");
                return;
            }
            strcpy(newPrefix, currPrefix);
            newPrefix[strlen(currPrefix)] = child;
            newPrefix[strlen(currPrefix) + 1] = '\0';
            suggestionsRec(node->children[i], newPrefix);
            free(newPrefix); // Free the allocated memory to avoid memory leaks
        }
    }
}

struct node* AutoSuggestions(char key[]) {
    int length = strlen(key);
    if (length < 3){
        return head; // Return head if the length of the key is less than 3
    }
    struct trieNode* q = root;    
    int index;

    for (int i = 0; i < length; i++) {
        index = key[i] - 'a';
        if (!q->children[index])
            return head; // Return head if no string in the Trie has this prefix
        q = q->children[index];
    }

    if (isLastNode(q)) {
        printf("%s\n", key);
        insertNode(key);
        return head; // Return head if the prefix is present as a word but there is no subtree below the last matching node.
    }

    char* prefix = malloc(length + 1); // +1 for the null terminator
    if (prefix == NULL) {
        fprintf(stderr, "Failed to allocate memory for prefix.\n");
        return head; // Return head in case of memory allocation failure
    }
    strcpy(prefix, key);
    suggestionsRec(q, prefix);
    free(prefix); // Free the allocated memory to avoid memory leaks
    return head; // Return head after printing suggestions
}
