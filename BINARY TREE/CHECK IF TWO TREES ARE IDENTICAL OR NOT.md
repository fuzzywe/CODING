tree isidentical or not :

100. Same Tree

https://leetcode.com/problems/same-tree/description/

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:

![image](https://github.com/user-attachments/assets/d700a1d2-beea-48c9-9a7f-95990b57a059)
Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:

![image](https://github.com/user-attachments/assets/557a044a-9581-44a6-bd89-254187211b38)


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:
![image](https://github.com/user-attachments/assets/d80ed877-6130-45f3-9a29-4585834f6ad4)


Input: p = [1,2,1], q = [1,1,2]
Output: false

---

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL||q==NULL) return (p==q);
        return(p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

```
