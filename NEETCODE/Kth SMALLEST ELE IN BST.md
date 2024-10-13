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
