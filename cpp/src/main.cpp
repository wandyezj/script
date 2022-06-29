
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "characters.h"

void print(const std::string& message) {
    std::cout << message << std::endl;
}

void print(char c) {
    //std::string s(1,c);
    std::cout << c;
    //print(s);
}

void print(size_t v) {
    std::cout << v;
}

void error(const std::string& message) {
    print("ERROR: " + message);
}

const std::string bar = "-----";

enum class Token {
    unknown,
    comment,
};

struct Token_data {
    Token token;
    size_t index_start;
    size_t index_end;
    std::string sequence;
};

enum class Sequence {
    unknown,
    comment,
};


class Tokenizer {

private:
    // current character index
    size_t character_index = 0;

    size_t next_buffer_index = 0;
    char buffer[200];
    Sequence current_sequence = Sequence::unknown;

    Token_data current_token;
public:
    std::list<Token_data> tokens;

    // parse as a stream of characters, information must be tracked
    // feed the next character to the tokenizer
    // can feed be a generator that can get the next sequence?
    void feed(char c) {

        // what is the character?
        auto character = get_character_type(c);

        // put everything in the buffer
        this->buffer[this->next_buffer_index] = c;
        this->next_buffer_index++;
        this->buffer[this->next_buffer_index] = '\0';

        // figure out what the tokens mean
        if (this->current_sequence == Sequence::unknown) {
            
            if (character == Character::hash) {
                this->current_sequence = Sequence::comment;
                this->current_token.token = Token::comment;
            }

            // can look at the buffer to see if there are tokens that can be pulled out
        }

        if (this->current_sequence != Sequence::unknown) {
            this->current_token.index_start = this->character_index;
        }

        bool reset_buffer = false;
        bool complete_token = false;
        if (this->current_sequence == Sequence::comment) {

            if (character == Character::newline) {
                this->current_token.index_end = this->character_index - 1;
                this->current_token.sequence = std::string(this->buffer);
                reset_buffer = true;
                complete_token = true;
            }
        }

        if (complete_token) {
            this->tokens.push_back(this->current_token);
            this->current_sequence = Sequence::unknown;
        }

        if (reset_buffer) {
            this->next_buffer_index = 0;
            this->buffer[this->next_buffer_index] = '\0';
        }

        // increment character index
        this->character_index++;
    }

};


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

    Tokenizer tokenizer;
    print(bar);
    while (!file.eof()) {
        char c;
        file.get(c);
        print(c);
        tokenizer.feed(c);
    }
    print(bar);

    auto tokens = tokenizer.tokens;
    std::cout << "Tokens " << tokens.size() << std::endl;

    for (auto i = tokens.begin(); i != tokens.end(); i++) {
        auto token = *i;
        std::cout << token.index_start 
                  << " "
                  << token.index_end
                  << " "
                  << "\n"
                  << token.sequence
                  << std::endl;
    }
    print(bar);

    std::cout << "done" << std::endl;

    // place output between two bars
    //printf("\n-----\n");

    //int result = tokenize_script_file(file_path);

    //printf("\n-----\n");
    return 0;
}