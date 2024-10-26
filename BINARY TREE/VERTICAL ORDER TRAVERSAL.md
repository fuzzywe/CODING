987. Vertical Order Traversal of a Binary Tree
988. 
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

 

Example 1:
![image](https://github.com/user-attachments/assets/163cb9a1-ec8e-4cde-a0bf-624bdc930420)


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
Example 2:
![image](https://github.com/user-attachments/assets/f5aaaaf7-6d23-4bbf-9012-4e1eb3035484)


Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.
Example 3:
![image](https://github.com/user-attachments/assets/73b47fd7-f492-490b-b4d3-8b1bc7c6c4fa)


Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.

 ---


 ```cpp
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map structure: map<x-coordinate, map<y-coordinate, multiset<node-values>>>
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        
        // Start BFS with the root at (0, 0) coordinate
        todo.push({root, {0, 0}});
        
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            
            // Insert the current node's value into the map
            nodes[x][y].insert(node->val);
            
            // If the left child exists, add it to the queue with adjusted coordinates
            if (node->left) {
                todo.push({node->left, {x - 1, y + 1}});
            }
            
            // If the right child exists, add it to the queue with adjusted coordinates
            if (node->right) {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }
        
        // Prepare the final answer by traversing the nodes map
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

```
Certainly! Let's go through each line of code and explain what each line does with a detailed dry run for each step. 

Consider this binary tree as an example:

```
       1
      / \
     2   3
    / \   \
   4   5   6
```

Each line of the code will be broken down in terms of its operation in this traversal.

---

### Code with Step-by-Step Dry Run:

```cpp
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map structure: map<x-coordinate, map<y-coordinate, multiset<node-values>>>
```
- **Explanation**: Define a nested map `nodes` to store nodes based on their vertical (x) and level (y) positions. The innermost `multiset` holds node values at a specific (x, y) position in sorted order.
- **State**: `nodes` is currently empty.

```cpp
        map<int, map<int, multiset<int>>> nodes;
```
- **Explanation**: Initialize `nodes` as `map<int, map<int, multiset<int>>>` to store nodes by (x, y) coordinates.
- **State**: `nodes` is an empty map.

```cpp
        queue<pair<TreeNode*, pair<int, int>>> todo;
```
- **Explanation**: Initialize a queue `todo` to perform a Breadth-First Search (BFS). Each element in the queue contains a `TreeNode*` and its `(x, y)` coordinates.
- **State**: `todo` is an empty queue.

```cpp
        todo.push({root, {0, 0}});
```
- **Explanation**: Add the root node to the queue with coordinates `(0, 0)`.
- **State**: `todo` = `[(1, (0, 0))]` (Root node 1 at `(0, 0)`).

```cpp
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
```
- **Explanation**: Enter a loop that processes each node until the queue is empty.
  - Get the front node `p` from `todo`.
  - Remove this node from `todo`.
- **State**:
  - First iteration: `p = (1, (0, 0))`, `todo` is now empty.

```cpp
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
```
- **Explanation**: Extract the `node`, `x` (horizontal coordinate), and `y` (vertical coordinate) from `p`.
- **State**:
  - `node = 1`, `x = 0`, `y = 0`.

```cpp
            // Insert the current node's value into the map
            nodes[x][y].insert(node->val);
```
- **Explanation**: Insert `node->val` (1) into `nodes` at position `(x, y)`, or `(0, 0)`.
- **State**:
  - `nodes = {0: {0: {1}}}`

```cpp
            // If the left child exists, add it to the queue with adjusted coordinates
            if (node->left) {
                todo.push({node->left, {x - 1, y + 1}});
            }
```
- **Explanation**: If `node` has a left child, add it to `todo` with coordinates `(x - 1, y + 1)` (left one position and down one level).
- **State**:
  - `todo = [(2, (-1, 1))]` (Node 2 at coordinates `(-1, 1)`).

```cpp
            // If the right child exists, add it to the queue with adjusted coordinates
            if (node->right) {
                todo.push({node->right, {x + 1, y + 1}});
            }
```
- **Explanation**: If `node` has a right child, add it to `todo` with coordinates `(x + 1, y + 1)` (right one position and down one level).
- **State**:
  - `todo = [(2, (-1, 1)), (3, (1, 1))]` (Nodes 2 and 3).

---

### **Subsequent Iterations**

Continue the `while` loop:

#### Second Iteration:
- **State before loop**: `todo = [(2, (-1, 1)), (3, (1, 1))]`
- **Processing**:
  - `p = (2, (-1, 1))`, `node = 2`, `x = -1`, `y = 1`
  - Insert 2 into `nodes[-1][1]`: `nodes = {0: {0: {1}}, -1: {1: {2}}}`
  - Add left child `(4, (-2, 2))` and right child `(5, (0, 2))` to `todo`
- **State after iteration**: `todo = [(3, (1, 1)), (4, (-2, 2)), (5, (0, 2))]`

#### Third Iteration:
- **State before loop**: `todo = [(3, (1, 1)), (4, (-2, 2)), (5, (0, 2))]`
- **Processing**:
  - `p = (3, (1, 1))`, `node = 3`, `x = 1`, `y = 1`
  - Insert 3 into `nodes[1][1]`: `nodes = {0: {0: {1}}, -1: {1: {2}}, 1: {1: {3}}}`
  - Add right child `(6, (2, 2))` to `todo`
- **State after iteration**: `todo = [(4, (-2, 2)), (5, (0, 2)), (6, (2, 2))]`

#### Fourth Iteration:
- **State before loop**: `todo = [(4, (-2, 2)), (5, (0, 2)), (6, (2, 2))]`
- **Processing**:
  - `p = (4, (-2, 2))`, `node = 4`, `x = -2`, `y = 2`
  - Insert 4 into `nodes[-2][2]`: `nodes = {0: {0: {1}}, -1: {1: {2}}, 1: {1: {3}}, -2: {2: {4}}}`
- **State after iteration**: `todo = [(5, (0, 2)), (6, (2, 2))]`

#### Fifth Iteration:
- **State before loop**: `todo = [(5, (0, 2)), (6, (2, 2))]`
- **Processing**:
  - `p = (5, (0, 2))`, `node = 5`, `x = 0`, `y = 2`
  - Insert 5 into `nodes[0][2]`: `nodes = {0: {0: {1}, 2: {5}}, -1: {1: {2}}, 1: {1: {3}}, -2: {2: {4}}}`
- **State after iteration**: `todo = [(6, (2, 2))]`

#### Sixth Iteration:
- **State before loop**: `todo = [(6, (2, 2))]`
- **Processing**:
  - `p = (6, (2, 2))`, `node = 6`, `x = 2`, `y = 2`
  - Insert 6 into `nodes[2][2]`: `nodes = {0: {0: {1}, 2: {5}}, -1: {1: {2}}, 1: {1: {3}}, -2: {2: {4}}, 2: {2: {6}}}`
- **State after iteration**: `todo` is empty; exit loop.

---

### Final Map Traversal and Result Construction

```cpp
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
```

- **Explanation**: Traverse `nodes` map to collect nodes column-wise.
  - `ans = [[4], [2], [1, 5], [3], [6]]`
