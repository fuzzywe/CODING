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

```cpp
class Solution {
public:
    unordered_map<int, int> mp;      // Stores the indices of elements in inorder traversal
    int postorderIndex;              // Tracks the current root element in postorder traversal

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        mp.clear();                  // Clear the map for reuse
        
        // Map elements of inorder array to their indices
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        
        postorderIndex = postorder.size() - 1;  // Start from the end of postorder (last element is the root)
        return build(postorder, 0, inorder.size() - 1);  // Begin recursive tree building
    }

    TreeNode* build(vector<int>& postorder, int start, int end) {
        // Base case: if there are no elements to construct the subtree
        if (start > end) return nullptr;

        // Get the current root value from postorder and decrement postorderIndex
        int rootVal = postorder[postorderIndex--];

        // Create the root node with this value
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of this root in inorder traversal to split left and right subtrees
        int mid = mp[rootVal];

        // Recursively build the right subtree first, since we're moving backwards in postorder
        root->right = build(postorder, mid + 1, end);
        
        // Recursively build the left subtree
        root->left = build(postorder, start, mid - 1);
        
        return root;  // Return the constructed subtree rooted at this node
    }
};

```

Let's go through a line-by-line dry run of the `buildTree` function and the recursive `build` function for constructing a binary tree from inorder and postorder traversals. I’ll also explain the concepts and the math behind why this approach works.

### Key Concept

The **postorder traversal** (`left -> right -> root`) gives us the last element as the root of the current subtree.
The **inorder traversal** (`left -> root -> right`) lets us find the left and right children relative to each root. By recursively choosing roots from `postorder` and using their positions in `inorder`, we can reconstruct the tree.

### Code Walkthrough with Explanation

Here's the code for reference, followed by a detailed dry run and explanation.

```cpp
class Solution {
public:
    unordered_map<int, int> mp;      // Stores the indices of elements in inorder traversal
    int postorderIndex;              // Tracks the current root element in postorder traversal

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        mp.clear();                  // Clear the map for reuse
        
        // Map elements of inorder array to their indices
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        
        postorderIndex = postorder.size() - 1;  // Start from the end of postorder (last element is the root)
        return build(postorder, 0, inorder.size() - 1);  // Begin recursive tree building
    }

    TreeNode* build(vector<int>& postorder, int start, int end) {
        // Base case: if there are no elements to construct the subtree
        if (start > end) return nullptr;

        // Get the current root value from postorder and decrement postorderIndex
        int rootVal = postorder[postorderIndex--];

        // Create the root node with this value
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of this root in inorder traversal to split left and right subtrees
        int mid = mp[rootVal];

        // Recursively build the right subtree first, since we're moving backwards in postorder
        root->right = build(postorder, mid + 1, end);
        
        // Recursively build the left subtree
        root->left = build(postorder, start, mid - 1);
        
        return root;  // Return the constructed subtree rooted at this node
    }
};
```

### Dry Run with Detailed Explanation

Let's go through a dry run with the example:

```cpp
inorder = [9, 3, 15, 20, 7];
postorder = [9, 15, 7, 20, 3];
```

#### Step 1: Initializing the Map

The `buildTree` function first fills the map `mp` with the indexes of each element in `inorder`:

```cpp
mp = {9: 0, 3: 1, 15: 2, 20: 3, 7: 4}
```

The map allows us to quickly locate the position of each node in the `inorder` traversal, which helps in dividing the array into left and right subtrees.

#### Step 2: Setting the Initial `postorderIndex`

We start from the end of `postorder`, as the last element is the root of the entire tree:

```cpp
postorderIndex = postorder.size() - 1 = 4
```

#### Step 3: Building the Tree with `build`

We call `build(postorder, 0, inorder.size() - 1)` to construct the tree.

---

### Recursive Calls and Explanation

Now let's see each recursive call in detail:

1. **First Call: `build(postorder, start=0, end=4)`**
   - `rootVal = postorder[4] = 3`
   - Create `root = new TreeNode(3)`, making `3` the root of the tree.
   - `mid = mp[3] = 1`, which splits `inorder` into `[9]` (left subtree) and `[15, 20, 7]` (right subtree).

2. **Construct Right Subtree of `3`: `build(postorder, start=2, end=4)`**
   - `rootVal = postorder[3] = 20`
   - Create `root = new TreeNode(20)`, making `20` the right child of `3`.
   - `mid = mp[20] = 3`, which splits `inorder` into `[15]` (left) and `[7]` (right).

3. **Construct Right Subtree of `20`: `build(postorder, start=4, end=4)`**
   - `rootVal = postorder[2] = 7`
   - Create `root = new TreeNode(7)`, making `7` the right child of `20`.
   - `mid = mp[7] = 4`, which splits `inorder` into no elements left and right, so both calls will return `nullptr`.

4. **Construct Left Subtree of `20`: `build(postorder, start=2, end=2)`**
   - `rootVal = postorder[1] = 15`
   - Create `root = new TreeNode(15)`, making `15` the left child of `20`.
   - `mid = mp[15] = 2`, which splits `inorder` into no elements left and right, so both calls will return `nullptr`.

5. **Construct Left Subtree of `3`: `build(postorder, start=0, end=0)`**
   - `rootVal = postorder[0] = 9`
   - Create `root = new TreeNode(9)`, making `9` the left child of `3`.
   - `mid = mp[9] = 0`, which splits `inorder` into no elements left and right, so both calls will return `nullptr`.

---

### Why This Works: The Math Behind It

1. **Postorder Traversal Order**: Since `postorder` goes `left -> right -> root`, we take each root from the end of `postorder`. Each `rootVal` picked divides `inorder` into left and right subtrees.

2. **Using Inorder for Split Points**: By finding each root’s position in `inorder`, we know exactly where left and right subtrees start and end:
   - For a root at index `mid` in `inorder`, elements from `start` to `mid - 1` are in the left subtree.
   - Elements from `mid + 1` to `end` are in the right subtree.

3. **Recursive Construction**: This recursive splitting continues until all nodes are processed, building subtrees bottom-up, from the leaf nodes to the root.

In this way, the combination of the `postorder` traversal for selecting roots and `inorder` traversal for structuring left and right children allows us to reconstruct the tree accurately.
