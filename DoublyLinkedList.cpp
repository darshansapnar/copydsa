#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;

    Node(int data){
        val = data;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;

    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

void display(){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}    


void insertAtStart(int val){
    Node* new_node = new Node(val);
    if(head == NULL){
        head = new_node;
        tail = new_node;
    }else{
        new_node -> next = head;
        head -> prev = new_node;
        head = new_node;
    }
}

void insertAtEnd(int val){
    Node* new_node = new Node(val);
    if(tail == NULL){
        head = new_node;
        tail = new_node;
        return;
    }
    tail->next=new_node;
    new_node->prev=tail;
    tail = new_node;
}

    // Insert a new node at an arbitrary position
    void insertAtPosition(int val, int pos) {
        if (pos <= 1) {  // Insert at the start if pos is 1 or less
            insertAtStart(val);
            return;
        }

        Node* new_node = new Node(val);
        Node* temp = head;
        int count = 1;

        // Traverse to the node before the position
        while (temp != nullptr && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        // If we reach the end, insert at the end
        if (temp == nullptr || temp->next == nullptr) {
            insertAtEnd(val);
            return;
        }

        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        temp->next->prev = new_node;
        return;
}

// Function to delete the node at the start of the list
void deleteAtStart() {
    if (head == nullptr) {  // Check if the list is empty
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = head;  // Store the current head
    head = head->next;  // Move the head to the next node

    if (head != nullptr) {  // If the new head is not null
        head->prev = nullptr;  // Set the new head's prev to null
    } else {
        tail = nullptr;  // If the list is now empty, set tail to null
    }

    delete temp;  // Free the memory of the old head
}

// Function to delete the node at the end of the list
void deleteAtEnd() {
    if (tail == nullptr) {  // Check if the list is empty
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = tail;  // Store the current tail
    tail = tail->prev;  // Move the tail to the previous node

    if (tail != nullptr) {  // If the new tail is not null
        tail->next = nullptr;  // Set the new tail's next to null
    } else {
        head = nullptr;  // If the list is now empty, set head to null
    }

    delete temp;  // Free the memory of the old tail
}



};
  

int main(){
    DoublyLinkedList list;
    list.insertAtStart(1);
    list.display();
    list.insertAtStart(2);
    list.display();
    list.insertAtStart(3);
    list.display();

    list.insertAtEnd(4);
    list.display();
    list.insertAtEnd(5);
    list.display();
    list.insertAtEnd(7);
    list.display();

    list.insertAtPosition(6,3);
    list.display();

    cout<<"deletion at start: "<<endl;
    list.deleteAtStart();
    list.display();

    cout<<"deletion at end: "<<endl;
    list.deleteAtEnd();
    list.display();

    

    return 0;
}