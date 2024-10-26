https://leetcode.com/problems/count-complete-tree-nodes/description/

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 ![L32  Count total Nodes in a COMPLETE Binary Tree _ O(Log^2 N) Approach _ C++ _ Java 5-53 screenshot](https://github.com/user-attachments/assets/3b31c987-b0f1-454b-b510-d86c187ad1fa)


Example 1:
![image](https://github.com/user-attachments/assets/275508e4-8381-409b-9615-1be20b85d3bc)


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1


 
 BFS with the traversal of every node. Time/space complexity is linear: O(N).
```cpp
class Solution 
{
public:
    int countNodes(TreeNode* root, int l = 1, int r = 1) 
    {
        if (!root) return 0;

        TreeNode *left = root, *right = root;
        while (left = left->left)   ++l; 
        while (right = right->right) ++r; 
        
        if (l == r) return (1 << l) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```