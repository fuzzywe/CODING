
https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

 ```cpp
      1
    /     \
   2       3
  /  \    /   \
4    5  6      7

```


Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 
For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

Example 1:

Input:

```cpp
      1
   /    \
  2      3

```
Output: 2 1 3
Example 2:

Input:

```cpp
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100

```
Output: 40 20 10 30 100
Your Task:
Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N).


```cpp
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == nullptr) return ans;
        
        map<int,int> mpp;
        queue<pair<Node * , int>> q;
        q.push({root , 0});
        while(!q.empty()){
            auto it = q.front();
            Node *node = it.first;
            int line = it.second;
            q.pop();
            if(mpp.find(line) == mpp.end()){//0 is 
                mpp[line] = node->data;
            }
            if(node->left != nullptr){
                q.push({node->left , line - 1});
            }
            if(node->right != nullptr){
                q.push({node->right , line + 1});
            }
            
        }
        
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }

};

```
---
**why not  recursive ? recursive traverse all the nodes. i need only top view so i will go for level order bcz** **recursive will traverse all the node.**

---

Let's go through the code step-by-step and perform a dry run with a detailed explanation for each line. This function, `topView`, calculates the "top view" of a binary tree, which is the set of nodes visible when the tree is viewed from above.

Consider the following example tree for our dry run:

```
       1
      / \
     2   3
    /     \
   4       5
```

### Code Explanation with Dry Run:

```cpp
class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
```
- **Explanation**: Initializes an empty vector `ans` to store the top view nodes, which will be returned at the end.
- **State**: `ans = []`

```cpp
        if(root == nullptr) return ans;
```
- **Explanation**: Checks if the tree is empty. If `root` is `nullptr`, return an empty vector.
- **State**: For our tree, `root` is not `nullptr`, so we proceed.

```cpp
        map<int,int> mpp;
```
- **Explanation**: Creates a `map` named `mpp` to store the first node encountered at each horizontal distance (or line) from the root. The key is the horizontal line number, and the value is the node's value.
- **State**: `mpp = {}`

```cpp
        queue<pair<Node*, int>> q;
        q.push({root , 0});
```
- **Explanation**: Initializes a queue `q` to perform a level-order traversal (BFS) and starts with the root node at horizontal distance `0`.
- **State**: `q = [(1, 0)]` (Root node `1` at horizontal distance `0`)

```cpp
        while(!q.empty()) {
            auto it = q.front();
            Node* node = it.first;
            int line = it.second;
            q.pop();
```
- **Explanation**: Start a loop that continues until the queue is empty. Extracts the front element of the queue into `it`, assigns the node to `node`, and the horizontal line to `line`. Then, removes this node from the queue.
- **State**:
  - First iteration: `node = 1`, `line = 0`, `q = []`

```cpp
            if(mpp.find(line) == mpp.end()) {
                mpp[line] = node->data;
            }
```
- **Explanation**: Checks if `line` is already in `mpp`. If not, it means this is the first node encountered at this horizontal line, so the node’s value is added to `mpp` for the top view.
- **State**:
  - First iteration: `mpp = {0: 1}` (Node `1` added at line `0`)

```cpp
            if(node->left != nullptr) {
                q.push({node->left, line - 1});
            }
```
- **Explanation**: Checks if the current node has a left child. If it does, it pushes the left child to `q` with a horizontal distance of `line - 1`.
- **State**:
  - First iteration: `q = [(2, -1)]` (Left child node `2` added with line `-1`)

```cpp
            if(node->right != nullptr) {
                q.push({node->right, line + 1});
            }
```
- **Explanation**: Checks if the current node has a right child. If it does, it pushes the right child to `q` with a horizontal distance of `line + 1`.
- **State**:
  - First iteration: `q = [(2, -1), (3, 1)]` (Right child node `3` added with line `1`)

### **Subsequent Iterations**

Continue the `while` loop for each node in `q`.

#### Second Iteration:
- **State before loop**: `q = [(2, -1), (3, 1)]`
- **Processing**:
  - `node = 2`, `line = -1`, `q = [(3, 1)]`
  - Since `-1` is not in `mpp`, add `2`: `mpp = {0: 1, -1: 2}`
  - Left child `4` is added to `q` with `line = -2`: `q = [(3, 1), (4, -2)]`

#### Third Iteration:
- **State before loop**: `q = [(3, 1), (4, -2)]`
- **Processing**:
  - `node = 3`, `line = 1`, `q = [(4, -2)]`
  - Since `1` is not in `mpp`, add `3`: `mpp = {0: 1, -1: 2, 1: 3}`
  - Right child `5` is added to `q` with `line = 2`: `q = [(4, -2), (5, 2)]`

#### Fourth Iteration:
- **State before loop**: `q = [(4, -2), (5, 2)]`
- **Processing**:
  - `node = 4`, `line = -2`, `q = [(5, 2)]`
  - Since `-2` is not in `mpp`, add `4`: `mpp = {0: 1, -1: 2, 1: 3, -2: 4}`

#### Fifth Iteration:
- **State before loop**: `q = [(5, 2)]`
- **Processing**:
  - `node = 5`, `line = 2`, `q = []`
  - Since `2` is not in `mpp`, add `5`: `mpp = {0: 1, -1: 2, 1: 3, -2: 4, 2: 5}`
- **Exit loop**: `q` is now empty.

---

### Final Map Traversal to Build the Result

```cpp
        for(auto it : mpp) {
            ans.push_back(it.second);
        }
```
- **Explanation**: Traverse the `mpp` map in ascending order of `line` and append each node's value to `ans`.
- **State**:
  - `ans = [4, 2, 1, 3, 5]`

```cpp
        return ans;
    }
};
```
- **Explanation**: Return the `ans` vector, which contains the nodes visible from the top view of the binary tree.
- **Final Output**:
  - For the given tree, the top view is `[4, 2, 1, 3, 5]`.

### Summary of `mpp` after all iterations:
- `mpp` contains nodes from leftmost to rightmost lines:
  - `-2: 4`
  - `-1: 2`
  - `0: 1`
  - `1: 3`
  - `2: 5`

### Final Output:
- **Top View**: `[4, 2, 1, 3, 5]`
