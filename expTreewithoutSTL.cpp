#include <iostream>
#define MAX 100  // Define maximum size of stack
using namespace std;

// Node structure for the Expression Tree
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = right = nullptr;
    }
};

// Stack class implemented using an array of pointers
class Stack {
private:
    Node* arr[MAX];  // Array to store node pointers
    int top;         // Top index

public:
    Stack() { top = -1; }

    // Push a node onto the stack
    void push(Node* node) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = node;
    }

    // Pop a node from the stack
    Node* pop() {
        if (isEmpty()) return nullptr;
        return arr[top--];
    }

    // Peek at the top node without removing it
    Node* peek() {
        return isEmpty() ? nullptr : arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

// Recursive function to construct an expression tree from prefix notation
Node* constructTree(const string &prefix, int &index) {
    if (index >= prefix.length()) return nullptr;

    Node* newNode = new Node(prefix[index]);

    // If character is an operand, return the node
    if (isalnum(prefix[index])) {
        return newNode;
    }

    // If character is an operator, create left and right subtrees
    index++;  // Move to next character
    newNode->left = constructTree(prefix, index);
    
    index++;  // Move to next character
    newNode->right = constructTree(prefix, index);

    return newNode;
}

// Postorder Traversal (Non-Recursive using Array-Based Stack)
void postorderTraversal(Node* root) {
    if (!root) return;

    Stack s1, s2;
    s1.push(root);

    while (!s1.isEmpty()) {
        Node* node = s1.pop();
        s2.push(node);

        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }

    // Print postorder from second stack
    while (!s2.isEmpty()) {
        cout << s2.pop()->data << " ";
    }
}

// Delete Tree using Array-Based Stack
void deleteTree(Node* &root) {
    if (!root) return;

    Stack s;
    s.push(root);

    while (!s.isEmpty()) {
        Node* node = s.pop();

        if (node->left) s.push(node->left);
        if (node->right) s.push(node->right);

        delete node;
    }
    root = nullptr;
}

// Main Function
int main() {
    string prefix = "+--a*bc/def";
    int index = 0;

    // Step 1: Construct the Expression Tree without using STL stack
    Node* root = constructTree(prefix, index);

    // Step 2: Perform Non-Recursive Postorder Traversal using Array-Based Stack
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    // Step 3: Delete the Tree
    deleteTree(root);

    return 0;
}
