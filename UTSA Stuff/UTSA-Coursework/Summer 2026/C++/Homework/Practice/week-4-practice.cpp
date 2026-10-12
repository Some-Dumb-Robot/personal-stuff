/*just need to practive stuff in here*/

#include <iostream>
using namespace std;
#include <vector>

int main() {

    vector<int> nums = {1, 2, 3, 4, 5};
    for (auto n : nums) {
        cout << n << " ";
    }

    cout << endl << nums.size() << endl;

    return 0;
}