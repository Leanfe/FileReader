#include "fileWriter.h"
#include <stdio.h>

void printToFile(char** arr, char* out) {
    FILE *fp = fopen(out, "w");

    for (int i = 0; arr[i]; i++) {
        fputs(arr[i++], fp);
    }

    fclose(fp);
}

/*  UTIL */

void printArray(char** arr) {
    for (int i = 0; arr[i]; i++) {
        printf("%s", arr[i]);
    }
}