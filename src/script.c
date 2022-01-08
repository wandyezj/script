#include <stdio.h>
#include <stdbool.h> // https://en.cppreference.com/w/c/types/boolean

#include "constants.h"
#include "characters.h"
#include "tokenize.h"

//
// restrictions
//



char* version = "0.0.0";

void print_version() {
    printf("%s", version);
}


void detect_characters_in_file(char* file_path) {
    int c;
    FILE *file;
    file = fopen(file_path, "r");
    if (file) {
        while ((c = getc(file)) != EOF) {
            putchar(c);

            if (is_number(c)) {
                printf("-");
            }

            if (is_lower(c)) {
                printf(".");
            }

            if (is_upper(c)) {
                printf("'");
            }

            if (is_space(c)) {
                printf("_");
            }

            if (is_newline(c)) {
                printf("(newline)");
            }

            if (is_hash(c)) {
                printf("(hash)");
            }
        }

        fclose(file);
    } else {
        printf("failed to open file [%s]", file_path);
    }
}



int execute_script_file(char* file_path) {
    int c;
    FILE *file;
    file = fopen(file_path, "r");
    if (!file) {
        printf("failed to open file [%s]", file_path);
        return 1;
    }

    // debugging variables
    bool print_character_line_column = false;

    unsigned int line = 1;
    unsigned int column = 1;

    bool inside_comment = false;
    while ((c = getc(file)) != EOF) {

        if (line > max_line) {
            printf("\nERROR: maximum number of lines exceeded. scripts may only have %i lines", max_line);
            return 1;
        }

        if (line > max_line) {
            printf("\nERROR: maximum characters in line %i exceeded. scripts may only have %i characters per line", line, max_column);
            return 1;
        }

        enum character_type t = get_character_type(c);
        if (print_character_line_column) {
            printf("\nline: %i column: %i, character [%c]\n", line, column, c);
        }

        switch (t) {
            case hash:
                inside_comment = true;
                break;
            case newline:
                inside_comment = false;
                line += 1;
                column = 1;
                break;
            case bracket_round_open:
            case bracket_round_close:
            case quote_double:
            case lower:
                break;
            case unknown:
                if (!inside_comment) {
                    printf("\nline: %i column: %i, unknown character [%c]\n", line, column, c);
                }
                break;
            default:
                if (!inside_comment) {
                    printf("%c", c);
                }
                
                break;
        }
        column +=1;

    }

    return 0;
}


int main(int argc, char **argv) 
{
    //printf("%i\n", argc);
    //printf("%s\n", argv[0]);
    //printf("Hello World!\n");

    if (argc != 2) {
        // should pass in the file path
        printf("usage: script file");
        return 1;
    }
    
    char* file_path = argv[1];

    // read in file and print it out

    // https://stackoverflow.com/questions/3463426/in-c-how-should-i-read-a-text-file-and-print-all-strings#:~:text=The%20simplest%20way%20is%20to%20read%20a%20character%2C,number%2C%20and%20a%20plain%20char%20may%20be%20unsigned.

    // inefficent to read individual characters but this is simple enough for now.

    // detect_characters_in_file(file_path);


    printf("-----\n");
    // place output between two bars
    int result = execute_script_file(file_path);
    printf("\n-----\n");
    return result;
}
