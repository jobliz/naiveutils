/*
cat_1.c is the simplest implementation of cat, using only stdio.h 
although GCC complains about the exit function stdlib.h is not
present.

This program produces a lot of warnings that are to be silenced
with a compiler flag, like:

    gcc cat_1.c -w && ./a.out test1.txt

The program cat_2.c is a version of cat_1 that fixes all the warnings.
cat_1 is as unsafely simple as it can be made to work. 

To compare the output of cat_1.c to that of the cat UNIX command you 
can diff them like this:

    diff <(gcc cat_1.c -w && ./a.out test1.txt test2.txt test3.txt) <(cat test1.txt test2.txt test3.txt)

Used references:
https://www.tecmint.com/13-basic-cat-command-examples-in-linux/
https://www.programmingsimplified.com/c-program-read-file
https://stackoverflow.com/questions/6882336/how-to-disable-warnings-when-compiling-c-code
https://askubuntu.com/questions/229447/how-do-i-diff-the-output-of-two-commands
*/

#include <stdio.h>
#include "common.c"

// prints a file handle using a buffer character
void print_file(FILE *f, char *ch) {
    while((ch = fgetc(f)) != EOF) {
        printf("%c", ch);
    }
}

int main (int argc, char *argv[]) {
    int number_of_files = argc - 1;
    FILE *files[number_of_files];
    char buffer_char;

    // FILE *fp;
    // fp = fopen(argv[1], "r"); // read mode
    // print_file(fp, buffer_char);

    // loading all file handles
    for(int i=1; i <= number_of_files; i++)
    {   
        files[i] = fopen(argv[i], "r");

        if (files[i] == NULL) {
            perror("Error while opening file\n");
            printf(argv[1]);
            printf("\n");
            exit(1);
        }
    }

    // print and close all file handles
    for(int i = 1; i <= number_of_files; i++) {
       print_file(files[i], buffer_char);
       fclose(files[i]);
    }

    return 0;
}