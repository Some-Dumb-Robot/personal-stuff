/*just need to practive stuff in here*/

#include <iostream>
using namespace std;
#include <vector>

//  #include "week-5-practice.hpp"

//you would make the class and it's definitions here. Then in main you would include the header file and call the class.
// when you build you must also include both .cpp files in the build command.
// must also add namespace infront of each function. DO NOT include the actual class line



int main() {

    vector<int> nums = {1, 2, 3, 4, 5};
    for (auto n : nums) {
        cout << n << " ";
    }

    cout << endl << nums.size() << endl;

    return 0;
}