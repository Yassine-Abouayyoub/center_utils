#include <stdio.h>
#include <windows.h>
#include <stdarg.h>
#include <string.h>
#include "center_utils.h"

void printc(const char* fmt, ...) {
    char buffer[512];

    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    int maxlen = 0;
    const char* ptr = buffer;
    while (*ptr) {
        const char* nl = strchr(ptr, '\n');
        int len = nl ? (nl - ptr) : strlen(ptr);
        if (len > maxlen) maxlen = len;
        if (!nl) break;
        ptr = nl + 1;
    }

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns = 80;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    int pad = (columns - maxlen) / 2;
    if (pad < 0) pad = 0;

    ptr = buffer;
    while (*ptr) {
        const char* nl = strchr(ptr, '\n');
        int len = nl ? (nl - ptr) : strlen(ptr);
        for (int i = 0; i < pad; i++) putchar(' ');
        fwrite(ptr, 1, len, stdout);
        putchar('\n');
        if (!nl) break;
        ptr = nl + 1;
    }
}
