#ifndef PREDICTION_H
#define PREDICTION_H

#include "Trie.h"           // Include the header file for the trie functions
#include "linkedList.h"     // Include the header file for the linked list functions
#include <stdbool.h>        // For bool type
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations

// Function to check if a given node is the last node in the trie
bool isLastNode(struct trieNode* node);

// Recursive function to generate suggestions for the given prefix
void suggestionsRec(struct trieNode* node, char* currPrefix, size_t prefixLen);

// Function to generate auto suggestions for the given key
struct node* AutoSuggestions(const char key[]);

#endif // PREDICTION_H
