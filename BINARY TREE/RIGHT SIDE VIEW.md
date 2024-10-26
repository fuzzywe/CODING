https://leetcode.com/problems/binary-tree-right-side-view/description/



199. Binary Tree Right Side View

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:
![image](https://github.com/user-attachments/assets/8fe56e12-cf9c-4541-9984-ef05dd7a59f7)


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []

---
```cpp
class Solution {
public:
    
    void solve(TreeNode* root , vector<int> &ans , int lvl)
    {
        if(root == NULL)
        return ;

        if(lvl == ans.size())
        {
            ans.push_back(root->val);
        }

        solve(root->right , ans , lvl+1);
        solve(root->left , ans , lvl+1);

    }

    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        solve(root , ans , 0);
        return ans;
    }
};
```
 The code provided implements a solution to get the right-side view of a binary tree. The right-side view consists of the nodes visible when the tree is viewed from the right. Here’s a dry run, detailing each line of the code step-by-step.

Consider the following example binary tree:

```
       1
      / \
     2   3
      \   \
       5   4
```

The expected right-side view for this tree is `[1, 3, 4]`.

### Code Explanation with Dry Run

```cpp
class Solution {
public:
    
    void solve(TreeNode* root, vector<int> &ans, int lvl)
    {
        if(root == NULL)
            return;
```

- **Explanation**: The function `solve` is a recursive helper function that performs a depth-first traversal on the tree. The base case checks if `root` is `NULL`, and if it is, the function simply returns (no further traversal).
- **State**:
  - Initially: `root = 1`, `ans = []`, `lvl = 0`
  
```cpp
        if(lvl == ans.size()) {
            ans.push_back(root->val);
        }
```

- **Explanation**: This line checks if the current `lvl` (level) is equal to the current size of the `ans` vector. If `lvl` equals `ans.size()`, it indicates that this is the first node encountered at this level from the right side, so `root->val` is added to `ans`.
- **State**:
  - For `root = 1` at `lvl = 0`, `ans.size() = 0`, so `1` is added to `ans`.
  - **Updated `ans`**: `[1]`

```cpp
        solve(root->right, ans, lvl + 1);
```

- **Explanation**: This line initiates a recursive call on the right child of the current node, increasing `lvl` by 1. This ensures that we prioritize the right child, capturing the rightmost nodes at each level.
- **State**:
  - For `root = 1`, `lvl = 0`: Calls `solve(3, ans, 1)` (moving to the right child `3` of node `1`).

```cpp
        solve(root->left, ans, lvl + 1);
    }
```

- **Explanation**: After completing the traversal on the right child, this line initiates a recursive call on the left child with `lvl + 1`. This step will only add a node to `ans` if the level wasn’t already captured by a right-side node.
- **State**:
  - For `root = 1`, after `solve(3, ans, 1)`, it calls `solve(2, ans, 1)` (moving to the left child `2` of node `1`).

---

### Main Function `rightSideView`

```cpp
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};
```

- **Explanation**:
  - `rightSideView` is the main function that initializes the `ans` vector to store the right-side view.
  - It calls `solve` with the root of the tree, `ans`, and an initial `lvl` of 0, beginning the depth-first search.
  - Once all recursive calls are completed, `rightSideView` returns the final `ans` vector, which contains the nodes seen from the right side.

---

### Dry Run with Example Tree

Starting with `root = 1`, `ans = []`, `lvl = 0`:

1. **First Call to `solve(1, ans, 0)`**
   - `root = 1`, `lvl = 0`
   - `lvl` matches `ans.size()`, so add `1` to `ans`: `ans = [1]`
   - **Recursive Call**: `solve(3, ans, 1)` (move to the right child)

2. **Second Call to `solve(3, ans, 1)`**
   - `root = 3`, `lvl = 1`
   - `lvl` matches `ans.size()`, so add `3` to `ans`: `ans = [1, 3]`
   - **Recursive Call**: `solve(4, ans, 2)` (move to the right child)

3. **Third Call to `solve(4, ans, 2)`**
   - `root = 4`, `lvl = 2`
   - `lvl` matches `ans.size()`, so add `4` to `ans`: `ans = [1, 3, 4]`
   - **Recursive Calls**: `solve(nullptr, ans, 3)` and `solve(nullptr, ans, 3)` (no children, so return)

4. **Back to Second Call**: `solve(3, ans, 1)`
   - **Recursive Call**: `solve(nullptr, ans, 2)` (no left child for node `3`, so return)

5. **Back to First Call**: `solve(1, ans, 0)`
   - **Recursive Call**: `solve(2, ans, 1)` (move to the left child)

6. **Fourth Call to `solve(2, ans, 1)`**
   - `root = 2`, `lvl = 1`
   - `lvl` does not match `ans.size()` (already a node at level 1 from the right side), so do not add `2`
   - **Recursive Call**: `solve(5, ans, 2)` (move to the right child)

7. **Fifth Call to `solve(5, ans, 2)`**
   - `root = 5`, `lvl = 2`
   - `lvl` does not match `ans.size()` (already a node at level 2 from the right side), so do not add `5`
   - **Recursive Calls**: `solve(nullptr, ans, 3)` and `solve(nullptr, ans, 3)` (no children, so return)

8. **Back to Fourth Call**: `solve(2, ans, 1)`
   - **Recursive Call**: `solve(nullptr, ans, 2)` (no left child for node `2`, so return)

---

### Final State

After all recursive calls, the `ans` vector contains `[1, 3, 4]`, which represents the right-side view of the binary tree. 

### Final Output
- **Right-Side View**: `[1, 3, 4]`
