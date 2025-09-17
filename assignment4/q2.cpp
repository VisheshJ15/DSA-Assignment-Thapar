#include <iostream>
using namespace std;

const int MAX = 5;

bool isFull(int front, int rear) {
    return ((rear + 1) % MAX == front);
}

bool isEmpty(int front) {
    return (front == -1);
}

void addElement(int cq[], int &front, int &rear) {
    if (isFull(front, rear)) {
        cout << "Queue overflow!" << endl;
        return;
    }
    int item;
    cout << "Enter number to enqueue: ";
    cin >> item;

    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    cq[rear] = item;
    cout << item << " added." << endl;
}

void removeElement(int cq[], int &front, int &rear) {
    if (isEmpty(front)) {
        cout << "Queue underflow!" << endl;
        return;
    }
    cout << "Removed: " << cq[front] << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void peekElement(int cq[], int front, int rear) {
    if (isEmpty(front)) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Front element: " << cq[front] << endl;
}

void displayElements(int cq[], int front, int rear) {
    if (isEmpty(front)) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue: ";
    int i = front;
    while (true) {
        cout << cq[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    int cq[MAX];
    int front = -1, rear = -1;
    int choice;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue (Add)\n";
        cout << "2. Dequeue (Remove)\n";
        cout << "3. IsEmpty\n";
        cout << "4. IsFull\n";
        cout << "5. Peek\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addElement(cq, front, rear); break;
            case 2: removeElement(cq, front, rear); break;
            case 3: cout << (isEmpty(front) ? "Empty" : "Not empty") << endl; break;
            case 4: cout << (isFull(front, rear) ? "Full" : "Not full") << endl; break;
            case 5: peekElement(cq, front, rear); break;
            case 6: displayElements(cq, front, rear); break;
            case 7: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice" << endl;
        }
    } while (choice != 7);

    return 0;
}