200. Number of Islands
Medium
Topics
Companies
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Final Complexity:
Time Complexity: O(n * m), where n is the number of rows and m is the number of columns.
Space Complexity: O(n * m) for the visitation matrix and the recursive stack in the worst case.

 ```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    count++;
                    dfs(row, col, vis, grid);
                }
            }
        }
        return count;
    }

private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        if(row < 0 || row > grid.size() -1 || col < 0 || col > grid[0].size() - 1 || grid[row][col] == '0' || vis[row][col])
        {
            return;
        }
        vis[row][col] = 1;
        dfs(row-1,col,vis,grid);
        dfs(row+1,col,vis,grid);
        dfs(row,col-1,vis,grid);
        dfs(row,col+1,vis,grid);
    }
};

```
