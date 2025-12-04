#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    ~Node() {
        cout << "Memory freed for node with data " << data << endl;
    }
};

void insertAtEnd(Node*& head, int d) {
    Node* n = new Node(d);
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}

bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp = head->next;
    while (temp && temp != head)
        temp = temp->next;
    return (temp == head);
}

int main() {
    Node* head = NULL;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    if (isCircular(head))
        cout << "Circular Linked List" << endl;
    else
        cout << "Not Circular Linked List" << endl;

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = head;

    if (isCircular(head))
        cout << "Circular Linked List" << endl;
    else
        cout << "Not Circular Linked List" << endl;

    return 0;
}
