/*just need to practive stuff in here*/

#include <iostream>
using namespace std;
void doubleIt(int* p) { *p = *p * 2; }


int main() {
int a = 3, b = 7;
doubleIt(&a);
doubleIt(&b);
cout << a << " " << b << "\n";
return 0;
}