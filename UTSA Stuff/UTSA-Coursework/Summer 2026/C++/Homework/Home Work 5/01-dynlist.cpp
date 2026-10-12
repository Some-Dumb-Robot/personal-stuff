/*Problem 1 — DynList Basics (30 pts)*/

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
};



int main() {
   DynList list;
   // make the initial list
   list.push_back(10);
   list.push_back(20);
   list.push_back(30);
   list.push_back(40);
   list.push_back(50);
   list.print();

    // remove the last element
    list.pop_back();
    list.print();

    //setting list of zero to 99
    list[0] = 99;
    list.print();
    
}
 