https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/1440900293/




```cpp

// Vector to store the
        // inorder traversal result
        vector<int> inorder;
        // Pointer to the current node,
        // starting from the root
        TreeNode* cur = root;
        
        // Loop until the current
        // node is not NULL
        while (cur != NULL) {
            // If the current node's
            // left child is NULL
            if (cur->left == NULL) {
                // Add the value of the current
                // node to the inorder vector
                inorder.push_back(cur->val);
                // Move to the right child
                cur = cur->right;
            } else {
                // If the left child is not NULL,
                // find the predecessor (rightmost node
                // in the left subtree)
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                
                // If the predecessor's right child
                // is NULL, establish a temporary link
                // and move to the left child
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    // If the predecessor's right child
                    // is already linked, remove the link,
                    // add current node to inorder vector,
                    // and move to the right child
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        
        // Return the inorder
        // traversal result
        return inorder;

```


Here's a comparison of the **Preorder Traversal** and **Inorder Traversal** using Morris Traversal, structured in a table format for clarity:

| **Aspect**               | **Preorder Traversal**                                 | **Inorder Traversal**                                   |
|--------------------------|-------------------------------------------------------|--------------------------------------------------------|
| **Function Name**        | `preorderTraversal(TreeNode* root)`                  | `inorderTraversal(TreeNode* root)`                     |
| **Purpose**              | Traverse the tree in Preorder (Root-Left-Right)      | Traverse the tree in Inorder (Left-Root-Right)        |
| **Traversal Order**      | 1. Visit the root<br>2. Traverse the left subtree<br>3. Traverse the right subtree | 1. Traverse the left subtree<br>2. Visit the root<br>3. Traverse the right subtree |
| **Code Initialization**  | `vector<int> preorder;`                               | `vector<int> inorder;`                                 |
| **Current Node**         | `TreeNode* cur = root;`                              | `TreeNode* cur = root;`                               |
| **Condition to Continue**| `while (cur != NULL)`                                | `while (cur != NULL)`                                 |
| **Handling Left Child**  | `if (cur->left == NULL)`                              | `if (cur->left == NULL)`                               |
| **Node Visit**           | `preorder.push_back(cur->val);`                      | `inorder.push_back(cur->val);`                        |
| **Move to Right Child**  | `cur = cur->right;`                                  | `cur = cur->right;`                                   |
| **Handling Right Child** | **Find predecessor:**<br>`TreeNode* prev = cur->left;`<br>...<br>`if (prev->right == NULL)`<br>`prev->right = cur;`<br>`preorder.push_back(cur->val);`<br>`cur = cur->left;` | **Find predecessor:**<br>`TreeNode* prev = cur->left;`<br>...<br>`if (prev->right == NULL)`<br>`prev->right = cur;`<br>`cur = cur->left;` |
| **Reset Link**           | `prev->right = NULL;`                               | `prev->right = NULL;`                                 |
| **Final Return**         | `return preorder;`                                   | `return inorder;`                                     |

### Code Representation

#### Preorder Traversal Code

```cpp
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    TreeNode* cur = root;

    while (cur != NULL) {
        if (cur->left == NULL) {
            preorder.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode* prev = cur->left;
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                prev->right = cur;
                preorder.push_back(cur->val);
                cur = cur->left;
            } else {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
}
```

#### Inorder Traversal Code

```cpp
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    TreeNode* cur = root;

    while (cur != NULL) {
        if (cur->left == NULL) {
            inorder.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode* prev = cur->left;
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return inorder;
}
```

This format provides a clear comparison between the two traversal methods, highlighting their respective structures, purposes, and operational differences.
