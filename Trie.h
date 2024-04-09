#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct node {
    int data;
    struct node* link[ALPHABET_SIZE];
};

extern struct node* root;

struct node* create_node();
void insert_node(char key[]);
int search(char key[]);
void free_all(struct node* root);

#endif // TRIE_H
