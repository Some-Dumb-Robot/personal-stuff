/*Problem — Stack or Queue (100 pts)*/
/*Your class must implement the rule of three correctly (deep-copying copy constructor, destructor,
and assignment operator), enforce an optional capacity limit, and support an equality operator. No
memory leaks.

Required members:
• Default constructor (empty, unlimited capacity).
• Parameterized constructor taking a capacity limit. Once the structure holds that many
elements, further pushes/enqueues are ignored.
• Copy constructor — independent deep copy.
• Destructor — frees every node.
• operator= — rule of three: self-assignment guard, free existing nodes, deep copy, returns
*this.
• operator== — true when both hold the same values in the same order.
• bool empty() const, void print() const — print in logical order, space-separated, fol-
lowed by a newline.*/

#include <iostream>
using namespace std;


struct Node {
    int val;
    Node* prev;
    Node* next;
};

class Stack {
    Node* top;
    int cap;
    int size;
public:

    Stack(int capacity = -1) : top(nullptr), cap(capacity), size(0) {} // default constructor with optional capacity

    ~Stack(){
        while(top){
            pop();
        }
    }

    void push(int val) {
        if (cap != -1 && size >= cap) {
            cout << "Stack is full. Cannot push " << val << endl;
            return;
        }

        Node* newNode = new Node{val, nullptr, top};

        if (top != nullptr)
            top->prev = newNode;

        top = newNode;
        size++;
    }
    void pop() {
        if (top == nullptr)
            return;

        Node* temp = top;
        top = top->next;

        if (top != nullptr)
            top->prev = nullptr;

        delete temp;
        size--;
    }

    int get_Top() const {return top->val;};

    int get_Size() const {return size;};

    bool empty() const {return top == nullptr;};

    void print() const {
        Node* curr = top;

        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    //copy constructor
    Stack(const Stack& other) {
    top = nullptr;
    size = other.size;
    cap = other.cap;

    if (other.top == nullptr)
        return;

    // Copy the first node (the top)
    top = new Node{other.top->val, nullptr, nullptr};

    Node* src = other.top->next;
    Node* dest = top;

    while (src != nullptr) {
        dest->next = new Node{src->val, dest, nullptr};
        dest = dest->next;
        src = src->next;
    }
}

    //assignment operator
    Stack& operator=(const Stack& other) {
        if(this == &other) {
            return *this;
        }
        while(top) {
            pop();
        }
        Node* curr = other.top;
        while(curr) {
            push(curr->val);
            curr = curr->prev;
        }
        return *this;
    };

    //equality operator
    bool operator==(const Stack& other) const {
        Node* curr1 = top;
        Node* curr2 = other.top;
        while(curr1 && curr2) {
            if(curr1->val != curr2->val) {
                return false;
            }
            curr1 = curr1->prev;
            curr2 = curr2->prev;
        }
        return curr1 == nullptr && curr2 == nullptr;
    }

};

int main() {

    Stack s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.print(); // Output: 30 20 10

    cout << "The top: " << s1.get_Top() << endl; //output should be 30

    Stack s2 = s1;
    
    s1.pop();   s1.push(99); //should replace the top value with 99
    cout << "after replacement: ";
    s1.print(); // output: 99 20 10

    cout << "Copy unchanged: ";
    s2.print(); //should put out 30 20 10

    

    cout << "Are they equal?: ";
    if(s1 == s2){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

    Stack s3(2);
    s3.push(1);
    s3.push(2);
    s3.push(3); //should not get pushed
    cout << "Capped (cap 2): ";
    s3.print();

    // cout << s1.get_Top() << endl; //output should be 99
    // cout << s1.get_Size() << endl; //output should be 3 




}
 