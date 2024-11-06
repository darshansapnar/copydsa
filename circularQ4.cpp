#include <iostream>
using namespace std;

// Node structure for a Circular Queue
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize node with data
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Circular Queue class
class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor to initialize an empty queue
    CircularQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to insert an element into the queue (Enqueue)
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
            newNode->next = front;  // Circular link
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;  // Maintain the circular link
        }
        cout << "Enqueued: " << value << endl;
    }

    // Function to remove an element from the queue (Dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        int value = front->data;
        if (front == rear) {  // Only one element in the queue
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;  // Maintain the circular link
            delete temp;
        }
        cout << "Dequeued: " << value << endl;
    }

    // Function to display the queue elements from front to rear (Forward Display)
    void displayForward() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue (Forward): ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }

    // Function to display the queue elements from rear to front (Reverse Display)
    void displayReverse() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue (Reverse): ";
        // To display in reverse, we need to reach the last node and print in reverse order.
        // We will need to traverse back from the rear, but since it's a singly linked list,
        // we will need to simulate a reverse traversal using a recursive approach.

        reverseDisplay(temp);
        cout << endl;
    }

    // Helper function for reverse display (recursive)
    void reverseDisplay(Node* node) {
        if (node == rear) {
            cout << node->data << " ";
            return;
        }
        reverseDisplay(node->next);
        cout << node->data << " ";
    }
};

int main() {
    // Create a CircularQueue object with no user input
    CircularQueue queue;

    // Enqueue some elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    // Display the queue (Forward)
    queue.displayForward();

    // Display the queue (Reverse)
    queue.displayReverse();

    // Dequeue some elements
    queue.dequeue();
    queue.dequeue();

    // Display the queue after dequeue operations
    queue.displayForward();
    queue.displayReverse();

    // Enqueue more elements
    queue.enqueue(50);
    queue.enqueue(60);

    // Final Display (Forward)
    queue.displayForward();

    // Final Display (Reverse)
    queue.displayReverse();

    return 0;
}
