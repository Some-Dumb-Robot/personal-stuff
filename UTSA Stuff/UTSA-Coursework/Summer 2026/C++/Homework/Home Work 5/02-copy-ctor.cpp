/*Problem 2 — Deep Copy with Copy Constructor (30 pts)*/

#include <iostream>
using namespace std;

class DynList {
    int* data;
    int sz;
    int cap;

public:
    DynList() : sz(0), cap(2) {// initial capacity 2
        data = new int[cap];
    }
    ~DynList(){ // free heap memory
        delete[] data;
    };
    void push_back(int v){// append; double capacity if full
        if(sz == cap){
            cap *= 2;
            int* newData = new int[cap];
            for(int i = 0; i < sz; ++i){
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;        
        }
        data[sz] = v;
        sz++; 
    }; 


    void pop_back(){// remove last element (do nothing if empty)
        if(sz > 0){
            sz--;
        } //techincally the last element is still in memory but we just ignore it
         // plus im lazy rn
    }; 

    int& operator[](int i) // read/write access
    {
        return data[i];
    }

    int size() const{// return size of list
        return sz;
    };

    void print() const{// space-separated elements + newline
        cout << "DynList: ";
        for(int i = 0; i < sz; ++i){
            cout << data[i] << " ";
        }
        cout << endl;
    } 

    // copy constructor
    DynList(const DynList& other) : sz(other.sz), cap(other.cap) {
        data = new int[cap];
        for (int i = 0; i < sz; ++i) {
            data[i] = other.data[i];
        }   
    }
};



int main() {
   DynList a;
   // make the initial list
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
   

    // make a copy of the list
    DynList b = a; // copy constructor is called
    b[0] = 99; // modify the copy
    a.print();
    b.print();
    
}
 