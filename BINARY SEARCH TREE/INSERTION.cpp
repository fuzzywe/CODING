Insertion in Binary Search Tree using Iterative approach:
Instead of using recursion, we can also implement the insertion operation iteratively using a while loop. Below is the implementation using a while loop.


#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int item)
    {
        key = item;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int x)
{

    Node* temp = new Node(x);

    // If tree is empty
    if (root == NULL)
        return temp;

    // Find the node who is going
    // to have the new node temp as
    // it child. The parent node is
    // mainly going to be a leaf node
    Node *parent = NULL, *curr = root;
    while (curr != NULL) {
        parent = curr;
        if (curr->key > x)
            curr = curr->left;
        else if (curr->key < x)
            curr = curr->right;
        else
            return root;
    }

    // If x is smaller, make it
    // left child, else right child
    if (parent->key > x)
        parent->left = temp;
    else
        parent->right = temp;
    return root;
}

// A utility function to do inorder
// tree traversal
void inorder(Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Driver program
int main()
{
    // Creating the following BST
    //      50
    //     /  \
    //    30   70
    //   / \   / \
    //  20 40 60 80

    Node* root = new Node(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print inorder traversal of the BST
    inorder(root);

    return 0;
}

Output
20 30 40 50 60 70 80 
The time complexity of inorder traversal is O(n), as each node is visited once. 
The Auxiliary space is O(n), as we use a stack to store nodes for recursion.


    #include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
public:
    TreeNode* root;

    BST() : root(nullptr) {}

    // Function to insert a value into the BST
    TreeNode* insert(TreeNode* root, int val) {
        // If the tree is empty, return a new node
        if (root == nullptr) {
            return new TreeNode(val);
        }

        // Otherwise, recur down the tree
        if (val < root->val) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }

        // return the (unchanged) node pointer
        return root;
    }

    // Helper function to insert into the BST starting from root
    void insert(int val) {
        root = insert(root, val);
    }

    // Function to print the tree in inorder traversal (just for visualization)
    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    // Wrapper function for inorder traversal
    void printInOrder() {
        inorder(root);
    }
};

int main() {
    BST tree;

    // Insert elements into the BST
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Print the tree in inorder to see the sorted elements
    cout << "Inorder traversal of the BST: ";
    tree.printInOrder();  // Output should be the elements in ascending order
    cout << endl;

    return 0;
}

