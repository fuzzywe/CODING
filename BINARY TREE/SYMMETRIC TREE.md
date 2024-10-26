https://leetcode.com/problems/symmetric-tree/description/

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:
![image](https://github.com/user-attachments/assets/c0cb699f-e421-4a88-9228-25f80e69a4a8)


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:

![image](https://github.com/user-attachments/assets/20533964-97dc-458f-9565-7433c5c471ab)

Input: root = [1,2,2,null,3,null,3]
Output: false

```cpp
class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

};

```
