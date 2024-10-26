235. Lowest Common Ancestor of a Binary Search Tree

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:

![image](https://github.com/user-attachments/assets/a268a0f8-27bc-4602-9e2a-03fb3ee08a22)

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:
![image](https://github.com/user-attachments/assets/8cd2a5f6-05ab-4778-96eb-6d19e2ac8777)


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2

```cpp
 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = min(p->val, q->val);
        int large = max(p->val, q->val);
        while (root != nullptr) {
            if (root->val > large) // p, q belong to the left subtree
                root = root->left;
            else if (root->val < small) // p, q belong to the right subtree
                root = root->right;
            else // Now, small <= root.val <= large -> This root is the LCA between p and q
                return root;
        }
        return nullptr;
    }
};

```
