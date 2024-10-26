102. Binary Tree Level Order Traversal
Medium
Topics
Companies
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>v;
            for(int i=0;i<s;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                v.push_back(node->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
```

This code defines a method `levelOrder` for performing a **level-order traversal** (also known as a breadth-first traversal) of a binary tree. The traversal visits nodes level by level, from left to right. The method takes the root of a binary tree as input and returns a 2D vector containing the values of the nodes at each level.

### Example:

Consider this binary tree:

```
        3
       / \
      9   20
         /  \
        15   7
```

The output for this tree should be:

```
[[3], [9, 20], [15, 7]]
```

This corresponds to:
- Level 1: `3`
- Level 2: `9, 20`
- Level 3: `15, 7`

### Line-by-Line Explanation:

```cpp
vector<vector<int>> ans;
```
- **Explanation**: We define `ans`, a 2D vector that will store the node values level by level. Each inner vector represents one level of the binary tree.

```cpp
if(root==NULL) return ans;
```
- **Explanation**: If the tree is empty (i.e., `root == NULL`), we immediately return the empty `ans` since there are no nodes to traverse.

```cpp
queue<TreeNode*> q;
q.push(root);
```
- **Explanation**: We declare a queue `q` of type `TreeNode*`. This queue will be used for the breadth-first traversal. We initialize the queue by pushing the root node into it, as this is the starting point of the traversal.

### **Dry Run** (So far):
- **Tree**: `3`
  - Queue (`q`): `[3]`
  - Result (`ans`): `[]` (empty)

```cpp
while(!q.empty()) {
```
- **Explanation**: This while loop continues as long as the queue is not empty, meaning there are still nodes to process.

```cpp
int s = q.size();
```
- **Explanation**: `s` stores the current size of the queue, which represents the number of nodes at the current level. This ensures we process all nodes at the current level before moving to the next.

### **Dry Run** (At this point):
- **Queue (`q`)**: `[3]`
  - `s = 1` (since the queue contains the root node only)

```cpp
vector<int> v;
```
- **Explanation**: This vector `v` will temporarily store the values of nodes at the current level.

```cpp
for(int i = 0; i < s; i++) {
```
- **Explanation**: This for loop iterates over all nodes at the current level (`s` nodes). We process each node one by one.

### **Dry Run** (Processing root):
- For `i = 0`:
  - We will process the root node (`3`).

```cpp
TreeNode* node = q.front();
q.pop();
```
- **Explanation**: We retrieve (but do not remove) the node at the front of the queue using `q.front()` and then remove it from the queue using `q.pop()`.

### **Dry Run** (Processing node `3`):
- `node = 3`
- After popping `3`:
  - Queue (`q`): `[]`

```cpp
if(node->left != NULL) q.push(node->left);
if(node->right != NULL) q.push(node->right);
```
- **Explanation**: If the current node (`node`) has a left child, we push the left child into the queue. Similarly, if the current node has a right child, we push the right child into the queue.

### **Dry Run** (Adding children of node `3`):
- Left child: `9`, Right child: `20`
  - Queue (`q`): `[9, 20]`

```cpp
v.push_back(node->val);
```
- **Explanation**: We add the value of the current node (`node->val`) to the `v` vector, which stores the values of the nodes at the current level.

### **Dry Run** (After processing `3`):
- `v = [3]`

```cpp
ans.push_back(v);
```
- **Explanation**: After processing all nodes at the current level, we add the vector `v` (which contains the values of the current level) to `ans`.

### **Dry Run** (After first level):
- `ans = [[3]]`

### **Repeat Process for Next Level**:
At this point, the while loop runs again for the next level (nodes `9` and `20`).

```cpp
s = q.size();  // Now, s = 2 (since we have 2 nodes in the queue)
vector<int> v;  // Reset the vector for the next level
```
- **Explanation**: We update `s` to the current size of the queue, which is 2 (for nodes `9` and `20`).

```cpp
for(int i = 0; i < s; i++) {  // Process nodes `9` and `20`
    TreeNode* node = q.front();
    q.pop();
```
- **Explanation**: We process each node at this level, just like in the previous level.

- For `i = 0`:
  - `node = 9`
  - Queue (`q`): `[20]`
  - `v = [9]`
  - Node `9` has no children, so we don't push anything to the queue.

- For `i = 1`:
  - `node = 20`
  - Queue (`q`): `[]`
  - `v = [9, 20]`
  - Node `20` has children `15` and `7`, so:
    - Queue (`q`): `[15, 7]`

- After the second level, `ans = [[3], [9, 20]]`.

### Final Level:
The process repeats for the next level (nodes `15` and `7`):
- `s = 2`
- Process nodes `15` and `7`, resulting in `v = [15, 7]` and `ans = [[3], [9, 20], [15, 7]]`.

```cpp
return ans;
```
- **Explanation**: After processing all levels, we return the result `ans`, which contains the values of the binary tree's nodes level by level.

### Final Output:
For the given example tree, the output is:

```
[[3], [9, 20], [15, 7]]
```
