144. Binary Tree Preorder Traversal

https://leetcode.com/problems/binary-tree-preorder-traversal/description/

Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:

![image](https://github.com/user-attachments/assets/4b096c10-c5d9-4738-a9f7-a1455ba23a39)


Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]

Explanation:

![image](https://github.com/user-attachments/assets/8fc55d4c-55f3-4d0e-a275-9c4435ca656e)



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]


```cpp

Inorder: Left, root, right
Preorder: Root, left, right
Postorder: Left, right, root

```

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;

        while(!st.empty() || root){
            while(root){
                ans.push_back(root->val);
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            root=root->right;
        }
        return ans;

        
        
    }
};
```

This code performs a **preorder traversal** (root, left, right) of a binary tree using an **iterative approach** with a **stack**. In preorder traversal, each node is visited in the order: root first, then the left subtree, followed by the right subtree.

Let's go through the code step-by-step and perform a dry run with a sample binary tree.

### Code
```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;

        while (!st.empty() || root) {
            while (root) {
                ans.push_back(root->val);   // Visit root node
                st.push(root);              // Push root onto stack
                root = root->left;          // Move to left child
            }
            root = st.top();                // Get the node from the top of the stack
            st.pop();                       // Remove the node from the stack
            root = root->right;             // Move to right child
        }
        return ans;
    }
};
```

### Key Steps in the Code
1. **Initialize Stack and Result Vector**:  
   - `stack<TreeNode*> st;` — Stack to help track nodes as we traverse.
   - `vector<int> ans;` — Stores the preorder traversal results.

2. **Outer `while` Loop**: 
   - This loop continues as long as either the stack is not empty or `root` is not null.
   - It ensures that all nodes are visited.

3. **Inner `while` Loop**: 
   - Moves down the left subtree of each node, visiting nodes in the preorder fashion (root, left, right).
   - **Key actions**:
     - **Visit Root Node**: `ans.push_back(root->val);`
     - **Push Root to Stack**: `st.push(root);`
     - **Move Left**: `root = root->left;`

4. **After Inner Loop**:
   - Once there are no more left nodes, `root` is set to the last node from the stack (this would be the most recently visited node's right child).
   - **Move Right**: `root = root->right;`

5. **End of Traversal**:
   - When there are no more nodes to process (`root == NULL` and `st.empty()`), the function returns the `ans` vector, containing the preorder traversal.

---

### Sample Dry Run

Let's apply the code to the following binary tree:

```
      1
     / \
    2   3
   / \
  4   5
```

#### Initial Setup
- `st = {}` (empty stack)
- `ans = []`
- `root` initially points to node `1`

#### Steps

1. **First Iteration of Outer `while`** (`root = 1`)
    - **Inner `while` (root is not NULL)**:
      - `ans.push_back(1);` ➔ `ans = [1]`
      - `st.push(1);` ➔ `st = [1]`
      - Move to left child: `root = 2`
    - **Inner `while` (root = 2)**:
      - `ans.push_back(2);` ➔ `ans = [1, 2]`
      - `st.push(2);` ➔ `st = [1, 2]`
      - Move to left child: `root = 4`
    - **Inner `while` (root = 4)**:
      - `ans.push_back(4);` ➔ `ans = [1, 2, 4]`
      - `st.push(4);` ➔ `st = [1, 2, 4]`
      - Move to left child: `root = NULL`
    - **Exit Inner `while`** (`root = NULL`).

2. **Process Node from Stack** (`st.top() = 4`)
    - `root = st.top();` ➔ `root = 4`
    - `st.pop();` ➔ `st = [1, 2]`
    - Move to right child: `root = NULL` (node `4` has no right child).

3. **Process Node from Stack** (`st.top() = 2`)
    - `root = st.top();` ➔ `root = 2`
    - `st.pop();` ➔ `st = [1]`
    - Move to right child: `root = 5`

4. **Next Iteration** (`root = 5`)
    - **Inner `while` (root = 5)**:
      - `ans.push_back(5);` ➔ `ans = [1, 2, 4, 5]`
      - `st.push(5);` ➔ `st = [1, 5]`
      - Move to left child: `root = NULL`
    - **Exit Inner `while`** (`root = NULL`).

5. **Process Node from Stack** (`st.top() = 5`)
    - `root = st.top();` ➔ `root = 5`
    - `st.pop();` ➔ `st = [1]`
    - Move to right child: `root = NULL` (node `5` has no right child).

6. **Process Node from Stack** (`st.top() = 1`)
    - `root = st.top();` ➔ `root = 1`
    - `st.pop();` ➔ `st = []`
    - Move to right child: `root = 3`

7. **Final Iteration** (`root = 3`)
    - **Inner `while` (root = 3)**:
      - `ans.push_back(3);` ➔ `ans = [1, 2, 4, 5, 3]`
      - `st.push(3);` ➔ `st = [3]`
      - Move to left child: `root = NULL`
    - **Exit Inner `while`** (`root = NULL`).

8. **Process Node from Stack** (`st.top() = 3`)
    - `root = st.top();` ➔ `root = 3`
    - `st.pop();` ➔ `st = []`
    - Move to right child: `root = NULL` (node `3` has no right child).

9. **End of Traversal**:
   - The queue and `root` are now both empty (`st.empty() && root == NULL`), so we exit the `while` loop.

10. **Return the Result**:
    - The function returns `ans`, which is `[1, 2, 4, 5, 3]`.

### Final Output:
The **preorder traversal** of the tree `[1, 2, 4, 5, 3]` matches the expected preorder order of visiting nodes (root, left, right).
