103. Binary Tree Zigzag Level Order Traversal

https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:
![image](https://github.com/user-attachments/assets/7ef6723e-67e6-4aa6-a876-49676707617c)


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>temp;
            for(int i=0;i<sz;i++)
            {
                TreeNode* node= q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                temp.emplace_back(node->val);
            }
            if(flag==false)
            {
                reverse(temp.begin(),temp.end());
                ans.emplace_back(temp);
                flag=true;
            }
            else
            {
                ans.emplace_back(temp);
                flag=false;
            }
        }
        return ans;
    }
};

```
