/*

- Program Name: appendn
- Author: Muhammad Altaaf
- Contact: taafuuu@gmail.com

- Description: Program to add newline at end of a file, if there is none.

*/


#include "definitions.h"
#include "usage.h"

#include <getopt.h>


struct option longoptions[] = {
    {"files-names", required_argument, 0, 'f'},
    {"help",        no_argument,       0, 'h'},
    {NULL, 0, NULL, '\0'}
};


static flag
        aflag    = 0,
        f_switch = 0,
        ask_help = 0;

int
main (int argc, char **argv)
{
    char optc,
        *file_name;
    
    int optidx;

    while ((optc = getopt_long(argc, argv, "f:h", longoptions, &optidx)) != -1)
    {
        switch (optc)
        {
            case 'f':
                aflag = f_switch = 1;
                file_name = optarg;
                break;
            
            case 'h':
                aflag = ask_help = 1;
                break;
        }
    }

    if (argc == 1)
        usage(1);

    if (ask_help)
        usage(0);

    if (!aflag && argc > 1)
    {
        FILE *file = fopen(argv[1], "a+");

        if (!is_newline_at_end (file))
            fputc('\n', file);
    }

    if (f_switch)
        file_names_from_file (file_name);
    
    return 0;
}
