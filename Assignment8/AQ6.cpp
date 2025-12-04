#include <iostream>
using namespace std;

int heap[100];
int size = 0;

void insert(int value) {
    size++;
    heap[size] = value;
    int i = size;

    while (i > 1 && heap[i/2] < heap[i]) {
        swap(heap[i], heap[i/2]);
        i = i / 2;
    }
    cout << value << " inserted\n";
}

int getMax() {
    if (size == 0) return -1;
    return heap[1];
}

void deleteMax() {
    if (size == 0) {
        cout << "Priority Queue is empty\n";
        return;
    }
    cout << "Deleted max: " << heap[1] << endl;

    heap[1] = heap[size];
    size--;

    int i = 1;
    while (true) {
        int left = 2*i, right = 2*i + 1, largest = i;

        if (left <= size && heap[left] > heap[largest]) largest = left;
        if (right <= size && heap[right] > heap[largest]) largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            i = largest;
        } else break;
    }
}

void display() {
    cout << "Priority Queue: ";
    for (int i = 1; i <= size; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n1. Insert\n2. Get Max\n3. Delete Max\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert(value);
                break;
            case 2:
                cout << "Maximum: " << getMax() << endl;
                break;
            case 3:
                deleteMax();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}