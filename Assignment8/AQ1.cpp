#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;

    node(int value) {
        data = value;
        left = right = NULL;
    }
};

node* buildTree(node* root) {
    int data;
    cout << "Enter the data (-1 for no node): ";
    cin >> data;

    if(data == -1) {
        return NULL;
    }

    root = new node(data);

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void preOrder(node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root) {
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(node* root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    node* root = NULL;

    root = buildTree(root);

    cout << "\nPre-order Traversal: ";
    preOrder(root);

    cout << "\nIn-order Traversal: ";
    inOrder(root);

    cout << "\nPost-order Traversal: ";
    postOrder(root);

    cout << endl;
    return 0;
}