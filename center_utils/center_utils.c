#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "center_utils.h"

void printCentered(const char* text, int width) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns = 80;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    int pad = (columns - width) / 2;
    if (pad < 0) pad = 0;
    for (int i = 0; i < pad; i++) putchar(' ');
    printf("%s\n", text);
}

void printc(const char* bigText, int fixed_width) {
    char buffer[512];
    const char* start = bigText;
    while (*start) {
        const char* end = strchr(start, '\n');
        if (!end) end = start + strlen(start);
        size_t line_len = end - start;
        strncpy(buffer, start, line_len);
        buffer[line_len] = '\0';
        printCentered(buffer, fixed_width);

        if (*end == '\n') start = end + 1;
        else break;
    }
}