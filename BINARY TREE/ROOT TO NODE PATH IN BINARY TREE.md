https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths
![WhatsApp Image 2024-10-26 at 11 25 42_32eb66c4](https://github.com/user-attachments/assets/261eb966-167e-4c44-948e-8881345ed66b)

![WhatsApp Image 2024-10-26 at 11 26 33_e1fcbfcd](https://github.com/user-attachments/assets/f7eafca5-9050-4102-9306-270c5b00ac62)


![WhatsApp Image 2024-10-26 at 11 26 52_8b2de7bf](https://github.com/user-attachments/assets/2a136b11-41a1-420b-9394-eacbd9d7fe6c)


Root to Leaf Paths
Difficulty: MediumAccuracy: 43.65%Submissions: 114K+Points: 4
Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

Example 1:

Input:

```cpp
       1
    /     \
   2       3

```
Output: 
1 2 
1 3 
Explanation: 
All possible paths:
1->2
1->3
Example 2:

Input:

```cpp
         10
       /    \
      20    30
     /  \
    40   60

```
Output: 
10 20 40 
10 20 60 
10 30 
Your Task:
Your task is to complete the function Paths() which takes the root node as an argument and returns all the possible paths. (All the paths are printed in new lines by the driver's code.)

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of the tree)
```cpp
lass Solution {
  public:
    vector<vector<int>> ans;
    vector<int> path;
    void getpath(Node* node){
        if(node == nullptr) return;
        
        path.push_back(node->data);
        
        if(node->left == NULL and node->right == NULL) ans.push_back(path);
        else{
            getpath(node->left);
            getpath(node->right);
        }
        path.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        if(root == nullptr) return ans;
        getpath(root);
        return ans;
    }
};

```
Let’s perform a detailed line-by-line dry run of the provided code, accompanied by visual representations of the binary tree and the state of the `path` and `ans` at each step. The code is designed to find all root-to-leaf paths in a binary tree.

We'll use the same binary tree structure as before:

```
      1
     / \
    2   3
   / \
  4   5
```

### The Code

Here’s the provided code for clarity:

```cpp
class Solution {
public:
    vector<vector<int>> ans;  // Stores all paths from root to leaves
    vector<int> path;         // Stores current path from root to current node

    void getpath(Node* node) {
        if (node == nullptr) return;  // If the node is null, end the recursion

        path.push_back(node->data);    // Add current node to path

        if (node->left == NULL && node->right == NULL) 
            ans.push_back(path);        // If it's a leaf node, add path to ans

        else {
            getpath(node->left);        // Recursive call for left child
            getpath(node->right);       // Recursive call for right child
        }

        path.pop_back();                // Backtrack: remove the current node from path
    }

    vector<vector<int>> Paths(Node* root) {
        if (root == nullptr) return ans;  // If root is null, return empty ans
        getpath(root);                    // Start finding paths from root
        return ans;                       // Return all paths found
    }
};
```

### Detailed Dry Run with Visual Representations

Let’s go through the code line-by-line with a visual representation of the binary tree and the state of `path` and `ans`.

---

### Initial Call to `Paths`

**Call: `Paths(root)` where root points to node 1**

1. **Line:** `if (root == nullptr) return ans;`  
   - **Check:** `root` is not null, so we proceed.
   
2. **Line:** `getpath(root);`  
   - **Call:** `getpath(node=1)`  

---

### First Call to `getpath` (Node 1)

**State Before Execution:**
```
      1
     / \
    2   3
```
**Current Path:** `[]`  
**Current Ans:** `[]`  

3. **Line:** `path.push_back(node->data);`  
   - **Operation:** Add `1` to `path`.  
   **State After Execution:**
   - **Current Path:** `[1]`

4. **Line:** `if (node->left == NULL && node->right == NULL)`  
   - **Check:** Node `1` is not a leaf (it has children).

5. **Line:** `getpath(node->left);`  
   - **Call:** `getpath(node=2)`  

---

### Second Call to `getpath` (Node 2)

**State Before Execution:**
```
      1
     / \
    2   3
```
**Current Path:** `[1]`  
**Current Ans:** `[]`  

6. **Line:** `path.push_back(node->data);`  
   - **Operation:** Add `2` to `path`.  
   **State After Execution:**
   - **Current Path:** `[1, 2]`

7. **Line:** `if (node->left == NULL && node->right == NULL)`  
   - **Check:** Node `2` is not a leaf (it has children).

8. **Line:** `getpath(node->left);`  
   - **Call:** `getpath(node=4)`  

---

### Third Call to `getpath` (Node 4)

**State Before Execution:**
```
      1
     / \
    2   3
   /
  4
```
**Current Path:** `[1, 2]`  
**Current Ans:** `[]`  

9. **Line:** `path.push_back(node->data);`  
   - **Operation:** Add `4` to `path`.  
   **State After Execution:**
   - **Current Path:** `[1, 2, 4]`

10. **Line:** `if (node->left == NULL && node->right == NULL)`  
    - **Check:** Node `4` is a leaf (it has no children).
    
11. **Line:** `ans.push_back(path);`  
    - **Operation:** Add the current path to `ans`.  
    **State After Execution:**
    - **Current Ans:** `[[1, 2, 4]]`

12. **Line:** `path.pop_back();`  
    - **Operation:** Remove `4` from `path` to backtrack.  
    **State After Execution:**
    - **Current Path:** `[1, 2]`

13. **Line:** `return;`  
    - **Return:** Backtrack to node `2`.

---

### Back to Node 2, Process Right Child (Node 5)

14. **Continuing at `getpath(node=2)`**:
    - **Line:** `getpath(node->right);`  
    - **Call:** `getpath(node=5)`  

---

### Fourth Call to `getpath` (Node 5)

**State Before Execution:**
```
      1
     / \
    2   3
     \
      5
```
**Current Path:** `[1, 2]`  
**Current Ans:** `[[1, 2, 4]]`  

15. **Line:** `path.push_back(node->data);`  
    - **Operation:** Add `5` to `path`.  
    **State After Execution:**
    - **Current Path:** `[1, 2, 5]`

16. **Line:** `if (node->left == NULL && node->right == NULL)`  
    - **Check:** Node `5` is a leaf (it has no children).
    
17. **Line:** `ans.push_back(path);`  
    - **Operation:** Add the current path to `ans`.  
    **State After Execution:**
    - **Current Ans:** `[[1, 2, 4], [1, 2, 5]]`

18. **Line:** `path.pop_back();`  
    - **Operation:** Remove `5` from `path` to backtrack.  
    **State After Execution:**
    - **Current Path:** `[1, 2]`

19. **Line:** `return;`  
    - **Return:** Backtrack to node `2`.

20. **Line:** `path.pop_back();`  
    - **Operation:** Remove `2` from `path` to backtrack.  
    **State After Execution:**
    - **Current Path:** `[1]`

21. **Line:** `return;`  
    - **Return:** Backtrack to node `1`.

---

### Back to Node 1, Process Right Child (Node 3)

22. **Continuing at `getpath(node=1)`**:
    - **Line:** `getpath(node->right);`  
    - **Call:** `getpath(node=3)`  

---

### Fifth Call to `getpath` (Node 3)

**State Before Execution:**
```
      1
     / \
    2   3
```
**Current Path:** `[1]`  
**Current Ans:** `[[1, 2, 4], [1, 2, 5]]`  

23. **Line:** `path.push_back(node->data);`  
    - **Operation:** Add `3` to `path`.  
    **State After Execution:**
    - **Current Path:** `[1, 3]`

24. **Line:** `if (node->left == NULL && node->right == NULL)`  
    - **Check:** Node `3` is a leaf (it has no children).
    
25. **Line:** `ans.push_back(path);`  
    - **Operation:** Add the current path to `ans`.  
    **State After Execution:**
    - **Current Ans:** `[[1, 2, 4], [1, 2, 5], [1, 3]]`

26. **Line:** `path.pop_back();`  
    - **Operation:** Remove `3` from `path` to backtrack.  
    **State After Execution:**
    - **Current Path:** `[1]`

27. **Line:** `return;`  
    - **Return:** Backtrack to node `1`.

28. **Line:** `path.pop_back();`  
    - **Operation:** Remove `1` from `path` to complete backtracking.  
    **State After Execution:**
    - **Current Path:** `[]`

29. **Line:** `return;`  
    - **Return:** Exit the function.

---

### Final State

At this point, all nodes have been processed, and we return the final paths:

- **Final Ans:** `[[1, 2, 4], [1, 2, 5], [1, 3]]`

---

### Summary of the Process

- **Purpose:** This code traverses the binary tree from root to leaves and collects all root-to-leaf paths.
- **Method:** A depth-first search (DFS) approach is used through recursion.
- **Data Structures Used:**
  - `path`: A temporary storage to keep track of the current path during recursion.


  - `ans`: A vector of vectors to store all the found paths.

### Visual Representation of Pathfinding

Here's a visual representation of the paths collected:

1. Path: `[1, 2, 4]`
2. Path: `[1, 2, 5]`
3. Path: `[1, 3]`

This provides a complete overview of how the code functions to retrieve all root-to-leaf paths in the binary tree. Let me know if you need further assistance!

Let’s break down the `Paths` function step by step in a way that’s easy to visualize, and I’ll include diagrams to illustrate how the binary tree is traversed.

### Code Overview

The function `Paths` aims to find all paths from the root to the leaf nodes in a binary tree. Here’s the relevant code again for context:

```cpp
vector<vector<int>> Paths(Node* root) {
    if (root == nullptr) return ans;  // Check if the tree is empty
    getpath(root);                     // Start finding paths from the root
    return ans;                        // Return all paths found
}
```

### Step-by-Step Explanation with Visual Representation

#### **1. Function Start**

- **Code:** `vector<vector<int>> Paths(Node* root) {`
- **Explanation:** This line defines the `Paths` function. It takes one parameter, `root`, which is the starting point of the binary tree.

#### **2. Check for Empty Tree**

- **Code:** `if (root == nullptr) return ans;`
- **Visual Representation:**
  - If the tree is empty (i.e., `root` is `nullptr`), the output is simply an empty vector of paths.
  ```
  Input Tree: None (Empty)
  Output: []
  ```

- **Explanation:** 
  - This line checks if `root` is `nullptr`. If it is, it means there are no nodes to traverse, and the function immediately returns an empty vector `ans`.

#### **3. Start Finding Paths**

- **Code:** `getpath(root);`
- **Visual Representation:**
  - Let's assume we have the following binary tree:
  ```
      1
     / \
    2   3
   / \
  4   5
  ```

- **Explanation:**
  - The function `getpath` is called with the `root` node (which has the value `1`).
  - This function will explore all paths from the root to each leaf node recursively.

#### **4. Return Found Paths**

- **Code:** `return ans;`
- **Visual Representation:**
  - After calling `getpath`, `ans` will hold all the paths found:
  ```
  Paths found: [[1, 2, 4], [1, 2, 5], [1, 3]]
  ```

- **Explanation:** 
  - Finally, this line returns the `ans` vector, which now contains all the root-to-leaf paths that were discovered.

### Putting It All Together

#### Example Walkthrough

Let’s walk through the function with a visual representation of how it processes the binary tree:

1. **Input Tree Structure**:
   ```
       1
      / \
     2   3
    / \
   4   5
   ```

2. **Calling `Paths(root)`**:
   - We call `Paths` with the root node (value `1`).

3. **Checking if Empty**:
   - The `if (root == nullptr)` check returns `false` since the tree is not empty.

4. **Calling `getpath(root)`**:
   - The `getpath` function starts traversing the tree from node `1`.

#### Inside `getpath`

- **First Call:** `getpath(1)`
  - Current path: `[1]`
  - Node `1` has left child `2` and right child `3`.

- **Next Call:** `getpath(2)`
  - Current path: `[1, 2]`
  - Node `2` has left child `4` and right child `5`.

- **Next Call:** `getpath(4)`
  - Current path: `[1, 2, 4]`
  - Node `4` is a leaf node (no children), so this path is added to `ans`.

- **Backtrack to Node `2` and Explore Right Child:** `getpath(5)`
  - Current path: `[1, 2, 5]`
  - Node `5` is also a leaf node, so this path is added to `ans`.

- **Backtrack to Node `1` and Explore Right Child:** `getpath(3)`
  - Current path: `[1, 3]`
  - Node `3` is a leaf node, so this path is added to `ans`.

### Final Result

After completing the traversal, the `ans` vector will contain:
```cpp
[[1, 2, 4], [1, 2, 5], [1, 3]]
```
### Summary

- The `Paths` function is a high-level function that checks if the tree is empty and starts the path-finding process.
- It uses the helper function `getpath` to traverse the tree and record paths from the root to each leaf node.
- After the traversal is complete, it returns the list of paths found.

### Visual Summary of the Steps

- Start at the root (1), then traverse left (2), left again (4), and record the path.
- Backtrack to (2) and explore right (5), recording that path.
- Backtrack to the root and explore right (3), recording that path.

If you have specific parts that you still don’t understand, please let me know, and I can explain those in more detail!
