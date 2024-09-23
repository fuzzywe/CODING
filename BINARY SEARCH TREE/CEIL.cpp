Ceil in a Binary Search Tree


23

0
Problem Statement: Given a Binary Search Tree and a key, return the ceiling of the given key in the Binary Search Tree.

Ceiling of a value refers to the value of the smallest node in the Binary Search Tree that is greater than or equal to the given key.
If the ceiling node does not exist, return nullptr.
Examples
Example 1:
Input:Binary Search Tree: 10 5 13 3 6 11 14 2 4 -1 9, Key = 8
				

Output:9
Explanation: In the given BST, the smallest value greater or equal to 8 is 9. 
Example 2:
Input:Binary Search Tree: 8 5 12 4 7 10 14 -1 -1 6 -1 -1 -1 13, Key = 8
				

Output: 12
Explanation:  In the given BST, the smallest value greater or equal to 11 is 12. 

                            
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
    // Function to find the ceiling of
    // a key in a Binary Search Tree (BST)
    int findCeil(TreeNode* root, int key){
        // Initialize the variable
        // to store the ceiling value
        int ceil = -1; 
        
        // Traverse the BST until reaching
        // the end or finding the key
        while(root){
             // If the key is found, assign it
             // as the ceiling and return
            if(root->val == key){
                ceil = root->val;
                return ceil;
            } 
            
             // If the key is greater,
             // move to the right subtree
            if(key > root->val){
                root = root->right;
            }
            else{ 
                // If the key is smaller, update ceil
                // and move to the left subtree
                ceil = root->val;
                root = root->left;
            }
        }
         // Return the computed ceiling value
        return ceil;
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
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;

    Solution solution;
    
    // Searching for a value in the BST
    int target = 8;
    int ciel = solution.findCeil(root, target);
    
    if(ciel != -1){
        cout << "Ceiling of " << target << " is: " << ciel << endl;
    }
    else{
        cout << "No ceiling found!";
    }
    
    return 0;
}
                            
                        
Output Binary Search Tree: 2 3 4 5 6 9 10 11 13 14, Ceiling of 8 is: 9

Complexity Analysis
Time Complexity: O(log2N) where N is the number of nodes in the Binary Search Tree. In the best case scenario, where the tree is balanced, the time complexity is the height of the tree ie. log2N. In the worst-case scenario, where the tree is degenerate (linear), the time complexity becomes O(n), as it would require traversing all nodes along the path from the root to the leaf.

Space Complexity: O(1) since the algorithm does not use any additional space or data structures


  Let's perform a detailed line-by-line dry run of the given C++ code to understand it better.

### **Line-by-line Breakdown**:

---

### **Struct Definition:**
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```
- **TreeNode Structure**:
    - `TreeNode` defines a node for a Binary Search Tree (BST).
    - It has three fields:
      - `val` stores the integer value of the node.
      - `left` is a pointer to the left child node.
      - `right` is a pointer to the right child node.
    - The constructor initializes the node's value (`val`), and sets `left` and `right` child pointers to `nullptr` (i.e., null).

---

### **Class Definition:**
```cpp
class Solution {
public:
    int findCeil(TreeNode* root, int key) {
        int ceil = -1;
        while(root) {
            if(root->val == key) {
                ceil = root->val;
                return ceil;
            } 
            if(key > root->val) {
                root = root->right;
            }
            else {
                ceil = root->val;
                root = root->left;
            }
        }
        return ceil;
    }
};
```
- **`findCeil` function**:
    - The goal of this function is to find the smallest number in the BST greater than or equal to a given `key` (the ceiling of `key`).
    - **Steps**:
      1. **Initialize `ceil` to `-1`**:
         - `ceil` will hold the result. Initially, it's set to `-1`, meaning that no ceiling has been found.
      2. **Traverse the BST**:
         - As long as `root` is not `nullptr` (i.e., we haven’t reached a leaf), the function keeps traversing the tree.
      3. **Check if the `root->val` matches the `key`**:
         - If the current node's value equals the `key`, we have found the ceiling, which is the `key` itself. We return this value.
      4. **Move to the right subtree if `key` is greater**:
         - If `key > root->val`, the `key` could only be in the right subtree, so we move `root = root->right`.
      5. **Move to the left subtree if `key` is smaller**:
         - If `key < root->val`, the current node could be the ceiling. We update `ceil = root->val` and move to the left subtree (`root = root->left`) to check for a smaller possible ceiling.
      6. **Return the ceiling**:
         - After traversing, if a ceiling was found, it will be returned. If not, `-1` is returned, indicating no ceiling exists.

---

### **In-order Traversal Function:**
```cpp
void printInOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}
```
- **`printInOrder` function**:
    - This function performs an in-order traversal of the binary tree and prints each node's value.
    - **Steps**:
      1. **Base Case**:
         - If `root` is `nullptr` (i.e., we've reached a leaf or an empty tree), the function returns without doing anything.
      2. **Recursive Call on the Left Subtree**:
         - Recursively calls `printInOrder(root->left)` to visit the left subtree first.
      3. **Print Current Node's Value**:
         - Prints the value of the current node.
      4. **Recursive Call on the Right Subtree**:
         - Recursively calls `printInOrder(root->right)` to visit the right subtree after visiting the left subtree and the current node.
      - This order ensures that values are printed in ascending order for a BST.

---

### **Main Function:**
```cpp
int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
```
- **Creating a Binary Search Tree (BST)**:
    - This section of code constructs a BST with the following structure:
      ```
              10
             /  \
            5    13
           / \   /  \
          3   6 11  14
         / \
        2   4
             \
              9
      ```
    - Each node is created with `new TreeNode(value)` and linked appropriately.

---

### **In-order Traversal:**
```cpp
    cout << "Binary Search Tree: " << endl;
    printInOrder(root);
    cout << endl;
```
- **Print the BST**:
    - Calls `printInOrder(root)` to print the nodes of the BST in ascending order.
    - Output: `2 3 4 5 6 9 10 11 13 14`.

---

### **Find the Ceiling:**
```cpp
    Solution solution;
    int target = 8;
    int ciel = solution.findCeil(root, target);
```
- **Initialize `Solution` object**:
    - Creates an instance of the `Solution` class.
- **Set `target` to 8**:
    - The target key for which we want to find the ceiling in the BST is `8`.
- **Call `findCeil(root, 8)`**:
    - Calls the `findCeil` function to find the smallest number greater than or equal to `8` in the BST.

---

### **Print the Ceiling Result:**
```cpp
    if(ciel != -1){
        cout << "Ceiling of " << target << " is: " << ciel << endl;
    }
    else{
        cout << "No ceiling found!";
    }
    
    return 0;
}
```
- **Check and Print Ceiling**:
    - If `ciel` is not `-1`, it prints the ceiling of `8`. If `-1`, it prints "No ceiling found!".
    - For this example, the ceiling of `8` is `9`.

---

### **Dry Run of `findCeil` for `target = 8`**:

- **Step 1**: Start at the root (`10`):
  - `key = 8`, `root->val = 10`.
  - `key < root->val`, so `ceil = 10` and move to the left subtree (`root = 5`).
  
- **Step 2**: At node `5`:
  - `key = 8`, `root->val = 5`.
  - `key > root->val`, so move to the right subtree (`root = 6`).

- **Step 3**: At node `6`:
  - `key = 8`, `root->val = 6`.
  - `key > root->val`, so move to the right subtree (`root = 9`).

- **Step 4**: At node `9`:
  - `key = 8`, `root->val = 9`.
  - `key < root->val`, so `ceil = 9` and move to the left subtree (`root = nullptr`).

- **Step 5**: `root` is now `nullptr`, so the function returns `9`.

---

### **Final Output**:
```
Binary Search Tree: 
2 3 4 5 6 9 10 11 13 14 
Ceiling of 8 is: 9
```

This dry run explains how the `findCeil` function works and how the ceiling of the number `8` is found in the given BST.
