/*
cp_1.c is the simples implementation of the cp UNIX command. It only
copies one file (not directory) into another place.

References:
https://www.programiz.com/c-programming/c-file-input-output
https://www.geeksforgeeks.org/c-program-copy-contents-one-file-another-file/
https://stackoverflow.com/questions/21713777/how-to-copy-a-image-to-a-directory-in-c-language
*/

#include <stdio.h>

int main (int argc, char *argv[]) {
    if(argc != 3) {
        printf("Incorrect number of parameters.");
        return 1;
    }

    char *source_path = argv[1];
    char *target_path = argv[2];
    FILE *source_file = fopen(source_path, "rb");;
    FILE *target_file = fopen(target_path, "wb");

    if(source_file == NULL) {
        printf("Invalid source filepath");
        return 1;
    }

    // get length of the input file
    fseek(source_file, 0, SEEK_END);
    int source_length = ftell(source_file);
    fseek(source_file, 0, SEEK_SET);

    // write the input filestream into the output filestream
    for(int i=0; i < source_length; i++){
        fputc(fgetc(source_file), target_file);
    }

    // close file descriptors and exit
    fclose(source_file);
    fclose(target_file);
    return 0;
}