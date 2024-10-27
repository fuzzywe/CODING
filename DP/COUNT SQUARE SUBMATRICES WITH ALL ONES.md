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

Here are two separate codes for each problem. The core logic is similar, but each one specifically returns the required output for each problem.

### 1. Maximal Square
For **Maximal Square**, we need to find the area of the largest square submatrix that contains all `1`s.

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        
        int maxSide = 0;  // Track the largest side length of the square found
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1; // First row or column has max side 1 if cell is '1'
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

- **Time Complexity**: \(O(m \times n)\)
- **Space Complexity**: \(O(m \times n)\)

### 2. Count Square Submatrices with All Ones
For **Count Square Submatrices with All Ones**, we need to count all possible square submatrices made up entirely of `1`s.

```cpp
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        
        int totalSquares = 0; // Track the total count of squares
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1; // First row or column square count is 1 if cell is 1
                    } else {
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                    totalSquares += dp[i][j]; // Count all squares ending at (i, j)
                }
            }
        }
        
        return totalSquares; // Total number of square submatrices with all 1s
    }
};
```

- **Time Complexity**: \(O(m \times n)\)
  
- **Space Complexity**: \(O(m \times n)\)

Each code is optimized to compute the desired results independently:

- The **Maximal Square** code returns the area of the largest square.
  
- The **Count Square Submatrices** code returns the count of all square submatrices with `1`s.

```

// For Maximal Square

```cpp
int maxSide = 0; // Tracking largest side length
maxSide = max(maxSide, dp[i][j]); // Update largest side length
return maxSide * maxSide; // Return area

// For Count Square Submatrices
int totalSquares = 0; // Tracking total count of squares
totalSquares += dp[i][j]; // Add square count ending at (i, j)
return totalSquares; // Return count of squares
```
