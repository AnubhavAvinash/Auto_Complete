#ifndef PREDICTION_H
#define PREDICTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h" // Include the header file for the trie functions

// Function declarations
int search(char key[]);

bool isLastNode(struct trieNode* node);

void suggestionsRec(struct trieNode* node, char* currPrefix);

int printAutoSuggestions(const char key[]);

#endif // PREDICTION_H
