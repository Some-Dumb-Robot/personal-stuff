/*Problem 3 — DynArray Class (40 pts) 
Implement the DynArray class below. Start with capacity 2 and double capacity when push_back
is called on a full array
In main(), create a DynArray, push 6 values, print them using operator[], and verify size()
returns 6.

Expected output:
10 20 30 40 50 60
size: 6
*/

#include <iostream>
using namespace std;

class DynArray {//constructor
    int* data_;
    int sz_;
    int cap_;
public:
    DynArray(int* a, int sz, int cap){// allocate initial capacity 2
        data_ = a;
        sz_ = sz;
        cap_ = cap;
    }; 

    ~DynArray(){//destructor to free memory {sounds like a cliche super villian}
        delete[] data_;
    };


    void push_back(int val){
        // append val; resize if full
        if(sz_ == cap_){
            cap_ *= 2;
            int* newData = new int[cap_];
            for(int i = 0; i < sz_; ++i){
                newData[i] = data_[i];
            }
            delete[] data_;
            data_ = newData;        
        }
        data_[sz_] = val;
        sz_++;  
    };
 

int size() const{
    return sz_;
}; // return number of elements

int& operator[](int i){ // return reference to element i
    return data_[i];
}; 
};

int main() {
    int* arr = new int[2];
    DynArray dyn_arr(arr, 0, 2);
    
    dyn_arr.push_back(10);
    dyn_arr.push_back(20);
    dyn_arr.push_back(30);
    dyn_arr.push_back(40);
    dyn_arr.push_back(50);
    dyn_arr.push_back(60);
    cout << dyn_arr[0] << " " << dyn_arr[1] << " " << dyn_arr[2] << " " << dyn_arr[3] << " " << dyn_arr[4] << " " << dyn_arr[5] << endl;
    cout << "size: " << dyn_arr.size() << endl;
    return 0;
}
 