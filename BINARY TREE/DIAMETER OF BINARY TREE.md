**543. Diameter of Binary Tree**

https://leetcode.com/problems/diameter-of-binary-tree/description/

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


![image](https://github.com/user-attachments/assets/cec0f7e4-834a-4cd8-a674-179b1e1c3566)


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1


```cpp
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        diameter(root,res);
        return res;
    }
    int diameter(TreeNode* root,int & res)
    {
        if(!root) return 0;//base case

        int left = diameter(root->left,res);
        int right = diameter(root->right,res);

        //update the maximum diameter encountered so far
        res = max(res,left+right);
        return max(left,right) +1;
    }
};

```
