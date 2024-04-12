#include "Trie.h" // Include the header file for the trie functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to initialize the Trie by reading words from a file
struct trieNode* initialisation(char fileName[])
{
    char word[50];
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error in opening file");
        return NULL;
    }

    while (fscanf(file, "%49s", word) != EOF) { // Limit the word length to avoid buffer overflow
        word[strcspn(word, "\n")] = '\0';
        insert_trieNode(word); // Insert each word into the trie
    }

    fclose(file);
    return root; // Return the root of the Trie
}
