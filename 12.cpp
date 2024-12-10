#include <iostream>
#include <string>
using namespace std;

// Structure to represent a club member
struct Member {
    int prn; // PRN of the member
    string name; // Name of the member
    Member* next; // Pointer to the next member
};

// Pinnacle Club class
class PinnacleClub {
private:
    Member* head; // Pointer to the president (head of the list)
    Member* tail; // Pointer to the secretary (tail of the list)

public:
    PinnacleClub() : head(nullptr), tail(nullptr) {}

    // Add a new member
    void addMember(int prn, const string& name, bool isPresident = false, bool isSecretary = false) {
        Member* newMember = new Member{prn, name, nullptr};

        if (isPresident) {
            newMember->next = head;
            head = newMember;
            if (!tail) tail = head; // If the list was empty, tail also points to the new president
            cout << "President " << name << " added successfully.\n";
        } else if (isSecretary) {
            if (!head) {
                head = tail = newMember;
            } else {
                tail->next = newMember;
                tail = newMember;
            }
            cout << "Secretary " << name << " added successfully.\n";
        } else {
            if (!head) {
                cout << "First, add a president before adding other members.\n";
                delete newMember;
                return;
            }
            if (!tail) tail = head; // Ensure tail is set for an empty list
            tail->next = newMember;
            tail = newMember;
            cout << "Member " << name << " added successfully.\n";
        }
    }

    // Delete a member
    void deleteMember(int prn) {
        if (!head) {
            cout << "No members in the club.\n";
            return;
        }

        if (head->prn == prn) { // Deleting the president
            Member* temp = head;
            head = head->next;
            if (!head) tail = nullptr; // If the list is now empty
            cout << "President " << temp->name << " removed successfully.\n";
            delete temp;
            return;
        }

        Member* current = head;
        Member* previous = nullptr;

        while (current && current->prn != prn) {
            previous = current;
            current = current->next;
        }

        if (!current) {
            cout << "No member found with PRN " << prn << ".\n";
            return;
        }

        if (current == tail) { // Deleting the secretary
            tail = previous;
            tail->next = nullptr;
            cout << "Secretary " << current->name << " removed successfully.\n";
        } else { // Deleting a regular member
            previous->next = current->next;
            cout << "Member " << current->name << " removed successfully.\n";
        }

        delete current;
    }

    // Compute total number of members
    int countMembers() const {
        int count = 0;
        Member* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display all members
    void displayMembers() const {
        if (!head) {
            cout << "No members in the club.\n";
            return;
        }

        cout << "\nPinnacle Club Members:\n";
        cout << "Role\t\tPRN\tName\n";
        cout << "-----------------------------------\n";

        Member* temp = head;
        if (temp) {
            cout << "President\t" << temp->prn << "\t" << temp->name << "\n";
            temp = temp->next;
        }

        while (temp && temp != tail) {
            cout << "Member\t\t" << temp->prn << "\t" << temp->name << "\n";
            temp = temp->next;
        }

        if (tail) {
            cout << "Secretary\t" << tail->prn << "\t" << tail->name << "\n";
        }
    }

    // Concatenate two lists
    void concatenate(PinnacleClub& other) {
        if (!head) { // If the current list is empty
            head = other.head;
            tail = other.tail;
        } else if (other.head) { // If both lists are non-empty
            tail->next = other.head;
            tail = other.tail;
        }
        other.head = other.tail = nullptr; // Clear the other list
        cout << "Lists concatenated successfully.\n";
    }

    // Destructor to free memory
    ~PinnacleClub() {
        while (head) {
            Member* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PinnacleClub divA, divB;
    int choice, prn;
    string name;

    do {
        cout << "\n--- Pinnacle Club Menu ---\n";
        cout << "1. Add President\n";
        cout << "2. Add Secretary\n";
        cout << "3. Add Member\n";
        cout << "4. Delete Member\n";
        cout << "5. Display Members\n";
        cout << "6. Count Members\n";
        cout << "7. Concatenate Divisions\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter PRN: ";
            cin >> prn;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            divA.addMember(prn, name, true);
            break;

        case 2:
            cout << "Enter PRN: ";
            cin >> prn;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            divA.addMember(prn, name, false, true);
            break;

        case 3:
            cout << "Enter PRN: ";
            cin >> prn;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            divA.addMember(prn, name);
            break;

        case 4:
            cout << "Enter PRN to delete: ";
            cin >> prn;
            divA.deleteMember(prn);
            break;

        case 5:
            divA.displayMembers();
            break;

        case 6:
            cout << "Total members: " << divA.countMembers() << "\n";
            break;

        case 7:
            cout << "Concatenating Division B with Division A...\n";
            divA.concatenate(divB);
            break;

        case 8:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}