https://leetcode.com/problems/maximum-width-of-binary-tree/

662. Maximum Width of Binary Tree

![L28  Maximum Width of Binary Tree _ C++ _ Java 1-36 screenshot](https://github.com/user-attachments/assets/dc9d72ea-fe92-4d14-9d50-5eb762f153ea)


Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

Example 1:

![image](https://github.com/user-attachments/assets/14a7336d-93b9-439e-9f9c-3a30df3c1371)

Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:

![image](https://github.com/user-attachments/assets/2ae46326-bdcb-48d3-bd0d-4efb209d2d06)

Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:
![image](https://github.com/user-attachments/assets/12c12971-c6e0-465d-9c1c-4e14a049138f)


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).


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
    int widthOfBinaryTree(TreeNode* root) {
        //ek toh whi vertical order jisme map of map of multiset bnate hai pr that takes more TC and SC
        //toh ab hm kya krenge ki level order traversal krenge..hr baar 2i+1 and 2i+2 sbko denge basically horiz wise isse numbering hojayegi toh last me right-left+1 will be the width
        //pr this will make the int overflow bcz at every order you are making twice 2powerheight will be the max so it will cause INT overfloiw if height is more than 30 also
        //since we only want width toh we will reset the values back to 0 1 2 type by everytime subtracting from the min 
        if(root==NULL)return 0;
        queue<pair<TreeNode*,int>>q;//node and index given to it
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            long long sz=q.size();
            long long mini=LLONG_MAX;
            long long minl=LLONG_MAX;
            long long maxl=LLONG_MIN;
            for(long long i=0;i<sz;i++){
                auto top=q.front();
                q.pop();
                long long val=top.second;
                TreeNode* curr=top.first;
                mini=min(mini,val);
                long long modi=val-mini;
                minl=min(minl,modi);
                maxl=max(maxl,modi);

                if(curr->left)q.push({curr->left,2*modi+1});
                if(curr->right)q.push({curr->right,2*modi+2});
            }
            ans=max(ans,maxl-minl+1);
        }
        return ans;
    }
};

```
