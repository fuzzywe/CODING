124. Binary Tree Maximum Path Sum

https://leetcode.com/problems/binary-tree-maximum-path-sum/solutions/5920758/efficient-approach-to-finding-the-maximum-path-sum-in-a-binary-tree/

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
![image](https://github.com/user-attachments/assets/4047185c-75e1-4564-9bdb-93b29e62b8b4)

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:

![image](https://github.com/user-attachments/assets/c7bab20b-732f-4242-84a8-2e72047556e0)

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

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
 int maxi = INT_MIN;
int sum(TreeNode* root)
{
    if(!root ) return 0;
   
     int leftsum =0;
        int rightsum =0;
        
        leftsum = max(0,sum(root->left));
        rightsum = max(0,sum(root->right));
        maxi = max(maxi,leftsum+rightsum+root->val);
        return root->val+max(leftsum,rightsum);
}
    int maxPathSum(TreeNode* root) {
       int ans = sum(root);
       return maxi;
    }
};
```
 Here's a line-by-line breakdown of the code, followed by a dry run for an example binary tree.

### Code Explanation (Line-by-Line)

```cpp
class Solution {
public:
    int maxi = INT_MIN;  // Initialize `maxi` with the minimum integer value to store the maximum path sum found.
```

- We declare `maxi` as an instance variable to keep track of the highest path sum across all nodes during traversal. Starting with `INT_MIN` allows any path sum to update this value initially.

```cpp
    int sum(TreeNode* root) {
```

- The `sum` function recursively computes the maximum path sum "through" each subtree rooted at the `root` node, returning the best path that includes either the left or right subtree.

```cpp
        if (!root) return 0;
```

- If `root` is `nullptr`, we return 0 because a non-existent node adds no value to the path sum.

```cpp
        int leftsum = 0;
        int rightsum = 0;
```

- We initialize `leftsum` and `rightsum` to store the maximum path sums of the left and right subtrees rooted at the current node, `root`.

```cpp
        leftsum = max(0, sum(root->left));
        rightsum = max(0, sum(root->right));
```

- We calculate the maximum path sum from each child node:
  - `sum(root->left)` and `sum(root->right)` are recursive calls that compute the path sums for the left and right subtrees.
  - `max(0, ...)` ensures we only add positive path sums to our current path. If the subtree sum is negative, we skip it by taking 0 instead.

```cpp
        maxi = max(maxi, leftsum + rightsum + root->val);
```

- We update `maxi` to hold the highest path sum found so far. For each node, this sum includes:
  - The node's value (`root->val`),
  - The maximum path from the left subtree (`leftsum`), and
  - The maximum path from the right subtree (`rightsum`).
  
  This line checks if the current path sum (from left to right through `root`) is greater than any previous path sum found, updating `maxi` if it is.

```cpp
        return root->val + max(leftsum, rightsum);
    }
```

- This line returns the maximum gain if continuing either left or right subtree's path from `root`. By choosing the higher of `leftsum` or `rightsum`, it allows each recursive call to pass the best path sum upward in the tree.

```cpp
    int maxPathSum(TreeNode* root) {
       int ans = sum(root);  // Start the recursive process.
       return maxi;  // Return the maximum path sum found.
    }
};
```

- `maxPathSum` initializes the recursive process by calling `sum(root)`. After traversing the entire tree, it returns the maximum path sum found.

### Dry Run

Let’s take an example binary tree:

```
       -10
       /  \
      9    20
          /  \
         15   7
```

#### Initial State
- `maxi = INT_MIN`
- Root node of the tree is `-10`.

#### Execution Steps

1. **Call `maxPathSum(root)` with `root = -10`:**
   - This calls `sum(-10)`.
   
2. **`sum(-10)` begins:**
   - `leftsum = max(0, sum(-10->left))`
   - Call `sum(9)`.

3. **`sum(9)` (left child of `-10`):**
   - `leftsum = max(0, sum(9->left)) = max(0, sum(nullptr)) = 0`
   - `rightsum = max(0, sum(9->right)) = max(0, sum(nullptr)) = 0`
   - Calculate `maxi = max(INT_MIN, 0 + 0 + 9) = 9`
   - Return `9 + max(0, 0) = 9` to `sum(-10)`.

4. **Continue `sum(-10)` with `leftsum = 9`:**
   - `rightsum = max(0, sum(-10->right))`
   - Call `sum(20)`.

5. **`sum(20)` (right child of `-10`):**
   - `leftsum = max(0, sum(20->left))`
   - Call `sum(15)`.

6. **`sum(15)` (left child of `20`):**
   - `leftsum = max(0, sum(15->left)) = 0`
   - `rightsum = max(0, sum(15->right)) = 0`
   - Calculate `maxi = max(9, 0 + 0 + 15) = 15`
   - Return `15 + max(0, 0) = 15` to `sum(20)`.

7. **Continue `sum(20)` with `leftsum = 15`:**
   - `rightsum = max(0, sum(20->right))`
   - Call `sum(7)`.

8. **`sum(7)` (right child of `20`):**
   - `leftsum = max(0, sum(7->left)) = 0`
   - `rightsum = max(0, sum(7->right)) = 0`
   - Calculate `maxi = max(15, 0 + 0 + 7) = 15`
   - Return `7 + max(0, 0) = 7` to `sum(20)`.

9. **Finish `sum(20)` with `leftsum = 15` and `rightsum = 7`:**
   - Calculate `maxi = max(15, 15 + 7 + 20) = 42`
   - Return `20 + max(15, 7) = 35` to `sum(-10)`.

10. **Finish `sum(-10)` with `leftsum = 9` and `rightsum = 35`:**
    - Calculate `maxi = max(42, 9 + 35 + (-10)) = 42`
    - Return `-10 + max(9, 35) = 25`.

11. **Final Output:**
    - `maxPathSum(root)` returns `maxi`, which is `42`.

So, the maximum path sum for this tree is **42**, achieved by the path `[15 -> 20 -> 7]`.
