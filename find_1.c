/*
A tool that *sort-of* mimics a very simple use case of the find command. 

It looks recursively at directories and prints the paths that contain a specific
susbstring. Output can be improved with help from the sort command. 

Full usage would be:

gcc find_1.c -w && ./a.out PATH PATTERN | sort --version-sort

Use "" as pattern if not looking for anything specific.

References:
https://stackoverflow.com/questions/8436841/how-to-recursively-list-directories-in-c-on-linux
https://codeforwin.org/2018/03/c-program-to-list-all-files-in-a-directory-recursively.html
https://superuser.com/questions/226449/why-does-sort-ignore-special-characters-like-the-asterisk
https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
*/

#include <stdio.h>
#include <dirent.h>

/**
 * Lists all files and sub-directories recursively 
 * considering path as base path. 
 * 
 * Taken and modified from:
 * https://codeforwin.org/2018/03/c-program-to-list-all-files-in-a-directory-recursively.html
 */
void listFilesRecursively(char *basePath, char *substring)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    // Unable to open directory stream
    if (!dir) {
        return;
    }

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            // printf("%s\n", dp->d_name);

            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            listFilesRecursively(path, substring);

            if(strstr(path, substring) != NULL) {
                printf(path);
                printf("\n");
            }
        }
    }

    closedir(dir);
}

int main (int argc, char *argv[]) {
    if(argc != 3) {
        printf("Incorrect number of parameters.\n");
        return 1;
    }

    char *path = argv[1];
    char *pattern = argv[2];
    DIR *dir = opendir(path);
    if (!dir) { return 1 ; }
    struct dirent *dp;

    /*
    while ((dp = readdir(dir)) != NULL)
    {
        printf("%s\n", dp->d_name);
    }*/
    listFilesRecursively(path, pattern);
}