#ifndef BINARY_H
#define BINARY_H

#define MAX_WORD 10

typedef struct Data{
    char *word;
    int freq;
}DATA; 

int binarySearch(DATA arr[], const char* target, int size);
int fileRead();

#endif