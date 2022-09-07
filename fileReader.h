#ifndef FILEREADER_FILEREADER_H
#define FILEREADER_FILEREADER_H

#include <stdio.h>

#define MAX_SIZE 1024

char** readFile(char* path);
void printToFile(char** arr, char* out);
void printArray(char** arr);

#endif
