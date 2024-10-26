987. Vertical Order Traversal of a Binary Tree
Solved
Hard
Topics
Companies
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
This code performs a vertical order traversal on a binary tree and arranges nodes vertically based on their x-coordinates. Let's break down the code with explanations for each section, and then follow it up with a dry run.

### Code Explanation (Line-by-Line)

```cpp
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map structure: map<x-coordinate, map<y-coordinate, multiset<node-values>>>
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        
        // Start BFS with the root at (0, 0) coordinate
        todo.push({root, {0, 0}});
```

1. **Data Structure Setup**: 
   - `nodes`: A map to store nodes based on their coordinates. The outer `map<int, map<int, multiset<int>>>` allows ordering by `x` and `y` coordinates.
   - `todo`: A queue used for BFS traversal. Each queue entry contains a node and its `(x, y)` coordinate.
   
2. **Initialize BFS**: Push the root node with initial coordinates `(0, 0)` into the `todo` queue.

```cpp
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            
            // Insert the current node's value into the map
            nodes[x][y].insert(node->val);
```

3. **Processing Each Node in BFS**:
   - Dequeue the current node and extract its coordinates `(x, y)`.
   - Insert the current node’s value into `nodes` at `nodes[x][y]`, which stores values at a specific coordinate in a sorted order using `multiset`.

```cpp
            // If the left child exists, add it to the queue with adjusted coordinates
            if (node->left) {
                todo.push({node->left, {x - 1, y + 1}});
            }
            
            // If the right child exists, add it to the queue with adjusted coordinates
            if (node->right) {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }
```

4. **Add Child Nodes with Updated Coordinates**:
   - If the left child exists, it is enqueued with `x-1` and `y+1`, meaning it’s positioned one unit left and one level deeper.
   - If the right child exists, it is enqueued with `x+1` and `y+1`, meaning it’s positioned one unit right and one level deeper.

```cpp
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

5. **Prepare the Final Answer**:
   - `ans`: Stores the result of vertical traversal in order.
   - Traverse the `nodes` map:
     - For each `x` coordinate, gather all nodes sorted by their `y` coordinate.
     - Combine nodes at the same coordinate into a `vector<int>` and add it to `ans`.

### Dry Run Example

Consider the binary tree:

```
       1
      / \
     2   3
    / \   \
   4   5   6
```

1. **Initial State**:
   - `nodes` is empty.
   - `todo` queue starts with `[(1, (0, 0))]`.

2. **Processing Node 1** (Root at `(0, 0)`):
   - Insert `1` into `nodes[0][0]`.
   - Enqueue `2` at `(x = -1, y = 1)` and `3` at `(x = 1, y = 1)`.

3. **Processing Node 2** (at `(-1, 1)`):
   - Insert `2` into `nodes[-1][1]`.
   - Enqueue `4` at `(x = -2, y = 2)` and `5` at `(x = 0, y = 2)`.

4. **Processing Node 3** (at `(1, 1)`):
   - Insert `3` into `nodes[1][1]`.
   - Enqueue `6` at `(x = 2, y = 2)`.

5. **Processing Node 4** (at `(-2, 2)`):
   - Insert `4` into `nodes[-2][2]`.

6. **Processing Node 5** (at `(0, 2)`):
   - Insert `5` into `nodes[0][2]`.

7. **Processing Node 6** (at `(2, 2)`):
   - Insert `6` into `nodes[2][2]`.

### Final `nodes` Map

After BFS traversal, `nodes` will look like this:

```cpp
{
    -2: {2: {4}},
    -1: {1: {2}},
     0: {0: {1}, 2: {5}},
     1: {1: {3}},
     2: {2: {6}}
}
```

### Final Output Construction

Traverse `nodes` to construct the final result:

```cpp
ans = [[4], [2], [1, 5], [3], [6]]
```

So, `verticalTraversal` returns `[[4], [2], [1, 5], [3], [6]]`.

