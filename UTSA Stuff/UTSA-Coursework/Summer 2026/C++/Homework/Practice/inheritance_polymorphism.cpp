/*just need to practive stuff in here*/

#include <iostream>
using namespace std;

//base class
class shape{
public:
    virtual double area() const{ return 0.0;}
    // if double were defined as the following, that would make it an abstract:
    //virtual double area() const = 0;  every class defined by shape HAS TO override this function.
    //additionally, then you cannot just call shape by itself
    virtual ~ shape(){}
};


//derived class circle
class circle : public shape{
    double r;
public:
    circle(double r) : r(r) {};
    double area() const override{
        return 3.14*r*r;
    }
};
//the override will force it to use the area function here

//derived class rectangle
class rect : public shape{
    
public:
    double w, h;
    rect(double w, double h) : w(w), h(h) {};
    double area() const {
        return h*w;
    }
};

//can use shape base class or other classes as the input variable of a function


int main(){
    circle c(3.0);
    rect rr(4.5, 5.0);
    cout << "circle area (direct): " << c.area() << endl;
    cout << "Rectangle area (direct): " << rr.area() << endl;
    shape *p = &c;
    // if no virtual in front of area this returns zero. IF there is virtual it returns area of what it points to
    cout << "Via shape (indirect ): " << p->area() << endl; 


    // can make an array:
    shape *shapes[2];
    shapes[0] = new circle(4.0);
    shapes[1] = new rect(5.0, 6.0);
    cout << "areas: " << endl;
    for (int i =0; i < 2; i++){
        
        cout << shapes[i]->area() << ", ";
    }
    cout << endl;

    for (int i =0; i < 2; i++){
        delete shapes[i];
    }

    return 0;
};