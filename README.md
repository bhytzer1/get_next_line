# get_next_line

A C function that reads one line at a time from a file descriptor.

## Description

`get_next_line` is a function that allows you to read a file line by line, returning the next line each time (including the `\n` character if present). The function automatically handles reading in chunks and keeps unprocessed content in memory between successive calls.

## Features

- Reads one line at a time from any file descriptor
- Handles files of any size
- Maintains reading state between successive calls
- Bonus version: supports simultaneous reading from multiple file descriptors
- Configurable buffer size via `BUFFER_SIZE`

## Usage

```c
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;
    
    fd = open("file.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```

## Compilation

```bash
# Standard version
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

# Using the included Makefile
make

# Bonus version (multiple file descriptors)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

## Project Files

- `get_next_line.c` - Main function implementation
- `get_next_line_utils.c` - Helper functions (strchr, strlen, strjoin)
- `get_next_line.h` - Header with declarations
- `get_next_line_bonus.c` - Bonus version to handle multiple file descriptors
- `get_next_line_bonus_utils.c` - Utilities for bonus version
- `get_next_line_bonus.h` - Header for bonus version

## How It Works

The function uses a `static` variable to preserve data that has been read but not yet returned. On each call:

1. Reads from the file in chunks of `BUFFER_SIZE`
2. Searches for the newline character (`\n`)
3. Extracts the complete line (up to and including `\n`)
4. Saves the remaining data for the next call
5. Returns the read line or `NULL` if there are no more lines

## Technical Notes

- `BUFFER_SIZE` can be defined at compile time
- The function correctly handles edge cases (empty files, lines without final `\n`)
- All dynamically allocated memory is properly freed
- The bonus version uses an array of static buffers to handle up to 1024 file descriptors simultaneously

## License

MIT License - see the `LICENSE` file for details.
