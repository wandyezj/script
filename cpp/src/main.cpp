
#include <iostream>
#include <fstream>
#include <string>

void print(const std::string& message) {
    std::cout << message << std::endl;
}

void print(char c) {
    //std::string s(1,c);
    std::cout << c;
    //print(s);
}

void error(const std::string& message) {
    print("ERROR: " + message);
}

const std::string bar = "-----";

int main(int argc, char **argv)  {
    std::cout << "Hello World" << std::endl;

    if (argc != 2) {
        // should pass in the file path
        std::cout << "usage: script file" << std::endl;
        return 1;
    }

    char* file_path = argv[1];
    std::string filename = file_path;

    std::fstream file;

    file.open(filename, std::ios::in);

    if (!file.is_open()) {
        error("Unable to open file: " + filename);
        return 1;
    }

    print(bar);
    while (!file.eof()) {
        char c;
        file.get(c);
        print(c);
    }
    print(bar);

    std::cout << "done" << std::endl;

    // place output between two bars
    //printf("\n-----\n");

    //int result = tokenize_script_file(file_path);

    //printf("\n-----\n");
    return 0;
}