236. Lowest Common Ancestor of a Binary Tree

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
![WhatsApp Image 2024-10-26 at 11 26 52_8b2de7bf](https://github.com/user-attachments/assets/9427ce5f-4717-4861-b780-4bf42e0ffabf)

 

Example 1:
![image](https://github.com/user-attachments/assets/75117104-b9ca-4b5c-a739-93a8eb623f24)


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

![image](https://github.com/user-attachments/assets/4b0eee1c-a9bb-448a-82f8-c2ea25cc4460)

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL||root==p||root==q) return root;

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left==NULL)  return right;
        if(right==NULL) return left;
        else
        return root;
        
    }
};

```
 
