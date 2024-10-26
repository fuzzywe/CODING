**same as top view one line change**

https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.
```cpp

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14


```

For the above tree, the output should be 5 10 4 14 25.

Examples :

Input:

```cpp
       1
     /   \
    3     2

```
Output: 3 1 2
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus bottom view of the binary tree will be 3 1 2.
Input:

```cpp
         10
       /    \
      20    30
     /  \
    40   60

```
Output: 40 20 60 30
```cpp
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        
        // line , node->data
        map<int,int> mpp;
        
        // node, line
        queue<pair<Node*,int>> q;
        
        q.push({root,0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int line = it.second;
            
            mpp[line] = node->data;
            
            if(node->left) q.push({node->left, line -1});
            if(node->right) q.push({node->right, line +1});
        }
        
        vector<int> ans;
        
        for(auto line : mpp){
            ans.push_back(line.second);
        }
        
        return ans;
    }
};

```
