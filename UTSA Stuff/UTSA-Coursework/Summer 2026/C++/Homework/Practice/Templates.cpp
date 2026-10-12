/*just need to practive stuff in here*/

#include <iostream>
using namespace std;

template <typename T>
T mymax(T a, T b){
    return (a>b) ? a : b;
}

template <typename T>
T add(T num1, T num2){
    return num1 + num2;
}

template <typename T>
class Stack{
    T data[100];
    int top_;
public:
    Stack() : top_(-1) {}

    void push(const T& val){
        if (top_ < 99) {data[++top_] = val;}
    }
    
    void pop(){ if (top_ >= 0){
        top_--;
    }   }

    T top() const{return data[top_];};
    bool empty() const { return top_ == -1;}
};

int main(){
    int a = 1;
    int b = 2;
    int result = add(a, b);
    cout << "result: " << result << endl;

    //this one forces the template to use int
    int sum = add<int>(a, b);


    return 0;
}