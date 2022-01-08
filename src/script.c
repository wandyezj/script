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

int main(int argc, char **argv) 
{
    printf("%i\n", argc);
    printf("%s\n", argv[0]);
    printf("Hello World!\n");

    // read in file and print it out

    // https://stackoverflow.com/questions/3463426/in-c-how-should-i-read-a-text-file-and-print-all-strings#:~:text=The%20simplest%20way%20is%20to%20read%20a%20character%2C,number%2C%20and%20a%20plain%20char%20may%20be%20unsigned.

    // inefficent to read individual characters but this is simple enough for now.

    int c;
    FILE *file;
    file = fopen("test.txt", "r");
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
        }
            
        fclose(file);
    }


    return 0;
}
