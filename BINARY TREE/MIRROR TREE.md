https://www.geeksforgeeks.org/problems/mirror-tree/1

Examples:

Input:
      1
    /  \
   2    3
Output: 3 1 2
Explanation: The tree is
  1    (mirror)     1
 /  \    =>        /  \
2    3           3   2
The inorder of mirror is 3 1 2
Input:
      10
     /  \
    20   30
   /  \
  40  60
Output: 30 10 60 20 40
Explanation: The tree is
      10               10
    /    \  (mirror)    /    \
   20    30    =>   30    20
  /  \                     /   \
 40  60                 60   40
The inroder traversal of mirror is: 30 10 60 20 40.


Problem Statement

Given a binary tree, convert it into its mirror tree. The mirror tree of a binary tree is obtained by swapping the left and right child of every node.

Approach

This can be done recursively:


Base Case:

If the current node is NULL, simply return. This is because there's nothing to mirror in an empty subtree.

Swap:

Swap the left and right children of the current node.

Recursive Call:

Recursively call the mirror function on the left and right children to continue the process for all nodes in the tree.

Algorithm

Check if the current node is NULL. If yes, return immediately (base case).

Swap the left and right children of the current node using swap(node->left, node->right).

Recursively call mirror on the new left and right children.

Continue until all nodes have been processed.

```cpp
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(node==NULL)
        return;
        swap(node->left,node->right);
        mirror(node->left);
        mirror(node->right);
    }
};

```
Explanation of Process:
Starting at the root (1), we swap its left (2) and right (3) children.

Move to the left child (3), and swap its children (6 and 7).

Then, move to the right child (2), and swap its children (4 and 5).

Repeat this process recursively for all nodes until the entire tree has been mirrored.

Time and Space Complexity

Time Complexity: O(n), where n is the number of nodes in the binary tree. Each node is visited once.

Space Complexity: O(h), where h is the height of the tree due to the recursion stack.

This approach efficiently converts any binary tree into its mirror form!
