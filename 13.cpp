#include <iostream>
#include <algorithm> // Include this for std::max
#include <string>

using namespace std;

class Election {
public:
    int electionid;
    string name;
    char partyAcronym;
    Election *next;

    // Constructor to initialize an election entry
    Election(int id, const char *n, char party) {
        electionid = id;
        name = n;
        partyAcronym = party;
        next = nullptr;
    }
};

class ElectionList {
private:
    Election *head;

public:
    // Constructor to initialize the list
    ElectionList() {
        head = nullptr;
    }

    // a. Vote First (Insert at the beginning)
    void voteFirst(int id, const char *name, char party) {
        Election *newVote = new Election(id, name, party);
        newVote->next = head;
        head = newVote;
    }

    // b. Delete voting entry from electionid
    void deleteVote(int electionid) {
        Election *temp = head;
        Election *prev = nullptr;

        // If the node to be deleted is the head node
        if (temp != nullptr && temp->electionid == electionid) {
            head = temp->next;
            delete temp;
            return;
        }

        // Search for the electionid to be deleted
        while (temp != nullptr && temp->electionid != electionid) {
            prev = temp;
            temp = temp->next;
        }

        // If the electionid was not found
        if (temp == nullptr) {
            cout << "Election ID not found!" << endl;
            return;
        }

        // Unlink the node from the list
        prev->next = temp->next;
        delete temp;
    }

    // c. Display all voted entries
    void displayVotes() {
        Election *temp = head;
        if (temp == nullptr) {
            cout << "No votes recorded!" << endl;
            return;
        }

        while (temp != nullptr) {
            cout << "Election ID: " << temp->electionid
                 << ", Name: " << temp->name
                 << ", Party: " << temp->partyAcronym << endl;
            temp = temp->next;
        }
    }

    // d. Search Voting Information from electionid
    void searchVote(int electionid) {
        Election *temp = head;
        while (temp != nullptr) {
            if (temp->electionid == electionid) {
                cout << "Election ID: " << temp->electionid
                     << ", Name: " << temp->name
                     << ", Party: " << temp->partyAcronym << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Election ID not found!" << endl;
    }

    // e. Show Winner Party Name with total count of winner
    void showWinner() {
        if (head == nullptr) {
            cout << "No votes recorded!" << endl;
            return;
        }

        int bjpCount = 0, congressCount = 0, aamAadmiCount = 0, shivSenaCount = 0, rashtrawadiCount = 0;
        Election *temp = head;

        while (temp != nullptr) {
            switch (temp->partyAcronym) {
                case 'B':
                    bjpCount++;
                    break;
                case 'C':
                    congressCount++;
                    break;
                case 'A':
                    aamAadmiCount++;
                    break;
                case 'S':
                    shivSenaCount++;
                    break;
                case 'R':
                    rashtrawadiCount++;
                    break;
            }
            temp = temp->next;
        }

        // Finding the maximum vote count among the parties
        int maxCount = max({bjpCount, congressCount, aamAadmiCount, shivSenaCount, rashtrawadiCount});

        // Determine which party got the most votes
        if (maxCount == bjpCount)
            cout << "Winner Party: BJP with " << bjpCount << " votes" << endl;
        else if (maxCount == congressCount)
            cout << "Winner Party: Congress with " << congressCount << " votes" << endl;
        else if (maxCount == aamAadmiCount)
            cout << "Winner Party: Aam Aadmi with " << aamAadmiCount << " votes" << endl;
        else if (maxCount == shivSenaCount)
            cout << "Winner Party: Shiv Sena with " << shivSenaCount << " votes" << endl;
        else
            cout << "Winner Party: Rashtrawadi with " << rashtrawadiCount << " votes" << endl;
    }

    // f. Exit (Cleanup the list)
    void exit() {
        Election *temp = head;
        while (temp != nullptr) {
            Election *next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }
};

// Main Function
int main() {
    ElectionList electionList;
    int choice, electionid;
    char name[20], party;

    while (true) {
        cout << "\nElection Voting System\n";
        cout << "1. Vote First\n";
        cout << "2. Delete Vote by Election ID\n";
        cout << "3. Display All Voted Entries\n";
        cout << "4. Search Voting Information by Election ID\n";
        cout << "5. Show Winner Party with Total Count\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Election ID: ";
                cin >> electionid;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Party Acronym (B for BJP, C for Congress, A for Aam Aadmi, S for Shiv Sena, R for Rashtrawadi): ";
                cin >> party;
                electionList.voteFirst(electionid, name, party);
                break;
            case 2:
                cout << "Enter Election ID to delete: ";
                cin >> electionid;
                electionList.deleteVote(electionid);
                break;
            case 3:
                electionList.displayVotes();
                break;
            case 4:
                cout << "Enter Election ID to search: ";
                cin >> electionid;
                electionList.searchVote(electionid);
                break;
            case 5:
                electionList.showWinner();
                break;
            case 6:
                electionList.exit();
                cout << "Exiting the system..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}