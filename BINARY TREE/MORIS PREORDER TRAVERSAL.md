
https://www.naukri.com/code360/problems/preorder-binary-tree_5948?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

https://leetcode.com/problems/binary-tree-preorder-traversal/description/



14![L37  Morris Traversal _ Preorder _ Inorder _ C++ _ Java 4-28 screenshot](https://github.com/user-attachments/assets/5a754ad1-600b-47eb-b433-2379dd94ea63)

![L37  Morris Traversal _ Preorder _ Inorder _ C++ _ Java 5-36 screenshot](https://github.com/user-attachments/assets/da3565be-01d3-471c-b454-8b9a4091a5f9)

4. Binary Tree Preorder Traversal
Solved
Easy
Topics
Companies
Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:

![image](https://github.com/user-attachments/assets/c20f2052-60ad-48e9-8c81-418ae08d8f96)

Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]

Explanation:

![image](https://github.com/user-attachments/assets/734b76df-9eeb-42e5-9b64-c51768a12aa5)


Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]


```cpp

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* cur = root;

        while (cur != NULL) {
            // If the current node has no left child
            if (cur->left == NULL) {
                // Add the value of the current node to the preorder vector
                preorder.push_back(cur->val);
                
                // Move to the right child
                cur = cur->right;
            } else {
                // Find the rightmost node in the left subtree
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // Set the right child of the rightmost node to the current node
                    prev->right = cur;
                    
                    // Add the current node value (for preorder)
                    preorder.push_back(cur->val);
                    
                    // Move to the left child
                    cur = cur->left;
                } else {
                    // If the right child of the rightmost node is not NULL, reset it
                    prev->right = NULL;
                    
                    // Move to the right child
                    cur = cur->right;
                }
            }
        }

        return preorder;
    }
};


```

Time Complexity: O(N)
Space Complexity: O(1) (excluding the output storage, which takes O(N))


Certainly! Let's go line by line through the Morris Preorder Traversal code with a graphical explanation of each line’s function and a corresponding code snippet.

Consider this example binary tree for visualizing the code:

```
      1
     / \
    2   3
   / \
  4   5
```

The preorder traversal should output: `[1, 2, 4, 5, 3]`.

I’ll break down the code, line by line, and provide a graphical representation of the tree state at each step.

### Full Code with Line-by-Line Explanation

Here’s the C++ code for Morris Preorder Traversal:

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;       // Line 1
        TreeNode* cur = root;       // Line 2
        
        while (cur != NULL) {       // Line 3
            if (cur->left == NULL) { // Line 4
                preorder.push_back(cur->val); // Line 5
                cur = cur->right;            // Line 6
            } else {
                TreeNode* prev = cur->left;  // Line 7
                while (prev->right && prev->right != cur) { // Line 8
                    prev = prev->right;     // Line 9
                }
                
                if (prev->right == NULL) {  // Line 10
                    prev->right = cur;      // Line 11
                    preorder.push_back(cur->val); // Line 12
                    cur = cur->left;        // Line 13
                } else {
                    prev->right = NULL;     // Line 14
                    cur = cur->right;       // Line 15
                }
            }
        }
        
        return preorder;                    // Line 16
    }
};
```

---

### Step-by-Step Walkthrough with Visual Graphs

#### Step 1: Initial Setup
- **Code**: 
    ```cpp
    vector<int> preorder;
    TreeNode* cur = root;
    ```
- **Explanation**: We initialize an empty vector `preorder` to store traversal results and a pointer `cur` set to the root node (`1`).
- **Tree State**:

    ```
          1 (cur)
         / \
        2   3
       / \
      4   5
    ```
  
---

#### Step 2: Start Traversing the Tree
- **Code**:
    ```cpp
    while (cur != NULL) {
    ```
- **Explanation**: This `while` loop runs until all nodes are visited (i.e., until `cur` is `NULL`).

---

#### Step 3: Check if `cur` Has Left Child
- **Code**:
    ```cpp
    if (cur->left == NULL) {
    ```
- **Explanation**: We check if the current node `cur` has a left child. If `cur` (node `1`) has a left child (`2`), we go to the `else` part of this code.

---

#### Step 4: If `cur` Has a Left Child, Traverse to the Rightmost Node
- **Code**:
    ```cpp
    TreeNode* prev = cur->left;
    while (prev->right && prev->right != cur) {
        prev = prev->right;
    }
    ```
- **Explanation**: Set `prev` to the left child of `cur` (node `2`). Move `prev` to the rightmost node in the left subtree (`5`). This traversal is finding where to create a temporary link back to `cur` for when we complete the left subtree traversal.
- **Tree State**:

    ```
          1 (cur)
         / \
        2   3
       / \
      4   5 (prev points here)
    ```

---

#### Step 5: Create a Thread from `prev` Back to `cur`
- **Code**:
    ```cpp
    if (prev->right == NULL) {
        prev->right = cur;
        preorder.push_back(cur->val);
        cur = cur->left;
    }
    ```
- **Explanation**: We create a temporary thread by setting `prev->right` to `cur` (node `1`). Visit the current node `cur` (node `1`) and add it to `preorder`. Move `cur` to its left child (`2`).
- **Tree State**:

    ```
          1
         / \
        2   3
       / \
      4   5
           \
            1 (thread created to `cur` = 1)

    preorder = [1]
    ```

---

#### Step 6: Repeat Steps 3-5 for Nodes 2 and 4
- **Explanation**: Following the same process as above, we create a thread from `4` back to `2`, add `2` to `preorder`, and move `cur` to `4`.
- **Tree State**:

    ```
          1
         / \
        2   3
       / \
      4   5
       \
        2 (thread created to `cur` = 2)

    preorder = [1, 2]
    ```

---

#### Step 7: Visit Node 4, Return to Node 2 via Thread, Visit Node 5
- **Explanation**: Since `4` has no left child, add `4` to `preorder`. Then remove the thread from `4` to `2`, move `cur` to `5`, add `5` to `preorder`, and return to `1` via the thread from `5` to `1`.
- **Tree State**:

    ```
          1
         / \
        2   3
       / \
      4   5

    preorder = [1, 2, 4, 5]
    ```

---

#### Step 8: Continue with Right Subtree (Node 3)
- **Code**:
    ```cpp
    if (cur->left == NULL) {
        preorder.push_back(cur->val);
        cur = cur->right;
    }
    ```
- **Explanation**: At `cur` = `3`, which has no left child, add `3` to `preorder` and set `cur` to `NULL`.
- **Final Tree State**:

    ```
    preorder = [1, 2, 4, 5, 3]
    ```

---

#### Final Output
The final `preorder` traversal of the tree is `[1, 2, 4, 5, 3]`.
