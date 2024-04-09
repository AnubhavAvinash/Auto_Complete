#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct node {
    int data;
    struct node* link[ALPHABET_SIZE];
};

struct node* root = NULL;
struct node* create_node()
{
    struct node* q = (struct node*)malloc(sizeof(struct node));
    for (int x = 0; x < ALPHABET_SIZE; x++) {
        q->link[x] = NULL;
    }
    q->data = -1;
    return q;
}

void insert_node(char key[])
{
    int length = strlen(key);
    int index;
    int level = 0;
    if (root == NULL) {
        root = create_node();
    }
    struct node* q = root;

    for (; level < length; level++) {
        index = key[level] - 'a';
        if (q->link[index] == NULL) {
            q->link[index] = create_node();
        }
        q = q->link[index];
    }
    q->data = level;
}

int search(char key[])
{
    struct node* q = root;
    int length = strlen(key);
    int level = 0;
    for (; level < length; level++) {
        int index = key[level] - 'a';
        if (q->link[index] != NULL)
            q = q->link[index];
        else
            break;
    }
    if (key[level] == '\0' && q->data != -1) {
        return q->data;
    }
    return length;
}

void free_all(struct node* curs) {
    int i;

    // Recursive case: go to the end of the trie
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (curs->link[i] != NULL) {
            free_all(curs->link[i]);
        }
    }

    // Base case: free the current node
    free(curs);
}

int main()
{
    char word[50];
    insert_node("by");
    insert_node("program");
    insert_node("programming");
    insert_node("data structure");
    insert_node("coding");
    insert_node("code");
    printf("Enter the word you would like to search:");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0';
    if (search(word) != -1) {
        printf("The word is present in the trie at level: %d\n", search(word));
    } else {
        printf("The word is not present in the trie\n");
    }
    free_all(root);
    return 0;
}
