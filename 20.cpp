#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Patient structure to hold details
struct Patient {
    string name;
    string condition;
    int priority;

    // Overloading the < operator to make it a max-priority queue
    bool operator<(const Patient& other) const {
        return priority < other.priority;
    }
};

// Function to assign priority based on condition
int getPriority(string condition) {
    if (condition == "Critical") return 4;
    if (condition == "High") return 3;
    if (condition == "Medium") return 2;
    if (condition == "Low") return 1;
    return 0; // Invalid condition
}

int main() {
    priority_queue<Patient> pq;

    int choice;
    do {
        cout << "\n1. Add Patient\n2. Serve Patient\n3. Display All Patients\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, condition;
                cout << "Enter patient's name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter patient's condition (Critical, High, Medium, Low): ";
                getline(cin, condition);
                int priority = getPriority(condition);
                if (priority == 0) {
                    cout << "Invalid condition. Please enter a valid condition.\n";
                } else {
                    pq.push({name, condition, priority});
                    cout << "Patient added successfully.\n";
                }
                break;
            }

            case 2: {
                if (pq.empty()) {
                    cout << "No patients in the queue.\n";
                } else {
                    Patient p = pq.top();
                    pq.pop();
                    cout << "Serving patient: " << p.name << " (Condition: " << p.condition << ")\n";
                }
                break;
            }

            case 3: {
                if (pq.empty()) {
                    cout << "No patients in the queue.\n";
                } else {
                    priority_queue<Patient> temp = pq;
                    cout << "All patients in the queue:\n";
                    while (!temp.empty()) {
                        Patient p = temp.top();
                        temp.pop();
                        cout << p.name << " (Condition: " << p.condition << ")\n";
                    }
                }
                break;
            }

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}