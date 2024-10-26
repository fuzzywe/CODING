653. Two Sum IV - Input is a BST

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

Example 1:
![image](https://github.com/user-attachments/assets/58fecb80-c003-407e-9508-8cf3b967fee9)


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:
![image](https://github.com/user-attachments/assets/dc31572a-ff98-43cc-a46a-8bebe1c83c6f)


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false


Method 1:
using inorder traversal + applying two pointer approach :

Time Complexity : O(N)
Space Complexity : O(N)

We know inorder traversal of a BST gives a sorted array.
After getting sorted array simply apply two pointer approach to find the sum of two number equal to target. ( same as Two Sum Problem of Leetcode )

---


```cpp
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        inorder(root, vec);
        
        // using two pointers approach for two sum
        int i  = 0, j = vec.size()-1;
        while(i<j){
            if(vec[i] + vec[j] == k)    return true;
            (vec[i] + vec[j]) < k ? i++ : j--;
        }
        return false;
    }
private:
    void inorder(TreeNode* root, vector<int>& vec){
        if(root == nullptr) return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
};
```
---

**Method 2:Recursion + keep values in set :**

Time Complexity : O(N)
Space Complexity : O(N)

The idea behind this is, to keep iterating the tree and inserting NodeValue in set.
If target-root.val already exist, then return true. (this means, sum of two nodes equal to target exist).
If not found after whole traversal of BST, return false.

```cpp
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        if(myset.count(k - root->val)>0)  return true;
        myset.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
private:
    unordered_set<int> myset;
};

```
---

Method 3:
**Inorder Traversal + Reverse Inorder Traversal :**

Time Complexity : O(N)

Space Complexity : O(logN)

We traverse the BST in normal inorder and reverse inorder simultaneously.

In normal inorder, we start from the left-most node of tree which is the minimum value in BST.

In reverse inorder, we start from the right-most node of tree which is the maximum value in BST.

Then, we add the sum of current nodes in both traversal and compare the sum with target.


It can lead to following three different cases :

sum == target, return true.

sum < target, we move to next node in normal inorder traversal.

sum > target, we move to next node in reverse inorder traversal.

If any traversal is finished, and no pair is found then return false.

```cpp
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> inord, revInord;
        TreeNode* root1 = root;
        TreeNode* root2 = root;
        
        while(true){
            while(root1)    inord.push(root1), root1 = root1->left;
            while(root2)    revInord.push(root2), root2 = root2->right;
            
            if(inord.empty() || revInord.empty())   return false;
            
            root1 = inord.top();    // node with the minimum value
            root2 = revInord.top(); // node with the maximum value.
            
            if(root1->val + root2->val == k){
                if(root1->val == root2->val)    return false;
                else    return true;
            }
            
            if(root1->val + root2->val < k){
                inord.pop();
                root1 = root1->right;
                root2 = nullptr;
            }
            
            else{
                revInord.pop();
                root2 = root2->left;
                root1 = nullptr;
            }
        }
        return false;
    }
};

```
