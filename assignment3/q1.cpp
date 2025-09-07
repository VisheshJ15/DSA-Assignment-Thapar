#include <iostream>
using namespace std;

#define MAX 5

int stackArr[MAX];
int top = -1;

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == MAX - 1);
}

void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << value << endl;
    } else {
        top++;
        stackArr[top] = value;
        cout << value << " pushed into the stack." << endl;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Cannot pop." << endl;
    } else {
        cout << stackArr[top] << " popped from the stack." << endl;
        top--;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty, nothing to peek." << endl;
    } else {
        cout << "Top element is: " << stackArr[top] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;
    do {
        cout << "\n=== STACK MENU ===\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. isEmpty\n";
        cout << "5. isFull\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                if (isEmpty()) cout << "Yes, stack is empty." << endl;
                else cout << "No, stack is not empty." << endl;
                break;
            case 5:
                if (isFull()) cout << "Yes, stack is full." << endl;
                else cout << "No, stack is not full." << endl;
                break;
            case 6:
                display();
                break;
            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
