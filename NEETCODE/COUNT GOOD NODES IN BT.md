1448. Count Good Nodes in Binary Tree
Solved
Medium
Topics
Companies
Hint
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

 

Example 1:



Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
Example 2:



Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
Example 3:

Input: root = [1]
Output: 1
Explanation: Root is considered as good.

```cpp
class Solution {
public:
    int dfs(TreeNode* node, int _max) {
        if (node && node->val > _max)
            _max = node->val;
        return node ? (node->val == _max)+dfs(node->left, _max)+dfs(node->right, _max) : 0;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, -10000);
    }
};
```

Let's go step by step through the code you provided and explain each line with a clear example and visuals to make it more appealing.

### Problem: Count the Number of "Good" Nodes in a Binary Tree

**Definition of a "Good" Node:**
- A node is considered "good" if, on the path from the root to the node, there is no node with a value greater than this node's value.

---

### The Code:

```cpp
class Solution {
public:
    int dfs(TreeNode* node, int _max) {
        if (node && node->val > _max)
            _max = node->val;
        return node ? (node->val == _max) + dfs(node->left, _max) + dfs(node->right, _max) : 0;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, -10000);
    }
};
```

---

### Example Tree

We will use the following binary tree as our example:

```
        3
       / \
      1   4
     /   / \
    3   1   5
```

### 1. **`goodNodes(TreeNode* root)` function**:

This is the main function that starts the process of counting "good" nodes.

- **Initial Call**: `goodNodes(root)` is called with the root of the tree (`3`) as input.
- **Start the DFS**: It calls the helper function `dfs` starting from the root node with an initial value of `_max = -10000`. We use a very small number here because any node's value will be larger than this value, making sure the root is always counted as a "good" node.

**Visualization**:
- We start the DFS from the root (3).
- `_max = -10000` initially.
- First, we explore the left subtree, then the right subtree.

### 2. **`dfs(TreeNode* node, int _max)` function**:

This is the depth-first search (DFS) function that traverses the tree and counts "good" nodes.

#### Line-by-Line Breakdown:

#### 1. `if (node && node->val > _max)`
- This line checks if the node exists and whether its value is greater than `_max`.
- If this condition is true, it means that the current node is the largest value we've encountered on this path, and we should update `_max` to this node's value.

**Example**: At the root node (3):
- `_max = -10000`.
- `3 > -10000`, so the current node is a "good" node, and `_max` is updated to 3.

#### 2. `_max = node->val;`
- If the node’s value is larger than `_max`, update `_max`.

**Example**: The value of `_max` becomes 3 when the root node is processed.

#### 3. `return node ? (node->val == _max) + dfs(node->left, _max) + dfs(node->right, _max) : 0;`
- If the node exists, this line does three things:
  - Checks if the current node is a "good" node (`node->val == _max`). If it is, add 1 to the count.
  - Calls the `dfs` function on the left child with the updated `_max`.
  - Calls the `dfs` function on the right child with the updated `_max`.

- If the node is `nullptr`, it returns `0`, which means that there are no nodes to process.

### **Step-by-Step Example Dry Run**:

1. **Start at Root (3)**:
   - `_max = -10000`, `3 > -10000`, so this node is a "good" node.
   - Update `_max` to 3.
   - Continue DFS to the left child (1) and right child (4).

2. **Move to Left Child (1)**:
   - `_max = 3`, `1 < 3`, so this node is **not** a "good" node.
   - No update to `_max`.
   - Continue DFS to the left child (3) and no right child (since it's `nullptr`).

3. **Move to Left Grandchild (3)**:
   - `_max = 3`, `3 == 3`, so this node is a "good" node.
   - No change to `_max`.
   - No children to explore, so backtrack to the previous node (1).

4. **Move to Right Child (4)**:
   - `_max = 3`, `4 > 3`, so this node is a "good" node.
   - Update `_max` to 4.
   - Continue DFS to the left child (1) and right child (5).

5. **Move to Left Grandchild (1)**:
   - `_max = 4`, `1 < 4`, so this node is **not** a "good" node.
   - No update to `_max`.
   - No children to explore, so backtrack to the previous node (4).

6. **Move to Right Grandchild (5)**:
   - `_max = 4`, `5 > 4`, so this node is a "good" node.
   - Update `_max` to 5.
   - No children to explore, so backtrack to the previous node (4).

### Final Count of Good Nodes:
- **Good Nodes**: 4 (Root 3, Left Grandchild 3, Right Child 4, Right Grandchild 5)

### Visual Summary

1. **Root (3)**:
   - **Good Node**: Yes (since `3 > -10000`).
   - **_max updated**: 3.

2. **Left Subtree**:
   - Node (1): Not a good node (`1 < 3`).
   - Left Grandchild (3): Good node (`3 == 3`).

3. **Right Subtree**:
   - Node (4): Good node (`4 > 3`).
   - Left Grandchild (1): Not a good node (`1 < 4`).
   - Right Grandchild (5): Good node (`5 > 4`).

---

### Conclusion:

The algorithm uses DFS to traverse the binary tree. At each node, it checks if the node's value is greater than or equal to the maximum value encountered so far along the path from the root. The function returns the total count of "good" nodes by adding 1 for each good node and recursing on the left and right children.

