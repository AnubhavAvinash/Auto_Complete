#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct trieNode {
    struct trieNode* children[ALPHABET_SIZE];
    bool isWordEnd;
};

struct trieNode* root = NULL;

struct trieNode* create_trieNode() {
    struct trieNode* q = (struct trieNode*)malloc(sizeof(struct trieNode));
    q->isWordEnd = false;
    for (int x = 0; x < ALPHABET_SIZE; x++) {
        q->children[x] = NULL;
    }
    return q;
}

void insert_trieNode(char key[]) {
    int length = strlen(key);
    int index;
    if (root == NULL) {
        root = create_trieNode();
    }
    struct trieNode* q = root;

    for (int level = 0; level < length; level++) {
        index = key[level] - 'a';
        if (q->children[index] == NULL) {
            q->children[index] = create_trieNode();
        }
        q = q->children[index];
    }
    q->isWordEnd = true;
}

void free_all(struct trieNode* curs) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (curs->children[i] != NULL) {
            free_all(curs->children[i]);
        }
    }
    free(curs);
}
