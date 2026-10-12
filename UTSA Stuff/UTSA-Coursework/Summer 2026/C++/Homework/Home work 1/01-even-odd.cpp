#include <iostream>
using namespace std;

int main() {
    
    int n = 1;
    int odd = 0;
    int even = 0;
    
    cout << "Please enter an integer. Enter zero to stop\n";

    do {
        cin >> n; 
        if ((n % 2 == 0)&&(n != 0)) {
            even++;
        } else if (n != 0) {
            odd++;
        }
    } 
    while (!(n == 0));

    cout << "\n";
    cout << "Odd numbers: " << odd << "\n";
    cout << "Even numbers: " << even << "\n";

    return 0;
}
