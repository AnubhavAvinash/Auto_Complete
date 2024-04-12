#include "Trie.h" // Include the header file for the trie functions
#include "linkedList.h" // Include the header file for the linked list functions
#include <stdbool.h> // For bool type
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isLastNode(struct trieNode* node)
{
    if (node == NULL) {
        return false;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            return false;
        }
    }
    if (node->isWordEnd) {
        printf("Last node\n");
        return true;
    } else {
        printf("Not a last node\n");
        return false;
    }
}

void suggestionsRec(struct trieNode* node, char* currPrefix)
{
    if (node->isWordEnd) {
        insertNode(currPrefix);
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

struct node* AutoSuggestions(char key[])
{
    struct trieNode* q = root;
    int length = strlen(key);
    int level = 0;
    if (length < 3) {
        return head; // Return head if the length of the key is less than 3
        printf("Word too short\n");
    }

    if (search(key, q) < length) {
        return head;
    }
        
    for (; level < length; level++) {
        int index = key[level] - 'a';
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
    suggestionsRec(q, prefix);
    free(prefix); // Free the allocated memory to avoid memory leaks
    return head; // Return head after printing suggestions
}
