#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int flag;

#define    STREQ(a, b)            (strcmp(a, b) == 0)

int
is_newline_at_end (FILE *fp)
{
    fseek(fp, SEEK_SET, SEEK_END); // set cursor at end of file

    long end = ftell(fp);
    fseek(fp, end - 1, SEEK_SET);  // cursor at second last position
    
    char character = fgetc(fp); // get last character

    return (character == '\n');
}


int
file_opened (FILE *fp)
{
    if (!fp)
        return 0; // file couldn't be read
    else
        return 1;
}


/* read files names from a file and do operation on them */
void
ap_file_names_from_file (FILE *entries_file_p)
{
    char file_name[255];
    
    while (1)
    {
        if (fscanf(entries_file_p, "%s", file_name) != 1)
            break;

        else
        {
            FILE *read = fopen(file_name, "r");
            if (!file_opened(read))
            {
                printf("Error: File %s couldn't be read.\n", file_name);
                exit(1);
            }

            FILE *append  = fopen(file_name, "a");
            
            if (!is_newline_at_end(read))
                fputc('\n', append);

            fclose(read);
            fclose(append);
        }

        char file_name[255];
    }
}


void
chk_file_names_from_file (FILE *entries_file_p)
{
    char file_name[255];
    
    while (1)
    {
        if (fscanf(entries_file_p, "%s", file_name) != 1)
            break;

        else
        {
            FILE *read = fopen(file_name, "r");
            if (!file_opened(read))
            {
                printf("Error: File %s couldn't be read.\n", file_name);
                exit(1);
            }
            
            if (is_newline_at_end(read))
            {
                printf("%s: yes", file_name);
                fclose(read);
            }

            else
            {
                printf("%s: no", file_name);
                fclose(read);
            }

            fclose(read);
        }

        char file_name[255];
    }
}
