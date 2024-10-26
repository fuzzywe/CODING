https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths
![WhatsApp Image 2024-10-26 at 11 25 42_32eb66c4](https://github.com/user-attachments/assets/261eb966-167e-4c44-948e-8881345ed66b)

![WhatsApp Image 2024-10-26 at 11 26 33_e1fcbfcd](https://github.com/user-attachments/assets/f7eafca5-9050-4102-9306-270c5b00ac62)


![WhatsApp Image 2024-10-26 at 11 26 52_8b2de7bf](https://github.com/user-attachments/assets/2a136b11-41a1-420b-9394-eacbd9d7fe6c)


Root to Leaf Paths
Difficulty: MediumAccuracy: 43.65%Submissions: 114K+Points: 4
Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

Example 1:

Input:

```cpp
       1
    /     \
   2       3

```
Output: 
1 2 
1 3 
Explanation: 
All possible paths:
1->2
1->3
Example 2:

Input:

```cpp
         10
       /    \
      20    30
     /  \
    40   60

```
Output: 
10 20 40 
10 20 60 
10 30 
Your Task:
Your task is to complete the function Paths() which takes the root node as an argument and returns all the possible paths. (All the paths are printed in new lines by the driver's code.)

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of the tree)
```cpp
lass Solution {
  public:
    vector<vector<int>> ans;
    vector<int> path;
    void getpath(Node* node){
        if(node == nullptr) return;
        
        path.push_back(node->data);
        
        if(node->left == NULL and node->right == NULL) ans.push_back(path);
        else{
            getpath(node->left);
            getpath(node->right);
        }
        path.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        if(root == nullptr) return ans;
        getpath(root);
        return ans;
    }
};

```
