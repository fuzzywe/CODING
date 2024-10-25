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

### Explanation and Dry Run

The algorithm uses two stacks, `st1` and `st2`, to simulate the postorder traversal iteratively. Here’s the breakdown:

1. **Initialize**:
   - `ans` is an empty vector to store the result.
   - `st1` is a stack to process nodes in a modified order (root, right, left).
   - `st2` is a stack to collect nodes in postorder (left, right, root).

2. **First Stack (`st1`) Operations**:
   - Push the `root` node onto `st1`.
   - **Loop**: While `st1` is not empty:
     - Pop a node from `st1` (starting with the root).
     - Push this node onto `st2` (to reverse the order later).
     - If the node has a left child, push it to `st1`.
     - If the node has a right child, push it to `st1`.

3. **Second Stack (`st2`) Operations**:
   - After the first loop, `st2` has nodes in postorder traversal order.
   - Pop each node from `st2` and add it to `ans`.

### Dry Run Example

Consider this binary tree:

```
      1
     / \
    2   3
   / \
  4   5
```

- **Initialization**:
  - `st1 = [1]`, `st2 = []`, `ans = []`

- **First Loop (Processing `st1`)**:
  1. Pop `1` from `st1`, push it to `st2`: `st2 = [1]`
     - Push `2` (left child) and `3` (right child) to `st1`: `st1 = [2, 3]`
  2. Pop `3` from `st1`, push it to `st2`: `st2 = [1, 3]`
     - `3` has no children, so `st1` remains `[2]`
  3. Pop `2` from `st1`, push it to `st2`: `st2 = [1, 3, 2]`
     - Push `4` (left child) and `5` (right child) to `st1`: `st1 = [4, 5]`
  4. Pop `5` from `st1`, push it to `st2`: `st2 = [1, 3, 2, 5]`
  5. Pop `4` from `st1`, push it to `st2`: `st2 = [1, 3, 2, 5, 4]`

- **Second Loop (Processing `st2`)**:
  - Pop each element from `st2` into `ans`:
    - `ans = [4, 5, 2, 3, 1]`

The final `ans` list `[4, 5, 2, 3, 1]` represents the postorder traversal of the tree.
