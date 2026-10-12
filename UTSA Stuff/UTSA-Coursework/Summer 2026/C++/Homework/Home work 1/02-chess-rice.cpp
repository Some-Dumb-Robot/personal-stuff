#include <iostream>
using namespace std;

int main() {
    
    int grain_count = 1;
    int squares = 1;
    int target_grain = 0;
    
    cout << "Please enter the amount of rice grain you want: \n";
    cin >> target_grain;
 
    while (grain_count < target_grain){
        if(squares >= 64){
            break;
        }
        grain_count *= 2;
        squares++;

    }

    cout << "\nTarget grain count: " << target_grain << "\n";
    cout << "squares used: " << squares << "\n";
    cout << "Actual grain count: " << grain_count << "\n";

    return 0;
}
