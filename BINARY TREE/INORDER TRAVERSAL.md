94. Binary Tree Inorder Traversal
Easy
Topics
Companies
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:
![image](https://github.com/user-attachments/assets/9e1679ff-e052-42d0-b73a-0bd0d492a9c3)



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:
![image](https://github.com/user-attachments/assets/06f6b01c-f294-46ef-9d2a-7a695cdf4467)



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]


```cpp
class Solution {
public:
void inorder(TreeNode* root,vector<int>&ans){
    if(root == NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return ans;

        
    }
};
```

Complexity
Time complexity:
The time complexity is O(n), where n is the number of nodes in the tree. Each node is visited exactly once.

Space complexity:
The space complexity is O(n) in the worst case due to the recursion stack, where n is the height of the tree. In the worst case (unbalanced tree), this can be O(n). However, in a balanced tree, it will be O(logn).
