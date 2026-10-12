/*Problem 1 — Remove Duplicates In Place (30 pts)*/

#include <iostream>
using namespace std;


int main() {
    int arr[10] = {10, 20, 20, 5, -9, 23, 67, 89, 10, 3};
    int size = sizeof(arr) / sizeof(arr[0]);       // Track current number of elements
    int target = 0; //element checker

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    cout << std::endl;

    for (int i = 0; i < size; i++) {
        
        if (arr[target] == arr[i]) {
            std::cout << "Deleting element: " << arr[i] << std::endl;
            
            // Shift elements to the left
            for (int i = target; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            
            size--; // Reduce the logical size
            target --; // Stay at the same index to check the new value
        }
        
        target++;
    }

    cout << "Array after removing duplicates: ";

    // Print updated array: 10 20 40 50
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    cout << std::endl;
}
 