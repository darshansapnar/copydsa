

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool leftThread, rightThread;

    Node(int value) {
        data = value;
        left = right = nullptr;
        leftThread = rightThread = true;
    }
};

class ThreadedBinaryTree {
private:
    Node* root;

    Node* inOrderSuccessor(Node* node) {
        if (node->rightThread) return node->right;
        node = node->right;
        while (!node->leftThread) node = node->left;
        return node;
    }

public:
    ThreadedBinaryTree() : root(nullptr) {}

    // Insert a new value into the threaded binary tree
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!root) {
            root = newNode;
            return;
        }

        Node* curr = root;
        Node* parent = nullptr;

        // Find the parent node for the new value
        while (curr) {
            parent = curr;
            if (value < curr->data) {
                if (!curr->leftThread) curr = curr->left;
                else break;
            } else {
                if (!curr->rightThread) curr = curr->right;
                else break;
            }
        }

        // Insert the new node as a threaded child
        if (value < parent->data) {
            newNode->right = parent;
            newNode->left = parent->left;
            parent->leftThread = false;
            parent->left = newNode;
        } else {
            newNode->left = parent;
            newNode->right = parent->right;
            parent->rightThread = false;
            parent->right = newNode;
        }
    }

    // In-order traversal of the threaded binary tree
    void inorderTraversal() {
        if (!root) return;

        Node* curr = root;

        // Move to the leftmost node
        while (!curr->leftThread) {
            curr = curr->left;
        }

        // Traverse in-order
        while (curr) {
            cout << curr->data << " ";
            curr = inOrderSuccessor(curr);
        }
    }
};

int main() {
    ThreadedBinaryTree tbt;
    tbt.insert(30);
    tbt.insert(20);
    tbt.insert(40);
    tbt.insert(10);
    tbt.insert(25);
    tbt.insert(35);
    tbt.insert(50);

    cout << "In-order traversal of TBT: ";
    tbt.inorderTraversal();
    cout << endl;

    return 0;
}