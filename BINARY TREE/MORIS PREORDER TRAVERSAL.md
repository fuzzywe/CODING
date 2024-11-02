
https://www.naukri.com/code360/problems/preorder-binary-tree_5948?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

https://leetcode.com/problems/binary-tree-preorder-traversal/description/



14![L37  Morris Traversal _ Preorder _ Inorder _ C++ _ Java 4-28 screenshot](https://github.com/user-attachments/assets/5a754ad1-600b-47eb-b433-2379dd94ea63)

![L37  Morris Traversal _ Preorder _ Inorder _ C++ _ Java 5-36 screenshot](https://github.com/user-attachments/assets/da3565be-01d3-471c-b454-8b9a4091a5f9)

4. Binary Tree Preorder Traversal
Solved
Easy
Topics
Companies
Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:

![image](https://github.com/user-attachments/assets/c20f2052-60ad-48e9-8c81-418ae08d8f96)

Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]

Explanation:

![image](https://github.com/user-attachments/assets/734b76df-9eeb-42e5-9b64-c51768a12aa5)


Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]


```cpp

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* cur = root;

        while (cur != NULL) {
            // If the current node has no left child
            if (cur->left == NULL) {
                // Add the value of the current node to the preorder vector
                preorder.push_back(cur->val);
                
                // Move to the right child
                cur = cur->right;
            } else {
                // Find the rightmost node in the left subtree
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // Set the right child of the rightmost node to the current node
                    prev->right = cur;
                    
                    // Add the current node value (for preorder)
                    preorder.push_back(cur->val);
                    
                    // Move to the left child
                    cur = cur->left;
                } else {
                    // If the right child of the rightmost node is not NULL, reset it
                    prev->right = NULL;
                    
                    // Move to the right child
                    cur = cur->right;
                }
            }
        }

        return preorder;
    }
};


```
