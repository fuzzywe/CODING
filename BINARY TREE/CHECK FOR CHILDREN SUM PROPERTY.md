**Children Sum in a Binary Tree**

![26 10 2024_10 11 12_REC](https://github.com/user-attachments/assets/04e4691c-893a-4a97-9070-823cb5cf77fd)



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
