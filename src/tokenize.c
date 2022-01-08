
#include <stdio.h>
#include <stdbool.h>

#include "constants.h"
#include "tokenize.h"

int tokenize_script_file(char* file_path) {

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

        printf("%c", c);
        // if (line > max_line) {
        //     printf("\nERROR: maximum number of lines exceeded. scripts may only have %i lines", max_line);
        //     return 1;
        // }

        // if (line > max_line) {
        //     printf("\nERROR: maximum characters in line %i exceeded. scripts may only have %i characters per line", line, max_column);
        //     return 1;
        // }

        // enum character_type t = get_character_type(c);
        // if (print_character_line_column) {
        //     printf("\nline: %i column: %i, character [%c]\n", line, column, c);
        // }

        // switch (t) {
        //     case hash:
        //         inside_comment = true;
        //         break;
        //     case newline:
        //         inside_comment = false;
        //         line += 1;
        //         column = 1;
        //         break;
        //     case bracket_round_open:
        //     case bracket_round_close:
        //     case quote_double:
        //     case lower:
        //         break;
        //     case unknown:
        //         if (!inside_comment) {
        //             printf("\nline: %i column: %i, unknown character [%c]\n", line, column, c);
        //         }
        //         break;
        //     default:
        //         if (!inside_comment) {
        //             printf("%c", c);
        //         }
                
        //         break;
        // }
        // column +=1;

    }

    return 0;

}