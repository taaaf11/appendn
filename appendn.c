/*

- Program Name: appendn
- Author: Muhammad Altaaf
- Contact: taafuuu@gmail.com

- Description: Program to add newline at end of a file, if there is none.

*/

/*

  In this project, some files are opened twice. One head is used for reading and the other
  for writing. This choice is made because mode "a+" was not working as expected.

*/


#include "definitions.h"
#include "usage.h"

#include <getopt.h>


struct option longoptions[] = {
    {"files-names", required_argument, 0, 'f'},
    {"check-ln",    no_argument,       0, 'c'},
    {"help",        no_argument,       0, 'h'},
    {NULL, 0, NULL, '\0'}
};


static flag
        aflag    = 0, // 1 if user has used a switch
        f_switch = 0, // 1 if -f is used. File names from given file.
        c_switch = 0, // 1 if -c is used. Check for trailing newline in files.
        ask_help = 0; // 1 if -h is used. Usage info.

int
main (int argc, char **argv)
{
    char optc,
        *entries_file_name,
        *file_name;
    
    int optidx;

    while ((optc = getopt_long(argc, argv, "f:ch", longoptions, &optidx)) != -1)
    {
        switch (optc)
        {
            case 'f':
                aflag = f_switch = 1;
                entries_file_name = optarg;
                break;
            
            case 'c':
                aflag = c_switch = 1;
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
        for (int i = 1; i < argc; i++)
        {
            FILE *read = fopen(argv[i], "r");
            if (!file_opened(read))
            {
                printf("Error: File %s couldn't be read.", argv[i]);
                exit(1);
            }
            
            FILE *append  = fopen(argv[i], "a");
        
            if (!is_newline_at_end(read))
               fputc('\n', append);
        
            fclose(read);
            fclose(append);
        }
    }

    if ((c_switch && !f_switch) && argc > 2)
    {
        for (int i = 1; i < argc; i++)
        {
            if (STREQ(argv[i], "-c")) // The option itself
                continue;
            
            if (STREQ(argv[i], "\\-c")) // Check file named "-c" -> supply "\-c" to the argument
            {
                FILE *read = fopen("-c", "r");
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

                continue;
            }

            FILE *read = fopen(argv[i], "r");
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
        }
    }


    if (c_switch)
    {
        if (f_switch)
        {
            if (!STREQ(entries_file_name, "-"))
            {
                FILE *entries_file_p = fopen(entries_file_name, "r");
                if (!file_opened(entries_file_p))
                {
                    printf("Error: File %s couldn't be read.", entries_file_name);
                    exit(1);
                }
                
                chk_file_names_from_file(entries_file_p);
                fclose(entries_file_p);
            }
            
            else
                chk_file_names_from_file(stdin);
            
            return 0;
        }

        FILE *read = fopen(file_name, "r");
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
        
        return 0;
    }

    if (f_switch)
    {
        if (!STREQ(entries_file_name, "-"))
        {
            FILE *entries_file_p = fopen(entries_file_name, "r");
            if (!file_opened(entries_file_p))
            {
                printf("Error: File %s couldn't be read.", entries_file_name);
                exit(1);
            }
            
            ap_file_names_from_file(entries_file_p);
            fclose(entries_file_p);
        }
        
        else
            ap_file_names_from_file(stdin);
    }
    
    return 0;
}
