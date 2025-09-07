#include <iostream>
#include <string>

using namespace std;

// Helper function to push a character onto the stack
void push(char stack[], int &top, char item) {
    top = top + 1;
    stack[top] = item;
}

// Helper function to pop a character from the stack
char pop(char stack[], int &top) {
    char item = stack[top];
    top = top - 1;
    return item;
}

// Function to reverse a string using a stack
void reverseString(string &s) {
    int n = s.length();
    if (n == 0) {
        return; // Nothing to reverse
    }

    // Create a character stack using a dynamic array
    char *stack = new char[n];
    int top = -1;

    // 1. Push all characters of the string onto the stack
    for (int i = 0; i < n; i++) {
        push(stack, top, s[i]);
    }

    // 2. Pop all characters from the stack back into the string
    for (int i = 0; i < n; i++) {
        s[i] = pop(stack, top);
    }

    // Free the allocated memory for the stack
    delete[] stack;
}

int main() {
    string input_str;
    cout << "Enter the string to reverse: ";
    // Use getline to correctly read strings with spaces
    getline(cin, input_str);

    cout << "Original string: " << input_str << endl;

    reverseString(input_str);

    cout << "Reversed string: " << input_str << endl;

    return 0;
}