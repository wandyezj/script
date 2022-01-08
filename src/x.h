//
// File for random code to save for later
// this file should not be included in compilation
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

