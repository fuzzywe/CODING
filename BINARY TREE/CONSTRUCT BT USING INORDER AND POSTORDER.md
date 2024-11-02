106. Construct Binary Tree from Inorder and Postorder Traversal

https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:
![image](https://github.com/user-attachments/assets/da53b059-88d2-406e-9250-eb61fbdc2128)


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]




Let's go through a line-by-line dry run of the `buildTree` function and the recursive `build` function for constructing a binary tree from inorder and postorder traversals. I’ll also explain the concepts and the math behind why this approach works.

### Key Concept

The **postorder traversal** (`left -> right -> root`) gives us the last element as the root of the current subtree.
The **inorder traversal** (`left -> root -> right`) lets us find the left and right children relative to each root. By recursively choosing roots from `postorder` and using their positions in `inorder`, we can reconstruct the tree.

### Code Walkthrough with Explanation

Here's the code for reference, followed by a detailed dry run and explanation.

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
    int postIndex; // To keep track of the current root in postorder traversal

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1; // Start from the last element in postorder
        return build(inorder, 0, inorder.size() - 1, postorder);
    }

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder) {
        // Base case: if the start index is greater than the end index
        if (inStart > inEnd) {
            return nullptr;
        }

        // Get the root value from the postorder traversal and decrement the index
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal); // Create the root node

        // Find the index of the root in the inorder traversal
        int rootIndex = inStart;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }

        // Recursively build the right and left subtrees
        root->right = build(inorder, rootIndex + 1, inEnd, postorder);
        root->left = build(inorder, inStart, rootIndex - 1, postorder);

        return root;
    }
};

```

Let's walk through the code line-by-line, explaining each step while building the tree visually. We’ll construct the tree incrementally with each call, updating its structure as we go along.

### Code and Dry Run

**Initial Input:**
```cpp
inorder = {9, 3, 15, 20, 7}
postorder = {9, 15, 7, 20, 3}
```

**Objective:** Build the tree using the `inorder` and `postorder` traversals.

---

### Step 1: `buildTree` Function

```cpp
postIndex = postorder.size() - 1;
```

- Initialize `postIndex` to the last index of `postorder`, which is `4`.
- `postorder[4]` is `3`, indicating that `3` is the root of the tree.

### Step 2: `build` Function (Root Node Creation)

1. **First call to `build`**
   ```cpp
   return build(inorder, 0, inorder.size() - 1, postorder);
   ```
   - We start with the entire range of `inorder`: `inStart = 0`, `inEnd = 4`.

---

#### Building Root Node `3`

1. **Get Root Value**
   ```cpp
   int rootVal = postorder[postIndex--];  // rootVal = 3
   TreeNode* root = new TreeNode(rootVal);
   ```
   - `postIndex = 4`, so `rootVal = postorder[4] = 3`.
   - A new `TreeNode` is created with value `3`.

   **Tree Structure:**
   ```
       3
   ```

2. **Find Root Index in `inorder`**
   ```cpp
   rootIndex = 1;  // Position of 3 in inorder array
   ```
   - `3` is at `rootIndex = 1` in `inorder`.

3. **Recursive Calls to Build Subtrees**
   - **Right Subtree:** `root->right = build(inorder, 2, 4, postorder);`
   - **Left Subtree:** `root->left = build(inorder, 0, 0, postorder);`

---

### Step 3: Building Right Subtree of `3` (Root Node `20`)

1. **Get Root Value**
   ```cpp
   rootVal = postorder[postIndex--];  // rootVal = 20
   TreeNode* root = new TreeNode(rootVal);
   ```
   - `postIndex = 3`, so `rootVal = postorder[3] = 20`.
   - A new `TreeNode` with value `20` becomes the right child of `3`.

   **Tree Structure:**
   ```
       3
        \
        20
   ```

2. **Find Root Index in `inorder`**
   ```cpp
   rootIndex = 3;  // Position of 20 in inorder array
   ```
   - `20` is at `rootIndex = 3` in `inorder`.

3. **Recursive Calls to Build Subtrees of `20`**
   - **Right Subtree:** `root->right = build(inorder, 4, 4, postorder);`
   - **Left Subtree:** `root->left = build(inorder, 2, 2, postorder);`

---

### Step 4: Building Right Subtree of `20` (Root Node `7`)

1. **Get Root Value**
   ```cpp
   rootVal = postorder[postIndex--];  // rootVal = 7
   TreeNode* root = new TreeNode(rootVal);
   ```
   - `postIndex = 2`, so `rootVal = postorder[2] = 7`.
   - A new `TreeNode` with value `7` becomes the right child of `20`.

   **Tree Structure:**
   ```
       3
        \
        20
          \
           7
   ```

2. **Find Root Index in `inorder`**
   ```cpp
   rootIndex = 4;  // Position of 7 in inorder array
   ```
   - `7` is at `rootIndex = 4` in `inorder`.

3. **Recursive Calls to Build Subtrees of `7`**
   - Both left and right subtree calls return `nullptr` as the base condition `inStart > inEnd` is met.

   **Tree Structure:**
   ```
       3
        \
        20
          \
           7
   ```

---

### Step 5: Building Left Subtree of `20` (Root Node `15`)

1. **Get Root Value**
   ```cpp
   rootVal = postorder[postIndex--];  // rootVal = 15
   TreeNode* root = new TreeNode(rootVal);
   ```
   - `postIndex = 1`, so `rootVal = postorder[1] = 15`.
   - A new `TreeNode` with value `15` becomes the left child of `20`.

   **Tree Structure:**
   ```
       3
        \
        20
       /  \
     15    7
   ```

2. **Find Root Index in `inorder`**
   ```cpp
   rootIndex = 2;  // Position of 15 in inorder array
   ```
   - `15` is at `rootIndex = 2` in `inorder`.

3. **Recursive Calls to Build Subtrees of `15`**
   - Both left and right subtree calls return `nullptr`.

   **Tree Structure:**
   ```
       3
        \
        20
       /  \
     15    7
   ```

---

### Step 6: Building Left Subtree of `3` (Root Node `9`)

1. **Get Root Value**
   ```cpp
   rootVal = postorder[postIndex--];  // rootVal = 9
   TreeNode* root = new TreeNode(rootVal);
   ```
   - `postIndex = 0`, so `rootVal = postorder[0] = 9`.
   - A new `TreeNode` with value `9` becomes the left child of `3`.

   **Tree Structure:**
   ```
       3
      / \
     9   20
        /  \
      15    7
   ```

2. **Find Root Index in `inorder`**
   - `9` is at `rootIndex = 0` in `inorder`.

3. **Recursive Calls to Build Subtrees of `9`**
   - Both left and right subtree calls return `nullptr`.

---

### Final Tree Structure

The final tree is:

```
       3
      / \
     9  20
       /  \
      15   7
```

This completes the dry run with each line building up the tree step-by-step. Let me know if you'd like more details on any specific part!
