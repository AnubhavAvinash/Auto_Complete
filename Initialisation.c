#include <stdio.h>
#include <stdlib.h>
#include "Trie.h" // Include the header file for the trie functions


// Function to initialize the Trie by reading words from a file
struct trieNode* initialisation(char fileName[]) {
    char word[50];
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error in opening file");
        return NULL;
    }

    // Create the root of the Trie if it doesn't exist
    if (root == NULL) {
        root = create_trieNode();
    }

    while (fscanf(file, "%49s", word) != EOF) { // Limit the word length to avoid buffer overflow
        insert_trieNode(word); // Insert each word into the trie
    }

    fclose(file);
    return root; // Return the root of the Trie
}
