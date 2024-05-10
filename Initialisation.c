#include "Trie.h" // Include the header file for the trie functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For POSIX getline
#include <assert.h> // For assert statements


// Function to initialize the Trie by reading words from a file
struct trieNode* initialisation(char fileName[]) {
    FILE* file = fopen(fileName, "r"); // Open the file for reading
    assert(file != NULL); // Check if the file was opened successfully

    char* word = NULL; // Dynamic memory allocation for the word
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&word, &len, file)) != -1) {
        // Remove newline character from the word
        word[strcspn(word, "\n")] = '\0';
        insert_trieNode(word); // Insert each word into the trie
    }

    free(word); // Free the allocated memory
    fclose(file); // Close the file after reading
    return root; // Return the root of the Trie
}
