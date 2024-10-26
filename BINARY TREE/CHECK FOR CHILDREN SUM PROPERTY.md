**Children Sum in a Binary Tree**

![26 10 2024_10 11 12_REC](https://github.com/user-attachments/assets/04e4691c-893a-4a97-9070-823cb5cf77fd)
![WhatsApp Image 2024-10-26 at 10 56 51_021c7375](https://github.com/user-attachments/assets/7ed90434-8efc-42c9-bbed-bb75ab50e9f2)

![WhatsApp Image 2024-10-26 at 10 56 49_2ef71db0](https://github.com/user-attachments/assets/2b27ddc3-3c98-499c-bfd7-439378ce4980)


https://www.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent

Given a binary tree having n nodes. Check whether all of its nodes have a value equal to the sum of their child nodes. Return 1 if all the nodes in the tree satisfy the given properties, else it returns 0. For every node, the data value must be equal to the sum of the data values in the left and right children. Consider the data value 0 for a NULL child. Also, leaves are considered to follow the property.
![26 10 2024_09 47 43_REC](https://github.com/user-attachments/assets/41ccfac2-bbc0-4722-9fdb-2d08c83cf831)

Examples:

Input:
Binary tree

```cpp
       35
      /  \
     20   15
    / \   / \
   15  5 10  5
```
Output: 1
Explanation: 
Here, every node is sum of its left and right child.
Input:
Binary tree

```cpp
       1
     /   \
    4     3
   /  
  5

``` 
Output: 0
Explanation: 
Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.
Input:
Binary tree

```cpp

       10
      /  \
     4    6
    / \  / \
   1   3 2  4

```

Output: 1
Explanation: 
Here, every node is a sum of its left and right child.



```cpp

class Solution{
    public:
    int isSumProperty(Node *root)
    { 
      if((root==NULL)||(root->left==NULL && root->right==NULL))return 1;
      int sum=0;
      if(root->left!=NULL) sum +=root->left->data;
      if(root->right!=NULL)sum+=root->right->data;
      return (root->data==sum && isSumProperty(root->left) &&isSumProperty(root->right));
    }
};

```
![SCVWB](https://github.com/user-attachments/assets/6bf0422b-88c6-4fea-9b75-717d50bd9335)


Starting from the root (35), we traverse the left subtree first.
At node 20, its value is equal to the sum of its children (15 + 5 = 20).
Similarly, at node 15, it's a leaf node, which satisfies the property. Now, we traverse the right subtree.
At node 15, it satisfies the property as well.
Finally, at node 5, it's a leaf node, adhering to the property.
Thus, the binary tree satisfies the Children Sum Property.
Time and Space Complexity
The time complexity of this solution is O(N), where N is the number of nodes in the binary tree. This is because we need to visit each node once.
The space complexity is also O(H) due to the recursion stack space incurred during the traversal.
 
Conclusion
Understanding and implementing the Children Sum Property in a binary tree is essential for solving various tree-related problems efficiently. By employing a recursive approach, we can traverse the tree and validate whether each node adheres to this property. The provided code offers an optimized solution, ensuring a balance between time and space complexity.
