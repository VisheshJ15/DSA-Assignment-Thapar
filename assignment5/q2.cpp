#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int deleteOccurrences(Node*& head, int key) {
    int count = 0;
    while (head && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        count++;
    }
    Node* cur = head;
    while (cur && cur->next) {
        if (cur->next->data == key) {
            Node* t = cur->next;
            cur->next = cur->next->next;
            delete t;
            count++;
        } else {
            cur = cur->next;
        }
    }
    return count;
}

int main() {
    Node* head = NULL;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 1);
    insertEnd(head, 3);
    insertEnd(head, 1);
    int key = 1;
    cout << "Original Linked List: ";
    printList(head);
    int count = deleteOccurrences(head, key);
    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    printList(head);
    return 0;
}