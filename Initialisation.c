#include <stdio.h>
#include <stdlib.h>

int* initialisation(char fileName[]){
    char word[50];
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error in opening file");
        return NULL;
    }
    while (fscanf(file, "%s", word) != EOF) {
    }
    fclose(file);
}

int main()
{
    char fileName[19] = "filtered_words.txt";
    initialisation(fileName);
    return (0);
}