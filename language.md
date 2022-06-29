# language

define what the programs actually look like.

## newlines

## Comments

comments start with a `#` and go to the next newline.
comments may only be preceded by spaces from the previous newline.

Only valid line for a comment
`newline` `spaces 4*` `#` `character *` `newline`

the number of allowable spaces is determined by the indent level. By default the indent level is zero.

## expressions

expressions evaluate to a single value.
expressions must be on a single line

Future: expressions may extend across lines if between parentheses.

## statements

statements do not evaluate to a value, but may contain expressions.

`let` and `if` are statements.

- variable declaration
- variable assignment
- control flow
- expressions can be a statement