/*just need to practive stuff in here*/
//Binary search trees

#include <iostream>
using namespace std;



class Tree {
public:
virtual void insert(int val) = 0;
virtual bool contains(int val) const = 0;
virtual int size() const = 0;
virtual void print(ostream& os) const = 0;
virtual ~Tree() {}
};



class BST : public Tree {
private:
    struct Node {
        int val;
        Node* left;
        Node* right;
    };

    Node* root;
    int sz = 0;

public:
    BST() : root(nullptr) {}

    // void insert(int val) override; CHECK
    // bool contains(int val) const override; CHECK
    // int size() const override; CHECK
    // void print(std::ostream& os) const override; 

    ~BST() {
        destroy(root);
    }

    void insert(int val) override{ 
        Node* newNode = new Node{val, nullptr, nullptr};
        sz++;

        // Empty tree
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* curr = root;

        while (true) {
            if (val < curr->val) { 
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    return;
                }
                curr = curr->left;
            }
            else if (val > curr->val) {
                if (curr->right == nullptr) {
                    curr->right = newNode;
                    return;
                }
                curr = curr->right;
            }
            else {
                // Value already exists
                delete newNode;
                sz--;
                return;
            }
        }
    }

    bool contains(int val) const override{ //looks for a specific value in the tree
        if(!root){
        return false;
    }
        Node* curr = root;

    while (true) {
            if (val < curr->val) { 
                if (curr->left == nullptr) {
                    return false;
                }
                curr = curr->left;
            }
            else if (val > curr->val) {
                if (curr->right == nullptr) {
                    return false;
                }
                curr = curr->right;
            }
            else {
                // Value exists

                return true;
            }
        }
    };

    int size() const override{
        return sz;
    }

    void print(ostream& os) const
    {
        inorder(os, root);
        os << endl;
    }
    
    //taken from the notes. will be useful
    void inorder(ostream& os, Node *root) const{
    if(!root){
        return;
    }
    inorder(os, root->left);
    os << root->val << " ";
    inorder(os, root->right);
    }
    
    //also taken from notes. will be useful
    void destroy(Node* root){
        if(!root){
            return;
        }
        destroy(root->left);
        destroy(root->right);
        delete root;
    }
    

};  


//will access whatever print function is available
ostream& operator<<(ostream& os, const Tree& t){
    t.print(os);
    return os;
}



int main(){

    BST t;
    t.insert(5); t.insert(3); t.insert(7); t.insert(1); t.insert(4); t.insert(6); t.insert(8); 


    cout << "In order: " << t;
    
    cout << "size: " << t.size() << endl;


    cout << "Contains 4: " << std::boolalpha << t.contains(4) << endl;
    cout << "Contains 9: " << std::boolalpha << t.contains(9) << endl;

    Tree *p = &t;
    cout << "Via Tree: " << *p << endl; 

    return 0;
}