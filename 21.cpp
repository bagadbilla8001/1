#include <iostream>
using namespace std;

class PizzaParlor {
private:
    int* queue;
    int front, rear, size, capacity;

public:
    // Constructor to initialize the circular queue
    PizzaParlor(int maxOrders) {
        capacity = maxOrders;
        queue = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor to free allocated memory
    ~PizzaParlor() {
        delete[] queue;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Place an order in the queue
    void placeOrder(int orderNumber) {
        if (isFull()) {
            cout << "Pizza Parlor is at full capacity. Cannot place more orders.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        queue[rear] = orderNumber;
        size++;
        cout << "Order " << orderNumber << " placed successfully.\n";
    }

    // Serve the next order in the queue
    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
            return;
        }
        cout << "Order " << queue[front] << " is being served.\n";
        if (front == rear) { // Only one order left
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
    }

    // Display all pending orders
    void displayOrders() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }
        cout << "Pending orders: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << queue[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << "\n";
    }
};

int main() {
    int maxOrders;
    cout << "Enter the maximum number of orders the Pizza Parlor can accept: ";
    cin >> maxOrders;

    PizzaParlor parlor(maxOrders);

    int choice, orderNumber;

    do {
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the order number: ";
                cin >> orderNumber;
                parlor.placeOrder(orderNumber);
                break;

            case 2:
                parlor.serveOrder();
                break;

            case 3:
                parlor.displayOrders();
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