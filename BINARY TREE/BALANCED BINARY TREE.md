110. Balanced Binary Tree

https://leetcode.com/problems/balanced-binary-tree/description/

Given a binary tree, determine if it is 
height-balanced
.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:
![image](https://github.com/user-attachments/assets/f009b7a9-be0b-465a-bf95-f4fc3d566a97)


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 ![image](https://github.com/user-attachments/assets/1fce98d5-72c7-433c-85f6-8e659ac36358)


```cpp
class Solution {
public:
     bool isBalanced(TreeNode*root ){
         return  dfsHeight(root ) != -1; 
     }

      int dfsHeight( TreeNode* root ){
          if( root == NULL){
            return 0 ;
          }

          int left = dfsHeight( root -> left ); 
          if( left == - 1) return -1 ; 
          int right = dfsHeight( root -> right);
          if( right == -1) return -1 ; 

         if( abs( left - right )> 1) return -1 ; 
         return max( left , right )+1 ; 

     } 


};

```
