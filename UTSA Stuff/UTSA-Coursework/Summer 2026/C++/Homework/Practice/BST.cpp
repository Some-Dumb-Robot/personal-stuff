/*just need to practive stuff in here*/
//Binary search trees

#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
};

Node *insert(Node *root, int val){
    if (!root){
        return new Node{val, nullptr, nullptr};

    }
    if(val < root->val){
        root->left = insert(root->left, val); //go left if smaller
    }
    else if (val > root->val){
        root->right = insert(root->right, val); //go right if larger
    }
    return root;
}

void inorder(Node *root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void destroy(Node* root){
    if(!root){
        return;
    }
    destroy(root->left);
    destroy(root->right);
    delete root;
}

void postorder (Node* root){
    if (!root){return;}
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " "; 
}

void printTree(ostream& os, Node* root, int indent){
    if (!root){return;}
    printTree(os, root->right, indent +4);
    os << string(indent, ' ') << root->val << endl;
    printTree(os, root->left, indent +4);

}

ostream& operator<<(ostream &os, Node* root){
    printTree(os, root, 0);
    return os;
}

Node* minNode(Node* root){
    while(root->left){root = root->left;}
    return root;
}

Node* remove(Node* root, int val){
    if(!root){ return nullptr;}
    if(val < root->val){
        root->left = remove(root->left, val);
        return root;
    }
    if(val > root->val){
        root->right = remove(root->right, val);
        return root;
    }
    if(!root->left && !root->right){ 
        delete root;
        return nullptr;
    }
    if(!root->left){
        Node* tmp = root->right;
        delete root;
        return tmp;
    }
    if(!root->right){
        Node* tmp = root->left;
        delete root;
        return tmp;
    }
    Node* succ = minNode(root->right);
    root->val = succ->val;
    root->right = remove(root->right, succ->val);
    return root;
}

int main(){
    Node *tree =nullptr;
    for(int v : {5, 3, 7, 1, 4, 6, 8, 2}){
        tree = insert(tree,v);
    }
    cout << tree; 
    destroy(tree);

    return 0;
}