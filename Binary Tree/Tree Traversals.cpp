#include <iostream>
#include <queue>
#include <stack>
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

//                TREE CONSTRUCTION (RECURSIVE)


Node* buildTree() {
    int data;
    cout << "Enter data (-1 for NULL): ";
    cin >> data;

    if (data == -1)
        return nullptr;

    Node* root = new Node(data);

    cout << "Enter left child of " << data << endl;
    root->left = buildTree();

    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    return root;
}

//            TREE CONSTRUCTION (LEVEL ORDER)

void buildFromLevelOrder(Node*& root) {

    cout << "Enter root data (-1 for NULL): ";
    int data;
    cin >> data;

    if (data == -1)
        return;

    root = new Node(data);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node* temp = q.front();
        q.pop();

        int leftData, rightData;

        cout << "Enter left child of " << temp->data << " : ";
        cin >> leftData;

        if (leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << " : ";
        cin >> rightData;

        if (rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

//                    INORDER TRAVERSAL


// Recursive
void inorder(Node* root) {

    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Iterative
void iterativeInorder(Node* root) {

    stack<Node*> st;
    Node* curr = root;

    while (!st.empty() || curr != nullptr) {

        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}


//                    PREORDER TRAVERSAL

// Recursive
void preorder(Node* root) {

    if (root == nullptr)
        return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

// Iterative (Approach 1)
void iterativePreorder(Node* root) {

    if (root == nullptr)
        return;

    stack<Node*> st;
    Node* curr = root;

    while (!st.empty() || curr != nullptr) {

        while (curr != nullptr) {
            cout << curr->data << " ";
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        curr = curr->right;
    }
}

// Iterative (Approach 2)
void iterativePreorder2(Node* root) {

    if (root == nullptr)
        return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {

        Node* curr = st.top();
        st.pop();

        cout << curr->data << " ";

        if (curr->right)
            st.push(curr->right);

        if (curr->left)
            st.push(curr->left);
    }
}


//        POSTORDER TRAVERSAL

// Recursive
void postorder(Node* root) {

    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}

// Iterative (One Stack)
void iterativePostorder(Node* root) {

    if (root == nullptr)
        return;

    stack<Node*> st;
    Node* curr = root;
    Node* prev = nullptr;

    while (!st.empty() || curr != nullptr) {

        if (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        else {

            Node* temp = st.top();

            if (temp->right != nullptr && temp->right != prev) {
                curr = temp->right;
            }
            else {
                cout << temp->data << " ";
                prev = temp;
                st.pop();
            }
        }
    }
}


//       LEVEL ORDER TRAVERSAL
// Iterative
void levelOrderTraversal(Node* root) {

    if (root == nullptr)
        return;

    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {

        int size = q.size();

        while (size--) {

            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }

        cout << endl;
    }
}


int main() {

    Node* root = nullptr;
    // root = buildTree();

    buildFromLevelOrder(root);

    cout << "\nRecursive Inorder : ";
    inorder(root);

    cout << "\nIterative Inorder : ";
    iterativeInorder(root);

    cout << "\n\nRecursive Preorder : ";
    preorder(root);

    cout << "\nIterative Preorder (Approach 1) : ";
    iterativePreorder(root);

    cout << "\nIterative Preorder (Approach 2) : ";
    iterativePreorder2(root);

    cout << "\n\nRecursive Postorder : ";
    postorder(root);

    cout << "\nIterative Postorder : ";
    iterativePostorder(root);

    cout << "\n\nLevel Order Traversal :\n";
    levelOrderTraversal(root);

    return 0;
}
