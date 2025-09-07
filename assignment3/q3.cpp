#include <iostream>
#include <string>

using namespace std;

void push(char stack[], int &top, char item) {
    top++;
    stack[top] = item;
}

void pop(int &top) {
    if (top > -1) {
        top--;
    }
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

bool areParenthesesBalanced(string expr) {
    int n = expr.length();
    if (n == 0) {
        return true;
    }

    char *stack = new char[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        char currentChar = expr[i];

        if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
            push(stack, top, currentChar);
        } else if (currentChar == ')' || currentChar == '}' || currentChar == ']') {
            if (isEmpty(top)) {
                delete[] stack;
                return false;
            }
            
            char topChar = peek(stack, top);
            if ((currentChar == ')' && topChar == '(') ||
                (currentChar == '}' && topChar == '{') ||
                (currentChar == ']' && topChar == '[')) {
                pop(top);
            } else {
                delete[] stack;
                return false;
            }
        }
    }

    bool result = isEmpty(top);
    delete[] stack;
    return result;
}

int main() {
    string expression;
    cout << "Enter an expression to check: ";
    getline(cin, expression);

    if (areParenthesesBalanced(expression)) {
        cout << "The expression has balanced parentheses." << endl;
    } else {
        cout << "The expression does not have balanced parentheses." << endl;
    }

    return 0;
}