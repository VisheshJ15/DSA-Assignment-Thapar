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

class CircularList {
public:
    Node* head;
    CircularList() { head = NULL; }

    void insertAtBeginning(int d) {
        Node* n = new Node(d);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        n->next = head;
        temp->next = n;
        head = n;
    }

    void insertAtEnd(int d) {
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

    void insertAfter(int key, int d) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* n = new Node(d);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found" << endl;
    }

    void deleteNode(int key) {
        if (!head) return;
        Node* temp = head;
        Node* prev = NULL;
        do {
            if (temp->data == key) {
                if (temp == head) {
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    if (head->next == head) {
                        delete head;
                        head = NULL;
                        return;
                    }
                    last->next = head->next;
                    Node* del = head;
                    head = head->next;
                    del->next = NULL;
                    delete del;
                    return;
                } else {
                    prev->next = temp->next;
                    temp->next = NULL;
                    delete temp;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found" << endl;
    }

    void search(int key) {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Found " << key << " at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node not found" << endl;
    }

    void print() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

class DoublyList {
public:
    Node* head;
    DoublyList() { head = NULL; }

    void insertAtBeginning(int d) {
        Node* n = new Node(d);
        if (head) {
            n->next = head;
            head->prev = n;
        }
        head = n;
    }

    void insertAtEnd(int d) {
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

    void insertAfter(int key, int d) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                Node* n = new Node(d);
                n->next = temp->next;
                if (temp->next) temp->next->prev = n;
                n->prev = temp;
                temp->next = n;
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found" << endl;
    }

    void insertBefore(int key, int d) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                Node* n = new Node(d);
                n->next = temp;
                n->prev = temp->prev;
                if (temp->prev) temp->prev->next = n;
                else head = n;
                temp->prev = n;
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found" << endl;
    }

    void deleteNode(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                if (temp->prev) temp->prev->next = temp->next;
                else head = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                temp->next = NULL;
                temp->prev = NULL;
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found" << endl;
    }

    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Found " << key << " at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found" << endl;
    }

    void print() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    CircularList cll;
    DoublyList dll;
    int choice, ch, data, key;
    while (true) {
        cout << "\n1. Circular Linked List\n2. Doubly Linked List\n3. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            while (true) {
                cout << "\n--- Circular Linked List ---\n1. Insert at Beginning\n2. Insert at End\n3. Insert After\n4. Delete Node\n5. Search\n6. Display\n7. Back\nEnter choice: ";
                cin >> ch;
                if (ch == 1) { cout << "Enter data: "; cin >> data; cll.insertAtBeginning(data); }
                else if (ch == 2) { cout << "Enter data: "; cin >> data; cll.insertAtEnd(data); }
                else if (ch == 3) { cout << "Enter key: "; cin >> key; cout << "Enter data: "; cin >> data; cll.insertAfter(key, data); }
                else if (ch == 4) { cout << "Enter data to delete: "; cin >> key; cll.deleteNode(key); }
                else if (ch == 5) { cout << "Enter data to search: "; cin >> key; cll.search(key); }
                else if (ch == 6) cll.print();
                else if (ch == 7) break;
                else cout << "Invalid choice" << endl;
            }
        } else if (choice == 2) {
            while (true) {
                cout << "\n--- Doubly Linked List ---\n1. Insert at Beginning\n2. Insert at End\n3. Insert After\n4. Insert Before\n5. Delete Node\n6. Search\n7. Display\n8. Back\nEnter choice: ";
                cin >> ch;
                if (ch == 1) { cout << "Enter data: "; cin >> data; dll.insertAtBeginning(data); }
                else if (ch == 2) { cout << "Enter data: "; cin >> data; dll.insertAtEnd(data); }
                else if (ch == 3) { cout << "Enter key: "; cin >> key; cout << "Enter data: "; cin >> data; dll.insertAfter(key, data); }
                else if (ch == 4) { cout << "Enter key: "; cin >> key; cout << "Enter data: "; cin >> data; dll.insertBefore(key, data); }
                else if (ch == 5) { cout << "Enter data to delete: "; cin >> key; dll.deleteNode(key); }
                else if (ch == 6) { cout << "Enter data to search: "; cin >> key; dll.search(key); }
                else if (ch == 7) dll.print();
                else if (ch == 8) break;
                else cout << "Invalid choice" << endl;
            }
        } else if (choice == 3) break;
        else cout << "Invalid choice" << endl;
    }
    return 0;
}
