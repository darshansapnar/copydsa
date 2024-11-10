#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class CircularQueue {
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = rear = nullptr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue operation to add an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front; // Circular linking
            front->prev = rear;
        } else {
            rear->next = newNode;    // Link the current rear to the new node
            newNode->prev = rear;    // Link the new node's previous to current rear
            rear = newNode;          // Update rear to new node
            rear->next = front;      // Circular link
            front->prev = rear;      // Update front's previous to the new rear
        }
    }

    // Dequeue operation to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        if (front == rear) { // Only one element in the queue
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;    // Move front to the next element
            front->prev = rear;     // Maintain circular link
            rear->next = front;
            delete temp;
        }
    }

    // Display the queue in forward direction
    void displayForward() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
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

    // Display the queue in reverse direction
    void displayReverse() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = rear;
        cout << "Queue (Reverse): ";
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != rear);
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    // Enqueue operations
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    // Display final state of the queue
    q.displayForward();          // Expected: 1 2 3 4
    q.displayReverse();          // Expected: 4 3 2 1

    // Perform dequeue and enqueue operations
    q.dequeue();
    q.enqueue(5);

    // Display final state of the queue after updates
    q.displayForward();          // Expected: 2 3 4 5
    q.displayReverse();          // Expected: 5 4 3 2

    return 0;
}
