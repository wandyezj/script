# spec

`#` starts a comment, all characters are ignored until the next newline `\n` character.

reject unknown characters outside of strings or comments.

scripts are restricted to a maximum number of lines and maximum number of columns per line. (configurable)

## thoughts

streaming execution, do not rely on anything not yet seen.

## tests

- maximum number of lines exceeded.
- maximum number of columns in a line exceeded.
- single line commend - all characters after a `#` comment to the next newline are ignored
- treat unicode characters (variable length encoding) correctly.
- null terminator within a specified variable string
- no newline at the end of the file (with a comment)