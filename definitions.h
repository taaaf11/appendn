#include <stdio.h>

typedef unsigned int flag;

int
is_newline_at_end (FILE *fp)
{
    fseek(fp, SEEK_SET, SEEK_END); // set cursor at end of file

    long end = ftell(fp);
    fseek(fp, end - 1, SEEK_SET);  // cursor at second last position
    
    char character = fgetc(fp); // get last character

    return (character == '\n');
}


/* read files names from a file and do operation on them */
void
file_names_from_file (char *entries_file)
{
    FILE *file = fopen(entries_file, "a+");
    char file_name[255];
    
    while (1)
    {
        if (fscanf(file, "%s", file_name) != 1)
            break;

        else
        {
            if (!is_newline_at_end (file))
                fputc('\n', file);
        }

        char file_name[255];
    }
}
