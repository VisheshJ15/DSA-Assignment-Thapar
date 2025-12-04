#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

Node* insertBinaryTree() {
    int value;
    cout << "Enter data (-1 for no node): ";
    cin >> value;

    if (value == -1)
        return NULL;

    Node* root = new Node(value);

    cout << "Enter left child of " << value << endl;
    root->left = insertBinaryTree();

    cout << "Enter right child of " << value << endl;
    root->right = insertBinaryTree();

    return root;
}

bool isBSTUtil(Node* root, long long &prev) {
    if (root == NULL)
        return true;

    if (!isBSTUtil(root->left, prev))
        return false;

    if (root->data <= prev)
        return false;
    prev = root->data;

    return isBSTUtil(root->right, prev);
}

bool isBST(Node* root) {
    long long prev = LLONG_MIN;
    return isBSTUtil(root, prev);
}

int main() {
    cout << "Create Binary Tree:\n";
    Node* root = insertBinaryTree();

    if (isBST(root))
        cout << "\nThe given binary tree IS a BST\n";
    else
        cout << "\nThe given binary tree is NOT a BST\n";

    return 0;
}