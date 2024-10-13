105. Construct Binary Tree from Preorder and Inorder Traversal
Medium
Topics
Companies
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.


Complexity
Time complexity: O(n)
Space complexity: O(n)

```cpp
class Solution {

private:
    int preorderIndex;
    unordered_map<int, int> mapping;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mapping.clear();
        for (int i = 0; i < inorder.size(); i++) {
            mapping[inorder[i]] = i;
        }

        preorderIndex = 0;
        return build(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mapping[rootVal];

        root->left = build(preorder, start, mid - 1);
        root->right = build(preorder, mid + 1, end);

        return root;
    }    
};
```

This solution reconstructs a binary tree using its **preorder** and **inorder** traversal arrays. The function uses recursion and a hash map for quick lookups to efficiently build the tree.

### Problem Explanation:
Given the **preorder** and **inorder** traversals of a binary tree, the goal is to rebuild the tree.

- **Preorder traversal** visits nodes in the order: root → left → right.
- **Inorder traversal** visits nodes in the order: left → root → right.

### Example:
For the given traversals:
- `preorder = [3, 9, 20, 15, 7]`
- `inorder = [9, 3, 15, 20, 7]`

The tree that needs to be reconstructed is:

```
      3
     / \
    9   20
       /  \
      15   7
```

### Line-by-Line Explanation:

```cpp
private:
    int preorderIndex;
    unordered_map<int, int> mapping;
```
- **Explanation**: Two private members are declared:
  - `preorderIndex`: This tracks the current index in the `preorder` array.
  - `mapping`: An unordered map (hash map) to store the index of each node value in the `inorder` array for fast lookup.

```cpp
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mapping.clear();
```
- **Explanation**: The `buildTree` function is the main public method, which initiates the tree-building process. First, it clears any previous values in the `mapping` to avoid issues from previous calls.

```cpp
        for (int i = 0; i < inorder.size(); i++) {
            mapping[inorder[i]] = i;
        }
```
- **Explanation**: This loop builds the `mapping` hash map. Each value from the `inorder` array is mapped to its index. This allows us to quickly find the index of any node in the `inorder` array later.

  For example:
  ```
  inorder = [9, 3, 15, 20, 7]
  mapping = {9: 0, 3: 1, 15: 2, 20: 3, 7: 4}
  ```

```cpp
        preorderIndex = 0;
```
- **Explanation**: We initialize `preorderIndex` to `0` because we always start building the tree from the first element in the `preorder` traversal (which is the root of the tree).

```cpp
        return build(preorder, 0, inorder.size() - 1);
    }
```
- **Explanation**: The `buildTree` function calls the recursive `build` method to construct the tree. It passes the entire `preorder` array and the range `[0, inorder.size() - 1]` for the `inorder` array, which represents the current subtree's boundaries.

---

### The `build` Function:

```cpp
private:
    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;
```
- **Explanation**: The `build` function is responsible for recursively constructing the tree. If the `start` index is greater than the `end` index, it means there are no nodes in this subtree, so we return `nullptr`.

```cpp
        int rootVal = preorder[preorderIndex++];
```
- **Explanation**: The current root node is found by using the current value from the `preorder` array at `preorderIndex`. We increment `preorderIndex` after picking the root value, as the next recursive call will use the next value for the next subtree.

  In the first call, `rootVal = preorder[0] = 3`.

```cpp
        TreeNode* root = new TreeNode(rootVal);
```
- **Explanation**: A new `TreeNode` is created for the root with the value `rootVal`.

```cpp
        int mid = mapping[rootVal];
```
- **Explanation**: Using the `mapping` hash map, we find the index `mid` of `rootVal` in the `inorder` array. This index splits the `inorder` array into two parts:
  - The left subtree is in the range `[start, mid - 1]`.
  - The right subtree is in the range `[mid + 1, end]`.

  For the example:
  - `rootVal = 3` and `mid = mapping[3] = 1`
  - Left subtree in `inorder`: `[9]` (from index `0` to `mid - 1`)
  - Right subtree in `inorder`: `[15, 20, 7]` (from index `mid + 1` to `4`)

```cpp
        root->left = build(preorder, start, mid - 1);
        root->right = build(preorder, mid + 1, end);
```
- **Explanation**: Recursively build the left and right subtrees:
  - For the left subtree, we pass the range `[start, mid - 1]` from the `inorder` array.
  - For the right subtree, we pass the range `[mid + 1, end]`.

  The recursion continues, building smaller subtrees until the entire tree is constructed.

```cpp
        return root;
    }    
```
- **Explanation**: Finally, return the root node once the left and right subtrees are attached.

---

### Dry Run:

Let's walk through the reconstruction process using the example:

#### Preorder: `[3, 9, 20, 15, 7]`
#### Inorder: `[9, 3, 15, 20, 7]`

1. **First Call**:
   - `preorderIndex = 0`, `rootVal = 3`
   - `mid = 1` (index of `3` in `inorder`)
   - Left subtree (inorder: `[9]`), Right subtree (inorder: `[15, 20, 7]`)
   
2. **Left Subtree of 3**:
   - `preorderIndex = 1`, `rootVal = 9`
   - `mid = 0` (index of `9` in `inorder`)
   - No left or right subtree (range invalid), so return `nullptr` for both.

3. **Right Subtree of 3**:
   - `preorderIndex = 2`, `rootVal = 20`
   - `mid = 3` (index of `20` in `inorder`)
   - Left subtree (inorder: `[15]`), Right subtree (inorder: `[7]`)
   
4. **Left Subtree of 20**:
   - `preorderIndex = 3`, `rootVal = 15`
   - `mid = 2` (index of `15` in `inorder`)
   - No left or right subtree, return `nullptr`.

5. **Right Subtree of 20**:
   - `preorderIndex = 4`, `rootVal = 7`
   - `mid = 4` (index of `7` in `inorder`)
   - No left or right subtree, return `nullptr`.

The final tree structure is:

```
      3
     / \
    9   20
       /  \
      15   7
```

### Time Complexity:
- **Time Complexity**: O(n), where `n` is the number of nodes in the tree. Each node is processed exactly once.
- **Space Complexity**: O(n), due to the space required for the recursion stack and the hash map.


why we aren't mapping preorder why inorder

We map the **inorder** traversal instead of the **preorder** traversal because of the specific properties of these two types of traversals in binary trees:

### 1. **Preorder Traversal Properties:**
- In **preorder** traversal, nodes are visited in the following order:
  1. **Root**
  2. **Left subtree**
  3. **Right subtree**
  
  The root node is always the first element of any subtree in the **preorder** array. Therefore, by iterating through the **preorder** array from left to right, we can naturally find the root node of each subtree in sequence without needing a map.

  - **Example:**
    - For `preorder = [3, 9, 20, 15, 7]`, `3` is the root of the whole tree, `9` is the root of the left subtree, and `20` is the root of the right subtree, and so on.
  
  Since we always know the root of the current subtree from the current index of the **preorder** array, there's no need to map the preorder values.

### 2. **Inorder Traversal Properties:**
- In **inorder** traversal, nodes are visited in the following order:
  1. **Left subtree**
  2. **Root**
  3. **Right subtree**

  The inorder traversal is crucial for determining the boundaries between the left and right subtrees of any node:
  - When you know the position of a node (i.e., the root) in the **inorder** array, you can immediately determine which part of the array corresponds to the **left subtree** and which part corresponds to the **right subtree**.

  Therefore, mapping the **inorder** array allows you to:
  - Quickly find the root’s position in **O(1)** time.
  - Easily divide the **inorder** array into left and right subtrees based on that position.

  - **Example:**
    - For `inorder = [9, 3, 15, 20, 7]`, once we know that the root `3` is at index `1`, we can split the array:
      - Left subtree (`inorder[0:0]`): `[9]`
      - Right subtree (`inorder[2:4]`): `[15, 20, 7]`

### Why Inorder and Not Preorder:
- **Preorder already gives the root** directly, so no mapping is needed for it.
- **Inorder** gives the exact positions of the left and right subtrees around the root, so mapping **inorder** is crucial to divide the tree efficiently.

### Summary of Key Points:
- **Preorder** naturally provides the root of the subtree in the current recursion step, so no map is needed for it.
- **Inorder** helps split the tree into left and right subtrees by locating the root’s position, so we map it for efficient lookup (O(1) time).

By combining the root discovery from **preorder** and the tree-splitting from **inorder**, the algorithm can efficiently reconstruct the binary tree.
