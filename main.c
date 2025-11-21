#include <stdio.h>
#include <windows.h>
#include "center_utils/center_utils.h"

const char* welcome =
"********************************************\n"
"*     Welcome to the Center Utils Demo     *\n"
"*      Clean & Centered Terminal Text      *\n"
"********************************************\n";

const char* info =
"Use this library to center any terminal line\n"
"It works with English, numbers, symbols, etc.\n"
"Just specify your actual line width for beauty\n";

int main() {
    SetConsoleOutputCP(CP_UTF8); // Enable international characters
    printc(welcome, 44);         // Each line is 44 characters wide
    printc(info, 40);            // Each line is about 40 characters
    getchar(); // Wait for a key press before closing
    return 0;

}