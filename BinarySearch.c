#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BINARY.h"

int binarySearch(char *arr[], const char* target, int size) {
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = (high + low) / 2;

        int cmp = strcmp(target, arr[mid]);

        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}


int fileRead() {

    char file_name[30];
    printf("Enter the file name:\n");
    scanf("%s",file_name);

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    const int MAX_LINES = 1000;
    const int MAX_LINE_LENGTH = 100;

    char *firstWords[MAX_LINES];
    int frequency[MAX_LINES];
    char line[MAX_LINE_LENGTH];
    char S[MAX_LINE_LENGTH];

    int index, lineNumber = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        // Use strtok to extract the first word from the line
        char *token = strtok(line, " 	\t\n");
        if (token != NULL) {
            firstWords[lineNumber] = strdup(token);
        
        token = strtok(NULL, " \n");
            if (token != NULL) {
                frequency[lineNumber] = atoi(token);
                lineNumber++;
            }
        }
    }


    printf("Enter a word to be searched: ");
    scanf("%s", S);

    index = binarySearch(firstWords, S, lineNumber) + 1;
    if(index!=0)
        printf("'%s' Found at line %d with frequency = %d\n",S, index,frequency[index-1]);
    else
        printf("Word not found\n");


    fclose(file);
	int i;
    // Free memory allocated for strdup
    for (i = 0; i < lineNumber; i++) {
        free(firstWords[i]);
    }

    return 0;
}

