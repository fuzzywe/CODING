Example 1:
Input:Binary Search Tree: 8 5 12 4 7 10 14 -1 -1 6 -1 -1 -1 13 -1, Key = 10

				

Output:True
Explanation:  
Example 2:
Input:Binary Search Tree: 4 2 6 1 3 5 7, Key = 3

				

Output :False
Explanation:  


                            
#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

// Definition of TreeNode structure
// for a binary tree node
struct TreeNode {
    // Value of the node
    int val;
    
    // Pointer to the left child node
    TreeNode* left;
    
    // Pointer to the right child node
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // This function searches for a node with
    // a specified value in a Binary Search Tree (BST).
    TreeNode* searchBST(TreeNode* root, int val){
        // Loop until either the tree is
        // exhausted (NULL) or the value is found.
        while(root != NULL && root->val != val){
            // Check if the target value is
            // less than the current node's value.
            // If so, move to the left subtree
            // (values smaller than the current node).
            // Otherwise, move to the right subtree
            // (values larger than the current node).
            root = val < root->val ? root->left : root->right;
        }
        // Return the node containing the target value,
        // if found; otherwise, return NULL.
        return root;
    }
};


// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode* root) {
    // Check if the current node
    // is null (base case for recursion)
    if (root == nullptr) {
        // If null, return and
        // terminate the function
        return;
    }

    // Recursively call printInOrder
    // for the left subtree
    printInOrder(root->left);

    // Print the value of the current node
    cout << root->val << " ";

    // Recursively call printInOrder
    // for the right subtree
    printInOrder(root->right);
}

int main() {
    // Creating a BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(10);
    
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;

    Solution solution;
    
    // Searching for a value in the BST
    int target = 6;
    TreeNode* result = solution.searchBST(root, target);

    // Displaying the search result
    if (result != nullptr) {
        std::cout << "Value " << target << " found in the BST!" << std::endl;
    } else {
        std::cout << "Value " << target << " not found in the BST." << std::endl;
    }
    
    return 0;
}
                            
                        
Output Binary Search Tree: 2 3 4 5 6 8 10, Value 6 found in the BST!

Complexity Analysis
Time Complexity: O(log2N) where N is the number of nodes in the Binary Search Tree. In the best case scenario, where the tree is balanced, the time complexity is the height of the tree ie. log2N. In the worst-case scenario, where the tree is degenerate (linear), the time complexity becomes O(n), as it would require traversing all nodes along the path from the root to the leaf.

Space Complexity: O(1) since the algorithm does not use any additional space or data structures. The algorithm does use auxiliary stack space from recursion. In the average and worst-case scenarios, the space complexity for recursive stack space is O(h), where 'h' represents the height of the tree.
