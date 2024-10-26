1008. Construct Binary Search Tree from Preorder Traversal

https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

 

Example 1:
![image](https://github.com/user-attachments/assets/2e66fe4a-456a-4336-8581-cd2d1f7608bd)


Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]

```cpp

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(0, preorder.size() - 1, preorder);
    }

private:
    TreeNode* solve(int start, int end, vector<int>& preorder) {
        // Base case: if start index is greater than end, return nullptr
        if (start > end) return nullptr;

        // Find the first index greater than preorder[start] (next greater element)
        int nge = end + 1;
        for (int i = start + 1; i <= end; i++) {
            if (preorder[i] > preorder[start]) {
                nge = i;
                break;
            }
        }

        // Create the root node with current start value
        TreeNode* root = new TreeNode(preorder[start]);

        // Recursive calls for left and right subtrees
        root->left = solve(start + 1, nge - 1, preorder);
        root->right = solve(nge, end, preorder);

        return root;
    }
};

```
