#include "fileReader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

char** readFile(char* path) {
    FILE* in = fopen(path, "r");

    char** arr = NULL;
    size_t arr_size = 0;
    char buffer[MAX_SIZE];
    char *temp_str = NULL;
    size_t temp_len = 0;
    while (fgets(buffer, MAX_SIZE, in)) {
        size_t len = strlen(buffer);
        if (len) {
            if (buffer[len-1] == '\n') {
                // Последняя порция строки
                buffer[--len] = '\0';
                temp_str = realloc(temp_str, temp_len + len + 1);
                strcpy(temp_str + temp_len, buffer);
                arr_size++;
                arr = realloc(arr, sizeof(char*) * (arr_size + 1));
                arr[arr_size-1] = temp_str;
                temp_str = NULL;
                temp_len = 0;
            } else {
                // Очередная не последняя порция строки
                temp_str = realloc(temp_str, temp_len + len + 1);
                strcpy(temp_str + temp_len, buffer);
                temp_len += len;
            }
        } else {
            printf("!!!!!!!!!!!!!!!!!!");
        }
    }
    if (temp_len) {
        arr_size++;
        arr = realloc(arr, sizeof(char*) * (arr_size + 1));
        arr[arr_size-1] = temp_str;
    }
    if (!arr_size) {
        arr = malloc(sizeof(char*) * (arr_size + 1));
    }
    arr[arr_size] = NULL;
    return arr;
}