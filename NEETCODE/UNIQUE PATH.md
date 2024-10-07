https://leetcode.com/problems/unique-paths/solutions/1581998/c-python-5-simple-solutions-w-explanation-optimization-from-brute-force-to-dp-to-math/?envType=problem-list-v2&envId=plakya4j&difficulty=MEDIUM&status=TO_DO
Solution - III (Dynamic Programming - Tabulation)

We can also convert the above appraoch to an iterative version. Here, we will solve it in bottom-up manner by iteratively calculating the number of unique paths to reach cell (i, j) starting from (0, 0) where 0 <= i <= m-1 and 0 <= j <= n-1. We will again use dynamic programming here using a dp matrix where dp[i][j] will denote the number of unique paths from cell (0, 0) the cell (i, j). (Note this differs from memoization appraoch where dp[i][j] denoted number of unique paths from cell (i, j) to the cell (m-1,n-1))

In this case, we first establish some base conditions first.

We start at cell (0, 0), so dp[0][0] = 1.
Since we can only move right or down, there is only one way to reach a cell (i, 0) or (0, j). Thus, we also initialize dp[i][0] = 1 and dp[0][j]=1.
For every other cell (i, j) (where 1 <= i <= m-1 and 1 <= j <= n-1), we can reach here either from the top cell (i-1, j) or the left cell (i, j-1). So the result for number of unique paths to arrive at (i, j) is the summation of both, i.e, dp[i][j] = dp[i-1][j] + dp[i][j-1].
C++
Time Complexity : O(m*n), we are computing dp values for each of the m*n cells from the previous cells value. Thus, the total number of iterations performed is requires a time of O(m*n).
Space Complexity : O(m*n), required to maintain the dp matrix
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];   // sum of unique paths ending at adjacent top and left cells
        return dp[m-1][n-1];         // return unique paths ending at cell (m-1, n-1)
    }
};
```

C++
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[j] += dp[j-1];   
        return dp[n-1];
    }
};
```

Time Complexity : O(m*n), for computing dp values for each of the m*n cells.
Space Complexity : O(n), required to maintain dp. We are only keeping two rows of length n giving space complexity of O(n).
There's a small change that can allow us to optimize the space complexity down to O(min(m, n)).
Comment below if you can figure it out :)

✔️ Solution - V (Math)

This problem can be modelled as a math combinatorics problem.



We start at (0, 0) cell and move to (m-1, n-1) cell.
We need to make m-1 down-moves and n-1 right-moves to reach the destination cell.
Thus, we need to perform a total number of m+n-2 moves.
At each cell along the path, we can choose either the right-move or down-move and we need to find the number of unique combinations of these choices (which eventually leads to unique paths).
This is nothing but calculating the number of different ways to choose m-1 down-moves and n-1 right-moves from a total of m+n-2 moves. Mathematically, this can be represented as -


We could cancel out the (n-1)! as well in the above evaluation. We will do one of those based on min(m,n) to give best time complexity in the solution below.

C++
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        for(int i = m+n-2, j = 1; i >= max(m, n); i--, j++) 
            ans = (ans * i) / j;
        return ans;
    }
};
```
Time Complexity : O(min(m,n)) for C++, and O(m+n) for Python. We could do it in O(min(m,n)) for python as well using technique used in C++.
Space Complexity : O(1)
