
#include <stdio.h>
#include <stdbool.h>

#include "constants.h"
#include "characters.h"
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

    char token_buffer[max_token_buffer + 1]; // +1 to include space for null terminator
    // place to insert next character in the buffer
    // the index of this character should always be set to a null terminator
    int token_buffer_length = 0;

    token_type token_id = token_type_unknown;

    while (((c = getc(file)) != EOF)) {

        // throw our CR
        if (is_carriage_return(c)) {
            continue;
        }

        if (line > max_line) {
            printf("\nERROR: maximum number of lines exceeded. Scripts may only have %i lines", max_line);
            return 1;
        }

        if (line > max_line) {
            printf("\nERROR: maximum characters in line %i exceeded. Scripts may only have %i characters per line", line, max_column);
            return 1;
        }

        if (token_buffer_length >= max_token_buffer) {
            printf("\nERROR: maximum token size in line %i exceeded. Tokens may only have %i characters", line, max_token_buffer);
            return 1;
        }

        if (print_character_line_column) {
            printf("\nline: %i column: %i, character [%c]\n", line, column, c);
        }
        printf("%c", c);


        enum character_type t = get_character_type(c);

        bool add_character_to_buffer = false;
        bool end_token = false;

        if (character_type_newline) {
            line += 1;
            column = 1;
        }

        // state machine that switches based on character type
        switch(token_id) {
            case token_type_comment:
                if (t == character_type_newline) {
                    end_token = true;
                } else {
                    add_character_to_buffer = true;
                }
                break;

            case token_type_unknown:
                switch (t) {
                    case character_type_hash:
                        token_id = token_type_comment;
                        break;
                    default:
                        break;
                }
                break;
            default:
                // who knows?
                break;
        }

        // put the character in the buffer
        if (add_character_to_buffer) {
            //printf("\nadd [%c]\n", c);
            token_buffer[token_buffer_length] = c;
            token_buffer_length++;
            token_buffer[token_buffer_length] = '\0'; // Null terminator
        }


        if (end_token) {
            end_token = false;

            // output token
            switch(token_id) {
                case token_type_comment:
                    printf("\ntoken: [%s]\n", "comment");
                    printf("buffer size: [%i]\n", token_buffer_length);
                    // CR will wrap the line around
                    printf("buffer: [%.*s]\n", token_buffer_length, token_buffer);
                    break;
                default:
                    printf("unknown token %i", token_id);
                    break;
            }

            // reset buffer
            token_buffer_length = 0;

            token_id = token_type_unknown;
        }




        column +=1;

    }

    return 0;

}