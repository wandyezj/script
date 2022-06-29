# Outline

tokenize

Parse AST

Check AST

Execute AST

## Tokens

All keywords are tokens.




## Questions

Can code be executed line by line? Only if function definitions are declared before they are called.

If multiple functions are exported in a file then the entire file would need to be parsed anyway.

It's simpler to load up the entire set of code in one go and view the world. A global view of the entire source allows checks to be performed as is.

Since script is targeted at small scripts the global view is likely less of an issue.


## Simplest program

expression is evaluated.

Boolean Expressions

true

false

Boolean operators `not` `or` `and`

`xor`?

Boolean operator precedence

Boolean expressions with Parentheses precedence

Arithmetic expressions with Positive integers

1

1 + 1

Arithmetic operators `+` `-` `*` `/` `%`

Arithmetic operators multiple

Arithmetic expressions with PMA precedence.

Arithmetic expressions with P ()



# Questions

Would it be better to implement in a high level language like TypeScript first?
    - Allow formulation of algorithms before translating to c++
    - TypeScript doesn't have the control needed for some of the types.