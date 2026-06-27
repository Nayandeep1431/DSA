#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// Build Binary Tree using Recursion
Node* buildTree() {
    cout << "Enter the data (-1 for NULL): ";
    int data;
    cin >> data;

    if (data == -1)
        return nullptr;

    Node* root = new Node(data);

    cout << "Enter data for left of " << data << endl;
    root->left = buildTree();

    cout << "Enter data for right of " << data << endl;
    root->right = buildTree();

    return root;
}

int main() {
    Node* root = buildTree();

    cout << "\nBinary Tree created successfully!" << endl;

    return 0;
}
