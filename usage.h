#include <stdio.h>
#include <stdlib.h>


void
usage (int status)
{
    if (status != EXIT_SUCCESS)
    {
        fprintf(stderr, "USAGE: appendn NAME_OF_FILE\n"
                        "  or   appendn -f FILE\n\n");

        fprintf(stderr, "    --files-names,  -f FILE\t\tGet files' names to be operated on from FILE.\n"
                        "                           \tIf FILE is -, read files names from stdin.\n"
                        "    --help,         -h\t\t\tPrint this help message.\n\n");
        
        exit(status);
    }

    fprintf(stdout, "USAGE: appendn NAME_OF_FILE\n"
                    "  or   appendn -f FILE\n\n");
                        
    fprintf(stdout, "    --files-names,  -f FILE\t\tGet files' names to be operated on from FILE.\n"
                    "                           \tIf FILE is -, read files names from stdin.\n"
                    "    --help,         -h\t\t\tPrint this help message.\n\n");
    
    exit(status);
}