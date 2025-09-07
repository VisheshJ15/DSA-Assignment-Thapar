#include <iostream>
#include <string>

using namespace std;

void push(int stack[], int &top, int item) {
    top++;
    stack[top] = item;
}

int pop(int stack[], int &top) {
    if (top > -1) {
        return stack[top--];
    }
    return -1;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isNumericDigit(char c) {
    return c >= '0' && c <= '9';
}

int performOperation(char operation, int operand1, int operand2) {
    if (operation == '+') return operand1 + operand2;
    if (operation == '-') return operand1 - operand2;
    if (operation == '*') return operand1 * operand2;
    if (operation == '/') return operand1 / operand2;
    return 0;
}

int evaluatePostfix(string expression) {
    int n = expression.length();
    int *stack = new int[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        char currentChar = expression[i];

        if (isNumericDigit(currentChar)) {
            push(stack, top, currentChar - '0');
        } else if (isOperator(currentChar)) {
            int operand2 = pop(stack, top);
            int operand1 = pop(stack, top);
            int result = performOperation(currentChar, operand1, operand2);
            push(stack, top, result);
        }
    }

    int finalResult = pop(stack, top);
    delete[] stack;
    return finalResult;
}

int main() {
    string postfix_expression;
    cout << "Enter a postfix expression to evaluate: ";
    getline(cin, postfix_expression);

    int result = evaluatePostfix(postfix_expression);

    cout << "Expression: " << postfix_expression << endl;
    cout << "Result: " << result << endl;

    return 0;
}