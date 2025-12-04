#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

#define HASH_SIZE 100
int hashSet[HASH_SIZE] = {0};
int hashVal[HASH_SIZE] = {0};

bool checkDuplicate(struct Node *root) {
    if (root == NULL)
        return false;

    int key = abs(root->data) % HASH_SIZE;

    if (hashSet[key] == root->data && hashVal[key] == 1)
        return true;

    hashSet[key] = root->data;
    hashVal[key] = 1;

    if (checkDuplicate(root->left)) return true;
    if (checkDuplicate(root->right)) return true;

    return false;
}

// Create new node
struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    
    struct Node *root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(8);
    root->left->left = newNode(2);
    root->left->right = newNode(3); 
    root->right->right = newNode(9);

    if (checkDuplicate(root))
        printf("Duplicates Found\n");
    else
        printf("No Duplicates\n");

    return 0;
}