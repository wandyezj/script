
int tokenize_script_file(char* file_path);


typedef enum token_type {
    token_type_comment,
    token_type_string,

    // don't know what this token is
    token_type_unknown,
} token_type;
