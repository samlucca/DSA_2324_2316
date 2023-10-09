#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

// Function to count words in a paragraph
void countWords(FILE* inputFile, FILE* outputFile) {
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    char c;

    // Initialize a frequency counter
    typedef struct {
        char word[MAX_WORD_LENGTH];
        int count;
    } WordFrequency;

    WordFrequency* wordFrequencies = NULL;
    int capacity = 0;
    int size = 0;

    while (fscanf(inputFile, "%s", word) != EOF) {
        // Search for the word in the wordFrequencies array
        int found = 0;
        for (int i = 0; i < size; i++) {
            if (strcmp(word, wordFrequencies[i].word) == 0) {
                wordFrequencies[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not found, add it to the array
        if (!found) {
            if (size == capacity) {
                // Double the capacity if needed
                capacity = (capacity == 0) ? 1 : capacity * 2;
                wordFrequencies = realloc(wordFrequencies, capacity * sizeof(WordFrequency));
            }

            strcpy(wordFrequencies[size].word, word);
            wordFrequencies[size].count = 1;
            size++;
        }

        wordCount++;
    }

    // Write word frequencies to the output file
    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%s %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    // Clean up and close files
    free(wordFrequencies);
    fclose(inputFile);
    fclose(outputFile);

    printf("Word frequencies written to the output file.\n");
}

int main() {
    char inputFilePath[] = "input.txt";    // Replace with the path to your input file
    char outputFilePath[] = "output.txt";  // Replace with the desired output file path

    FILE* inputFile = fopen(inputFilePath, "r");
    FILE* outputFile = fopen(outputFilePath, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    countWords(inputFile, outputFile);

    return 0;
}
