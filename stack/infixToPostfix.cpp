#include <iostream>
#include <string>



class CustomStack {
private:
    char* stack;
    int top;
    int capacity;

public:
    CustomStack(int size) {
        capacity = size;
        stack = new char[capacity];
        top = -1;
    }

    ~CustomStack() {
        delete[] stack;
    }

    void push(char ch) {
        if (isFull()) {
            std::cerr << "Stack overflow" << std::endl;
            return;
        }
        stack[++top] = ch;
    }

    char pop() {
        if (isEmpty()) {
            std::cerr << "Stack underflow" << std::endl;
            return '\0';
        }
        return stack[top--];
    }

    char peek() {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            return '\0';
        }
        return stack[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }
};

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // For other characters or invalid operators
}

std::string infixToPostfix(const std::string& infix) {
    CustomStack operatorStack(infix.length());
    std::string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            operatorStack.push(ch);
        }
        else if (ch == ')') {
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {
                postfix += operatorStack.pop();
            }
            if (!operatorStack.isEmpty() && operatorStack.peek() == '(') {
                operatorStack.pop();
            }
        }
        else {
            while (!operatorStack.isEmpty() && getPrecedence(ch) <= getPrecedence(operatorStack.peek())) {
                postfix += operatorStack.pop();
            }
            operatorStack.push(ch);
        }
    }

    while (!operatorStack.isEmpty()) {
        postfix += operatorStack.pop();
    }

    return postfix;
}

int main() {
    std::string infixExpression = "a+b*(c-d/e)";
    std::string postfixExpression = infixToPostfix(infixExpression);
    std::cout << "Infix Expression: " << infixExpression << std::endl;
    std::cout << "Postfix Expression: " << postfixExpression << std::endl;

    return 0;
}
