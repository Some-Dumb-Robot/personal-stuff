/*Problem 2 — Insert Into a Dynamic Array (30 pts)

Consider an array created with new[]. Write a function:
int* insert_after(int* a, int csz, int cap, int after, int val);
that inserts val immediately after the first occurrence of after. Parameters: csz is the current
number of elements, cap is the allocated capacity. Assume after exists.
1
• If there is spare capacity (csz < cap), shift elements right, insert in place, and return nullptr
(no new array was needed).
• If the array is full, allocate a larger array, copy the contents with val inserted, and return
the new array’s address.

Your program must have no memory leaks — free every array you allocate with new[].
In main(), start with a full capacity-5 array {10, 20, 30, 40, 50}. First call insert_after(a,
5, 5, 30, 99) — the array is full, so it must grow and return a new pointer. Then call
insert_after again to insert 77 after 40 into the array that now has spare capacity — it must
insert in place and return nullptr. Free every array you allocate.
Sample output:
10 20 30 99 40 50
10 20 30 99 40 77 50
*/


#include <iostream>
using namespace std;

int* insert_after(int* a, int csz, int cap, int after, int val){
    if(csz < cap){
        cout << "less than cap happened" << endl;
        
        // Shift elements to the right
        for(int i = csz; i > 0; --i){
            if(a[i-1] == after){
                a[i] = val;
                
                return nullptr;
            }
            a[i] = a[i-1];
        }
        

    } else {
        cout << "bigger than cap happened" << endl;

        // Allocate new array with increased capacity
        int* newArr = new int[cap + 1];
        bool inserted = false;
        for(int i = 0, j = 0; i < csz; ++i, ++j){
            newArr[j] = a[i];
            if(a[i] == after && !inserted){
                newArr[++j] = val;
                inserted = true;
            }
        }
        
        return newArr;
    }

}




int main() {
    int* arr = new int[5]{10, 20, 30, 40, 50};
    int* newArr = insert_after(arr, 5, 5, 30, 99);
    if (newArr != nullptr) {
        delete[] arr;
        arr = newArr;
    }

    cout << "Array after insertion: ";
    for (int i = 0; i < 6; ++i) {
        cout << arr[i] << " "; }
    cout << endl;

    newArr = insert_after(arr, 6, 7, 40, 77);
    if (newArr != nullptr) {
        delete[] arr;
        arr = newArr;
    }

    cout << "Array after second insertion: ";
    for (int i = 0; i < 7; ++i) {
        cout << arr[i] << " "; }
    cout << endl;
}
 