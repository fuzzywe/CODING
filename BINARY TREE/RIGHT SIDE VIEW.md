https://leetcode.com/problems/binary-tree-right-side-view/description/



199. Binary Tree Right Side View

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:
![image](https://github.com/user-attachments/assets/8fe56e12-cf9c-4541-9984-ef05dd7a59f7)


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []

---
```cpp
class Solution {
public:
    
    void solve(TreeNode* root , vector<int> &ans , int lvl)
    {
        if(root == NULL)
        return ;

        if(lvl == ans.size())
        {
            ans.push_back(root->val);
        }

        solve(root->right , ans , lvl+1);
        solve(root->left , ans , lvl+1);

    }

    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        solve(root , ans , 0);
        return ans;
    }
};
```
 
