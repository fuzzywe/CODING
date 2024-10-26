https://leetcode.com/problems/validate-binary-search-tree/

A valid BST is defined as follows:

The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

![image](https://github.com/user-attachments/assets/975296df-6c5d-4239-9872-11c9b4e07f22)

Input: root = [2,1,3]
Output: true
Example 2:
![image](https://github.com/user-attachments/assets/b54ee5d2-70ea-4574-844d-12b6917add22)


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);        
    }

private:
    bool valid(TreeNode* node, long minimum, long maximum) {
        if (!node) return true;

        if (!(node->val > minimum && node->val < maximum)) return false;

        return valid(node->left, minimum, node->val) && valid(node->right, node->val, maximum);
    }    
};

```
