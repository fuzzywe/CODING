https://leetcode.com/problems/maximum-width-of-binary-tree/

662. Maximum Width of Binary Tree

![L28  Maximum Width of Binary Tree _ C++ _ Java 1-36 screenshot](https://github.com/user-attachments/assets/dc9d72ea-fe92-4d14-9d50-5eb762f153ea)


Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.
![WhatsApp Image 2024-10-26 at 10 56 50_a71e69d9](https://github.com/user-attachments/assets/71b6fe88-c93f-4f3d-8eaf-354b66643652)

![WhatsApp Image 2024-10-26 at 10 56 50_3d86b489](https://github.com/user-attachments/assets/1491bf54-9bc5-405a-a656-66cb6d57cb32)

 ![WhatsApp Image 2024-10-26 at 10 56 49_2ef71db0](https://github.com/user-attachments/assets/87c580b8-0158-49dc-866b-a353b9a84696)


Example 1:

![image](https://github.com/user-attachments/assets/14a7336d-93b9-439e-9f9c-3a30df3c1371)

Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:

![image](https://github.com/user-attachments/assets/2ae46326-bdcb-48d3-bd0d-4efb209d2d06)

Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:
![image](https://github.com/user-attachments/assets/12c12971-c6e0-465d-9c1c-4e14a049138f)


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).

![L28  Maximum Width of Binary Tree _ C++ _ Java 8-4 screenshot](https://github.com/user-attachments/assets/3a920174-51df-4ca4-baab-ec279fa65c47)

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
    int widthOfBinaryTree(TreeNode* root) {
        //ek toh whi vertical order jisme map of map of multiset bnate hai pr that takes more TC and SC
        //toh ab hm kya krenge ki level order traversal krenge..hr baar 2i+1 and 2i+2 sbko denge basically horiz wise isse numbering hojayegi toh last me right-left+1 will be the width
        //pr this will make the int overflow bcz at every order you are making twice 2powerheight will be the max so it will cause INT overfloiw if height is more than 30 also
        //since we only want width toh we will reset the values back to 0 1 2 type by everytime subtracting from the min 
        if(root==NULL)return 0;
        queue<pair<TreeNode*,int>>q;//node and index given to it
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            long long sz=q.size();
            long long mini=LLONG_MAX;
            long long minl=LLONG_MAX;
            long long maxl=LLONG_MIN;
            for(long long i=0;i<sz;i++){
                auto top=q.front();
                q.pop();
                long long val=top.second;
                TreeNode* curr=top.first;
                mini=min(mini,val);
                long long modi=val-mini;
                minl=min(minl,modi);
                maxl=max(maxl,modi);

                if(curr->left)q.push({curr->left,2*modi+1});
                if(curr->right)q.push({curr->right,2*modi+2});
            }
            ans=max(ans,maxl-minl+1);
        }
        return ans;
    }
};

```
Thank you for clarifying. Let's go through each line with a visual step-by-step graph and dry run. Since I can't create interactive visuals here, I'll guide you through each line with illustrations as closely as possible in text form.

Let's start with a simple binary tree example to illustrate how each line of the code affects it.

### Example Binary Tree

Consider this binary tree:

```
         1
       /   \
      2     3
     / \     \
    4   5     7
```

Each node will be assigned an index to represent its position at each level, starting from the root with index `0`. The left child’s index is `2 * i + 1` and the right child’s index is `2 * i + 2`.

---

### Code and Explanation with Graphs at Each Step

Here's the code snippet:

```cpp
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        long long ans = 0;
        while (!q.empty()) {
            long long sz = q.size();
            long long mini = LLONG_MAX;
            long long minl = LLONG_MAX;
            long long maxl = LLONG_MIN;

            for (long long i = 0; i < sz; i++) {
                auto top = q.front();
                q.pop();

                long long val = top.second;
                TreeNode* curr = top.first;

                mini = min(mini, val);
                long long modi = val - mini;

                minl = min(minl, modi);
                maxl = max(maxl, modi);

                if (curr->left) q.push({curr->left, 2 * modi + 1});
                if (curr->right) q.push({curr->right, 2 * modi + 2});
            }

            ans = max(ans, maxl - minl + 1);
        }

        return ans;
    }
};
```

### Step 1: Initial Setup

1. **`if (root == NULL) return 0;`**  
   Checks if the tree is empty. If `root` is `NULL`, returns `0`. In this case, the root is not `NULL`, so we proceed.

   ```
   Tree:
         1
       /   \
      2     3
     / \     \
    4   5     7
   ```

2. **`queue<pair<TreeNode*, int>> q;`**  
   Creates an empty queue to hold pairs of nodes and their indexes.

3. **`q.push({root, 0});`**  
   Pushes the root node (`1`) with index `0` into the queue.

   **Queue**:
   ```
   [(1, 0)]
   ```

4. **`long long ans = 0;`**  
   Initializes `ans` to `0`. This variable will store the maximum width encountered.

---

### Step 2: Level 1 (Root Level)

5. **`while (!q.empty()) {`**  
   Enters the main loop, which will execute as long as there are nodes in the queue.

6. **`long long sz = q.size();`**  
   `sz` is set to the size of the queue, which is `1` (only the root node is in the queue at this level).

7. **Initialize `mini`, `minl`, and `maxl`**  
   Sets `mini = LLONG_MAX`, `minl = LLONG_MAX`, and `maxl = LLONG_MIN` to find minimum and maximum indices for this level.

8. **`for (long long i = 0; i < sz; i++) {`**  
   Enters a loop to process each node in the current level.  

**Tree Diagram**:
```
         1 (index 0)
```

**Queue**:
```
[(1, 0)]
```

#### Processing Node 1

9. **`auto top = q.front(); q.pop();`**  
   `top` is `(1, 0)` (the root node and its index), and we remove it from the queue.  

10. **`long long val = top.second; TreeNode* curr = top.first;`**  
    Sets `val = 0` (index of node `1`) and `curr = node 1`.

11. **`mini = min(mini, val);`**  
    Updates `mini` to `0`, which is the minimum index at this level.

12. **`long long modi = val - mini;`**  
    Calculates `modi = val - mini = 0 - 0 = 0`.

13. **`minl = min(minl, modi); maxl = max(maxl, modi);`**  
    Sets `minl = 0` and `maxl = 0` (both minimum and maximum normalized indices for this level are `0`).

14. **`if (curr->left) q.push({curr->left, 2 * modi + 1});`**  
    Node `2` is added to the queue with index `2 * 0 + 1 = 1`.

15. **`if (curr->right) q.push({curr->right, 2 * modi + 2});`**  
    Node `3` is added to the queue with index `2 * 0 + 2 = 2`.

   **Queue After Processing Node 1**:
   ```
   [(2, 1), (3, 2)]
   ```

16. **`ans = max(ans, maxl - minl + 1);`**  
    Updates `ans = max(0, 0 - 0 + 1) = 1`, which is the width at this level.

---

### Step 3: Level 2

**Queue**:
```
[(2, 1), (3, 2)]
```

**Tree Diagram**:
```
         1
       /   \
      2 (1) 3 (2)
```

---

I'll continue with more levels similarly if you'd like, or can also create a visual explanation as a text-based solution per line. Let me know how you prefer this structure for each line!


Let’s go over the mathematical reasoning behind the formula in the code for calculating the width of a binary tree at each level. The primary concepts are **node indexing** and **normalization**.

### 1. Node Indexing in Binary Trees

In a binary tree, nodes can be indexed as if they were stored in an array, where the left and right children of a node at index `i` have indices `2*i + 1` and `2*i + 2`, respectively. This way of numbering nodes enables us to visualize the layout of nodes at each level without explicitly storing each position in a 2D array. Here’s a quick breakdown of how it works:

#### Example Tree Structure (Indexing Nodes Like an Array)

Given this binary tree:

```
         1
       /   \
      2     3
     / \     \
    4   5     7
```

If we consider the root at `index = 0`, the rest of the nodes are indexed as follows:

```
         1 (0)
       /       \
      2 (1)     3 (2)
     /   \         \
    4 (3) 5 (4)     7 (6)
```

This indexing scheme enables us to compute the "width" of each level simply by looking at the leftmost and rightmost indices at each level.

### 2. Formula for Width Calculation at Each Level

The width of each level in the tree can be calculated as:

\[
\text{width} = \text{rightmost index} - \text{leftmost index} + 1
\]

For each level:
- **Leftmost index** is the index of the first node at that level.
- **Rightmost index** is the index of the last node at that level.

Using this, the width of a level is the difference between the rightmost and leftmost indices, plus one.

### 3. Handling Integer Overflow with Normalization

In a very deep binary tree, the indices of nodes can become extremely large, leading to potential integer overflow. To handle this, we use **index normalization**. Here’s how:

- For each level, we calculate a **minimum index (`mini`)** that acts as a baseline for all other indices at that level.
- We adjust every index in the current level by subtracting `mini` from it. This normalized index (`modi`) for each node at that level will be a smaller, manageable number starting from zero.

### Explanation of Key Lines in the Code

Let’s go over the key lines with this understanding in mind.

1. **Initialize `mini`**:
   ```cpp
   mini = min(mini, val);
   ```
   `mini` stores the smallest index in the current level. We use this to normalize other indices to avoid overflow.

2. **Normalize each node’s index**:
   ```cpp
   long long modi = val - mini;
   ```
   Subtracting `mini` from `val` gives a smaller, normalized index `modi`, which we can safely use in calculations.

3. **Track `minl` and `maxl`**:
   ```cpp
   minl = min(minl, modi);
   maxl = max(maxl, modi);
   ```
   - `minl` and `maxl` store the smallest and largest normalized indices at the current level.
   - Using these, we can calculate the width for the current level as `maxl - minl + 1`.

4. **Calculate width and update `ans`**:
   ```cpp
   ans = max(ans, maxl - minl + 1);
   ```
   For each level, the width is `maxl - minl + 1`. The final answer (`ans`) stores the maximum width seen across all levels.

---

### Putting It All Together

In summary:
- The formula `2*i + 1` and `2*i + 2` for left and right children helps map a binary tree into an "array-like" structure.
- To avoid overflow, we use normalization by subtracting the minimum index (`mini`) at each level.
- We calculate width as `maxl - minl + 1` using the normalized indices for each level. This gives us the effective width for each level, and `ans` holds the maximum width across all levels.

This approach efficiently calculates the width without running into overflow issues, even for large trees.
