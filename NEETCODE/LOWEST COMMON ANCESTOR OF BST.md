235. Lowest Common Ancestor of a Binary Search Tree
Medium
Topics
Companies
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = min(p->val, q->val);
        int large = max(p->val, q->val);
        while (root != nullptr) {
            if (root->val > large) // p, q belong to the left subtree
                root = root->left;
            else if (root->val < small) // p, q belong to the right subtree
                root = root->right;
            else // Now, small <= root.val <= large -> This root is the LCA between p and q
                return root;
        }
        return nullptr;
    }
};

```
Let’s go step by step, providing a **dry run** of the code and **explaining each line** for the given function that finds the **Lowest Common Ancestor (LCA)** in a Binary Search Tree (BST).

### Problem Overview:
Given a binary search tree (BST), we need to find the **Lowest Common Ancestor (LCA)** of two nodes `p` and `q`. In a BST:
- The left child is always smaller than the parent.
- The right child is always larger than the parent.
The LCA of two nodes is the deepest node in the tree that is an ancestor of both `p` and `q`.

### Code Explanation & Dry Run:

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
```
- **Line 1-3**: This is the function definition. It accepts three parameters:
  - `root`: The root node of the BST.
  - `p`: The first target node for which we need to find the LCA.
  - `q`: The second target node.
  - The function will return a pointer to the **Lowest Common Ancestor** node.

---

```cpp
int small = min(p->val, q->val);
int large = max(p->val, q->val);
```
- **Line 4-5**: We find the smaller and larger values between `p` and `q`.
  - `small`: The smaller of `p->val` and `q->val`.
  - `large`: The larger of `p->val` and `q->val`.

**Dry Run**: 
- If `p->val = 2` and `q->val = 8`, then:
  - `small = 2`
  - `large = 8`

---

```cpp
while (root != nullptr) {
```
- **Line 6**: We start a loop that continues until the `root` becomes `nullptr`. This ensures we traverse through the tree starting from the root node and looking for the LCA of `p` and `q`.

---

```cpp
if (root->val > large) // p, q belong to the left subtree
    root = root->left;
```
- **Line 7-8**: If the current `root` value is larger than `large` (both `p` and `q` are smaller than the current node), we move the `root` to its left child. This is because both `p` and `q` must be in the left subtree.
  
**Dry Run**:
- Suppose we are at `root = 6` and:
  - `large = 8`, `small = 2`
  - Since `6` is not greater than `large (8)`, this condition is false. We do not move to the left.

---

```cpp
else if (root->val < small) // p, q belong to the right subtree
    root = root->right;
```
- **Line 9-10**: If the current `root` value is smaller than `small` (both `p` and `q` are larger than the current node), we move the `root` to its right child. This is because both `p` and `q` must be in the right subtree.

**Dry Run**:
- At `root = 6`:
  - `small = 2`, `large = 8`
  - Since `6` is greater than `small (2)` and smaller than `large (8)`, this condition is false. We do not move to the right.

---

```cpp
else // Now, small <= root->val <= large -> This root is the LCA between p and q
    return root;
```
- **Line 11-12**: If the current `root` value lies between `small` and `large` (inclusive), then the current node is the **Lowest Common Ancestor (LCA)** of `p` and `q`.
  - We return this `root` node because it is the deepest node that has both `p` and `q` as descendants.

**Dry Run**:
- At `root = 6`:
  - `small = 2`, `large = 8`
  - Since `2 <= 6 <= 8`, the current node `6` is the LCA of `p` and `q`.
  - We return `root = 6` as the LCA.

---

```cpp
return nullptr;
```
- **Line 13**: This is the fallback return in case the `root` is `nullptr` (which means no LCA was found). However, in the context of a valid BST and valid `p` and `q` inputs, we should never reach this line.

---

### Full Dry Run:

Let’s perform a dry run of the code for the following BST:

```
         6
       /   \
      2     8
     / \   / \
    0   4 7   9
       / \
      3   5
```

Given nodes `p = 2` and `q = 8`, we want to find the **Lowest Common Ancestor (LCA)**.

1. **Initialization**:
   - `small = min(2, 8) = 2`
   - `large = max(2, 8) = 8`
   
2. **First Iteration**:
   - **Current `root = 6`**.
   - Condition check:
     - `root->val = 6`, `small = 2`, `large = 8`
     - Since `2 <= 6 <= 8`, `root = 6` is the LCA.
   - **Return `root = 6`**.

The output is `6`, which is the **Lowest Common Ancestor** of nodes `2` and `8`.

---

### Time Complexity:

- **O(H)**: The time complexity is proportional to the height of the tree `H`.
  - In the best case, the tree is balanced, and the height is `log N`, where `N` is the number of nodes in the tree.
  - In the worst case, the tree is completely skewed (like a linked list), and the height becomes `N`.

### Space Complexity:

- **O(1)**: The solution uses constant space (we are only using a few integer variables).
  - No additional space is required except for the input and a few variables for comparisons.
  - Note: In a recursive approach, the space complexity would be `O(H)` due to the recursion stack, but this is an iterative approach.
