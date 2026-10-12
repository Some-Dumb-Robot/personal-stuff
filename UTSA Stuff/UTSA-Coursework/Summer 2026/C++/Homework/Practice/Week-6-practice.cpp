/*just need to practive stuff in here*/

#include <iostream>
using namespace std;
#include <vector>

/* shallow copy: copies pointer field by field
both objects point to the same memory location
modyfiing one object will modify the other object
destroying one object will destroy the other object.
ex: 
buf b = a ;
b.set (0, 999);
cout << a.get(0) << endl;



deep copy: copies the values of the object to a new memory location
allocates new memory for the new object
copies elements one by one to the new memory location
each object has its own copy of the data
destroying one object will not affect the other object
ex:
buf(const buf& other) : sz(other.sz) {
 data = new int[sz];
 for (int i = 0; i < sz; i++) {data [i] = other.data[i];
}

buf& operator=(const buf& other) {   // copy assignment operator, replace buffer, self assignment guard
if (this == &other ) {return *this;}
}
 */ 






 /* Nodes:
 single linked:
 struct Node {int val; Node* next;};

Node *push_front(Node* head, int val){
    Node* n = new Node{val, head};
    return n;
} 


Node pushback:
void push_back(Node*& head, int val){
    Node* n = new Node{val, nullptr};
    if(!head){ head = n; return;}
    Node* curr = head;
    while(curr->next){ curr = curr->next;}
    curr->next = n;
 }


  destroy every node to free memory:
void destroy(Node* head){
    while(head){
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
}
 */

/* Double Linked List 
struct Node {
    int val;
    Node* prev;
    Node* next;
};

push_front:
Node* push_front(Node* head, int val){
    Node* n = new Node{val, nullptr, head};
    if(head){ head->prev = n;}
    return n;


*/


int main() {

    

    return 0;
}