124. Binary Tree Maximum Path Sum

https://leetcode.com/problems/binary-tree-maximum-path-sum/solutions/5920758/efficient-approach-to-finding-the-maximum-path-sum-in-a-binary-tree/

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
![image](https://github.com/user-attachments/assets/4047185c-75e1-4564-9bdb-93b29e62b8b4)

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:

![image](https://github.com/user-attachments/assets/c7bab20b-732f-4242-84a8-2e72047556e0)

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

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
 int maxi = INT_MIN;
int sum(TreeNode* root)
{
    if(!root ) return 0;
   
     int leftsum =0;
        int rightsum =0;
        
        leftsum = max(0,sum(root->left));
        rightsum = max(0,sum(root->right));
        maxi = max(maxi,leftsum+rightsum+root->val);
        return root->val+max(leftsum,rightsum);
}
    int maxPathSum(TreeNode* root) {
       int ans = sum(root);
       return maxi;
    }
};
```
 
