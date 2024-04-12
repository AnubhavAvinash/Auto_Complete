#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Trie node structure
struct trieNode {
    struct trieNode* children[ALPHABET_SIZE];
    bool isWordEnd;
};

extern struct trieNode* root;

// Function prototypes
struct trieNode* create_trieNode();

void insert_trieNode(char key[]);

int search(char key[], struct trieNode* head);

void free_all(struct trieNode* curs);

#endif // TRIE_H
