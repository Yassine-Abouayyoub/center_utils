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
