// Character Classification
#include <stdbool.h>

typedef enum character_type {
    // #
    character_type_hash,

    // 
    character_type_space,

    // \n
    character_type_newline,

    // ABCDEFGHIJKLMNOPQRSTUVWXYZ
    character_type_upper,

    // abcdefghijklmnopqrstuvwxyz
    character_type_lower,

    // 0123456789
    character_type_number,

    // "
    character_type_quote_double,

    // (
    character_type_bracket_round_open,
    // )
    character_type_bracket_round_close,

    character_type_unknown,
} character_type;

character_type get_character_type(char c);

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