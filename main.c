#include <stdio.h>
#include <unistd.h>

#include "fileReader.h"


int main(int argc, char *argv[])
{
    int opt;
    char* filename = NULL;
    char* outfile = NULL;
    int useOut = 0;

    // поместите ':' в начало строки
    //, чтобы программа могла
    //различать '?' и ':'
    while((opt = getopt(argc, argv, ":f:o:lrx")) != -1)
    {
        switch(opt)
        {
            case 'f':
                filename = optarg;
                break;
            case 'l':
            case 'r':
                printf("option: %c\n", opt);
                break;
            case 'o':
                outfile = optarg;
                useOut = 1;
                break;
            case ':':
                printf("option needs a value\n");
                break;
            case '?':
                printf("unknown option: %c\n", optopt);
                break;
        }
    }

    if (filename == NULL) {
        printf("не указан файл откуда читать! \n");
        return 1;
    }

    // опция предназначена для дополнительных аргументов
    // которые не анализируются
    for(; optind < argc; optind++){
        printf("extra arguments: %s\n", argv[optind]);
    }

    if (useOut == 1) {
        printToFile(readFile(filename), outfile);
    } else {
        printArray(readFile(filename));
    }
    return 0;
}

