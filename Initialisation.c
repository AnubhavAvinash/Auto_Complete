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
    return NULL; // Return NULL or any other appropriate value
}

int main()
{
    char fileName[18] = "filtered_words.txt";
    initialisation(fileName);
    // Here you can use the trie functions as needed, for example:
    int searchResult = search("example");
    printf("Search result: %d\n", searchResult);
    return 0;
}
