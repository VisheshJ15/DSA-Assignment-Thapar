#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node() {
        cout << "Memory freed for node with data " << data << endl;
    }
};

void insertAtEnd(Node*& head, char ch) {
    Node* n = new Node(ch);
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;
    Node* left = head;
    Node* right = head;
    while (right->next) right = right->next;
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    Node* head = NULL;
    string s = "RADAR";
    for (char c : s) insertAtEnd(head, c);

    if (isPalindrome(head))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}
