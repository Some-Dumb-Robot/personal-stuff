/*Write a function void reverseArray(int* arr, int n) that reverses an array in place.
Constraint: The function body must use pointer arithmetic only — no subscript [] operator
anywhere inside reverseArray. Use pointer addition and dereference.
In main(), declare a 6-element array, print it, call the function, and print the reversed array*/

#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* start = arr;
    int* end = arr + n - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    reverseArray(arr, n);

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    return 0;
}