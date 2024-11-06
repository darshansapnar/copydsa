#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int val;
    Node* next;
    Node* prev;

    // Constructor to initialize node with a value
    Node(int data) {
        val = data;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    // Constructor initializes head and tail to null
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Display the list from start to end
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Insert a new node at the beginning
    void insertAtBeginning(int val) {
        Node* new_node = new Node(val);
        if (head == nullptr) {  // If list is empty
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    // Insert a new node at the end
    void insertAtEnd(int val) {
        Node* new_node = new Node(val);
        if (tail == nullptr) {  // If list is empty
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    // Insert at a specific position
    void insertAtPosition(int val, int pos) {
        if (pos <= 1) {
            insertAtBeginning(val);
            return;
        }
        Node* new_node = new Node(val);
        Node* temp = head;
        int count = 1;
        
        while (temp != nullptr && count < pos - 1) {
            temp = temp->next;
            count++;
        }
        
       if (temp == nullptr || temp->next == nullptr) {
            insertAtEnd(val);
            return;
        }

        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        temp->next->prev = new_node;
        return;

    // Delete node from the beginning
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else { // If the list becomes empty
            tail = nullptr;
        }
        delete temp;
    }

    // Delete node from the end
    void deleteAtEnd() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else { // If the list becomes empty
            head = nullptr;
        }
        delete temp;
    }

    // Delete node at a specific position
    void deleteAtPosition(int pos) {
        if (pos <= 1) {
            deleteAtBeginning();
            return;
        }
        Node* temp = head;
        int count = 1;
        
        while (temp != nullptr && count < pos) {
            temp = temp->next;
            count++;
        }
        
        if (temp == nullptr) {
            cout << "Position out of bounds." << endl;
            return;
        }
        
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        } else { // Deleting the last node
            tail = temp->prev;
        }
        
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        
        delete temp;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, value, position;

    while (true) {
        cout << "\nDoubly Linked List Operations:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                dll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                dll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value and position to insert: ";
                cin >> value >> position;
                dll.insertAtPosition(value, position);
                break;
            case 4:
                dll.deleteAtBeginning();
                break;
            case 5:
                dll.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                dll.deleteAtPosition(position);
                break;
            case 7:
                cout << "List: ";
                dll.display();
                break;
            case 8:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
