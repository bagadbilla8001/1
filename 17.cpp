#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <cmath>
using namespace std;

// Function to determine precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to convert infix to postfix
string infixToPostfix(const string& infix) {
    stack<char> st;
    string postfix;

    for (char ch : infix) {
        // If operand, add it to the postfix expression
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If '(', push it onto the stack
        else if (ch == '(') {
            st.push(ch);
        }
        // If ')', pop and output from the stack until '(' is encountered
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Remove '(' from the stack
        }
        // If operator, pop operators of higher or equal precedence and then push
        else if (isOperator(ch)) {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop all remaining operators from the stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> st;

    for (char ch : postfix) {
        // If operand, push onto the stack
        if (isdigit(ch)) {
            st.push(ch - '0'); // Convert char to integer
        }
        // If operator, pop two operands, perform the operation, and push the result
        else if (isOperator(ch)) {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch (ch) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }

    return st.top();
}

int main() {
    string infix, postfix;
    cout << "Enter a valid infix expression: ";
    cin >> infix;

    postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}