/*just need to practive stuff in here*/

#include <iostream>
using namespace std;
#include <vector>

/* Stack: LIFO (last in first out)
push: add an element to the top of the stack
pop: remove the top element from the stack
(like a stack of plates, you can only add or remove the top plate)
top: read the top element without removing it
empty: check if the stack is empty
EX:
class Stack {
    Node* top;
public:
    void push(int val) {
        top = new Node{val, top};}

    void pop () {
        if (top == nullptr) {return;}
        Node* temp = top->next;
        delete top;
        top = temp;}

    int top() {return top->val;}

    bool empty() {return top == nullptr;}

    ~stack(){
        while(top){
            pop();
        }
    }



Queue: FIFO (first in first out)
enqueue: add an element to the back of the queue
dequeue: remove the front element from the queue
front: read the front element without removing it
back: read the back element without removing it
empty: check if the queue is empty        
can access front and back of the queue, but can only remove from the front and add to the back
EX:
class Queue {
    Node* head;
    Node* tail;
Public:
    void enqueue(int val) {
        Node* n = new Node{val, nullptr};
        if (tail == nullptr) {
            head = tail = n;
            return;
        } else {
            tail->next = n;
            tail = n;}
    }
    
    void dequeue() {
        if (head == nullptr) {return;}
        Node* temp = head->next;
        delete head;
        head = temp;
        if (head == nullptr) {tail = nullptr;}
    }


*/


int main() {

    

    return 0;
}