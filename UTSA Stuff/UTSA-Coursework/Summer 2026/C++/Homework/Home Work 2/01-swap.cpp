/*Write a function void swapInts(int* a, int* b) that swaps two integers using pointer param-
eters. Do not use references — the parameters must be int* and you must dereference them to
access the values.
In main(), declare two integers, print them before and after calling swapInts.*/

#include <iostream>
using namespace std;

void swapInts(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5;
    int y = 10;

    cout << "Before swap: x = " << x << ", y = " << y << endl;

    swapInts(&x, &y);

    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}