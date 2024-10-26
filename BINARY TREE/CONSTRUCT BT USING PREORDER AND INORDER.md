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

```cpp
class Solution {
public:
unordered_map<int,int>mp;
int preorderIndex;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mp.clear();
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;

        }
        int preorderIndex=0;
        return build(preorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder,int start,int end){
        if(start>end) return nullptr;
        int rootval= preorder[preorderIndex++];
        TreeNode* root= new TreeNode(rootval);
        int mid = mp[rootval];
        root->left= build(preorder,start,mid-1);
        root->right= build(preorder,mid+1,end);
        return root;

    }
};
```
Let's go through this `buildTree` function and `build` helper function line by line, explaining each line's purpose, followed by a dry run on a sample input.

### Code Explanation

```cpp
class Solution {
public:
    unordered_map<int,int> mp;  // Stores indices of elements in the inorder traversal
    int preorderIndex;          // Tracks the current root element in the preorder traversal

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mp.clear();             // Clear any previous data in the map
        
        // Map elements of inorder array to their indices for quick access
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        
        preorderIndex = 0;      // Initialize the preorder index to start from the root element
        return build(preorder, 0, inorder.size() - 1);  // Begin recursive tree building
    }

    TreeNode* build(vector<int>& preorder, int start, int end) {
        // Base case: If the current subtree range is invalid, return nullptr
        if (start > end) return nullptr;

        // Get the current root value from preorder and increment preorder index
        int rootval = preorder[preorderIndex++];
        
        // Create a new tree node with this root value
        TreeNode* root = new TreeNode(rootval);
        
        // Find the index of this root value in the inorder traversal
        int mid = mp[rootval];

        // Recursively build the left subtree with the range left of the root in inorder
        root->left = build(preorder, start, mid - 1);
        
        // Recursively build the right subtree with the range right of the root in inorder
        root->right = build(preorder, mid + 1, end);
        
        return root; // Return the current subtree rooted at this node
    }
};
```

---

### Example Input for Dry Run

Let's take the following input arrays:

```cpp
preorder = [3, 9, 20, 15, 7];
inorder = [9, 3, 15, 20, 7];
```

The tree to be constructed is:

```
        3
       / \
      9   20
         /  \
        15   7
```

### Dry Run

1. **`buildTree` Function Call**
    - **Input**: `preorder = [3, 9, 20, 15, 7]`, `inorder = [9, 3, 15, 20, 7]`.
    - **Steps**:
      - `mp.clear()`: Clears any previous entries in the map.
      - Loop to populate `mp`:
        - `i = 0`: `mp[9] = 0`
        - `i = 1`: `mp[3] = 1`
        - `i = 2`: `mp[15] = 2`
        - `i = 3`: `mp[20] = 3`
        - `i = 4`: `mp[7] = 4`
      - `preorderIndex = 0`: Initialize `preorderIndex` to start at the beginning of `preorder`.
      - Call `build(preorder, 0, 4)`.

2. **First Call to `build(preorder, 0, 4)`**
    - **Purpose**: This call is to construct the entire tree.
    - **Steps**:
      - **Base Case**: `start (0) <= end (4)`, so we proceed.
      - `rootval = preorder[0] = 3`: Get the current root value, and increment `preorderIndex` to `1`.
      - `root = new TreeNode(3)`: Create a new node with value `3`.
      - `mid = mp[3] = 1`: Find index of `3` in `inorder`.
      - Call `build(preorder, 0, 0)` to build the left subtree of `3`.
    
3. **Second Call to `build(preorder, 0, 0)`**
    - **Purpose**: To construct the left subtree of node `3`.
    - **Steps**:
      - **Base Case**: `start (0) <= end (0)`, so we proceed.
      - `rootval = preorder[1] = 9`: Get the current root value, and increment `preorderIndex` to `2`.
      - `root = new TreeNode(9)`: Create a new node with value `9`.
      - `mid = mp[9] = 0`: Find index of `9` in `inorder`.
      - Call `build(preorder, 0, -1)` to build the left subtree of `9`.

4. **Third Call to `build(preorder, 0, -1)`**
    - **Purpose**: To construct the left subtree of node `9`.
    - **Steps**:
      - **Base Case**: `start (0) > end (-1)`, so we return `nullptr`.
    
5. **Back to Second Call: `build(preorder, 0, 0)`**
    - **Purpose**: Now construct the right subtree of node `9`.
    - Call `build(preorder, 1, 0)`.

6. **Fourth Call to `build(preorder, 1, 0)`**
    - **Purpose**: To construct the right subtree of node `9`.
    - **Steps**:
      - **Base Case**: `start (1) > end (0)`, so we return `nullptr`.

7. **Back to First Call: `build(preorder, 0, 4)`**
    - **Purpose**: Now construct the right subtree of node `3`.
    - Call `build(preorder, 2, 4)`.

8. **Fifth Call to `build(preorder, 2, 4)`**
    - **Purpose**: To construct the right subtree of node `3`.
    - **Steps**:
      - **Base Case**: `start (2) <= end (4)`, so we proceed.
      - `rootval = preorder[2] = 20`: Get the current root value, and increment `preorderIndex` to `3`.
      - `root = new TreeNode(20)`: Create a new node with value `20`.
      - `mid = mp[20] = 3`: Find index of `20` in `inorder`.
      - Call `build(preorder, 2, 2)` to build the left subtree of `20`.

9. **Sixth Call to `build(preorder, 2, 2)`**
    - **Purpose**: To construct the left subtree of node `20`.
    - **Steps**:
      - **Base Case**: `start (2) <= end (2)`, so we proceed.
      - `rootval = preorder[3] = 15`: Get the current root value, and increment `preorderIndex` to `4`.
      - `root = new TreeNode(15)`: Create a new node with value `15`.
      - `mid = mp[15] = 2`: Find index of `15` in `inorder`.
      - Call `build(preorder, 2, 1)` to build the left subtree of `15`.

10. **Seventh Call to `build(preorder, 2, 1)`**
    - **Purpose**: To construct the left subtree of node `15`.
    - **Steps**:
      - **Base Case**: `start (2) > end (1)`, so we return `nullptr`.

11. **Back to Sixth Call: `build(preorder, 2, 2)`**
    - **Purpose**: Now construct the right subtree of node `15`.
    - Call `build(preorder, 3, 2)`.

12. **Eighth Call to `build(preorder, 3, 2)`**
    - **Purpose**: To construct the right subtree of node `15`.
    - **Steps**:
      - **Base Case**: `start (3) > end (2)`, so we return `nullptr`.

13. **Back to Fifth Call: `build(preorder, 2, 4)`**
    - **Purpose**: Now construct the right subtree of node `20`.
    - Call `build(preorder, 4, 4)`.

14. **Ninth Call to `build(preorder, 4, 4)`**
    - **Purpose**: To construct the right subtree of node `20`.
    - **Steps**:
      - **Base Case**: `start (4) <= end (4)`, so we proceed.
      - `rootval = preorder[4] = 7`: Get the current root value.
      - `root = new TreeNode(7)`: Create a new node with value `7`.
      - `mid = mp[7] = 4`: Find index of `7` in `inorder`.
      - Call `build(preorder, 4, 3)` for the left subtree of `7`.

15. **Tenth Call to `build(preorder, 4, 3)`**
    - **Base Case**: `start (4) > end (3)`, so return `nullptr`.

16. **Back to Ninth Call: `build(preorder, 4, 4)`**
    - **Purpose**: Now construct the right subtree

 of node `7`.
    - Call `build(preorder, 5, 4)`.

17. **Eleventh Call to `build(preorder, 5, 4)`**
    - **Base Case**: `start (5) > end (4)`, so return `nullptr`.

All nodes are now connected, forming the tree:

```
        3
       / \
      9   20
         /  \
        15   7
```
