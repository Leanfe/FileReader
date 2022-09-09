#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fileReader.h"


int main(int argc, char *argv[])
{
    int opt;
    FILE* filename = stdin;
    FILE* outfile = stdout;
    int useOut = 0;

    char* USAGE[] = {
            "USAGE: fileReader [OPTION]\n",
            "Concatenate FILE(s) to standard output. \n",
            "\n",
            "-f                       read from file \n",
            "-o                       output to file \n",
            "\n",
            "Examples: \n",
            "fileReader -f obeme.txt -o output.txt \n",
    };

    while((opt = getopt(argc, argv, ":f:o:h")) != -1)
    {
        switch(opt)
        {
            case 'f':
                filename = fopen(optarg, "r");
                break;
            case 'o':
                outfile = fopen(optarg, "w");
                break;
            case 'h':
                printf(USAGE);
                return EXIT_SUCCESS;
            case ':':
                perror("Option needs a value!");
                return EXIT_FAILURE;
            case '?':
                perror("Unknown option!");
                return EXIT_FAILURE;
            default:
                break;
        }
    }

    //printArray(readFile(filename, outfile));
    return EXIT_SUCCESS;
}

