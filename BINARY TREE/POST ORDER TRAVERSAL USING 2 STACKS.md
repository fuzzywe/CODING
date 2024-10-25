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

---

POST ORDER TRAVERSAL USING ONE STACK

---
```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* lastVisited = nullptr;

        while (!st.empty() || root) {
            // Traverse to the leftmost node.
            while (root) {
                st.push(root);
                root = root->left;
            }

            TreeNode* node = st.top();

            // If right child is null or already processed, process the current node.
            if (!node->right || node->right == lastVisited) {
                ans.push_back(node->val);
                st.pop();
                lastVisited = node; // Mark this node as visited.
                root = nullptr; // Prevent going left again.
            } else {
                // If the right child exists and hasn't been processed, move to the right child.
                root = node->right;
            }
        }

        return ans;
    }
};
```
Let's go through a full dry run of this iterative postorder traversal code for a sample binary tree. Here’s the tree we’ll use:

```
      1
     / \
    2   3
   / \
  4   5
```

The expected postorder traversal for this tree is `[4, 5, 2, 3, 1]` (left-right-root). Let’s go through each line of the code with detailed explanations at each step.

### Code with Dry Run

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;                   // Result vector for storing the postorder traversal.
        stack<TreeNode*> st;               // Stack to help with the traversal.
        TreeNode* lastVisited = nullptr;   // Pointer to keep track of the last visited node.

        while (!st.empty() || root) {      // Continue until stack is empty and root is null.
            while (root) {                 // Traverse down the leftmost path.
                st.push(root);             // Push the current node to stack.
                root = root->left;         // Move to left child.
            }

            TreeNode* node = st.top();     // Peek the top node in the stack (current root).
            
            // If right child is null or already processed, process the current node.
            if (!node->right || node->right == lastVisited) {
                ans.push_back(node->val);  // Add current node’s value to result.
                st.pop();                  // Pop the current node from the stack.
                lastVisited = node;        // Mark this node as last visited.
                root = nullptr;            // Set root to null to avoid moving left again.
            } else {
                // If the right child exists and hasn't been processed, move to right child.
                root = node->right;        // Set root to the right child.
            }
        }

        return ans;                        // Return the result vector containing postorder traversal.
    }
};
```

### Step-by-Step Dry Run

#### Initial Setup
- **TreeNode definitions:**
  - `root` is the root node with value `1`.
  - `root.left` is node `2`.
  - `root.right` is node `3`.
  - `root.left.left` is node `4`.
  - `root.left.right` is node `5`.

#### Execution Flow

1. **Initialization:**
   - `ans = []` (empty vector for result).
   - `st = []` (empty stack).
   - `lastVisited = nullptr`.

#### Iteration 1
- **Outer `while` Loop**: `!st.empty() || root` is true (`root` is node `1`).
  - **Inner `while` Loop**: `root` is node `1`, not null.
    - `st.push(1)` → Stack: `[1]`.
    - `root = root->left` → `root` is now node `2`.
  - **Continue Inner `while`**: `root` is node `2`, not null.
    - `st.push(2)` → Stack: `[1, 2]`.
    - `root = root->left` → `root` is now node `4`.
  - **Continue Inner `while`**: `root` is node `4`, not null.
    - `st.push(4)` → Stack: `[1, 2, 4]`.
    - `root = root->left` → `root` is now `nullptr`.

#### Iteration 2
- **Outer `while` Loop**: `root` is `nullptr`, but `st` is not empty.
  - **Set `node = st.top()`** → `node` is `4`.
  - **Check**: `!node->right || node->right == lastVisited`:
    - `node->right` is `nullptr` (node `4` has no right child).
    - **Action**:
      - `ans.push_back(node->val)` → `ans = [4]`.
      - `st.pop()` → Stack: `[1, 2]`.
      - `lastVisited = node` → `lastVisited` is node `4`.
      - `root = nullptr`.

#### Iteration 3
- **Outer `while` Loop**: `!st.empty() || root` is true.
  - **Set `node = st.top()`** → `node` is `2`.
  - **Check**: `!node->right || node->right == lastVisited`:
    - `node->right` is node `5` (right child exists and hasn’t been visited).
    - **Action**: `root = node->right` → `root` is now node `5`.

#### Iteration 4
- **Outer `while` Loop**: `!st.empty() || root` is true.
  - **Inner `while` Loop**: `root` is node `5`, not null.
    - `st.push(5)` → Stack: `[1, 2, 5]`.
    - `root = root->left` → `root` is now `nullptr`.

#### Iteration 5
- **Outer `while` Loop**: `root` is `nullptr`, but `st` is not empty.
  - **Set `node = st.top()`** → `node` is `5`.
  - **Check**: `!node->right || node->right == lastVisited`:
    - `node->right` is `nullptr`.
    - **Action**:
      - `ans.push_back(node->val)` → `ans = [4, 5]`.
      - `st.pop()` → Stack: `[1, 2]`.
      - `lastVisited = node` → `lastVisited` is node `5`.
      - `root = nullptr`.

#### Iteration 6
- **Outer `while` Loop**: `!st.empty() || root` is true.
  - **Set `node = st.top()`** → `node` is `2`.
  - **Check**: `!node->right || node->right == lastVisited`:
    - `node->right` is node `5` (which is `lastVisited`).
    - **Action**:
      - `ans.push_back(node->val)` → `ans = [4, 5, 2]`.
      - `st.pop()` → Stack: `[1]`.
      - `lastVisited = node` → `lastVisited` is node `2`.
      - `root = nullptr`.

#### Iteration 7
- **Outer `while` Loop**: `!st.empty() || root` is true.
  - **Set `node = st.top()`** → `node` is `1`.
  - **Check**: `!node->right || node->right == lastVisited`:
    - `node->right` is node `3` (right child exists and hasn’t been visited).
    - **Action**: `root = node->right` → `root` is now node `3`.

#### Iteration 8
- **Outer `while` Loop**: `!st.empty() || root` is true.
  - **Inner `while` Loop**: `root` is node `3`, not null.
    - `st.push(3)` → Stack: `[1, 3]`.
    - `root = root->left` → `root` is now `nullptr`.

#### Iteration 9
- **Outer `while` Loop**: `root` is `nullptr`, but `st` is not empty.
  - **Set `node = st.top()`** → `node` is `3`.
  - **Check**: `!node->right || node->right == lastVisited`:
    - `node->right` is `nullptr`.
    - **Action**:
      - `ans.push_back(node->val)` → `ans = [4, 5, 2, 3]`.
      - `st.pop()` → Stack: `[1]`.
      - `lastVisited = node` → `lastVisited` is node `3`.
      - `root = nullptr`.

#### Iteration 10
- **Outer `while` Loop**: `!st.empty() || root` is true.
  - **Set `node = st.top()`** → `node` is `1`.
  - **Check**: `!node->right || node->right == lastVisited`:
    - `node->right` is node `3` (which is `lastVisited`).
    - **Action**:
      - `ans.push_back(node->val)` → `ans = [4, 5, 2, 3, 1]`.
      - `st.pop()` → Stack: `[]`.
      - `lastVisited = node` → `lastVisited` is node `1`.
      - `root = nullptr`.

#### End
- **Return**: `ans = [4, 5, 2, 3, 1]`.

This completes the postorder traversal: **`[4, 5, 2, 3, 1]`**.
