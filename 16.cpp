#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// Stack class template
template<typename T>
class Stack {
private:
    stack<T> st;

public:
    void push(T val) {
        st.push(val);
    }

    void pop() {
        if (!st.empty())
            st.pop();
    }

    T top() {
        if (!st.empty())
            return st.top();
        throw runtime_error("Stack is empty");
    }

    bool isEmpty() {
        return st.empty();
    }

    void clear() {
        while (!st.empty()) {
            st.pop();
        }
    }
};

// Function to reverse a string using stack
string reverseString(const string& str) {
    Stack<char> s;
    for (char ch : str) {
        s.push(ch);
    }
    string reversed;
    while (!s.isEmpty()) {
        reversed += s.top();
        s.pop();
    }
    return reversed;
}

// Function to check if a string is a palindrome
bool isPalindrome(const string& str) {
    string reversed = reverseString(str);
    return str == reversed;
}

// Function to check if an expression is well-parenthesized
bool isWellParenthesized(const string& expr) {
    Stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false;
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.isEmpty();
}

// Function to convert decimal to binary using stack
string decimalToBinary(int num) {
    Stack<int> s;
    while (num > 0) {
        s.push(num % 2);
        num /= 2;
    }
    string binary;
    while (!s.isEmpty()) {
        binary += to_string(s.top());
        s.pop();
    }
    return binary.empty() ? "0" : binary;
}

// Menu-driven program
int main() {
    int choice;
    string input;
    int number;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Print Original and Reversed String\n";
        cout << "2. Check if String is Palindrome\n";
        cout << "3. Check if Expression is Well-Parenthesized\n";
        cout << "4. Convert Decimal to Binary\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter a string: ";
            cin >> input;
            cout << "Original String: " << input << endl;
            cout << "Reversed String: " << reverseString(input) << endl;
            break;

        case 2:
            cout << "Enter a string: ";
            cin >> input;
            if (isPalindrome(input)) {
                cout << "The string is a palindrome.\n";
            } else {
                cout << "The string is not a palindrome.\n";
            }
            break;

        case 3:
            cout << "Enter an expression: ";
            cin >> input;
            if (isWellParenthesized(input)) {
                cout << "The expression is well-parenthesized.\n";
            } else {
                cout << "The expression is not well-parenthesized.\n";
            }
            break;

        case 4:
            cout << "Enter a decimal number: ";
            cin >> number;
            cout << "Binary Representation: " << decimalToBinary(number) << endl;
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}