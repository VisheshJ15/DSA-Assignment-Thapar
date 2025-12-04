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
        n->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = n;
    n->next = head;
}

void display(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl;
}

int main() {
    Node* head = NULL;
    insertAtEnd(head, 20);
    insertAtEnd(head, 100);
    insertAtEnd(head, 40);
    insertAtEnd(head, 80);
    insertAtEnd(head, 60);
    display(head);
    return 0;
}
