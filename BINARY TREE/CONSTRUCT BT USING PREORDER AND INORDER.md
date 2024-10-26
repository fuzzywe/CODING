105. Construct Binary Tree from Preorder and Inorder Traversal

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:

![image](https://github.com/user-attachments/assets/ff4269ba-0c9c-4426-ada7-e95695bdfc29)

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]

```cpp
class Solution {
public:
unordered_map<int,int>mp;
int preorderIndex;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mp.clear();
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;

        }
        int preorderIndex=0;
        return build(preorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder,int start,int end){
        if(start>end) return nullptr;
        int rootval= preorder[preorderIndex++];
        TreeNode* root= new TreeNode(rootval);
        int mid = mp[rootval];
        root->left= build(preorder,start,mid-1);
        root->right= build(preorder,mid+1,end);
        return root;

    }
};
```
