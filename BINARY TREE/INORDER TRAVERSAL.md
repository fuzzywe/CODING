https://leetcode.com/problems/binary-tree-inorder-traversal/description/

94. Binary Tree Inorder Traversal
Easy
Topics
Companies
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:
![image](https://github.com/user-attachments/assets/9e1679ff-e052-42d0-b73a-0bd0d492a9c3)



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:
![image](https://github.com/user-attachments/assets/06f6b01c-f294-46ef-9d2a-7a695cdf4467)



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]


```cpp
class Solution {
public:
void inorder(TreeNode* root,vector<int>&ans){
    if(root == NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return ans;

        
    }
};
```

Complexity
Time complexity:
The time complexity is O(n), where n is the number of nodes in the tree. Each node is visited exactly once.

Space complexity:
The space complexity is O(n) in the worst case due to the recursion stack, where n is the height of the tree. In the worst case (unbalanced tree), this can be O(n). However, in a balanced tree, it will be O(logn).


---

ITERATIVE APPROACH

---

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;

        while (root != nullptr || !stack.empty()) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }

            root = stack.top();
            stack.pop();
            res.push_back(root->val);
            root = root->right;
        }

        return res;        
    }
};
```


For the given iterative inorder traversal code, here is the **overall time and space complexity**:

### Time Complexity
- **Overall Time Complexity**: **O(n)**, where \( n \) is the total number of nodes in the binary tree.
  - Each node is processed (visited, pushed, and popped from the stack) exactly once, resulting in an \( O(n) \) time complexity.

### Space Complexity
- **Overall Space Complexity**: **O(h)**, where \( h \) is the height of the tree.
  - The space complexity is mainly due to the stack used to traverse the tree.
  - In the worst case, if the tree is completely unbalanced (like a linked list), \( h \) could be \( n \), giving a space complexity of **O(n)**.
  - In the best case, if the tree is balanced, \( h \) would be \( O(\log n) \), giving a space complexity of **O(\log n)**. 

So the **overall time complexity** is **O(n)**, and the **overall space complexity** is **O(h)**, where \( h \) can range from \( O(\log n) \) to \( O(n) \), depending on the tree's structure.
Yes, this is an iterative approach for **inorder traversal** of a binary tree (left, root, right) in Python. 



### Example Dry Run

Consider this binary tree:

```
      1
       \
        2
       /
      3
```

The expected inorder traversal result is `[1, 3, 2]`.

1. **Initialization**:
   - `res = []`
   - `stack = []`
   - `root = 1`

2. **First Outer Loop** (`root = 1`):
   - Enter inner `while` loop:
     - Push `1` to `stack`: `stack = [1]`
     - Move `root` to `root.left`, which is `None`.

3. **Process Node `1`**:
   - Pop `1` from `stack`: `stack = []`
   - Add `1` to `res`: `res = [1]`
   - Move `root` to `root.right`, which is `2`.

4. **Second Outer Loop** (`root = 2`):
   - Enter inner `while` loop:
     - Push `2` to `stack`: `stack = [2]`
     - Move `root` to `root.left`, which is `3`.

5. **Third Outer Loop** (`root = 3`):
   - Enter inner `while` loop:
     - Push `3` to `stack`: `stack = [2, 3]`
     - Move `root` to `root.left`, which is `None`.

6. **Process Node `3`**:
   - Pop `3` from `stack`: `stack = [2]`
   - Add `3` to `res`: `res = [1, 3]`
   - Move `root` to `root.right`, which is `None`.

7. **Process Node `2`**:
   - Pop `2` from `stack`: `stack = []`
   - Add `2` to `res`: `res = [1, 3, 2]`
   - Move `root` to `root.right`, which is `None`.

8. **End**:
   - Both `root` is `None` and `stack` is empty, so we exit the loop and return `res = [1, 3, 2]`.

This produces the final result `[1, 3, 2]`, which is the correct inorder traversal.
