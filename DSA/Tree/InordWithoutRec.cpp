#include <iostream>
#include <stack>
using namespace std;

void inorderTraversal(Node* root) {
    stack<Node*> stack;
    Node* current = root;

    while (current != nullptr || !stack.empty()) {
        // Reach the leftmost node of the current node
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        // Current must be nullptr at this point
        current = stack.top();
        stack.pop();

        cout << current->val << " ";

        // We have visited the node and its left subtree. Now, it's right subtree's turn
        current = current->right;
    }
}

int main() {
    // Creating a simple binary tree
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->left = new Node(3);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    // Clean up memory (not shown for simplicity)
    return 0;
}