#include <iostream>
#include <cstring>
using namespace std;

struct BusReservation {
    char pname[25];  // Passenger name
    int seatno;      // Seat number
    int distance;    // Distance traveled
    int bill;        // Total bill
    BusReservation* next; // Pointer to next node
    BusReservation* prev; // Pointer to previous node
};

class BusReservationSystem {
private:
    BusReservation* head;
    const int totalSeats = 10;  // Maximum seats available

public:
    BusReservationSystem() : head(nullptr) {}

    // Function to calculate the bill based on distance
    int calculateBill(int distance) {
        if (distance <= 100) return distance * 2;
        if (distance <= 200) return distance * 3;
        if (distance <= 300) return distance * 4;
        return distance * 5;
    }

    // Display available seats
    void displayAvailableSeats() {
        cout << "\nAvailable seats: ";
        for (int i = 1; i <= totalSeats; i++) {
            if (!isSeatReserved(i)) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    // Book a ticket
    void bookTicket() {
        char name[25];
        int seatno, distance;

        cout << "\nEnter passenger name: ";
        cin >> name;
        cout << "Enter seat number (1-" << totalSeats << "): ";
        cin >> seatno;

        if (seatno < 1 || seatno > totalSeats || isSeatReserved(seatno)) {
            cout << "Invalid or already reserved seat number!\n";
            return;
        }

        cout << "Enter distance to travel: ";
        cin >> distance;

        BusReservation* newPassenger = new BusReservation();
        strcpy(newPassenger->pname, name);
        newPassenger->seatno = seatno;
        newPassenger->distance = distance;
        newPassenger->bill = calculateBill(distance);

        if (!head) {  // First reservation
            head = newPassenger;
            head->next = head;
            head->prev = head;
        } else {  // Insert into circular linked list
            BusReservation* tail = head->prev;
            tail->next = newPassenger;
            newPassenger->prev = tail;
            newPassenger->next = head;
            head->prev = newPassenger;
        }

        cout << "Ticket booked successfully for " << name << " (Seat No: " << seatno << ").\n";
    }

    // Cancel a booking
    void cancelBooking() {
        int seatno;
        cout << "\nEnter seat number to cancel: ";
        cin >> seatno;

        if (!head) {
            cout << "No reservations found.\n";
            return;
        }

        BusReservation* temp = head;
        bool found = false;

        do {
            if (temp->seatno == seatno) {
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != head);

        if (!found) {
            cout << "Seat number not found in reservations.\n";
            return;
        }

        if (temp->next == temp) {  // Single reservation
            head = nullptr;
        } else {  // Multiple reservations
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (temp == head) {
                head = temp->next;
            }
        }

        delete temp;
        cout << "Reservation cancelled successfully.\n";
    }

    // Display all reserved passengers
    void displayAllPassengers() {
        if (!head) {
            cout << "No reservations found.\n";
            return;
        }

        cout << "\nReserved Passengers Details:\n";
        BusReservation* temp = head;

        do {
            cout << "Name: " << temp->pname
                 << ", Seat No: " << temp->seatno
                 << ", Distance: " << temp->distance
                 << ", Bill: " << temp->bill << endl;
            temp = temp->next;
        } while (temp != head);
    }

    // Search for passenger information
    void searchPassenger() {
        char name[25];
        cout << "\nEnter passenger name to search: ";
        cin >> name;

        if (!head) {
            cout << "No reservations found.\n";
            return;
        }

        BusReservation* temp = head;
        bool found = false;

        do {
            if (strcmp(temp->pname, name) == 0) {
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != head);

        if (found) {
            cout << "Passenger found:\n";
            cout << "Name: " << temp->pname
                 << ", Seat No: " << temp->seatno
                 << ", Distance: " << temp->distance
                 << ", Bill: " << temp->bill << endl;
        } else {
            cout << "Passenger not found.\n";
        }
    }

    // Check if a seat is already reserved
    bool isSeatReserved(int seatno) {
        if (!head) return false;

        BusReservation* temp = head;
        do {
            if (temp->seatno == seatno) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);

        return false;
    }

    // Exit
    void exitSystem() {
        cout << "Exiting system. Thank you!\n";
    }
};

int main() {
    BusReservationSystem system;
    int choice;

    do {
        cout << "\n--- Bus Reservation System ---";
        cout << "\n1. Display Available Seats";
        cout << "\n2. Book Ticket";
        cout << "\n3. Cancel Booking";
        cout << "\n4. Display All Reserved Passengers";
        cout << "\n5. Search Passenger Information";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.displayAvailableSeats();
            break;
        case 2:
            system.bookTicket();
            break;
        case 3:
            system.cancelBooking();
            break;
        case 4:
            system.displayAllPassengers();
            break;
        case 5:
            system.searchPassenger();
            break;
        case 6:
            system.exitSystem();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}