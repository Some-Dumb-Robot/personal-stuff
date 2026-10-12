/*Write a function void myCopy(const char* src, char* dst) that copies a null-terminated C-
string from src to dst using pointer arithmetic only — no strcpy, no [] operator. Advance both
pointers one character at a time and copy the null terminator.
In main(), declare a source char array and a destination buffer of at least 64 bytes, call myCopy,
and print the destination.*/

#include <iostream>
using namespace std;



void myCopy(const char* src, char* dst) {
    while (*src != '\0') {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = '\0'; // Copy the null terminator
}

int main() {
    const char* source = "Hello, World!";
    char destination[64];

    cout << "Original string: " << source << endl;

    myCopy(source, destination);
    cout << "Copied string: " << destination << endl;

    return 0;
}

