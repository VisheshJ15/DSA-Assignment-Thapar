#include <iostream>
using namespace std;

bool isFull(int rear, int maxSize) {
    return (rear == maxSize - 1);
}

bool isEmpty(int front, int rear) {
    return (front == -1 || front > rear);
}

void addElement(int queue[], int &front, int &rear, int maxSize) {
    if (isFull(rear, maxSize)) {
        cout << "Queue overflow!" << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    int item;
    cout << "Enter the number to enqueue: ";
    cin >> item;
    rear++;
    queue[rear] = item;
    cout << item << " added." << endl;
}

void removeElement(int queue[], int &front, int &rear) {
    if (isEmpty(front, rear)) {
        cout << "Queue underflow!" << endl;
        return;
    }
    cout << "Removed: " << queue[front] << endl;
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

void peek(int queue[], int front, int rear) {
    if (isEmpty(front, rear)) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Front element: " << queue[front] << endl;
}

void display(int queue[], int front, int rear) {
    if (isEmpty(front, rear)) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int maxSize;
    cout << "Enter maximum queue size: ";
    cin >> maxSize;

    int *queue = new int[maxSize];
    int front = -1, rear = -1;
    int choice;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. IsEmpty\n";
        cout << "4. IsFull\n";
        cout << "5. Peek\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addElement(queue, front, rear, maxSize); break;
            case 2: removeElement(queue, front, rear); break;
            case 3: cout << (isEmpty(front, rear) ? "Empty" : "Not empty") << endl; break;
            case 4: cout << (isFull(rear, maxSize) ? "Full" : "Not full") << endl; break;
            case 5: peek(queue, front, rear); break;
            case 6: display(queue, front, rear); break;
            case 7: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice" << endl;
        }
    } while (choice != 7);

    delete[] queue;
    return 0;
}