1277. Count Square Submatrices with All Ones
1278. 
https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.



---

```cpp
class Solution {
public:
        int countSquares(vector<vector<int>>& A) {
        int res = 0;
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < A[0].size(); res += A[i][j++])
                if (A[i][j] && i && j)
                    A[i][j] += min({A[i - 1][j - 1], A[i - 1][j], A[i][j - 1]});
        return res;
    }
};

```

---


**Note this is almost identical to #221 just change the max there to + here**



https://leetcode.com/problems/maximal-square/description/

221. Maximal Square
Solved
Medium
Topics
Companies
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:

![image](https://github.com/user-attachments/assets/e678bf17-6613-4725-950e-28938ad5a47e)

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:

![image](https://github.com/user-attachments/assets/6ba91326-6dac-485e-b039-c71b93617a9d)

Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        int maxSide = 0;

        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1; // First row or column
                    } else {
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        
        return maxSide * maxSide; // Area of the largest square
    }
};


```
---
