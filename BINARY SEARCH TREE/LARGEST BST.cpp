Largest BST
Difficulty: MediumAccuracy: 29.73%Submissions: 151K+Points: 4
Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
Note: Here Size equals the number of nodes in the subtree.

Examples :

Input:   1
        /  \
        4   4              
       / \ 
      6   8
Output: 1 
Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size equal to 1.

Input:    6
        /   \
      6      2              
       \    / \
        2  1   3
Output: 3
Explanation: The following sub-tree is a BST of size 3:  2
                                                       /   \
                                                      1     3
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the BST).

                                  
#include <iostream>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the size
    // of the largest BST subtree
    int largestBSTSubtree(TreeNode* root) {
        if (root == nullptr) return 0;
        if (isValidBST(root, INT_MIN, INT_MAX)) {
            // If the current node is a valid BST,
            // return the size of the entire subtree
            return countNodes(root);
        } else {
            // If not, explore left and right subtrees
            int left = largestBSTSubtree(root->left);
            int right = largestBSTSubtree(root->right);
            return max(left, right);
        }
    }
    
    // Function to check if a given root is a valid BST
    bool isValidBST(TreeNode* root, int minVal, int maxVal) {
        if (root == nullptr) return true;
        if (root->val >= maxVal || root->val <= minVal) return false;
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }
    
    // Function to count the number of  
    // nodes given the root of a subtree
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Utility function to insert nodes into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Utility function to perform
// inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}


int main() {
    Solution solution;

    // Create the BST
    TreeNode* root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);
    insert(root, 20);
    
    // Create a new tree, attaching the
    // BST root as the left child of a new root
    TreeNode* newRoot = new TreeNode(6);
    newRoot->left = root;
    newRoot->right = new TreeNode(3);

    // Display the original tree using inorder traversal
    cout << "Original BST: ";
    inorderTraversal(newRoot);
    cout << endl;

    // Find the size of the largest BST subtree
    int largestBSTSize = solution.largestBSTSubtree(newRoot);
    
    // Display the size of the largest BST subtree found
    cout << "Size of the largest BST subtree: " << largestBSTSize << endl;

    return 0;
}
                                
                            
Output: Original BST: 2 5 7 10 12 15 20 6 3, Size of the largest BST subtree: 7

Complexity Analysis
Time Complexity: O(N*N) twhere N is the number of nodes in the Binary Tree. O(N) to traverse through each node in the tree and for each node, the validation ot check whether its subtree is a valid BST takes O(N) time hence the overall time complexity is O(N * N).

Space Complexity : O(1)as the there no additional space required for storing variables or data structures. The recursive calls for validation can reach a depth of the entire tree’s height hence the auxiliary space can be O(H) for the recursive stack.

Optimal Approach
Algorithm / Intuition
A more optimised approach would be to traverse the tree and simultaneously check is each subtree is a BST. Utilise a bottom up recursive approach to traverse the tree efficiently.

For each node the minimum value, maximum value, size of the BST and whether or not it is a BST which the node as root is passed and updated based on its children’s information. In the end, the size of the largest BST subtree found is returned.

Algorithm

Step 1:Define a `NodeValue` class to hold the following information about each subtree:

minNode`: minimum value of the subtree
`maxNode`: maximum value of the subtree.
`maxSize`: maximum size of the BST encountered so far

Step 2: next () function

Implement a helper function `largestBSTSubtreeHelper` that takes the root as input and recursively gathers information (`minNode`, `maxNode` and `maxSize`) for each subtree.

The `NodeValue` information fo the current node is updated based on the information from the left and right subtree properties ie. the left subtree’s maximum node is less than the current ndoe and the right subtree’s minimum node is greater than the current node.
If the current subtree satisfied the BST property, update the size of the node ie. `maxSize` as `maxSize` from left subtree + `maxSize` from right subtree + 1.
If the current subtree is not a BST, pass on the current maxSize but return minNode as int min and minSize as int max.
Step 3: Return the maxSize of the largest BST subtree found.

Code
C++
Java
Python
JavaScript
Copy
                                
#include <iostream>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Class to hold information
// about the subtree
class NodeValue {
public:
    int maxNode, minNode, maxSize;
    
    // Constructor to initialize
    // the NodeValue object
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    // Helper function to find the
    // largest BST subtree recursively
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        // An empty tree is a BST of size 0
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        // Get values from left and right
        // subtrees of the current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Check if the current tree is a BST based
        // on its left and right subtrees' properties
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST, update the values for the current tree
            return NodeValue(min(root->val, left.minNode),
                max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        
        // If the current tree is not a BST,
        // return values indicating invalid tree properties
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    // Function to find the size
    // of the largest BST subtree
    int largestBSTSubtree(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};

// Utility function to insert nodes into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Utility function to perform
// inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}


int main() {
    Solution solution;

    // Create the BST
    TreeNode* root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);
    insert(root, 20);
    
    // Create a new tree, attaching the
    // BST root as the left child of a new root
    TreeNode* newRoot = new TreeNode(6);
    newRoot->left = root;
    newRoot->right = new TreeNode(3);

    // Display the original tree using inorder traversal
    cout << "Original BST: ";
    inorderTraversal(newRoot);
    cout << endl;

    // Find the size of the largest BST subtree
    int largestBSTSize = solution.largestBSTSubtree(newRoot);
    
    // Display the size of the largest BST subtree found
    cout << "Size of the largest BST subtree: " << largestBSTSize << endl;

    return 0;
}
                                
                            
Output: Original BST: 2 5 7 10 12 15 20 6 3, Size of the largest BST subtree: 7

Complexity Analysis
Time Complexity: O(N)where N is the number of nodes in the Binary tree as we traverse through all the nodes in the tree. The information update for each nodes takes constant time hence the overall time complexity is O(N) as the tree is traversed once.

Space Complexity : O(N) where N is number of nodes in the Binary Tree as for each node we store additional information using a struct class whose new object is initialised. This additional space for variables is proportional to the number of nodes. An additional memory stack space proportional to the height of the Binary Tree O(H) is used by the recursive called to reach the leaf nodes.
