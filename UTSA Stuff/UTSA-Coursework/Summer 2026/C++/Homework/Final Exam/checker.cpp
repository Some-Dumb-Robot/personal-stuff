#include <iostream>
using namespace std;
struct Node { int val; Node* left; Node* right; };
Node* insert(Node* root, int val) {
if (!root) { return new Node{val, nullptr, nullptr}; }
if (val < root->val) { root->left = insert(root->left, val); }
else if (val > root->val) { root->right = insert(root->right, val); }
return root;
}
void inorder(Node* root) {
if (!root) { return; }
inorder(root->left);
cout << root->val << " ";
inorder(root->right);
}
int main() {
Node* t = nullptr;
for (int v : {5, 2, 8, 1, 4}) { t = insert(t, v); }
inorder(t);
cout << "\n";
return 0;
}