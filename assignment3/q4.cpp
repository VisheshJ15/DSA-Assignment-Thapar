#include <iostream>
#include <string>

using namespace std;

void push(char stack[], int &top, char item) {
    top++;
    stack[top] = item;
}

char pop(char stack[], int &top) {
    if (top > -1) {
        return stack[top--];
    }
    return '\0';
}

char peek(char stack[], int top) {
    if (top > -1) {
        return stack[top];
    }
    return '\0';
}

bool isEmpty(int top) {
    return top == -1;
}

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

string infixToPostfix(string infix) {
    string postfix = "";
    int n = infix.length();
    char *stack = new char[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        char currentChar = infix[i];

        if (isOperand(currentChar)) {
            postfix += currentChar;
        } else if (currentChar == '(') {
            push(stack, top, currentChar);
        } else if (currentChar == ')') {
            while (!isEmpty(top) && peek(stack, top) != '(') {
                postfix += pop(stack, top);
            }
            if (!isEmpty(top)) {
                pop(stack, top);
            }
        } else {
            while (!isEmpty(top) && peek(stack, top) != '(' && getPrecedence(currentChar) <= getPrecedence(peek(stack, top))) {
                postfix += pop(stack, top);
            }
            push(stack, top, currentChar);
        }
    }

    while (!isEmpty(top)) {
        postfix += pop(stack, top);
    }

    delete[] stack;
    return postfix;
}

int main() {
    string infix_expression;
    cout << "Enter an infix expression: ";
    getline(cin, infix_expression);

    string postfix_expression = infixToPostfix(infix_expression);

    cout << "Infix:   " << infix_expression << endl;
    cout << "Postfix: " << postfix_expression << endl;

    return 0;
}