https://leetcode.com/problems/binary-tree-postorder-traversal/

To perform an **iterative postorder traversal** of a binary tree (left, right, root) using a stack, we need to modify the approach. Postorder traversal is trickier than preorder or inorder because we need to ensure the left and right children are processed before the root.

### Code for Iterative Postorder Traversal

Here's how you can implement it:

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        // Process nodes in modified order (root-right-left)
        while (!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);

            if (node->left) st1.push(node->left);
            if (node->right) st1.push(node->right);
        }

        // Collect nodes in postorder (left-right-root)
        while (!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }
};
```

Let's go through the dry run of the iterative postorder traversal code in more detail.

Given the binary tree:

```
      1
     / \
    2   3
   / \
  4   5
```

The expected postorder traversal (left, right, root) result is: `[4, 5, 2, 3, 1]`.

### Code Explanation Recap
The code uses two stacks:
1. `st1`: To push nodes in a modified order (root, right, left).
2. `st2`: To collect nodes in reverse order so that popping from `st2` gives the postorder traversal.

### Dry Run Step-by-Step

#### Initial State
- `st1 = []` (empty stack)
- `st2 = []` (empty stack)
- `ans = []` (empty result vector)

#### Step 1: Start with Root
- Push `root` (node `1`) onto `st1`.
- **`st1 = [1]`**

#### Step 2: Process Nodes in `st1`
1. **Pop from `st1`**:
   - Pop `1` from `st1`, push it onto `st2`.
   - **`st1 = []`**
   - **`st2 = [1]`**
   - Push `2` (left child) and `3` (right child) of `1` onto `st1`.
   - **`st1 = [2, 3]`**

2. **Pop from `st1`**:
   - Pop `3` from `st1`, push it onto `st2`.
   - **`st1 = [2]`**
   - **`st2 = [1, 3]`**
   - `3` has no children, so `st1` remains the same.

3. **Pop from `st1`**:
   - Pop `2` from `st1`, push it onto `st2`.
   - **`st1 = []`**
   - **`st2 = [1, 3, 2]`**
   - Push `4` (left child) and `5` (right child) of `2` onto `st1`.
   - **`st1 = [4, 5]`**

4. **Pop from `st1`**:
   - Pop `5` from `st1`, push it onto `st2`.
   - **`st1 = [4]`**
   - **`st2 = [1, 3, 2, 5]`**
   - `5` has no children, so `st1` remains the same.

5. **Pop from `st1`**:
   - Pop `4` from `st1`, push it onto `st2`.
   - **`st1 = []`**
   - **`st2 = [1, 3, 2, 5, 4]`**
   - `4` has no children, so `st1` remains empty.

#### Step 3: Process Nodes in `st2` to Get Postorder
- Pop each node from `st2` and add it to `ans`:
  - Pop `4` from `st2`, add to `ans`: **`ans = [4]`**
  - Pop `5` from `st2`, add to `ans`: **`ans = [4, 5]`**
  - Pop `2` from `st2`, add to `ans`: **`ans = [4, 5, 2]`**
  - Pop `3` from `st2`, add to `ans`: **`ans = [4, 5, 2, 3]`**
  - Pop `1` from `st2`, add to `ans`: **`ans = [4, 5, 2, 3, 1]`**

### Final Result
The `ans` vector now contains `[4, 5, 2, 3, 1]`, which is the correct postorder traversal of the tree.

For this iterative postorder traversal code using two stacks, here is the time and space complexity analysis:

### Time Complexity
- **Overall Time Complexity**: **O(n)**, where \( n \) is the number of nodes in the binary tree.
  - Each node is processed (visited, pushed, and popped) exactly twice — once in `st1` and once in `st2`.
  - Therefore, the overall time complexity is \( O(2n) \), which simplifies to **O(n)**.

### Space Complexity
- **Overall Space Complexity**: **O(n)**.
  - The space complexity comes from storing nodes in `st1` and `st2`.
  - In the worst case, both stacks together may hold all nodes in the tree, giving an **O(n)** space complexity.
  
So, the **overall time complexity** is **O(n)**, and the **overall space complexity** is **O(n)**.
