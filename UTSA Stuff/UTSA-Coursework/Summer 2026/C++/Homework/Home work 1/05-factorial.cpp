#include <iostream>
using namespace std;


// Recursive function to calculate factorial
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
        return n * factorial(n - 1);
        //recursives were not taught in the video lesson
}

int main() {

    int number;


    cout << "here are examples for 0!, 1!, 5!, and 10!:\n";
    cout << factorial(0) << "\n";
    cout << factorial(1) << "\n";
    cout << factorial(5) << "\n";
    cout << factorial(10) << "\n";
    cout << "Please enter a number to calculate its factorial: \n";
    cin >> number;
    cout << "Factorial of " << number << " is " << factorial(number) << "\n";
    return 0;

    //why was this so much easier than 04?
}