#include <iostream>
#define MAX 100 // Maximum size of the queue
using namespace std;

class Queue {
private:
    int arr[MAX]; // Array to store queue elements
    int front;    // Front index
    int rear;     // Rear index
    int size;     // Current size of the queue

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    // Add an element to the queue
    void enqueue(int value) {
        if (size == MAX) {
            cout << "Queue is full. Cannot add more jobs." << endl;
            return;
        }
        rear = (rear + 1) % MAX; // Circular increment
        arr[rear] = value;
        size++;
        cout << "Job " << value << " added to the queue." << endl;
    }

    // Remove an element from the queue
    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty. No jobs to process." << endl;
            return;
        }
        cout << "Processing job " << arr[front] << "..." << endl;
        front = (front + 1) % MAX; // Circular increment
        size--;
    }

    // Display the elements in the queue
    void display() {
        if (size == 0) {
            cout << "The queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % MAX;
            cout << arr[index] << " ";
        }
        cout << endl;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    Queue jobQueue;
    int choice, value;

    while (true) {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Add job to the queue" << endl;
        cout << "2. Process a job (Remove from queue)" << endl;
        cout << "3. Display all jobs in the queue" << endl;
        cout << "4. Check if the queue is empty" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job ID to add: ";
                cin >> value;
                jobQueue.enqueue(value);
                break;

            case 2:
                jobQueue.dequeue();
                break;

            case 3:
                jobQueue.display();
                break;

            case 4:
                if (jobQueue.isEmpty()) {
                    cout << "The queue is empty." << endl;
                } else {
                    cout << "The queue is not empty." << endl;
                }
                break;

            case 5:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
