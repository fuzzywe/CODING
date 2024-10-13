230. Kth Smallest Element in a BST
Solved
Medium
Topics
Companies
Hint
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104


 
(1) Naive Approach:
Intuition:
We can do traversal of the given tree using any traversal technique and store the node values in an array/vector. Then we can sort the array in ascending order such that the 1st smallest element comes at 0th index, 2nd smallest element at 1st index ... kth samllest element at k-1th index.

Algorithm:
Initialize an empty vector 'v'.
Do any traversal (lets say preorder) and store the node values in v.
Sort vector v in ascending order.
Return v[k-1].
Complexity:
Time complexity: O(n) + O(nlogn) -> O(nlogn)
O(n) for traversing the Tree and O(nlogn) for sorting the vector of size n.

Space complexity:O(n) + recursive stack space

Code
```cpp
class Solution {
public:
    void preOrderTraversal(TreeNode* root, vector<int> &v){
        if(root == NULL)    return;
        
        //root, left, right 
        v.push_back(root->val);
        preOrderTraversal(root->left, v);
        preOrderTraversal(root->right, v);      
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v; 
        preOrderTraversal(root, v);
        sort(v.begin(), v.end());
        return v[k-1];
    }
};
```

optimized solution
```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        int count = 0;

        // Iterative in-order traversal
        while (curr != NULL || !st.empty()) {
            // Traverse to the leftmost node
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            // Pop the top node
            curr = st.top();
            st.pop();
            count++;

            // If count matches k, we've found the k-th smallest
            if (count == k) return curr->val;

            // Move to the right subtree
            curr = curr->right;
        }

        return -1; // This should never be reached if the tree is valid and k is correct
    }
};
```

Space Complexity: 𝑂(ℎ) 
Time Complexity: O(k)


It’s not possible to reduce the space complexity to **O(1)** in terms of auxiliary space while maintaining the correctness of the solution, because the in-order traversal inherently requires either a stack (for an iterative approach) or recursion (which implicitly uses the call stack). 

However, we can achieve **O(1)** auxiliary space using **Morris Traversal**. Morris Traversal is a method for in-order traversal of a binary tree that doesn’t use a stack or recursion. Instead, it temporarily modifies the tree structure by creating and removing threads (links) between nodes, and then restores the original tree structure after the traversal is complete.

### Morris In-Order Traversal:

The Morris Traversal algorithm avoids using extra space by threading the tree. It establishes a temporary link between the current node and its predecessor in the in-order sequence, allowing you to traverse the tree without a stack.

### Code for finding the \(k\)th smallest element with **O(1)** space complexity:

```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;  // To count the number of processed nodes
        int result = -1;  // To store the result

        TreeNode* current = root;

        while (current != nullptr) {
            if (current->left == nullptr) {
                // Visit this node
                count++;
                if (count == k) {
                    result = current->val;
                }
                // Move to the right subtree
                current = current->right;
            } else {
                // Find the inorder predecessor of current
                TreeNode* pred = current->left;
                while (pred->right != nullptr && pred->right != current) {
                    pred = pred->right;
                }

                // Make a thread (temporary link) between the predecessor and current
                if (pred->right == nullptr) {
                    pred->right = current;
                    current = current->left;
                }
                // Revert the changes (remove the thread) and visit the node
                else {
                    pred->right = nullptr;
                    count++;
                    if (count == k) {
                        result = current->val;
                    }
                    current = current->right;
                }
            }
        }

        return result;
    }
};
```

### **Explanation**:

1. **Morris Traversal** modifies the tree structure temporarily:
   - If the left child is null, visit the node and move to the right child.
   - If the left child exists, find the in-order predecessor (rightmost node in the left subtree).
   - Create a temporary thread (link) from the in-order predecessor to the current node.
   - Move to the left child to continue traversal.
   - When returning to the node after visiting the left subtree, remove the thread (restore the tree) and visit the node.

2. **When we find the \(k\)-th node**:
   - We increment the count each time we visit a node.
   - When `count == k`, we store the result and terminate.

### **Dry Run Example**:

Let's take the same binary tree:

```
     5
    / \
   3   7
  / \   \
 2   4   8
/
1
```

Assume \(k = 3\) (we want to find the 3rd smallest element).

1. **Current Node = 5**:
   - Left child exists, find predecessor (rightmost in left subtree).
   - Predecessor = 4. Create a thread from 4 to 5 and move to 3.

2. **Current Node = 3**:
   - Left child exists, find predecessor (rightmost in left subtree).
   - Predecessor = 2. Create a thread from 2 to 3 and move to 2.

3. **Current Node = 2**:
   - Left child exists, find predecessor (rightmost in left subtree).
   - Predecessor = 1. Create a thread from 1 to 2 and move to 1.

4. **Current Node = 1**:
   - No left child, visit node (count = 1), move to the right (null).

5. **Back to Node = 2**:
   - Remove thread from 1 to 2, visit node (count = 2), move to the right (null).

6. **Back to Node = 3**:
   - Remove thread from 2 to 3, visit node (count = 3). Since count == 3, we return 3.

### **Time Complexity**:

- **Time Complexity**: **O(n)**.
  - Every edge of the tree is visited at most twice (once to create the thread, once to remove it).
  - Therefore, the time complexity is linear in the number of nodes.

### **Space Complexity**:

- **Space Complexity**: **O(1)** auxiliary space.
  - No stack or recursion is used.
  - Only a few pointers are used, and the tree structure is temporarily modified and restored.

### **Summary**:

- The Morris Traversal method allows you to achieve **O(1)** space complexity (without using recursion or a stack) while maintaining **O(n)** time complexity.
- This is the most space-efficient solution possible for the problem. However, it comes at the cost of temporarily modifying the tree structure. If you can't modify the tree, you'd need to use the previous iterative or recursive approaches.
