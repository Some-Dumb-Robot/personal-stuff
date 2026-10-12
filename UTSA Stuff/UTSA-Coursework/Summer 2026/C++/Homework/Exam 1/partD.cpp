/*just need to practive stuff in here*/

#include <iostream>
using namespace std;
int* buildSquares(int n) {
    int* squares = new int[n];
    for (int i = 0; i < n; i++) {
        squares[i] = ((i + 1) * (i + 1));
    }
    return squares;
}



int main() {
int n = 6;
int* sq = buildSquares(n);
// TODO: print and free
for (int i = 0; i < n; i++) {
    cout << sq[i] << " ";
}
cout << endl;
delete[] sq;
return 0;
}