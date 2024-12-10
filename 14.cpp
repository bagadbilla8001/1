#include <iostream>
#include <list>
using namespace std;

// Templated class for priority queue items
template <typename T>
class PriorityQueueItem {
public:
    T data;
    int priority;

    // Constructor
    PriorityQueueItem(T d, int p) : data(d), priority(p) {}

    // Overload the <= operator for in-order insertion
    bool operator<=(const PriorityQueueItem& other) const {
        return this->priority >= other.priority; // Higher priority first
    }

    // Display the item
    void display() const {
        cout << "Data: " << data << ", Priority: " << priority << "\n";
    }
};

// Templated class for Priority Queue
template <typename T>
class PriorityQueue {
private:
    list<PriorityQueueItem<T>> queue;

public:
    // Add an item to the queue
    void enqueue(T data, int priority) {
        PriorityQueueItem<T> newItem(data, priority);
        auto it = queue.begin();
        // Find the correct position to maintain in-order
        while (it != queue.end() && *it <= newItem) {
            ++it;
        }
        queue.insert(it, newItem);
        cout << "Item added successfully.\n";
    }

    // Remove and return the highest-priority item
    void dequeue() {
        if (queue.empty()) {
            cout << "Queue is empty. Nothing to dequeue.\n";
            return;
        }
        PriorityQueueItem<T> highestPriorityItem = queue.front();
        queue.pop_front();
        cout << "Dequeued: ";
        highestPriorityItem.display();
    }

    // Display all items in the queue
    void display() const {
        if (queue.empty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Priority Queue:\n";
        for (const auto& item : queue) {
            item.display();
        }
    }
};

int main() {
    PriorityQueue<string> pq;

    int choice;
    string data;
    int priority;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin.ignore();
                getline(cin, data);
                cout << "Enter priority: ";
                cin >> priority;
                pq.enqueue(data, priority);
                break;

            case 2:
                pq.dequeue();
                break;

            case 3:
                pq.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}