#include <stdio.h>
#include <stdlib.h>
#include "Trie.h" // Include the header file for the trie functions

int* initialisation(char fileName[]){
    char word[50];
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error in opening file");
        return NULL;
    }
    while (fscanf(file, "%s", word) != EOF) {
        insert_node(word); // Insert each word into the trie
    }
    fclose(file);
    return root; // Returning a reference to the ADT
}