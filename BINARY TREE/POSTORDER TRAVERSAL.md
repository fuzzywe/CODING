https://leetcode.com/problems/binary-tree-postorder-traversal/solutions/5688315/beats-100-python-c-java-shortest-code-easy-to-understand-best-approach-dps/

Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]

Explanation:


![image](https://github.com/user-attachments/assets/c21dc89d-5c46-4edd-8259-fb326a2ea21f)

Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,6,7,5,2,9,8,3,1]

Explanation:

![image](https://github.com/user-attachments/assets/c70b0c01-d43c-43ae-8f73-86df0fd7e924)


Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 
```cpp
#include <vector>
using namespace std;

class Solution {
public:
    void find(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        find(root->left, ans);
        find(root->right, ans);
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        find(root, ans);
        return ans;
    }
};
```
