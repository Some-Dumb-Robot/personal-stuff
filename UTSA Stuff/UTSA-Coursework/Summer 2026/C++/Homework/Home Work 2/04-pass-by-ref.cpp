/*Write a function void scale(double& val, double factor) that multiplies val by factor in
place using a reference parameter.
In main(), start with x = 5.0. Call scale(x, 2.0) and print x. Then call scale(x, 3.0) and
print x again.
Expected output:
After x2: 10
After x3: 30.*/

#include <iostream>
using namespace std;

void scale(double& val, double factor) {
    val *= factor;
}


int main() {
    double x = 5.0;
    cout << "Original X Value: " << x << endl;

    scale(x, 2.0);
    cout << "After x2: " << x << endl;

    scale(x, 3.0);
    cout << "After x3: " << x << endl;

    return 0;
}

