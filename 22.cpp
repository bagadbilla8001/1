#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;
    int front;
    int rear;
    int size;

public:
    Deque(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~Deque() {
        delete[] arr;
    }

    // Check if the deque is full
    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear + 1 == front);
    }

    // Check if the deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Add an element at the front
    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the front.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        arr[front] = value;
    }

    // Add an element at the rear
    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the rear.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
    }

    // Delete an element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the front.\n";
            return;
        }
        cout << "Deleted element from front: " << arr[front] << "\n";
        if (front == rear) { // Only one element was present
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    // Delete an element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the rear.\n";
            return;
        }
        cout << "Deleted element from rear: " << arr[rear] << "\n";
        if (front == rear) { // Only one element was present
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
    }

    // Display the deque elements
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << "\n";
    }
};

int main() {
    int n;
    cout << "Enter the size of the deque: ";
    cin >> n;
    Deque dq(n);

    int choice, value;
    do {
        cout << "\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                dq.insertFront(value);
                break;

            case 2:
                cout << "Enter value to insert at rear: ";
                cin >> value;
                dq.insertRear(value);
                break;

            case 3:
                dq.deleteFront();
                break;

            case 4:
                dq.deleteRear();
                break;

            case 5:
                dq.display();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}