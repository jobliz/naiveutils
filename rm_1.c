/*
A simple imitation of the rm command that can delete a file.

You can do a rather peculiar test:

    gcc rm_1.c && ./a.out a.out

It will compile the executable, run it and then delete itself.
*/

#include <stdio.h>
    
int main(int argc, char *argv[])
{   
    if(argc != 2) {
        printf("Incorrect number of parameters.\n");
        return 1;
    }

    char *filepath = argv[1];
    int status;

    status = remove(filepath);
    
    if (status == 0)
        return 0;
    else
    {
        printf("Unable to delete the file\n");
        perror("Following error occurred");
    }
}