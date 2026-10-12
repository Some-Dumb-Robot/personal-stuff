/*Problem 2  — Static-Array List ADT (60 pts)*/

#include <iostream>
using namespace std;

class arrayList {
  int list[50];
  int sz = 0;

public:
  arrayList() {
    sz = 0;
  }

  void append(int value) {
    if (sz < 50) {
      list[sz] = value;
      sz++;
    }
  }

  void remove(int index) {
    if (index >= 0 && index < sz) {
      for (int i = index; i < sz - 1; i++) {
        list[i] = list[i + 1];
      }
      sz--;
    }
  }
  int get(int index) const {
    if (index >= 0 && index < sz) {
      return list[index];
    }
    return -1; // Return -1 for invalid index
  }

  int getSize() const {
    return sz;
  }

  void print() const {
    for (int i = 0; i < sz; i++) {
      cout << list[i] << " ";
    }
    cout << endl;
  }

};

int main() {
   arrayList myArray;
    myArray.append(10);
    myArray.append(20);
    myArray.append(30);
    myArray.append(40);
    myArray.append(50);
    myArray.print(); // Output: 10 20 30 40 50

    myArray.remove(2); // Remove the element at index 2 (30)
    cout << "After removing(2): ";
    myArray.print(); // Output: 10 20 40 50
    
    cout << "get(0) = " << myArray.get(0) << endl; // output: 10
}
 