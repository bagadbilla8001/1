#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

void reverseFileContents(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    stack<char> charStack;

    // Check if input file opened successfully
    if (!inFile) {
        cerr << "Error: Could not open the input file.\n";
        return;
    }

    // Read characters from the input file into the stack
    char ch;
    while (inFile.get(ch)) {
        charStack.push(ch);
    }
    inFile.close();

    // Write characters from the stack to the output file
    while (!charStack.empty()) {
        outFile.put(charStack.top());
        charStack.pop();
    }
    outFile.close();

    cout << "Reversed contents have been saved to: " << outputFile << "\n";
}

int main() {
    string inputFile, outputFile;

    cout << "Enter the name of the input file: ";
    cin >> inputFile;

    cout << "Enter the name of the output file: ";
    cin >> outputFile;

    reverseFileContents(inputFile, outputFile);

    return 0;
}