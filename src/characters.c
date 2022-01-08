#include "characters.h"

character_type get_character_type(char c) {
    // can simplify by creating an array of function pointers and iterating through.
    if (is_hash(c)) {
        return character_type_hash;
    }

    if (is_space(c)){
        return character_type_space;
    }

    if (is_newline(c)) {
        return character_type_newline;
    }

    if (is_upper(c)) {
        return character_type_upper;
    }

    if (is_lower(c)){
        return character_type_lower;
    }

    if (is_number(c)) {
        return character_type_number;
    }

    if (is_quote_double(c)) {
        return character_type_quote_double;
    }

    if (is_bracket_round_open(c)) {
        return character_type_bracket_round_open;
    }

    if (is_bracket_round_close(c)) {
        return character_type_bracket_round_close;
    }

    return character_type_unknown;
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

bool is_carriage_return(char c) {
    return c == '\r';
}

bool is_hash(char c) {
    return c == '#';
}

bool is_quote_double(char c) {
    return c == '"';
}

// https://en.wikipedia.org/wiki/Bracket

bool is_bracket_round_open(char c) {
    return c == '(';
}

bool is_bracket_round_close(char c){
    return c == ')';
}