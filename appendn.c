#include <stdio.h>


int
main (int argc, char **argv)
{
    if (argc > 1)
    {
        FILE *file = fopen(argv[1], "a+");
        fseek(file, SEEK_SET, SEEK_END); // set cursor at end of file

        long end = ftell(file);
        fseek(file, end - 1, SEEK_SET);  // cursor at second last position

        char character = fgetc(file); // get last character

        if (character == '\n')
            return 0;
        else
            fputc('\n', file);
    }
    
    return 0;
}
