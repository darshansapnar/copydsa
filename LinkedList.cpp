#include<iostream>
using namespace std;
 
 class node{              //creaion of single node
    public:
    int val;
    node* next;

     node (int data){
        val = data;
        next = nullptr;
     }
 };

//INSERTION AT BEGINNING
void insertAtBeginning(node* &head ,int val){
    node* new_node = new node(val);   //creation of new node
    new_node->next = head;            //set new node's next to head
    head = new_node;                  //head eaqual to new node
}

void insertAtEnd(node* &head, int val) {
    node* new_node = new node(val);  // Create a new node with the given value
    // If the list is empty, new node becomes the head
    if (head == nullptr) {
        head = new_node;
        return;
    }
    // Otherwise, traverse to the end of the list
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    // Insert the new node at the end
    temp->next = new_node;
}

void insertAtPosition(node* &head, int val, int pos) {
    // If inserting at the beginning
    if (pos == 0) {
        insertAtBeginning(head, val);
        return;
    }
    node* new_node = new node(val);
    node* temp = head;
    int current_pos = 0;

    // Traverse the list until just before the desired position or until temp becomes nullptr
    while (temp != nullptr && current_pos != pos - 1) {
        temp = temp->next;
        current_pos++;
    }

    // Check if temp is valid (i.e., the position is within bounds)
    if (temp != nullptr) {
        new_node->next = temp->next;
        temp->next = new_node;
    } else { 
        // Position is out of bounds
        cout << "Position out of bounds." << endl;
        delete new_node; // Prevent memory leak
    }
}

void deleteAtHead(node* &head){
    if(head==NULL){
        cout<<"list is empty"<<endl;
        return;
    }

    node* temp = head;
    head = head -> next;
    delete(temp);
}

void deleteLastNode(node* &head) {
    // If the list is empty
    if (head == nullptr) {
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    // If there's only one node in the list
    if (head->next == nullptr) {
        delete head;  // Delete the only node
        head = nullptr;  // Set head to nullptr as the list is now empty
        return;
    }

    // Traverse to the second-to-last node
    node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    // Delete the last node and update the second-to-last node's next to nullptr
    delete temp->next;
    temp->next = nullptr;
}

void deleteAtPosition(node* &head, int pos) {
    // If the list is empty
    if (head == nullptr) {
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    // If deleting the head node (position 0)
    if (pos == 0) {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Traverse the list to find the node just before the one to delete
    node* temp = head;
    int current_pos = 0;

    while (temp != nullptr && current_pos != pos - 1) {
        temp = temp->next;
        current_pos++;
    }

    // Check if we are at a valid position (temp should not be nullptr and temp->next should exist)
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position out of bounds." << endl;
        return;
    }

    // Store the node to be deleted
    node* node_to_delete = temp->next;

    // Update the next pointer to skip the node
    temp->next = temp->next->next;

    // Delete the node
    delete node_to_delete;
}

void display(node* head){
    node* temp = head;
    while(temp!=nullptr){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = nullptr;

    insertAtBeginning(head,2);
    insertAtBeginning(head,3);
    insertAtEnd(head,4);
    insertAtPosition(head,5,2);
    deleteAtPosition(head, 2);

    // Display the updated list
    cout << "After deleting node at position 2: ";
    display(head);
    
    deleteLastNode(head);
    deleteAtHead(head);
    
    display(head);

    

    return 0;
}