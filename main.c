#include "Initialisation.h" // Include the header file for the initialisation function
#include "Prediction.h" // Include the header file for the prediction function
#include "Trie.h" // Include the header file for the trie functions
#include "linkedList.h" // Include the header file for the linked list functions
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[50];
    char fileName[18] = "filtered_words.txt";
    struct trieNode* adtRoot = initialisation(fileName);
    if (adtRoot == NULL) {
        printf("Initialisation failed\n");
        exit(1);
    }
    printf("Please enter the word you would like auto completed suggestions for: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0';
    for (int i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);
    }
    if (!AutoSuggestions(word)) {
        printf("No suggestions found\n");
    } else {
        printf("Suggestions:\n");
        printLinkedlist(head);
    }
    free_all(adtRoot);
    freeList(&head);
    return 0;
}