199. Binary Tree Right Side View
Solved
Medium
Topics
Companies
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []

 Time Complexity: O(N), where N is the number of nodes in the tree.
Space Complexity: O(N) in the worst case, due to the space used by the queue and the answer vector.

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
if(!root)return ans;
queue<TreeNode*>q;
q.push(root);
while(!q.empty())
{
int siz=q.size();
for(int i=0;i<siz;i++)
{
auto ele=q.front();
q.pop();
if(i==siz-1)ans.push_back(ele->val);
if(ele->left)q.push(ele->left);
if(ele->right)q.push(ele->right);
}
}
return ans;
    }
};

```


Complexity
Time Complexity: O(N), where N is the number of nodes in the tree.
Space Complexity:
O(N) in the worst case due to the recursion stack.
O(log N) in the best case for a balanced tree.

Code

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
