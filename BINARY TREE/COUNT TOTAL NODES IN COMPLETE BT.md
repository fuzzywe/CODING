https://leetcode.com/problems/count-complete-tree-nodes/description/

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 ![L32  Count total Nodes in a COMPLETE Binary Tree _ O(Log^2 N) Approach _ C++ _ Java 5-53 screenshot](https://github.com/user-attachments/assets/3b31c987-b0f1-454b-b510-d86c187ad1fa)


Example 1:
![image](https://github.com/user-attachments/assets/275508e4-8381-409b-9615-1be20b85d3bc)


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1


 
 BFS with the traversal of every node. Time/space complexity is linear: O(N).
```cpp
class Solution 
{
public:
    int countNodes(TreeNode* root, int l = 1, int r = 1) 
    {
        if (!root) return 0;

        TreeNode *left = root, *right = root;
        while (left = left->left)   ++l; 
        while (right = right->right) ++r; 
        
        if (l == r) return (1 << l) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```
The given code is a solution to count the number of nodes in a **complete binary tree**. Let's go through it step-by-step.

### Key Points to Understand

1. **Complete Binary Tree**: A complete binary tree is a binary tree in which every level is fully filled except possibly the last, which is filled from left to right. This property helps in optimizing the counting process.

2. **Height Calculation**: For a complete binary tree, if the leftmost and rightmost paths from the root node are of the same height, the tree is perfect, and the number of nodes can be calculated directly using the formula:
   \[
   \text{nodes} = 2^{\text{height}} - 1
   \]
3. **Recursive Counting**: If the leftmost and rightmost paths have different heights, the tree is not perfect, and we recursively calculate the number of nodes in the left and right subtrees.

### Code Explanation

```cpp
class Solution {
public:
    int countNodes(TreeNode* root, int l = 1, int r = 1) {
        if (!root) return 0;  // Base case: if the tree is empty, return 0.

        // Pointers to traverse the leftmost and rightmost paths
        TreeNode *left = root, *right = root;
        
        // Calculate left height
        while (left = left->left) ++l;
        
        // Calculate right height
        while (right = right->right) ++r;
        
        // If left height equals right height, it's a perfect binary tree
        if (l == r) return (1 << l) - 1;
        
        // Otherwise, count nodes recursively in left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```

### Step-by-Step Execution

Let’s break down each part of the code:

1. **Base Case Check**:
   ```cpp
   if (!root) return 0;
   ```
   - If the `root` is `nullptr`, it means the tree (or subtree) is empty, so we return 0.

2. **Left and Right Height Calculation**:
   ```cpp
   TreeNode *left = root, *right = root;
   while (left = left->left) ++l;
   while (right = right->right) ++r;
   ```
   - Two pointers, `left` and `right`, start at the `root`.
   - The `while` loop for `left` traverses down the leftmost path, counting levels to determine the left height `l`.
   - Similarly, the `while` loop for `right` traverses down the rightmost path, counting levels to determine the right height `r`.

3. **Perfect Binary Tree Check**:
   ```cpp
   if (l == r) return (1 << l) - 1;
   ```
   - If the left and right heights (`l` and `r`) are the same, the subtree rooted at `root` is a perfect binary tree.
   - The number of nodes in a perfect binary tree of height `l` is \(2^l - 1\), which is calculated by `(1 << l) - 1` (bitwise left shift for \(2^l\)).

4. **Recursive Count for Non-Perfect Tree**:
   ```cpp
   return 1 + countNodes(root->left) + countNodes(root->right);
   ```
   - If `l` and `r` are not equal, the subtree is not perfect. We recursively calculate the number of nodes in the left and right subtrees.
   - We add `1` for the `root` node itself and the results of `countNodes(root->left)` and `countNodes(root->right)`.

### Complexity Analysis

- **Time Complexity**: \(O(\log^2 n)\), where \(n\) is the number of nodes. Each recursive call calculates the height of the tree, which takes \(O(\log n)\), and there are \(O(\log n)\) recursive calls.
- **Space Complexity**: \(O(\log n)\), for the recursive call stack in a complete binary tree.

This approach is efficient for large trees, as it leverages the properties of a complete binary tree.
