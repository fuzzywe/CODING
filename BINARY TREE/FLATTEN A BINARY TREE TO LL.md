https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/



Example 1:
![image](https://github.com/user-attachments/assets/3dae0b23-5b7d-4619-b549-afc0892162a3)


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

![L38  Flatten a Binary Tree to Linked List _ 3 Approaches _ C++ _ Java 3-55 screenshot](https://github.com/user-attachments/assets/f9ec656c-321b-4d8e-b8e8-f88ba1ad652d)

![L38  Flatt![L38  Flatten a Binary Tree to Linked List _ 3 Approaches _ C++ _ Java 15-22 screenshot](https://github.com/user-attachments/assets/c9f6bc26-3f59-4584-b5cb-0b85f8805f45)

![L38  Flatten a Bin![L38  Flatten a Binary Tree to Linked List _ 3 Approaches _ C++ _ Java 6-11 screenshot](https://github.com/user-attachments/assets/37408fa2-7c74-44f5-b335-6c7157e0f314)

![L38  Flatten a Binary Tree to Linked List _ 3 Approaches _ C++ _ Java 9-33 screenshot](https://github.com/user-attachments/assets/b2be3fca-25e3-4dc4-9317-8d2faf2e567d)


![L38  Flatten a Binary Tree to Linked List _ 3 Approaches _ C++ _ Java 16-56 screenshot](https://github.com/user-attachments/assets/bda100f9-1286-42ae-b78f-ef6a1a9e0121)


Flatten Binary Tree to Linked List


41

0
Problem Statement: Given a Binary Tree, convert it to a Linked List where the linked list nodes follow the same order as the pre-order traversal of the binary tree.

Use the right pointer of the Binary Tree as the ‘next’ pointer for the linked list and set the left pointer to null. Do this in place and do not create extra nodes.

Examples
Disclaimer: Don’t jump directly to the solution, try it out yourself first.

Brute Force Approach
Algorithm / Intuition
The intuition behind this approach is to perform a reverse pre-order traversal where, instead of simply visiting nodes, we flatten the tree into a linked list as we traverse it.

We start at the root of the tree and recursively do the following for each node, we first ensure that the right subtree is flattened into a linked list. This means that all nodes in the right subtree are processed and attached to the linked list in the correct order.


Next, we do the same for the left subtree. This ensures that all nodes in the left subtree are processed and attached to the linked list in the correct order. Once both subtrees are flattened, we attach the flattened left subtree as the right child of the current node. Since we're using the right pointer of the binary tree as the next pointer for the linked list, this effectively attaches the left subtree to the current node in the linked list. Finally, we attach the flattened right subtree to the rightmost node of the flattened left subtree. This ensures that the right subtree is properly attached to the end of the linked list.

Algorithm

![image](https://github.com/user-attachments/assets/ebc2c6a7-9a51-463d-b16a-566700e4d0c2)

Step 1:Initialise a global variable `prev` to keep track of the previously processed node. Initially set it to null.

Step 2: Base Case: If the current node is null, return null.

Step 3: Flatten the Right and Left Subtree: Recursively flatten the right and left subtree of the current node by calling the flatten function on the current node's right and left child.

![image](https://github.com/user-attachments/assets/83a1e0c6-36ab-4129-af34-85f26dd1aa2e)

Step 4: Attach the Right Subtree to the Flattened Left Subtree: Set the right child of the current node to the value of `prev` since `prev` points to the rightmost node in the flattened left subtree. This effectively attaches the right subtree to the right of the rightmost node of the left subtree.


![image](https://github.com/user-attachments/assets/28963c2b-8772-4ecd-9bdc-223e25364c93)

Step 5:Attach the Left Subtree as Right Child: Set the right child of the current node to the left subtree.

Set the left child of the current node to null since we are flattening the binary tree to a linked list and there should be no left child.

Step 6:Update `prev` to the current node for the next iteration and recursion step.

Code
Complexity Analysis


```cpp

                                
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>
#include <stack>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Initialize a global variable
    // 'prev' to keep track of the
    // previously processed node.
    TreeNode* prev = NULL;

    // Function to flatten a binary tree
    // to a right next Linked List structure
    void flatten(TreeNode* root) {
       // Base case: If the current
       // node is NULL, return.
       if(root==NULL){
           return;
       }

       // Recursive call to
       // flatten the right subtree
       flatten(root->right);
       
       // Recursive call to
       // flatten the left subtree
       flatten(root->left);
       
       // At this point, both left and right
       // subtrees are flattened, and 'prev'
       // is pointing to the rightmost node
       // in the flattened right subtree.

       // Set the right child of
       // the current node to 'prev'.
       root->right = prev;

       // Set the left child of the
       // current node to NULL.
       root->left = NULL;

       // Update 'prev' to the current
       // node for the next iteration.
       prev = root;
    }
};




// Print the preorder traversal of the
// Orignal Binary Tree
void printPreorder(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Print the Binary Tree along the 
// Right Pointers after Flattening
void printFlattenTree(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printFlattenTree(root->right);
}


int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

    Solution sol;
    
    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;
    
    sol.flatten(root);
    
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;
    

    return 0;
}
                                



```





Complexity Analysis

Time Complexity: O(N) where N is the number of nodes in the Binary Tree. Each node of the binary node is visited exactly once. At each node, constant-time operations are performed. Hence the time complexity is O(N).

Space Complexity : O(log2N)where N is the number of nodes in the Binary Tree. There are no additional data structures or space used but the auxiliary stack space is used during recursion. Since the recursion depth can be at most equal to the height to the Binary Tree, the space complexity is O(H) where H is the height of the Binary Tree. In the ideal case, H = log2N and in the worst case H = N (skewed tree).

---

**Better Approach**

![image](https://github.com/user-attachments/assets/f5429f98-09e4-45dd-b55d-c92ea4009e4f)

Algorithm / Intuition
This approach is an extension of the previous approach where we use a stack to simulate recursion.

Algorithm

Step 1: Base Case: If the root node is null, we return as there is no tree to flatten.

![image](https://github.com/user-attachments/assets/0a05554e-21d7-4d98-9512-020081fcf8f7)


Step 2: Initialise Stack: Create a stack to perform an iterative traversal of the binary tree. Push the root node onto the sack to start the traversal.

Step 3: Iterative Traversal with Stack: While the stack is not empty, repeat the following steps:

Pop the top node from the stack.
If the popped node has a right child, push it onto the stack. This ensures that the right child is processed after the left child nodes.
If the popped node has a left child, push it onto the stack.

If the stack is not empty after pushing the left child, connect the right pointer of the current node (popped from the stack) to the top node of the stack. This creates the linked list structure by setting the next pointer.
Set the left pointer of the current node to null as we have to form a right skewed linked list.

Step 4: Once the stack becomes empty, the traversal is complete and the binary tree is flattened into a right next linked list structure.

```cpp
                                
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>
#include <stack>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Initialize a global variable
    // 'prev' to keep track of the
    // previously processed node.
    TreeNode* prev = NULL;

    // Function to flatten a binary tree
    // to a right next Linked List structure
    void flatten(TreeNode* root) {
        // Base case: If the current
        // node is NULL, return.
        if(root == NULL){
            return;
        }
        // Use a stack for
        // iterative traversal.
        stack<TreeNode*> st;
        // Push the root node
        // onto the stack.
        st.push(root);  
        
        // Continue the loop until
        // the stack is empty.
        while (!st.empty()) {  
            // Get the top node from the stack.
            TreeNode* cur = st.top(); 
            // Pop the top node.
            st.pop();  

            if (cur->right != NULL) {
                 // Push the right child
                 // onto the stack.
                st.push(cur->right); 
            }
            
            if (cur->left != NULL) {
                 // Push the left child
                 // onto the stack.
                st.push(cur->left); 
            }

            if (!st.empty()) {
                // Connect the right child to
                // the next node in the stack.
                cur->right = st.top();  
            }
            
            // Set the left child to NULL to
            // form a right-oriented linked list.
            cur->left = NULL;  
        }
    }
};





// Print the preorder traversal of the
// Orignal Binary Tree
void printPreorder(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Print the Binary Tree along the 
// Right Pointers after Flattening
void printFlattenTree(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printFlattenTree(root->right);
}


int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

    Solution sol;
    
    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;
    
    sol.flatten(root);
    
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;
    

    return 0;
}
```                                
                            
Output: Binary Tree Preorder: 1 2 4 5 6 3 8 7, Binary Tree After Flatten: 1 2 4 5 6 3 8 7

Complexity Analysis

Time Complexity: O(N) where N is the number of nodes in the Binary Tree. Each node of the binary node is visited exactly once. At each node, constant-time operations are performed. Hence the time complexity is O(N).

Space Complexity : O(log2N) where N is the number of nodes in the Binary Tree. There are no additional data structures or space used but the auxiliary stack space is used during recursion. Since the recursion depth can be at most equal to the height to the Binary Tree, the space complexity is O(H) where H is the height of the Binary Tree. In the ideal case, H = log2N and in the worst case H = N (skewed tree).


---

Optimal Approach
Algorithm / Intuition
Morris Traversal is an algorithm that allows preorder/inorder tree traversal without using any extra space for stack or recursion. It utilises threaded binary trees to traverse the tree without requiring a stack for saving the path. Read more about Morris Preorder Traversal here


![image](https://github.com/user-attachments/assets/3d6b50e7-d9f2-49c4-a88c-144ab6212da7)


Algorithm
Step 1: Start with the current node as the root of the tree.

Step 2: While the current node is not null we traverse the tree in a while loop:

If the current node has a left child:
Find the rightmost node in the left subtree.
Connect the rightmost node of the left subtree to the current node’s right child.
Update the current node’s right child to be its left child.
Set the current node’s left child to null.
Move to the current node’s right child.
If the current node has no right child:
Move to the current node’s left child (if it exists) or null.
Step 3: Repeat until all nodes are processed.

```cpp
                                
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>
#include <stack>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to flatten a binary tree
    // to a right next Linked List structure
    void flatten(TreeNode* root) {
        // Initialize a pointer
        // 'curr' to the root of the tree
        TreeNode* curr = root;

        // Iterate until 'curr'
        // becomes NULL
        while (curr) {
            // Check if the current
            // node has a left child
            if (curr->left) {
                // If yes, find the rightmost
                // node in the left subtree
                TreeNode* pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }

                // Connect the rightmost node in
                // the left subtree to the current
               //  node's right child
                pre->right = curr->right;

                // Move the entire left subtree to the
                // right child of the current node
                curr->right = curr->left;

                // Set the left child of
                // the current node to NULL
                curr->left = NULL;
            }

            // Move to the next node
            // on the right side
            curr = curr->right;
        }
    }
};



// Print the preorder traversal of the
// Orignal Binary Tree
void printPreorder(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Print the Binary Tree along the 
// Right Pointers after Flattening
void printFlattenTree(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printFlattenTree(root->right);
}


int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

    Solution sol;
    
    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;
    
    sol.flatten(root);
    
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;
    

    return 0;
}
  
```                           
                            
Output: Binary Tree Preorder: 1 2 4 5 6 3 8 7, Binary Tree After Flatten: 1 2 4 5 6 3 8 7

Complexity Analysis

Time Complexity: O(2N) where N is the number of nodes in the Binary Tree.

The time complexity is linear, as each node is visited at most twice (once for establishing the temporary link and once for reverting it).
In each step, we perform constant-time operations, such as moving to the left or right child and updating pointers.
Space Complexity: O(1) The space complexity is constant, as the algorithm uses only a constant amount of extra space irrespective of the input size.

Morris Traversal does not use any additional data structures like stacks or recursion, making it an in-place algorithm.
The only space utilised is for a few auxiliary variables, such as pointers to current and in-order predecessor nodes.
