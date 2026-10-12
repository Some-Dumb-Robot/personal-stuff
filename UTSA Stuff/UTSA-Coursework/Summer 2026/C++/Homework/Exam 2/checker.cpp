/*just need to practive stuff in here*/

#include <iostream>
using namespace std;
struct Node { int val; Node* next; };
class Stack {
Node* top_ = nullptr;
public:
void push(int v) { top_ = new Node{v, top_}; }
void pop() { Node* t = top_->next; delete top_; top_ = t; }
int top() const { return top_->val; }
};
int main() {
Stack s;
s.push(5); s.push(10); s.push(15);
s.pop();
cout << s.top() << "\n";
s.push(99);
cout << s.top() << "\n";
return 0;
}