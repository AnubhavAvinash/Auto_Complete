#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>

// Assuming insert_node is a function that inserts a word into the trie
// and root is a global variable or a part of the trie structure
void insert_node(char* word);
extern int* root; // Assuming root is a pointer to the root of the trie

// Function declaration for initialisation
int* initialisation(char fileName[]);

#endif // TRIE_H
