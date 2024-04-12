#ifndef PREDICTION_H
#define PREDICTION_H

#include "Trie.h" // Include the header file for the trie functions
#include "linkedList.h" // Include the header file for the linked list functions
#include <stdbool.h> // For bool type
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Assuming ALPHABET_SIZE and root are defined elsewhere

// Function declarations
bool isLastNode(struct trieNode* node);
void suggestionsRec(struct trieNode* node, char* currPrefix);
struct node* AutoSuggestions(char key[]);

#endif // PREDICTION_H
