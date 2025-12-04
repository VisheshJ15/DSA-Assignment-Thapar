#include <iostream>
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

// Insert data in BST (Tree creation)
Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// (a) Search Recursive
Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

// (a) Search Iterative / Non-recursive
Node* searchIterative(Node* root, int key) {
    while (root != NULL) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// (b) Maximum element of BST
Node* maxNode(Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

// (c) Minimum element of BST
Node* minNode(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// (d) In-order Successor
Node* inorderSuccessor(Node* root, Node* target) {
    if (target->right != NULL)
        return minNode(target->right);

    Node* successor = NULL;
    while (root != NULL) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        }
        else if (target->data > root->data)
            root = root->right;
        else
            break;
    }
    return successor;
}

// (e) In-order Predecessor
Node* inorderPredecessor(Node* root, Node* target) {
    if (target->left != NULL)
        return maxNode(target->left);

    Node* predecessor = NULL;
    while (root != NULL) {
        if (target->data > root->data) {
            predecessor = root;
            root = root->right;
        }
        else if (target->data < root->data)
            root = root->left;
        else
            break;
    }
    return predecessor;
}

// Traversal to verify Tree formation
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nBST (In-order Traversal): ";
    inorder(root);
    cout << endl;

    int key;
    cout << "\nEnter element to search: ";
    cin >> key;

    cout << "Recursive Search: ";
    cout << (searchRecursive(root, key) ? "Found" : "Not Found") << endl;

    cout << "Iterative Search: ";
    cout << (searchIterative(root, key) ? "Found" : "Not Found") << endl;

    cout << "\nMinimum element = " << minNode(root)->data << endl;
    cout << "Maximum element = " << maxNode(root)->data << endl;

    Node* target = searchRecursive(root, key);
    if (target != NULL) {
        Node* succ = inorderSuccessor(root, target);
        Node* pred = inorderPredecessor(root, target);

        cout << "\nIn-order Successor of " << key << ": ";
        if (succ) cout << succ->data; else cout << "None";

        cout << "\nIn-order Predecessor of " << key << ": ";
        if (pred) cout << pred->data; else cout << "None";
    }

    cout << endl;
    return 0;
}