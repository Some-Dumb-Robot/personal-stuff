#include <iostream>
using namespace std;


class IntStack {
    int* data_;
    int cap_;
    int sz_;
public:
    IntStack(int capacity) : sz_(0){ //constructor
        data_ = new int[capacity];
        cap_ = capacity;

    };

    ~IntStack(){ //destructor
        delete[] data_;
    };
    bool empty() const{ // check if list is empty
        if(sz_ > 0){
            return false;
        }
        return true;
    };

    bool full() const{ // check if list is full
        if(sz_ == cap_){
            return true;
        }
        return false;
    }

    void push(int val) { // push to the top of the list
        if (sz_ >= cap_) {
            cout << "Stack is full. Cannot push " << val << endl;
            return;
        }
        data_[sz_] = val;
        sz_++;
    }

    void pop(){ // remove the top of the list
        if(sz_ > 0){
            sz_--;
        }
    };

    int top() const{ // return the top value
        return data_[sz_-1];
    };

    int size() const{// return size of list
        return sz_;
    };

    void print() const{ // print out the list
        for(int i = sz_ - 1; i >= 0; i--){
            cout << data_[i] << " ";
        }
        cout << endl;
    };
};


int main() {
    IntStack s(5);
    s.push(10); s.push(20); s.push(30);
    s.print();
    cout << "top: " << s.top() << "\n";
    s.pop();
    s.push(99);
    s.print();
    
    return 0;
}