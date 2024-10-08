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
Complexity
Time complexity: O(n)
Space complexity: O(n)

https://leetcode.com/problems/validate-binary-search-tree/solutions/5622933/video-check-range-of-each-node/?envType=problem-list-v2&envId=adx6f5td&difficulty=MEDIUM&status=TO_DO
