
https://leetcode.com/problems/transpose-matrix/description/

https://www.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1

https://www.naukri.com/code360/problems/transpose-of-a-matrix_2824817?leftPanelTabValue=SUBMISSION

calculate the transpose of Matrix.
867. Transpose Matrix
Solved
Easy
Topics
Companies
Hint
Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.



 

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

optimal

Time complexity: O(n*n)
Space complexity: O(n)

```cpp

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size(); 

        vector<vector<int>>ans(m,vector<int>(n,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {

                ans[j][i]=matrix[i][j];
                
            }
        }
        return ans;
        
    }
};

```

gfgs

---

```cpp

class Solution
{   
    public:  
    //Function to find transpose of a matrix.
    void transpose(vector<vector<int> >& matrix, int n)
    { 
        // code here 
        
        int m = matrix[0].size();
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
             int temp= matrix[i][j];
             matrix[i][j]=matrix[j][i];
             matrix[j][i]=temp;}}
    }
};

```
i got void so i just need to modify the code

---

```cpp

#include <bits/stdc++.h> 
vector<vector<int>> transpose(int m, int n, vector<vector<int>> &mat){
    // Write your code here.

    vector<vector<int>>ans(n,vector<int>(m,0));
    for(int i=0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            ans[j][i]=mat[i][j];
        }
    }return ans;

    ```

got int m as row and n as col nakuri soln
