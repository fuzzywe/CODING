https://leetcode.com/problems/symmetric-tree/description/

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:
![image](https://github.com/user-attachments/assets/c0cb699f-e421-4a88-9228-25f80e69a4a8)


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:

![image](https://github.com/user-attachments/assets/20533964-97dc-458f-9565-7433c5c471ab)

Input: root = [1,2,2,null,3,null,3]
Output: false
Let me explain the Symmetric Tree problem in detail:

Problem Understanding:
1. A binary tree is symmetric if it is a mirror image of itself.
2. In other words, the left subtree should be a mirror reflection of the right subtree.

Let's break it down with examples:

Example 1:
```
     1
   /   \
  2     2    → Symmetric
 / \   / \
3   4 4   3
```
This is symmetric because:
- Both children of root are 2
- Left subtree's left (3) matches right subtree's right (3)
- Left subtree's right (4) matches right subtree's left (4)

Example 2:
```
     1
   /   \
  2     2    → Not Symmetric
   \     \
    3     3
```
This is not symmetric because:
- Left subtree's right (3) should match right subtree's left (null)
- But right subtree has 3 on the right instead of left

Solution Approaches:

1. Recursive Solution:
```cpp
class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        // Base cases
        if (left == NULL && right == NULL) return true;  // Both empty
        if (left == NULL || right == NULL) return false; // One empty
        
        // For trees to be mirror images:
        // 1. Their root values should be same
        // 2. Left's left should match Right's right
        // 3. Left's right should match Right's left
        return (left->val == right->val) && 
               isMirror(left->left, right->right) && 
               isMirror(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isMirror(root->left, root->right);
    }
};
```

2. Iterative Solution (using queue):
```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            
            if (!left && !right) continue;
            if (!left || !right) return false;
            if (left->val != right->val) return false;
            
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};
```

Key Points:
1. For a tree to be symmetric:
   - Root's left and right subtrees should be mirror images
   - Values should match symmetrically
   - Structure should match symmetrically

2. Base Cases:
   - Empty tree is symmetric
   - If one subtree is empty and other isn't, not symmetric
   - If values don't match, not symmetric

3. Recursive Check:
   - Compare left->left with right->right
   - Compare left->right with right->left

Time Complexity: O(n) where n is number of nodes
Space Complexity: 
- Recursive: O(h) where h is height of tree (recursion stack)
- Iterative: O(w) where w is maximum width of tree (queue size)

Test Cases to Consider:
1. Empty tree → true
2. Single node → true
3. Complete symmetric tree → true
4. Asymmetric values → false
5. Asymmetric structure → false

Example walk-through for [1,2,2,3,4,4,3]:
```
1. Check root exists → Yes
2. Compare root->left (2) and root->right (2) → Match
3. Compare:
   - left->left (3) with right->right (3) → Match
   - left->right (4) with right->left (4) → Match
4. Result: true
```

Let's go through the code line by line, explaining each line's purpose, followed by a dry run of each line on a simple symmetric binary tree.

### Code Explanation and Dry Run

```cpp
class Solution {
public:
    // Helper function to check if two trees are mirror images
    bool isMirror(TreeNode* left, TreeNode* right) {
        // If both nodes are NULL, they are mirror images
        if (!left && !right) return true;
        
        // If only one node is NULL, they are not mirror images
        if (!left || !right) return false;
        
        // Check if the values of the nodes are equal and recursively check the children
        return (left->val == right->val) 
            && isMirror(left->left, right->right) 
            && isMirror(left->right, right->left);
    }

    // Main function to check if the tree is symmetric
    bool isSymmetric(TreeNode* root) {
        // If the tree is empty, it is symmetric
        if (!root) return true;
        
        // Start the mirror check with the left and right children of the root
        return isMirror(root->left, root->right);
    }
};
```

### Example Tree for Dry Run

We’ll use a symmetric binary tree for this example:

```
        1
       / \
      2   2
     / \ / \
    3  4 4  3
```

Each line’s execution with explanations:

---

1. **`bool isSymmetric(TreeNode* root)`**  
   - This function is the entry point. We call `isSymmetric(root)` with `root` as the input node (value `1`).
   
   - **Dry Run**: `root` has the value `1`.

2. **`if (!root) return true;`**  
   - This line checks if the `root` is `NULL`. If `NULL`, the tree is symmetric by default. Since `root` is not `NULL`, we move to the next line.
   
   - **Dry Run**: `root` is not `NULL`, so we proceed.

3. **`return isMirror(root->left, root->right);`**  
   - This line calls the `isMirror` helper function with `root->left` (value `2`) and `root->right` (value `2`) to determine if they are mirror images.
   
   - **Dry Run**: Call `isMirror(left=2, right=2)`.

4. **`bool isMirror(TreeNode* left, TreeNode* right)`**  
   - The `isMirror` function checks if two nodes (`left` and `right`) and their children are mirror images.
   
   - **Dry Run**: `left` and `right` are both nodes with value `2`.

5. **`if (!left && !right) return true;`**  
   - This checks if both nodes (`left` and `right`) are `NULL`. If true, they are mirror images. Both nodes here are not `NULL`, so we proceed.
   
   - **Dry Run**: Both `left` and `right` are not `NULL`, so continue.

6. **`if (!left || !right) return false;`**  
   - This checks if only one of `left` or `right` is `NULL`. If true, they are not mirror images. Both nodes here are not `NULL`, so we proceed.
   
   - **Dry Run**: Neither `left` nor `right` is `NULL`, so we proceed.

7. **`return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);`**  
   - This checks three things:
      - The values of `left` and `right` nodes are equal.
      - Recursively, the `left->left` subtree is a mirror of `right->right`.
      - Recursively, the `left->right` subtree is a mirror of `right->left`.
   
   - **Dry Run**:
      - **Step 1**: `left->val` (2) equals `right->val` (2), so we continue.
      - **Step 2**: Call `isMirror(left->left=3, right->right=3)` for the left subtree.

8. **Recursive Call: `isMirror(left=3, right=3)`**  
   - We now check if the nodes with values `3` are mirror images.
   
   - **Dry Run**: `left` and `right` both have value `3`.

9. **Repeat Steps 5, 6, 7 for nodes with value `3`**  
   - **Dry Run**:
      - Both `left` and `right` are not `NULL`.
      - `left->val` (3) equals `right->val` (3).
      - Call `isMirror(left->left=NULL, right->right=NULL)` for the left-left and right-right subtrees.

10. **Recursive Call: `isMirror(left=NULL, right=NULL)`**  
    - Both nodes are `NULL`, so they are mirrors. This returns `true`.
    
    - **Dry Run**: Returns `true`.

11. **Back to Call `isMirror(left=3, right=3)`**
    - Now call `isMirror(left->right=NULL, right->left=NULL)` for the right subtrees.

12. **Recursive Call: `isMirror(left=NULL, right=NULL)`**
    - Both nodes are `NULL`, so they are mirrors. This returns `true`.
    
    - **Dry Run**: Returns `true`.

13. **Back to Call `isMirror(left=2, right=2)`**
    - Now call `isMirror(left->right=4, right->left=4)` for the right subtrees.

14. **Recursive Call: `isMirror(left=4, right=4)`**
    - Now we check nodes with value `4`.
    
    - **Dry Run**:
      - `left->val` (4) equals `right->val` (4).
      - Call `isMirror(left->left=NULL, right->right=NULL)`.

15. **Repeat Steps 10-12 for nodes with value `4`**
    - This call and subsequent calls return `true` for both `NULL` pairs, indicating all checks pass.

16. **Return to `isSymmetric` and Finish**
    - Since all recursive checks returned `true`, `isSymmetric` returns `true`.

---

### Final Result

The `isSymmetric` function returns `true`, indicating that the tree is symmetric.
