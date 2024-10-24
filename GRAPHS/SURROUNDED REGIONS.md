130. Surrounded Regions

https://leetcode.com/problems/surrounded-regions/description/

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:

![image](https://github.com/user-attachments/assets/3773e5d4-62b9-41b3-96a8-65e64cd977b1)

In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]

---
```cpp
class Solution {
public:
   void bfs(int i,int j, vector<vector<char>>& board)
    {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        board[i][j]='T'; //not surrounded

        //directions
        vector<pair<int,int>>d{{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();

            //check in all four directions
            //int a,b;
            for(auto dir:d)
            {
                int  a=x+dir.first;
                int  b=y+dir.second;
        
            //if valid then push
                if(a>=0 && a<m && b>=0 && b<n && board[a][b]=='O')
                {
                    board[a][b]='T';
                    q.push({a,b});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        if(m==0)
        {
            return;
        }

//mark all 0s of border and that are connected to border 0
        for(int i=0;i<m;i++)
        {
            //left border
            if(board[i][0]=='O')
            {
                bfs(i,0,board);
            }

            //right border
            if(board[i][n-1]=='O')
            {
                bfs(i,n-1,board);
            }
        }

        for(int j=0;j<n;j++)
        {
            //top border
            if(board[0][j]=='O')
            {
                bfs(0,j,board);
            }

            //bottom border
            if(board[m-1][j]=='O')
            {
                bfs(m-1,j,board);
            }
        }

        //flip all Os to Xs and YS to back Os
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                else if(board[i][j]=='T')
                {
                    board[i][j]='O';
                }
            }
        }
    }
};

```


Intuition
The code is designed to solve the problem of capturing surrounded regions in a matrix of 'X' and 'O' cells. The primary concept is based on identifying which 'O' cells are surrounded and which are not.

Approach
Identify Border Cells:
Any 'O' cell on the border (first or last row/column) or connected to a border 'O' cannot be surrounded by 'X'. These cells are considered safe.

Mark Safe Regions Using BFS:
Traverse the matrix and perform a Breadth-First Search (BFS) from each 'O' on the border.

For every 'O' found on the border, mark it and all connected 'O' cells as safe by changing their value from 'O' to 'T' (a temporary marker).

This way, all 'O's connected to the border are identified and excluded from being flipped.

Flip the Remaining 'O' Cells:
After marking safe cells, loop through the matrix again.
Any 'O' cell that is still 'O' (i.e., not marked as 'T') must be surrounded by 'X', so flip these 'O's to 'X'.

Restore Safe Regions:
Finally, change all 'T' cells (those connected to the border and safe from capture) back to 'O' to restore their original state.

Complexity
Time complexity:
O(m×n)

Space complexity:
O(m×n)

Clean, efficient, and well-optimized solution!


---

```cpp
Beats Most - DFS - Simple Logic | Clean Code | C++ |

Antim_Sankalp
200 Days Badge 2024
357
409
Apr 07, 2024
C++
Code
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            dfs(board, i, 0, m, n);
            dfs(board, i, n - 1, m, n);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(board, 0, j, m, n);
            dfs(board, m - 1, j, m, n);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n)
    {
        if (min (i, j) < 0 || i >= m || j >= n || board[i][j] != 'O')
            return ;
        
        board[i][j] = 'T';

        dfs(board, i - 1, j, m, n);
        dfs(board, i + 1, j, m, n);
        dfs(board, i, j - 1, m, n);
        dfs(board, i, j + 1, m, n);
    }
};

```
