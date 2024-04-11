#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h" // Include the header file for the trie functions

int search(char key[]) {
    struct trieNode* q = root;
    int length = strlen(key);
    for (int level = 0; level < length; level++) {
        int index = key[level] - 'a';
        if (q->children[index] != NULL)
            q = q->children[index];
        else
            return -1; // Key not found in Trie
    }
    return (q != NULL && q->isWordEnd) ? q->data : -1;
}

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
            strcpy(newPrefix, currPrefix);
            newPrefix[strlen(currPrefix)] = child;
            newPrefix[strlen(currPrefix) + 1] = '\0';
            suggestionsRec(node->children[i], newPrefix);
            free(newPrefix); // Free the allocated memory to avoid memory leaks
        }
    }
}

int printAutoSuggestions(const char key[]) {
    int length = strlen(key);
    if (length < 3){
        return -1;
    }
    struct trieNode* q = root;    
    int index;

    for (int i = 0; i < length; i++) {
        index = key[i] - 'a';
        if (!q->children[index])
            return -1; // No string in the Trie has this prefix
        q = q->children[index];
    }

    if (isLastNode(q)) {
        printf("%s\n", key);
        return -1; // Prefix is present as a word, but there is no subtree below the last matching node.
    }

    char* prefix = malloc(length + 1); // +1 for the null terminator
    strcpy(prefix, key);
    suggestionsRec(q, prefix);
    free(prefix); // Free the allocated memory to avoid memory leaks
    return 1;
}