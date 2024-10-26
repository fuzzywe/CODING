https://leetcode.com/problems/maximum-width-of-binary-tree/

662. Maximum Width of Binary Tree
Medium
Topics
Companies
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
