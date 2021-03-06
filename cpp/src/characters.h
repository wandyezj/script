// Character Classification

enum class Character {
    // #
    hash,

    // 
    space,

    // \n
    newline,

    // ABCDEFGHIJKLMNOPQRSTUVWXYZ
    upper,

    // abcdefghijklmnopqrstuvwxyz
    lower,

    // 0123456789
    number,

    // "
    quote_double,

    // (
    bracket_round_open,
    // )
    bracket_round_close,

    unknown,
};

Character get_character_type(char c);

//
// character classification
//

bool is_upper(char c);
bool is_lower(char c);
bool is_number(char c);

bool is_space(char c);
bool is_newline(char c);
bool is_carriage_return(char c);

bool is_hash(char c);
bool is_quote_double(char c);

bool is_bracket_round_open(char c);
bool is_bracket_round_close(char c);