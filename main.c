#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fileReader.h"
#include "fileWriter.h"

#define ESCSEQ "\033["

int main(int argc, char *argv[])
{
    int opt;
    FILE* file = stdin;

    FILE* outfile = stdout;
    int useOutFile = 0;

    char* USAGE[] = {
            ESCSEQ"32;40mUSAGE: fileReader [OPTION]\033[0m\n",
            ESCSEQ"33;40mConcatenate FILE(s) to standard output.\033[0m\n",
            "\n",
            "-f                       read from file\n",
            "-o                       output to file\n",
            "\n",
            ESCSEQ"32;40mExamples:\033[0m\n",
            ESCSEQ"34;40mfileReader -f obeme.txt -o output.txt\033[0m\n",
            NULL
    };

    while((opt = getopt(argc, argv, ":f:o:h")) != -1)
    {
        switch(opt)
        {
            case 'f':
                file = fopen(optarg, "r");
                break;
            case 'o':
                outfile = fopen(optarg, "w");
                useOutFile = 1;
                break;
            case 'h':
                printArray(USAGE);
                return EXIT_SUCCESS;
            case ':':
                printf(ESCSEQ"31;47mOption needs a value!\033[0m");
                return EXIT_FAILURE;
            case '?':
                printf(ESCSEQ"31;47mUnknown option!\033[0m");
                return EXIT_FAILURE;
            default:
                break;
        }
    }

    if (useOutFile) {
        printToFile(readFile(file), outfile);
    } else {
        printArray(readFile(file));
    }

    return EXIT_SUCCESS;
}


