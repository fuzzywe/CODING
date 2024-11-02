105. Construct Binary Tree from Preorder and Inorder Traversal

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:

![image](https://github.com/user-attachments/assets/ff4269ba-0c9c-4426-ada7-e95695bdfc29)

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]

To construct a binary tree from **preorder** and **inorder** traversal arrays, we use the following approach:

1. **Preorder traversal** provides the root nodes in sequence, i.e., the first element in the preorder array is always the root of the tree (or subtree).
2. **Inorder traversal** provides the left and right subtrees relative to each root node. For any root node, elements to the left of it in the inorder array are part of the left subtree, and elements to the right are part of the right subtree.

### Algorithm to Build the Tree

1. Start with the root node as the first element of the preorder traversal.
2. Locate this root in the inorder traversal; this divides the tree into left and right subtrees in the inorder array.
3. Recursively apply this process for left and right subtrees using slices of preorder and inorder arrays.

Here’s the code implementation:

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int preIndex; // To keep track of the current root in preorder traversal

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex = 0; // Start from the first element in preorder
        return build(preorder, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
        // Base case: if there are no elements to construct the subtree
        if (inStart > inEnd) {
            return nullptr;
        }

        // Get the root value from the preorder traversal and increment the index
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal); // Create the root node

        // Find the index of the root in the inorder traversal
        int rootIndex = inStart;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }

        // Recursively build the left and right subtrees
        root->left = build(preorder, inorder, inStart, rootIndex - 1);
        root->right = build(preorder, inorder, rootIndex + 1, inEnd);

        return root;
    }
};
```

### Dry Run and Visual Explanation

Let's go through this code line-by-line with an example.

**Example Input:**
```cpp
preorder = {3, 9, 20, 15, 7};
inorder = {9, 3, 15, 20, 7};
```

**Goal:** Construct the tree based on the given traversals.

---

### Step-by-Step Construction

1. **Initialize** `preIndex = 0` (pointing to the first element in `preorder`).

2. **Root Node `3`**
   - `preorder[preIndex] = 3`, so `3` is the root.
   - Increment `preIndex` to 1.
   - Locate `3` in `inorder` at index 1. Elements to the left (`{9}`) are part of the left subtree, and elements to the right (`{15, 20, 7}`) are part of the right subtree.

   **Tree Structure:**
   ```
       3
      / \
   [left] [right]
   ```

3. **Left Subtree of `3` (Root Node `9`)**
   - `preorder[preIndex] = 9`, so `9` is the left child of `3`.
   - Increment `preIndex` to 2.
   - Locate `9` in `inorder` at index 0. There are no elements on either side, so both left and right subtrees are `nullptr`.

   **Tree Structure:**
   ```
       3
      / \
     9   [right]
   ```

4. **Right Subtree of `3` (Root Node `20`)**
   - `preorder[preIndex] = 20`, so `20` is the right child of `3`.
   - Increment `preIndex` to 3.
   - Locate `20` in `inorder` at index 3. Elements to the left (`{15}`) form the left subtree, and elements to the right (`{7}`) form the right subtree.

   **Tree Structure:**
   ```
       3
      / \
     9   20
        /  \
      [left] [right]
   ```

5. **Left Subtree of `20` (Root Node `15`)**
   - `preorder[preIndex] = 15`, so `15` is the left child of `20`.
   - Increment `preIndex` to 4.
   - Locate `15` in `inorder` at index 2. There are no elements on either side, so both left and right subtrees are `nullptr`.

   **Tree Structure:**
   ```
       3
      / \
     9   20
        /  \
       15   [right]
   ```

6. **Right Subtree of `20` (Root Node `7`)**
   - `preorder[preIndex] = 7`, so `7` is the right child of `20`.
   - Increment `preIndex` to 5 (end of `preorder` array).
   - Locate `7` in `inorder` at index 4. There are no elements on either side, so both left and right subtrees are `nullptr`.

   **Final Tree Structure:**
   ```
       3
      / \
     9   20
        /  \
       15   7
   ```

### Final Tree Representation

The final binary tree structure from the given `preorder` and `inorder` arrays is:

```
       3
      / \
     9   20
        /  \
       15   7
```

This completes the tree construction using the `preorder` and `inorder` traversals. Let me know if you'd like any additional clarification!
