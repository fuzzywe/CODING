99. Recover Binary Search Tree

https://leetcode.com/problems/recover-binary-search-tree/description/

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:

![image](https://github.com/user-attachments/assets/016d0129-e0b6-45c1-b047-6fbe8af2a88a)

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:
![image](https://github.com/user-attachments/assets/dee2d801-2259-44d9-94bd-8ed4444e0b1d)


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

C++ morris traversal || O(1) space


Binary Search Tree
According to question statement there will be only one swap necessary to make recover BST.

From observation inorder traversal in BST gives sorted arrays

Now if there is any nodes in in wrong order it makes array irregular

there can be one or two wrong ordered pairs of elements in inorders traversal array.

If one pair wrong ordered element then keep track of two element in that pair and swap their values.
If two wrong pair exist then swap first element of first pair with second element of second pair
Example:
BST inorder: 2, 1, 3 // one pair wrong ordered. here swaping 2 and 1 makes a BST valid
BST inorder: 1, 7, 3, 5, 6, 2, 8, // two pair wrong ordered. swaping 7 and 2 make valid BST


```cpp
class Solution {
    TreeNode* first{nullptr}, *second{nullptr}, *prev{nullptr};
public:
    void verifyNode(TreeNode* node){
	
	// check if previous pointer == null or node values are correct inorder traversal i.e prev is smaller than current node
        if(prev == nullptr || (prev->val<node->val)){ 
            prev = node;
            return;
        }
        
        if(first == nullptr ){
            first = prev;
            second = node;
        }else{ 
            second = node;
        }
    }
    void morrisInorder(TreeNode* root){
        if(!root)return;
        while(root){
            if(root->left == nullptr){
                verifyNode(root);
                root = root->right;
            }else{
                TreeNode* iter = root->left;
                // find predecessor
                while(iter->right && iter->right!=root){
                    iter = iter->right;
                }
                
                if(iter->right == nullptr)//create morris thread
                {
                    iter->right = root;
                    root = root->left;
                }else{
                    iter->right = nullptr;
                    verifyNode(root);
                    root = root->right;
                }
            }
        }
    }
    void recoverTree(TreeNode* root) {
        morrisInorder(root);
        swap(first->val, second->val);
    }
};

```
This code is solving a problem where two nodes in a Binary Search Tree (BST) have been swapped by mistake, and the goal is to identify and correct these swapped nodes. The solution uses **Morris Inorder Traversal** to avoid using extra space (like recursion or a stack) and restore the BST in-place.

Let’s break down the code step-by-step with a detailed explanation of each line and the Morris Inorder Traversal concept, followed by a dry run of an example.

---

### Concepts Explained

1. **Binary Search Tree (BST)**:
   - A BST is a tree where each node’s left child has a smaller value, and each node’s right child has a larger value.
   - In a correct BST, an **inorder traversal** (left-root-right) will yield a sorted sequence of values.

2. **Problem of Swapped Nodes**:
   - Two nodes in the BST have been swapped, violating the BST properties.
   - For example, in an inorder traversal, we should see increasing values, but two nodes might appear out of order, indicating they were swapped.

3. **Morris Inorder Traversal**:
   - Morris Traversal is a method of inorder traversal without using extra space (like a stack or recursion).
   - It achieves this by creating temporary "threads" (links) to nodes’ predecessors, allowing us to return to the root node after processing the left subtree.
   - This way, we can traverse the entire tree with only O(1) additional space.

4. **Restoring the BST**:
   - By using Morris Traversal, we can identify the two nodes that violate the BST property.
   - We keep track of the nodes using `first`, `second`, and `prev` pointers, which will help us locate and swap the misplaced nodes to restore the BST.

---

### Code Explanation with Dry Run

Let's go through each function and its components in detail.

#### Step 1: Defining Variables in the Class

```cpp
TreeNode* first{nullptr}, *second{nullptr}, *prev{nullptr};
```
- **`first`**: Points to the first node out of order.
- **`second`**: Points to the second node out of order.
- **`prev`**: Keeps track of the previous node during traversal for comparison.

---

### `verifyNode` Function

This function checks if the current node is in the correct inorder sequence by comparing it to the `prev` node. If it's not, it means there's a violation of the BST properties.

```cpp
void verifyNode(TreeNode* node){
    if(prev == nullptr || (prev->val < node->val)){ 
        prev = node;  // Set prev to the current node if order is correct
        return;
    }
    
    if(first == nullptr){
        first = prev;   // Mark the first incorrect node
        second = node;  // Mark the second node
    }else{
        second = node;  // Only update the second node if we find further violations
    }
}
```

**Explanation**:
- If `prev` is null or if `prev->val` is less than the current node's value, then the BST property is maintained, and we move forward.
- If we find a violation (i.e., `prev->val` >= `node->val`), we:
  - Set `first` to `prev` (the first misplaced node) if it hasn’t been set yet.
  - Set `second` to `node` (the second misplaced node).
  
---

### `morrisInorder` Function

This function implements Morris Inorder Traversal to traverse the tree without extra space.

```cpp
void morrisInorder(TreeNode* root){
    if(!root) return;  // Return if the tree is empty
    
    while(root){
        if(root->left == nullptr){
            verifyNode(root);  // Process current node
            root = root->right; // Move to the right subtree
        } else {
            TreeNode* iter = root->left;
            while(iter->right && iter->right != root){
                iter = iter->right;  // Move to the rightmost node of the left subtree
            }
            
            if(iter->right == nullptr){
                iter->right = root;  // Create a thread from rightmost to root
                root = root->left;  // Move to the left subtree
            } else {
                iter->right = nullptr;  // Remove the thread
                verifyNode(root);  // Process current node
                root = root->right;  // Move to the right subtree
            }
        }
    }
}
```

**Explanation**:
- If `root->left` is `nullptr`, we:
  - Process the current node by calling `verifyNode`.
  - Move to the `root->right`.
- If `root->left` is not `nullptr`, we find the **rightmost node in the left subtree** of `root` (this is called the predecessor).
  - If `iter->right` is `nullptr`, we create a "thread" by setting `iter->right = root` and move to `root->left`.
  - If `iter->right` points back to `root`, we:
    - Remove the thread by setting `iter->right = nullptr`.
    - Process the current node by calling `verifyNode`.
    - Move to `root->right`.

---

### `recoverTree` Function

Finally, this function calls `morrisInorder` to identify the swapped nodes and then swaps them to correct the BST.

```cpp
void recoverTree(TreeNode* root) {
    morrisInorder(root);  // Perform Morris Traversal to find misplaced nodes
    swap(first->val, second->val);  // Correct the BST by swapping values
}
```

**Explanation**:
- `morrisInorder(root)` performs the inorder traversal, identifying the `first` and `second` misplaced nodes.
- `swap(first->val, second->val)` restores the BST by swapping these nodes back to their correct positions.

---

### Dry Run Example

Suppose we have the BST where nodes `1` and `4` have been swapped:

**Tree structure** (before recovery):
```
      3
     / \
    1   4
     \   \
      2   5
```
**Correct BST structure** (after recovery):
```
      3
     / \
    2   4
   /     \
  1       5
```

**Inorder traversal of this tree (incorrect BST)**: `1, 3, 4, 2, 5`

During the traversal, we’ll notice that the node with value `4` comes before `2`, which violates the BST ordering.

---

### Step-by-Step Dry Run

1. **Initialize**: `first = nullptr`, `second = nullptr`, `prev = nullptr`
2. **First Call `morrisInorder(root)`**:
   - Current `root = 3`
   - **Left Subtree**: Move to `root->left = 1`, create a thread from `2` (rightmost in left subtree of `1`) back to `3`.
   
3. **Traversal Continues**:
   - `verifyNode(1)`: `prev = 1`
   - Move to `2` using the thread.
   - `verifyNode(2)`: `prev = 2`
   - Back to `3`, `verifyNode(3)`: `prev = 3`
   - Move to `4`, `verifyNode(4)`: **Detects issue with 4 > 2**
   - Set `first = 3`, `second = 2`
   
4. **Final Correction in `recoverTree`**:
   - `swap(first->val, second->val)`, swap values `3` and `2`.

The tree is now correctly restored. This completes the dry run, and the BST is valid again.

Let's break down the code in the most detailed, line-by-line dry run possible, explaining each line individually along with what it does in the context of our example tree.

The example tree with misplaced nodes is as follows:
```
      3
     / \
    1   4
         \
          2
```

We’ll go line by line, explaining exactly what happens at each line. 

---

### Step 1: Member Initialization

```cpp
TreeNode* first{nullptr}, *second{nullptr}, *prev{nullptr};
```

- **Purpose**: Initializes three pointers:
  - `first` and `second`: Used to store pointers to the two nodes that are out of order in the BST.
  - `prev`: Keeps track of the previous node in the inorder traversal to detect any violations in the BST property.
- **Initial State**: `first = nullptr`, `second = nullptr`, `prev = nullptr`.

---

### `verifyNode` Function - Line by Line

This helper function checks if a node violates the BST inorder property (left < root < right).

#### Line 1

```cpp
if (prev == nullptr || (prev->val < node->val)) {
```

- **Purpose**: Checks if either:
  - `prev` is `nullptr` (the very first node in the inorder traversal).
  - The `prev` node’s value is less than the current node’s value (meaning no BST violation here).
- **Example Execution (first call with `node = 1`)**: Since `prev = nullptr`, this condition is true. 

---

#### Line 2

```cpp
prev = node;
```

- **Purpose**: Sets `prev` to the current `node`, moving to the next node in the inorder traversal.
- **Example Execution**: `prev` is now set to `node = 1`.

---

#### Line 3

```cpp
return;
```

- **Purpose**: If no BST violation is found, exit `verifyNode` to continue traversal.
- **Example Execution**: For `node = 1`, this line exits `verifyNode` because no violation was detected.

---

#### Line 4

```cpp
if (first == nullptr) {
```

- **Purpose**: Checks if `first` is `nullptr`, which would mean it’s the first time we’re encountering a violation of the BST property.
- **Example Execution** (when a violation is detected): For `node = 2`, a violation is detected because `prev->val = 4` is greater than `node->val = 2`. Since `first = nullptr`, this condition will be true.

---

#### Line 5

```cpp
first = prev;
second = node;
```

- **Purpose**: Sets `first` to `prev` (the previous node that was in order) and `second` to `node` (the current node that is out of order).
- **Example Execution**: When `prev = 4` and `node = 2`, `first` becomes `4`, and `second` becomes `2`.

---

#### Line 6

```cpp
} else {
    second = node;
}
```

- **Purpose**: If we’ve already set `first` but encounter another violation, we set `second` to `node`.
- **Example Execution**: If another violation is encountered later, this line would update `second`.

---

### `morrisInorder` Function - Line by Line

The `morrisInorder` function performs an inorder traversal without extra space, using temporary pointers (Morris threading).

---

#### Line 1

```cpp
if (!root) return;
```

- **Purpose**: If the tree is empty, exit `morrisInorder`.
- **Example Execution**: Here, the root is not `nullptr`, so we proceed.

---

#### Line 2

```cpp
while (root) {
```

- **Purpose**: This loop continues the traversal as long as `root` is not `nullptr`.
- **Example Execution**: Starting with `root = 3`.

---

#### Line 3

```cpp
if (root->left == nullptr) {
```

- **Purpose**: Checks if the current node (`root`) has a left child. If there’s no left child, we visit this node directly.
- **Example Execution (first iteration)**: For `root = 3`, `root->left` is not `nullptr` (it’s `1`), so this condition is false.

---

#### Line 4

```cpp
TreeNode* iter = root->left;
```

- **Purpose**: If the current node has a left child, we begin to find the rightmost node in the left subtree (the inorder predecessor).
- **Example Execution**: Set `iter = root->left`, so `iter` is now `1`.

---

#### Line 5

```cpp
while (iter->right && iter->right != root) {
    iter = iter->right;
}
```

- **Purpose**: Move `iter` to the rightmost node in the left subtree, stopping if it points back to `root` (indicating a thread).
- **Example Execution**: `iter = 1`, and `iter->right = nullptr`, so the loop exits.

---

#### Line 6

```cpp
if (iter->right == nullptr) {
    iter->right = root;
    root = root->left;
}
```

- **Purpose**: If there’s no existing thread, create one by setting `iter->right = root`, and then move to the left subtree by setting `root = root->left`.
- **Example Execution**: `iter->right` is `nullptr`, so set `iter->right = 3`, creating a thread from `1` to `3`. Then set `root = 1`.

---

#### Line 7

```cpp
else {
    iter->right = nullptr;
    verifyNode(root);
    root = root->right;
}
```

- **Purpose**: If a thread exists, remove it (by setting `iter->right = nullptr`), verify the current node, and move to the right subtree.
- **Example Execution**: After visiting `1`, we reach `3` again, remove the thread from `1`, call `verifyNode(3)`, and move to `root->right`, so `root = 4`.

---

### `recoverTree` Function - Line by Line

This function calls the Morris Inorder Traversal and then swaps the misplaced nodes.

---

#### Line 1

```cpp
morrisInorder(root);
```

- **Purpose**: Calls the `morrisInorder` function to perform the inorder traversal, during which the misplaced nodes (`first` and `second`) are identified.

---

#### Line 2

```cpp
swap(first->val, second->val);
```

- **Purpose**: After traversal, `first` and `second` point to the two misplaced nodes, so this line swaps their values to correct the BST.
- **Example Execution**: `first` is `4` and `second` is `2`, so swapping them corrects the tree.

---

After running this, the corrected tree will be:
```
      3
     / \
    1   2
         \
          4
```

This completes the dry run for each line of the code. Let me know if you'd like further clarification on any specific line.
