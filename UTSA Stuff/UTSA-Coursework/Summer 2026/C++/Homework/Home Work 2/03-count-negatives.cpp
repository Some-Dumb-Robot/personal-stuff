/*Write a function int countNegatives(const int* arr, int n) that counts negative values in
an array passed as a const int*. Traverse using pointer arithmetic.
In main(), create an array with both negative and non-negative values, call the function, and print
the result.*/

#include <iostream>
using namespace std;

int countNegatives(const int* arr, int n) {
    const int* start = arr;
    int count = 0;

    while (start < arr + n) {
        if (*start < 0) {
            count++;
        }
        start++;
    }

    return count;
}

int main() {
    int arr[] = {-1, 2, -3, 4, -5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The array: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    int negativeCount = countNegatives(arr, n);

    cout << "Number of negative values: " << negativeCount << endl;

    return 0;
}

