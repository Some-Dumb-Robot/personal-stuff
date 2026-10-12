#include <iostream>
using namespace std;

//I made this before watching video 3

int main() {
    
    
    int entry = 0;
    int array_size = 0;
    bool peak_check = false;
    
    cout << "Please enter the size of the array: \n";
    cin >> array_size;

    int array[array_size];

    cout << "Please enter values for your array: \n";
    for (int i = 0; i < array_size; i++) {
        cin >> entry;
        array[i] = entry;
    }

    if(array[0] > array[1]) {
        cout << "At index 1 a local peak is: " << array[0] << "\n";
        peak_check = true;
    }

    for(int i = 0; i < array_size; i++) {
        if ((array[i] > array[i-1])&&(array[i] > array[i+1])) {
            cout << "At index " << i+1 << " a local peak is: " << array[i] << "\n";
            peak_check = true;
        }
    }
    if (peak_check == false) {
        cout << "No local peaks were found in the array.\n";
    }

    return 0;
}
