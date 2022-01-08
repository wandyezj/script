# TODO

- buffer component strings
- recognize string
- recognize function call

- handle unicode properly

## Roadmap

- split project across files
- print
- variables
    - declaration
    - assignment
- type
    - string
- type
    - integer
- variables
    - assignment restriction of type to previous type assigned. (no fluctuation of variable handles types)
- expression - arithmetic operator expressions
    - plus, minus, multiply
    - type match function lookup and supply arguments
    - variable value resolution
- type
    - boolean
- expression
    - boolean operators on strings
    - equal
- expressions - boolean operators on integers
    - less, greater, equals
- expression - boolean operator expressions
    - and, or, not
- if
- variables
    - scope {}
    - variables declared in scope are not valid outside of that scope
    - variables may not shadow external variables (for now)
- infrastructure - built in functions
    - now()
    - registry of functions
- infrastructure - analysis of which functions called
- infrastructure - restrictions on which functions called
- while
- type - list
- dot operator semantics -> find matching function for argument types