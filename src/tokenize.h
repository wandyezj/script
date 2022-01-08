// #ifndef HEADER_FILE_tokenize
// #define HEADER_FILE_tokenize

int tokenize_script_file(char* file_path);


enum token_type {
    comment,
    string,
};

// #endif