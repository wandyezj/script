# Tokens

set of characters

token {
    // characters read for the token
    buffer
    token_type
}

break string into a stream of tokens

# comment
-> 
[#, comment]

# comment #
-> [#, comment #]
?

a + b
->
[a, +, b]


Assume random string of characters is an identifier or possibly an if



https://github.com/python/cpython/blob/main/Grammar/Tokens