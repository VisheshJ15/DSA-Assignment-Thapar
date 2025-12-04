#include <iostream>
#include <algorithm>
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

// (a) INSERT (No duplicates allowed)
Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        cout << "Duplicate not allowed: " << value << endl;

    return root;
}

// Find min node (used for delete)
Node* minNode(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// (b) DELETE element
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {  // Node found

        // Case 1: No child / 1 child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: 2 children → replace with inorder successor
        Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// (c) MAXIMUM depth of BST
int maxDepth(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// (d) MINIMUM depth of BST
int minDepth(Node* root) {
    if (root == NULL)
        return 0;

    // If one child is NULL, consider the depth of the other child
    if (root->left == NULL)
        return 1 + minDepth(root->right);
    if (root->right == NULL)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Inorder traversal (for display)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (true) {
        cout << "\n------ BST MENU ------";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display (In-order)";
        cout << "\n4. Maximum Depth";
        cout << "\n5. Minimum Depth";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;

        case 3:
            cout << "\nBST in-order: ";
            inorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Maximum Depth of BST = " << maxDepth(root) << endl;
            break;

        case 5:
            cout << "Minimum Depth of BST = " << minDepth(root) << endl;
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice!";
        }
    }
}