# Learning

To process the file up front and then execute or to process the file as it executes?

For a script it is important to reveal any issues up front before they are hit during execution.

Technically it is also easier to process the entire script at once.

# Headers

Prevent header from being included multiple times

```c
#ifndef HEADER_FILE_constants
#define HEADER_FILE_constants

#pragma once
...
#endif
```