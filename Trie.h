#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>        // Include the standard library for the bool type
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For POSIX getline

#define ALPHABET_SIZE 26    // Define the size of the alphabet

// Trie node structure
struct trieNode {
    struct trieNode* children[ALPHABET_SIZE]; // Array to hold child nodes for each alphabet character
    bool isWordEnd;                           // Flag to mark the end of a word
};

extern struct trieNode* root;   // External declaration of the root of the trie

// Function prototypes
struct trieNode* create_trieNode(void);    // Function to create a new trie node

void insert_trieNode(const char key[]);      // Function to insert a word into the trie

int search(const char key[], struct trieNode** head);   // Function to search for a word in the trie

void free_all(struct trieNode* curs);   // Function to free all nodes in the trie

#endif // TRIE_H
