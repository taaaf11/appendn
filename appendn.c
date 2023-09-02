#include "definitions.h"

#include <getopt.h>


struct option longoptions[] = {
    {"files-names", required_argument, 0, 'f'},
    {NULL, 0, NULL, '\0'}
};


static flag
        aflag = 0,
        f_switch = 0;


int
main (int argc, char **argv)
{
    char optc,
        *file_name;
    
    int optidx;

    while ((optc = getopt_long(argc, argv, "f:", longoptions, &optidx)) != -1)
    {
        switch (optc)
        {
            case 'f':
                aflag = f_switch = 1;
                file_name = optarg;
                break;
        }
    }

    if (!aflag && argc > 1)
    {
        FILE *file = fopen(argv[1], "a+");

        if (!newline_at_end (file))
            fputc('\n', file);
    }

    if (f_switch)
        file_names_from_file (file_name);
    
    return 0;
}
