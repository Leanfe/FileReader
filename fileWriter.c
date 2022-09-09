#include "fileWriter.h"
#include <stdio.h>

void printToFile(char** arr, FILE* file) {

    for (int i = 0; arr[i]; i++) {
        fputs(arr[i++], file);
    }

    fclose(file);
}

/*  UTIL */

void printArray(char** arr) {
    for (int i = 0; arr[i]; i++) {
        printf("%d) |%s| \n", i, arr[i]);
    }
}