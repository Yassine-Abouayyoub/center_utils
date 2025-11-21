# Center Utils

A simple C library to **center and print text in the terminal/console** on Windows.

## Features

- ✅ Center any text horizontally in your terminal
- ✅ Supports multi-line text via `\n`
- ✅ Works with English, numbers, symbols, and box drawing characters
- ✅ UTF-8 compatible—international text ready
- ✅ Easy to use in any C project

## Installation

1. Download or clone this repository
2. Copy `center_utils.h` and `center_utils.c` to your project folder
3. Include the header at the top of your `.c` file:
   ```c
   #include "center_utils/center_utils.h"
   ```

## Usage Example

```c
#include <stdio.h>
#include <windows.h>
#include "center_utils/center_utils.h"

const char* welcome =
"********************************************\n"
"*     Welcome to the Center Utils Demo     *\n"
"*      Clean & Centered Terminal Text      *\n"
"********************************************\n";

const char* info =
"**************************************************\n"
"*  Use this library to center any terminal line  *\n"
"*It works with characters, numbers, symbols, etc.*\n"
"* Just specify your actual line width for beauty *\n"
"**************************************************\n";

int main() {
    SetConsoleOutputCP(CP_UTF8); // Enable Unicode
    printc(welcome, 44);         // Each line is 44 characters wide
    printc(info, 50);            // Each line is 50 characters wide
    getchar(); // Wait for key press before closing
    return 0;
}
```

## Functions

- `printc(multi_line_text, line_width)`: Center and print all lines in the text block.
- `printCentered(single_line_text, line_width)`: Center and print one line.

## Compilation

Use GCC:
```bash
gcc main.c center_utils/center_utils.c -o demo.exe
```

## Parameters

- **multi_line_text**: Your string (can include several lines separated by `\n`)
- **line_width**: The character width of a line (count it, don't trust `strlen()` for Unicode or special characters)

## Requirements

- Windows OS
- GCC (MinGW) or compatible compiler

## License

MIT License — free to use, modify, and share.

---

**Tip:** Always verify your actual line widths for perfect centering, especially with special or Unicode characters!