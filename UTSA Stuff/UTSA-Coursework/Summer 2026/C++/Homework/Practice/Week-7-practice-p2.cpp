/*just need to practive stuff in here*/

#include <iostream>
using namespace std;
#include <vector>

/* operators are just functions with syntax:   + == << [] ++

operators can be overloaded

point c = a + b;    calls operator with a.operator+(b)

operator+ returns a new value
operator== returns a bool
const point& o takes by const reference. so no copy is made

point operator +(const point& o) const{
    return point(x + o.x, y + o.y);
}

bool operator == (const point& o) const{
    return x == o.x && y == o.y;
}

full example: */

struct point {
    double x;
    double y;
    
    point (double px, double py) : x(px), y(py) {} 

    //returns new point and doesn't modify anything
    point operator +(const point& o) const{
    return point(x + o.x, y + o.y);
    }

    //compares field by field
    bool operator == (const point& o) const{
    return x == o.x && y == o.y;
    }




};

//this is what makes the thing printable:
// it is also a free function and does not need to be within the class. (this is due to the type of operator it is)
ostream &operator<<(ostream &os, const point &p){
    os << "(" << p.x << "," << p.y << ")";
    return os;
}


class Counter{
    int val;

public:
    Counter(int v = 0) : val(v) {}    

    //increments before returning the value
    Counter& operator++(){
    ++val;
    return *this;
    }


    //increments after returning the value
    Counter operator++(int){
        Counter tmp = *this;
        ++val;
        return tmp;
    } 

    int get() const {return val;}

};

class IntVec{
    int data[10];
    int sz;
public:
    IntVec() : sz(0){
        for (int i = 0; i < 10; i++){
            data[i] = 0;
        }
    }

    void push_back(int v){
        if (sz < 10){
            data[sz++] = v;

        }
    }

    int size() const {return sz;}

    //non const overload
    int &operator[](int i){
        return data[i];
    }
    //const overload
    const int &operator[](int i) const{
        return data[i];
    }
};





int main() {
// normal point operators 
/*
    point a(1.0, 2.0);
    point b(3.0, 4.0);
    point c = a + b;
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << c << endl;
    cout << "a==b " << (a==b) << endl;
    cout << "a==a " << (a==a) << endl;   */


// counter operators:
/*
    Counter c(5);
    cout << "start: " << c.get() <<endl;
    cout << "++c: " << (++c).get() << endl;
    cout << "c++: " << (c++).get() << endl;
    cout << "after: " << c.get() << endl; 
*/

// vector operators:
    IntVec v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout << "v[1]: " << v[1] << endl;
    v[1] = 99;
    cout << "v[1] after write: " << v[1] << endl;

    const IntVec cv = v;
    cout << "cv[0]: " << cv[0] << endl;
    

    return 0;
}