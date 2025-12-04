#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node() {
        cout << "Memory freed for node with data " << data << endl;
    }
};

void insertAtEndDoubly(Node*& head, int d) {
    Node* n = new Node(d);
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

void insertAtEndCircular(Node*& head, int d) {
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

int sizeOfDoubly(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int sizeOfCircular(Node* head) {
    if (!head) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    Node* doubly = NULL;
    Node* circular = NULL;

    insertAtEndDoubly(doubly, 10);
    insertAtEndDoubly(doubly, 20);
    insertAtEndDoubly(doubly, 30);
    insertAtEndDoubly(doubly, 40);

    insertAtEndCircular(circular, 5);
    insertAtEndCircular(circular, 15);
    insertAtEndCircular(circular, 25);

    cout << "Size of Doubly Linked List: " << sizeOfDoubly(doubly) << endl;
    cout << "Size of Circular Linked List: " << sizeOfCircular(circular) << endl;

    return 0;
}
