73. Set Matrix Zeroes
Medium
Topics
Companies
Hint
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 https://leetcode.com/problems/set-matrix-zeroes/description/?envType=problem-list-v2&envId=plakya4j&difficulty=MEDIUM&status=TO_DO

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int> setRows; 
        unordered_set<int> setColumns; 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    setRows.insert(i);
                    setColumns.insert(j);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(setRows.count(i) > 0 || setColumns.count(j) > 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};






/*

    Time Complexity : O(N*M), Where N is the number of row and M is number of column of matrix. Here two nested 
    loops creates the time complexity.

    Space Complexity : O(1), Constant space.

    Solved using Matrix.

*/
```

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> visited = matrix;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<m; k++){
                        visited[i][k] = 0;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<n; k++){
                        visited[k][j] = 0;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j] = visited[i][j];
            }
        }
    }
};






/*

    Time Complexity : O((N*M)*(N+M)), Where N is the number of row and M is number of column of matrix. Here
    nested loops creates the time complexity. O(N*M) for traversing through each element and (N+M)for traversing
    to row and column of elements having value 0.

    Space Complexity : O(1), Constant space.

    Solved using Matrix.

*/
```
