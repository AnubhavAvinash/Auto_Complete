#include "Initialisation.h" // Include the header file for the initialisation function
#include "Prediction.h" // Include the header file for the prediction function
#include "Trie.h" // Include the header file for the trie functions
#include "linkedList.h" // Include the header file for the linked list functions
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For POSIX getline

int main()
{
    char* word = NULL; // Dynamic memory allocation for the word
    size_t len = 0;
    ssize_t read;
    char fileName[18] = "filtered_words.txt";

    // Initialize the trie by reading words from the file
    struct trieNode* adtRoot = initialisation(fileName);
    if (adtRoot == NULL) {
        // If initialization fails, print an error message and exit the program
        printf("Initialisation failed\n");
        exit(1);
    }
    // Prompt the user to enter the word for auto-completion suggestions
    printf("Please enter the word you would like auto completed suggestions for: ");
    read = getline(&word, &len, stdin); // Read the word entered by the user
    //printf("You entered: %s\n", word);
    if (read == -1) {
        perror("Error reading input");
        free(word);
        exit(1);
    }
    word[strcspn(word, "\n")] = '\0'; // Remove newline character from the word
    //printf("The size of your word is: %ld\n", strlen(word));
    // Convert the word to lowercase
    for (size_t i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);
    }
    // Generate auto-completion suggestions for the entered word
    struct trieNode* r = NULL;
    if (AutoSuggestions(word) == NULL) {
        // If no suggestions are found, print a message indicating the same
        printf("No suggestions found\n");
    } else {
        // If suggestions are found, print the suggestions
        printf("Suggestions:\n");
        printLinkedlist(head);
    }
    // Free memory allocated for the trie and linked list
    free_all(adtRoot);
    freeList(&head);
    free(word); // Free dynamically allocated memory for the word
    return 0;
}
