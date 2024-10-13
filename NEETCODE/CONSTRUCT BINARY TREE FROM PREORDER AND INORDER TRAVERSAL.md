105. Construct Binary Tree from Preorder and Inorder Traversal
Medium
Topics
Companies
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.


Complexity
Time complexity: O(n)
Space complexity: O(n)

```cpp
class Solution {

private:
    int preorderIndex;
    unordered_map<int, int> mapping;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mapping.clear();
        for (int i = 0; i < inorder.size(); i++) {
            mapping[inorder[i]] = i;
        }

        preorderIndex = 0;
        return build(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mapping[rootVal];

        root->left = build(preorder, start, mid - 1);
        root->right = build(preorder, mid + 1, end);

        return root;
    }    
};
```

This solution reconstructs a binary tree using its **preorder** and **inorder** traversal arrays. The function uses recursion and a hash map for quick lookups to efficiently build the tree.

### Problem Explanation:
Given the **preorder** and **inorder** traversals of a binary tree, the goal is to rebuild the tree.

- **Preorder traversal** visits nodes in the order: root → left → right.
- **Inorder traversal** visits nodes in the order: left → root → right.

### Example:
For the given traversals:
- `preorder = [3, 9, 20, 15, 7]`
- `inorder = [9, 3, 15, 20, 7]`

The tree that needs to be reconstructed is:

```
      3
     / \
    9   20
       /  \
      15   7
```

### Line-by-Line Explanation:

```cpp
private:
    int preorderIndex;
    unordered_map<int, int> mapping;
```
- **Explanation**: Two private members are declared:
  - `preorderIndex`: This tracks the current index in the `preorder` array.
  - `mapping`: An unordered map (hash map) to store the index of each node value in the `inorder` array for fast lookup.

```cpp
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mapping.clear();
```
- **Explanation**: The `buildTree` function is the main public method, which initiates the tree-building process. First, it clears any previous values in the `mapping` to avoid issues from previous calls.

```cpp
        for (int i = 0; i < inorder.size(); i++) {
            mapping[inorder[i]] = i;
        }
```
- **Explanation**: This loop builds the `mapping` hash map. Each value from the `inorder` array is mapped to its index. This allows us to quickly find the index of any node in the `inorder` array later.

  For example:
  ```
  inorder = [9, 3, 15, 20, 7]
  mapping = {9: 0, 3: 1, 15: 2, 20: 3, 7: 4}
  ```

```cpp
        preorderIndex = 0;
```
- **Explanation**: We initialize `preorderIndex` to `0` because we always start building the tree from the first element in the `preorder` traversal (which is the root of the tree).

```cpp
        return build(preorder, 0, inorder.size() - 1);
    }
```
- **Explanation**: The `buildTree` function calls the recursive `build` method to construct the tree. It passes the entire `preorder` array and the range `[0, inorder.size() - 1]` for the `inorder` array, which represents the current subtree's boundaries.

---

### The `build` Function:

```cpp
private:
    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;
```
- **Explanation**: The `build` function is responsible for recursively constructing the tree. If the `start` index is greater than the `end` index, it means there are no nodes in this subtree, so we return `nullptr`.

```cpp
        int rootVal = preorder[preorderIndex++];
```
- **Explanation**: The current root node is found by using the current value from the `preorder` array at `preorderIndex`. We increment `preorderIndex` after picking the root value, as the next recursive call will use the next value for the next subtree.

  In the first call, `rootVal = preorder[0] = 3`.

```cpp
        TreeNode* root = new TreeNode(rootVal);
```
- **Explanation**: A new `TreeNode` is created for the root with the value `rootVal`.

```cpp
        int mid = mapping[rootVal];
```
- **Explanation**: Using the `mapping` hash map, we find the index `mid` of `rootVal` in the `inorder` array. This index splits the `inorder` array into two parts:
  - The left subtree is in the range `[start, mid - 1]`.
  - The right subtree is in the range `[mid + 1, end]`.

  For the example:
  - `rootVal = 3` and `mid = mapping[3] = 1`
  - Left subtree in `inorder`: `[9]` (from index `0` to `mid - 1`)
  - Right subtree in `inorder`: `[15, 20, 7]` (from index `mid + 1` to `4`)

```cpp
        root->left = build(preorder, start, mid - 1);
        root->right = build(preorder, mid + 1, end);
```
- **Explanation**: Recursively build the left and right subtrees:
  - For the left subtree, we pass the range `[start, mid - 1]` from the `inorder` array.
  - For the right subtree, we pass the range `[mid + 1, end]`.

  The recursion continues, building smaller subtrees until the entire tree is constructed.

```cpp
        return root;
    }    
```
- **Explanation**: Finally, return the root node once the left and right subtrees are attached.

---

### Dry Run:

Let's walk through the reconstruction process using the example:

#### Preorder: `[3, 9, 20, 15, 7]`
#### Inorder: `[9, 3, 15, 20, 7]`

1. **First Call**:
   - `preorderIndex = 0`, `rootVal = 3`
   - `mid = 1` (index of `3` in `inorder`)
   - Left subtree (inorder: `[9]`), Right subtree (inorder: `[15, 20, 7]`)
   
2. **Left Subtree of 3**:
   - `preorderIndex = 1`, `rootVal = 9`
   - `mid = 0` (index of `9` in `inorder`)
   - No left or right subtree (range invalid), so return `nullptr` for both.

3. **Right Subtree of 3**:
   - `preorderIndex = 2`, `rootVal = 20`
   - `mid = 3` (index of `20` in `inorder`)
   - Left subtree (inorder: `[15]`), Right subtree (inorder: `[7]`)
   
4. **Left Subtree of 20**:
   - `preorderIndex = 3`, `rootVal = 15`
   - `mid = 2` (index of `15` in `inorder`)
   - No left or right subtree, return `nullptr`.

5. **Right Subtree of 20**:
   - `preorderIndex = 4`, `rootVal = 7`
   - `mid = 4` (index of `7` in `inorder`)
   - No left or right subtree, return `nullptr`.

The final tree structure is:

```
      3
     / \
    9   20
       /  \
      15   7
```

### Time Complexity:
- **Time Complexity**: O(n), where `n` is the number of nodes in the tree. Each node is processed exactly once.
- **Space Complexity**: O(n), due to the space required for the recursion stack and the hash map.


why we aren't mapping preorder why inorder

We map the **inorder** traversal instead of the **preorder** traversal because of the specific properties of these two types of traversals in binary trees:

### 1. **Preorder Traversal Properties:**
- In **preorder** traversal, nodes are visited in the following order:
  1. **Root**
  2. **Left subtree**
  3. **Right subtree**
  
  The root node is always the first element of any subtree in the **preorder** array. Therefore, by iterating through the **preorder** array from left to right, we can naturally find the root node of each subtree in sequence without needing a map.

  - **Example:**
    - For `preorder = [3, 9, 20, 15, 7]`, `3` is the root of the whole tree, `9` is the root of the left subtree, and `20` is the root of the right subtree, and so on.
  
  Since we always know the root of the current subtree from the current index of the **preorder** array, there's no need to map the preorder values.

### 2. **Inorder Traversal Properties:**
- In **inorder** traversal, nodes are visited in the following order:
  1. **Left subtree**
  2. **Root**
  3. **Right subtree**

  The inorder traversal is crucial for determining the boundaries between the left and right subtrees of any node:
  - When you know the position of a node (i.e., the root) in the **inorder** array, you can immediately determine which part of the array corresponds to the **left subtree** and which part corresponds to the **right subtree**.

  Therefore, mapping the **inorder** array allows you to:
  - Quickly find the root’s position in **O(1)** time.
  - Easily divide the **inorder** array into left and right subtrees based on that position.

  - **Example:**
    - For `inorder = [9, 3, 15, 20, 7]`, once we know that the root `3` is at index `1`, we can split the array:
      - Left subtree (`inorder[0:0]`): `[9]`
      - Right subtree (`inorder[2:4]`): `[15, 20, 7]`

### Why Inorder and Not Preorder:
- **Preorder already gives the root** directly, so no mapping is needed for it.
- **Inorder** gives the exact positions of the left and right subtrees around the root, so mapping **inorder** is crucial to divide the tree efficiently.

### Summary of Key Points:
- **Preorder** naturally provides the root of the subtree in the current recursion step, so no map is needed for it.
- **Inorder** helps split the tree into left and right subtrees by locating the root’s position, so we map it for efficient lookup (O(1) time).

By combining the root discovery from **preorder** and the tree-splitting from **inorder**, the algorithm can efficiently reconstruct the binary tree.


solution two

Complexity
Time complexity: O(n2)
Space complexity: O(n2)


```cpp
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        deque<int> preorderQueue(preorder.begin(), preorder.end());
        return build(preorderQueue, inorder);        
    }

private:
    TreeNode* build(deque<int>& preorder, vector<int>& inorder) {
        if (!inorder.empty()) {
            int val = preorder.front();
            preorder.pop_front();
            auto it = find(inorder.begin(), inorder.end(), val);
            int idx = it - inorder.begin();

            TreeNode* root = new TreeNode(val);
            vector<int> leftInorder(inorder.begin(), inorder.begin() + idx);
            vector<int> rightInorder(inorder.begin() + idx + 1, inorder.end());

            root->left = build(preorder, leftInorder);
            root->right = build(preorder, rightInorder);

            return root;
        }

        return nullptr;
    }    
};

```
Let's walk through a dry run of the code **line by line** with the following example:

### Example Input:
- `preorder = [3, 9, 20, 15, 7]`
- `inorder = [9, 3, 15, 20, 7]`

We'll go through each step, explaining what happens and how the data structures change.

### Code:
```cpp
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        deque<int> preorderQueue(preorder.begin(), preorder.end());
        return build(preorderQueue, inorder);        
    }

private:
    TreeNode* build(deque<int>& preorder, vector<int>& inorder) {
        if (!inorder.empty()) {
            int val = preorder.front();
            preorder.pop_front();
            auto it = find(inorder.begin(), inorder.end(), val);
            int idx = it - inorder.begin();

            TreeNode* root = new TreeNode(val);
            vector<int> leftInorder(inorder.begin(), inorder.begin() + idx);
            vector<int> rightInorder(inorder.begin() + idx + 1, inorder.end());

            root->left = build(preorder, leftInorder);
            root->right = build(preorder, rightInorder);

            return root;
        }
        return nullptr;
    }
};
```

---

### **Step 1: `buildTree(preorder, inorder)`**

- **Line:**
  ```cpp
  deque<int> preorderQueue(preorder.begin(), preorder.end());
  ```
  - **Explanation:** Convert the `preorder` vector `[3, 9, 20, 15, 7]` into a `deque`. Now, `preorderQueue` will look like this:
    ```
    preorderQueue = [3, 9, 20, 15, 7]
    ```

- **Line:**
  ```cpp
  return build(preorderQueue, inorder);
  ```
  - **Explanation:** Call the recursive function `build()` with `preorderQueue` and the original `inorder` vector `[9, 3, 15, 20, 7]`.

---

### **Step 2: `build(preorderQueue, inorder)` (First Call)**

- **Line:**
  ```cpp
  if (!inorder.empty()) { 
  ```
  - **Explanation:** Since the `inorder` array is not empty (`[9, 3, 15, 20, 7]`), continue.

- **Line:**
  ```cpp
  int val = preorder.front();
  ```
  - **Explanation:** Get the first value from `preorderQueue`, which is `3`. Now:
    ```
    val = 3
    preorderQueue = [9, 20, 15, 7]
    ```

- **Line:**
  ```cpp
  preorder.pop_front();
  ```
  - **Explanation:** Remove the front element (`3`) from `preorderQueue`.

- **Line:**
  ```cpp
  auto it = find(inorder.begin(), inorder.end(), val);
  int idx = it - inorder.begin();
  ```
  - **Explanation:** Find the value `3` in the `inorder` array. It is at index `1`. Now:
    ```
    idx = 1
    ```

- **Line:**
  ```cpp
  TreeNode* root = new TreeNode(val);
  ```
  - **Explanation:** Create a new `TreeNode` with the value `3`. This node will be the root of the tree or subtree. Now:
    ```
    root = TreeNode(3)
    ```

- **Line:**
  ```cpp
  vector<int> leftInorder(inorder.begin(), inorder.begin() + idx);
  vector<int> rightInorder(inorder.begin() + idx + 1, inorder.end());
  ```
  - **Explanation:** Split the `inorder` array into two parts based on the index `1`:
    - **Left Subtree:** Elements before index `1` (`[9]`).
    - **Right Subtree:** Elements after index `1` (`[15, 20, 7]`).
    Now:
    ```
    leftInorder = [9]
    rightInorder = [15, 20, 7]
    ```

- **Line:**
  ```cpp
  root->left = build(preorder, leftInorder);
  ```
  - **Explanation:** Recursively build the left subtree of the current root (`3`) using `preorderQueue` and `leftInorder` (`[9]`).

---

### **Step 3: `build(preorderQueue, leftInorder)` (Left Subtree of 3)**

- **Line:**
  ```cpp
  if (!inorder.empty()) { 
  ```
  - **Explanation:** Since the `inorder` array is not empty (`[9]`), continue.

- **Line:**
  ```cpp
  int val = preorder.front();
  ```
  - **Explanation:** Get the first value from `preorderQueue`, which is `9`. Now:
    ```
    val = 9
    preorderQueue = [20, 15, 7]
    ```

- **Line:**
  ```cpp
  preorder.pop_front();
  ```
  - **Explanation:** Remove the front element (`9`) from `preorderQueue`.

- **Line:**
  ```cpp
  auto it = find(inorder.begin(), inorder.end(), val);
  int idx = it - inorder.begin();
  ```
  - **Explanation:** Find the value `9` in the `inorder` array. It is at index `0`. Now:
    ```
    idx = 0
    ```

- **Line:**
  ```cpp
  TreeNode* root = new TreeNode(val);
  ```
  - **Explanation:** Create a new `TreeNode` with the value `9`. This node will be the left child of the root `3`. Now:
    ```
    root = TreeNode(9)
    ```

- **Line:**
  ```cpp
  vector<int> leftInorder(inorder.begin(), inorder.begin() + idx);
  vector<int> rightInorder(inorder.begin() + idx + 1, inorder.end());
  ```
  - **Explanation:** Split the `inorder` array into two parts based on the index `0`:
    - **Left Subtree:** No elements (`[]`).
    - **Right Subtree:** No elements (`[]`).
    Now:
    ```
    leftInorder = []
    rightInorder = []
    ```

- **Line:**
  ```cpp
  root->left = build(preorder, leftInorder);
  ```
  - **Explanation:** Recursively build the left subtree of the current root (`9`) using `preorderQueue` and `leftInorder` (`[]`).

---

### **Step 4: `build(preorderQueue, leftInorder)` (Left Subtree of 9)**

- **Line:**
  ```cpp
  if (!inorder.empty()) {
  ```
  - **Explanation:** Since `inorder` is empty (`[]`), return `nullptr` for the left child of `9`.

---

### **Step 5: Back to Left Subtree of 9**

- **Line:**
  ```cpp
  root->right = build(preorder, rightInorder);
  ```
  - **Explanation:** Recursively build the right subtree of `9` using `preorderQueue` and `rightInorder` (`[]`).

---

### **Step 6: `build(preorderQueue, rightInorder)` (Right Subtree of 9)**

- **Line:**
  ```cpp
  if (!inorder.empty()) {
  ```
  - **Explanation:** Since `inorder` is empty (`[]`), return `nullptr` for the right child of `9`.

---

### **Step 7: Back to Root 3 (Right Subtree)**

- **Line:**
  ```cpp
  root->right = build(preorder, rightInorder);
  ```
  - **Explanation:** Recursively build the right subtree of the root (`3`) using `preorderQueue` and `rightInorder` (`[15, 20, 7]`).

---

### **Step 8: `build(preorderQueue, rightInorder)` (Right Subtree of 3)**

Repeat similar steps as above for constructing the right subtree of `3` with nodes `20`, `15`, and `7`.

---

### Final Output:

The constructed binary tree will look like:

```
      3
     / \
    9   20
       /  \
     15    7
```

This code reconstructs a binary tree from its **preorder** and **inorder** traversal arrays. Here's a detailed breakdown of how the code works, followed by an explanation of each part:

### Step-by-Step Explanation:

#### 1. **`buildTree()` Function:**
- **Purpose:** This function is the entry point, which initiates the tree construction by calling the recursive helper function `build()`.
- **Parameters:**
  - `preorder`: A vector of integers representing the preorder traversal of the binary tree.
  - `inorder`: A vector of integers representing the inorder traversal of the binary tree.
  
- **Deque Initialization:** 
  - The `preorder` vector is converted to a `deque` (double-ended queue) called `preorderQueue`.
  - **Why `deque`?** A `deque` allows fast access to the front, and popping from the front (which is needed in preorder traversal) is efficient.

```cpp
deque<int> preorderQueue(preorder.begin(), preorder.end());
return build(preorderQueue, inorder);
```

- **`build()` Recursive Function Call:** The `build()` function is called with `preorderQueue` and `inorder` to recursively construct the tree.

---

#### 2. **`build()` Recursive Helper Function:**
- **Purpose:** Recursively builds the binary tree using the preorder and inorder arrays.
- **Parameters:**
  - `preorder`: A reference to the `deque` containing the preorder traversal elements.
  - `inorder`: A vector representing the current portion of the inorder traversal array.

##### Base Case:
- **Empty Inorder Array:** If the `inorder` array is empty, there is no node to construct, so return `nullptr` (indicating no child in that branch).
```cpp
if (!inorder.empty()) { /* continue */ } else { return nullptr; }
```

##### Recursive Case:
- **Step 1: Get the Root from Preorder**
  - **`preorder.front()`** gives the first element of the preorder array, which is always the root node of the current subtree.
  - This value is stored in `val`, and `preorder.pop_front()` removes it from the `deque`.
  
```cpp
int val = preorder.front();
preorder.pop_front();
```

- **Step 2: Find the Root in Inorder**
  - The root value `val` is found in the `inorder` array using `find()`.
  - `idx` represents the index of the root value in the `inorder` array. This index splits the `inorder` array into two parts:
    - **Left subtree elements:** Elements before `idx`.
    - **Right subtree elements:** Elements after `idx`.

```cpp
auto it = find(inorder.begin(), inorder.end(), val);
int idx = it - inorder.begin();
```

- **Step 3: Construct the Root Node**
  - A new `TreeNode` is created with the root value `val`.
```cpp
TreeNode* root = new TreeNode(val);
```

- **Step 4: Divide the Inorder Array**
  - The `inorder` array is split into two parts:
    - **Left Subtree Inorder:** Elements before the root (`inorder.begin()` to `inorder.begin() + idx`).
    - **Right Subtree Inorder:** Elements after the root (`inorder.begin() + idx + 1` to `inorder.end()`).

```cpp
vector<int> leftInorder(inorder.begin(), inorder.begin() + idx);
vector<int> rightInorder(inorder.begin() + idx + 1, inorder.end());
```

- **Step 5: Recursively Build Subtrees**
  - The `build()` function is recursively called for both the left and right subtrees using the `preorder` deque and the divided `inorder` arrays.
  - These recursive calls return the left and right child nodes, which are assigned to the root node’s `left` and `right` pointers.

```cpp
root->left = build(preorder, leftInorder);
root->right = build(preorder, rightInorder);
```

- **Return the Root:** Finally, return the constructed root node (and its subtrees).

```cpp
return root;
```

##### Base Case for Empty Subtree:
- If the `inorder` array is empty (i.e., no more nodes in that subtree), return `nullptr`.

```cpp
return nullptr;
```

---

### Dry Run Example:

Given:
- `preorder = [3, 9, 20, 15, 7]`
- `inorder = [9, 3, 15, 20, 7]`

1. **First Call (Root Construction):**
   - `preorder.front()` is `3`, so the root is `3`.
   - In `inorder`, `3` is at index `1`. Split `inorder` into:
     - Left subtree: `[9]`
     - Right subtree: `[15, 20, 7]`
   - Recursively build left and right subtrees.

2. **Left Subtree of 3:**
   - `preorder.front()` is `9`, so the left child of `3` is `9`.
   - In `inorder`, `9` is at index `0`. Split `inorder` into:
     - Left subtree: `[]`
     - Right subtree: `[]` (both empty).
   - Since both parts are empty, the left and right children of `9` are `nullptr`.

3. **Right Subtree of 3:**
   - `preorder.front()` is `20`, so the right child of `3` is `20`.
   - In `inorder`, `20` is at index `1`. Split `inorder` into:
     - Left subtree: `[15]`
     - Right subtree: `[7]`
   - Recursively build left and right subtrees.

4. **Left Subtree of 20:**
   - `preorder.front()` is `15`, so the left child of `20` is `15`.
   - In `inorder`, `15` is at index `0`. Split `inorder` into:
     - Left subtree: `[]`
     - Right subtree: `[]` (both empty).
   - The left and right children of `15` are `nullptr`.

5. **Right Subtree of 20:**
   - `preorder.front()` is `7`, so the right child of `20` is `7`.
   - In `inorder`, `7` is at index `0`. Split `inorder` into:
     - Left subtree: `[]`
     - Right subtree: `[]` (both empty).
   - The left and right children of `7` are `nullptr`.

### Final Tree Structure:
```
      3
     / \
    9   20
       /  \
     15    7
```

### Conclusion:
This code constructs a binary tree using preorder and inorder traversals by leveraging the order of node discovery from preorder and the splitting of subtrees from inorder. The use of `deque` for preorder makes it efficient to pop elements, while recursively dividing the inorder array helps build the correct subtree structure.
