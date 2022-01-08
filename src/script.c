#include <stdio.h>
#include <stdbool.h> // https://en.cppreference.com/w/c/types/boolean

#include "constants.h"
#include "characters.h"
#include "tokenize.h"


int main(int argc, char **argv) 
{

    if (argc != 2) {
        // should pass in the file path
        printf("usage: script file");
        return 1;
    }
    
    char* file_path = argv[1];

    // place output between two bars
    printf("\n-----\n");


    int result = tokenize_script_file(file_path);

    printf("\n-----\n");
    return result;
}
