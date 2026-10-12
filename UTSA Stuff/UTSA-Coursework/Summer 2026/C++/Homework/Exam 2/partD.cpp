/*just need to practive stuff in here*/

#include <iostream>
using namespace std;

struct Node { int val; Node* next; };

class Bag {
    Node* head_;
    int sz_;
public:
    Bag() : head_(nullptr), sz_(0) {}

    ~Bag(){
        if (head_ == nullptr)
            return;

        Node* temp = head_;
        head_ = head_->next;

        if (head_ != nullptr)
            head_->next = nullptr;

        delete temp;
        sz_--;
    };

    void add(int v){
         Node* n = new Node{v, head_};
         head_ = n;
         sz_++;
    };

    bool contains(int v) const{
        Node* curr = head_;

        while (curr) {
            if (curr->val == v) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
    int size() const { return sz_; }

    void print() const{
        Node* curr = head_;

        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }

        cout << endl;
    };
};

int main() {
    Bag b;
    b.add(10); b.add(20); b.add(30); b.add(10);
    b.print();
    cout << "size: " << b.size() << "\n";
     cout << boolalpha;
     cout << "contains 20: " << b.contains(20) << "\n";
     cout << "contains 99: " << b.contains(99) << "\n";
return 0;
}