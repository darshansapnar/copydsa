#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Find the node with the minimum value (used for deletion)
Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// Insert or Create a new node
Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

// Delete a node
Node* deleteNode(Node* root, int value) {
    if (!root) return root;

    if (value < root->data) root->left = deleteNode(root->left, value);
    else if (value > root->data) root->right = deleteNode(root->right, value);
    else {
        // Node with only one child or no child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children
        Node* temp = findMin(root->right); // Use findMin here
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Search for a value in the tree
bool search(Node* root, int value) {
    if (!root) return false;
    if (root->data == value) return true;
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}

// Inorder Traversal (Display)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Insert nodes into the BST
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    // Display tree using Inorder Traversal
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Search for a value
    cout << "Searching for 11: " << (search(root, 11) ? "Found" : "Not Found") << endl;

    // Delete a node
    cout << "Deleting node 11..." << endl;
    root = deleteNode(root, 11);

    // Display tree after deletion
    cout << "Inorder Traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
