Brute Force Approach
Intuition
Since its a BST so according to the property we can traverse the tree in inorder and keep updating our minimum value.

Implementation
create a function inorder and start calling the function and keep comparing the current element with previous min
If current element is smaller than the previous min then update the minimum with curr element .
Now return the min of the array.
Code:

void solve(Node* root,int &minvalue){

    //Base Case

    if(root==NULL) return ;
    solve(root->left,minvalue);
    minvalue = min(minvalue,root->data);
    solve(root->right,minvalue);
} 
int minValue(Node* root) {
      if (root==NULL){
          return -1;
      }
      int minValue=INT_MAX;
      solve(root,minValue);
      return minValue;
}
Complexity
Time Complexity : O(N) since we traversed through all the elements in a BST.
Space Complexity : O(N), auxiliary stack space required for recursion.

Expected Approach:
Intuition:
In BST,  we know that left element is less than root node which means The node whose left is NULL is the node with minimum value(Iterative Solution).

Example:

 
In this example we start traversing from root towards left and when we came at node-1 their is no left child hence it is the minimum one

Minimum element = 1


 
In this example we start traversing from root towards left and we can see that their is no left child of root then root is the minimum one value

hence, Minimum element = 4

Implementation:
Check if root is null then return -1.
Initialize answer with root data
Now run a while loop till root != NULL
update the answer with root data.
Set root as root->left.
Return the answer.
Code:

//Back-end complete function Template for C++

// Function to find the minimum element in the given BST.

class Solution {
  public:
    int minValue(Node* root) {
        // base case
        if (root == NULL)
            return -1;

        struct Node* current = root;

        // leftmost node is minimum so we move in BST till left node is not NULL.
        while (current->left != NULL) {
            current = current->left;
        }
        // returning the data at leftmost node.
        return (current->data);
    }
};
Complexity
Time Complexity: O(H), Worst case happens for left skewed trees.
Auxiliary Space: O(1), we are not using any extra memory.
