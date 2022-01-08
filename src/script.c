#include <stdio.h>
#include <stdbool.h> // https://en.cppreference.com/w/c/types/boolean
char* version = "0.0.0";

void print_version() {
    printf("%s", version);
}

/*
 * inclusive of begin and end
 */
bool is_between(char c, char begin, char end) {
    return c >= begin && c <= end;
}

//
// character comparisons
//

bool is_upper(char c) {
    return is_between(c, 'A', 'Z');
}

bool is_lower(char c) {
    return is_between(c, 'a', 'z');
}

bool is_number(char c) {
    return is_between(c, '0', '9');
}

bool is_space(char c) {
    return c == ' ';
}

bool is_newline(char c) {
    return c == '\n';
}

bool is_hash(char c) {
    return c == '#';
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

enum character_type {
    hash,
    space,
    newline,


    unknown,
};

enum character_type get_character_type(char c) {
    if (is_newline(c)) {
        return newline;
    }

    if (is_hash(c)) {
        return hash;
    }


    return unknown;
}

int execute_script_file(char* file_path) {
    int c;
    FILE *file;
    file = fopen(file_path, "r");
    if (!file) {
        printf("failed to open file [%s]", file_path);
        return 1;
    }

    bool inside_comment = false;
    while ((c = getc(file)) != EOF) {

        enum character_type t = get_character_type(c);

        switch (t) {
            case hash:
                inside_comment = true;
                break;
            case newline:
                inside_comment = false;
                break;
            default:
                if (!inside_comment) {
                    printf("%c", c);
                }
                
                break;
        }

        // if (is_newline(c) ) {
        //     // end any single line comment
        //     if(inside_comment) {
        //         inside_comment = false;
        //     }

        // } else if (is_hash(c)) {
        //     inside_comment = true;
        // }

        // if (!inside_comment) {
        //     // can do some other things
        //     printf("%c", c);
        // }

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
