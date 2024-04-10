#include <stdio.h>
#include <stdlib.h>
#include "Trie.h" // Include the header file for the trie functions
#include "Initialisation.h" // Include the header file for the initialisation function
#include "Prediction.h" // Include the header file for the prediction function

int main()
{
    char fileName[18] = "filtered_words.txt";
    int* adtRoot = initialisation(fileName);
    int searchResult = search("a");
    printf("Search result: %d\n", searchResult);
    return 0;
}
