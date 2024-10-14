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

🔍 Methods To Solve This Problem:
I'll be covering two different methods to solve this problem:

Depth-First Search (DFS)
Breadth-First Search (BFS)
1️⃣ Depth-First Search (DFS):
The DFS approach involves exploring each cell in the grid. When encountering a '1' (representing land), it signifies the start of a new island. The goal is to explore and mark all connected land cells (forming an island) using recursive DFS.

DFS Function: Define a recursive DFS function that takes the grid and the current cell coordinates (i, j) as parameters.

If the cell is out of the grid boundaries or not land ('1'), return.
Mark the current cell as visited by changing it from '1' to '0'.
Recursively call DFS for the neighboring cells (up, down, left, right) to explore and mark all connected land cells.
Main Function:

Iterate through each cell in the grid.
When encountering an unvisited '1', increment the island count and trigger DFS to explore and mark all connected land cells belonging to this island.
Code👨🏻‍💻:
```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return numIslands;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        
        grid[i][j] = '0'; // mark as visited
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }
};
```
2️⃣ Breadth-First Search (BFS):
The BFS approach involves using a queue to systematically explore all cells of each island. We'll iterate through each cell in the grid. When encountering a '1' (indicating land), we'll use BFS to explore all connected land cells and mark them as visited.

BFS Function: Use a queue to perform BFS starting from each unvisited land cell ('1').

Initialize a queue with the starting cell.
While the queue is not empty, dequeue a cell, mark it as visited, and enqueue its neighboring land cells (up, down, left, right).
Continue until all connected land cells of the current island are visited.
Main Function:

Iterate through each cell in the grid.
If encountering an unvisited '1', increment the island count and trigger BFS to explore and mark all connected land cells of this island.
Code👩🏻‍💻:
```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int numIslands = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    q.push({i, j});
                    
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1') {
                            continue;
                        }
                        
                        grid[x][y] = '0'; // mark as visited
                        
                        for (auto& dir : directions) {
                            int nx = x + dir.first;
                            int ny = y + dir.second;
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        
        return numIslands;
    }
};
```
Comparison⚔️:
Both DFS and BFS are used to explore and mark connected land cells.
DFS uses a recursive approach, while BFS employs an iterative queue-based approach.
DFS can lead to deep recursion (which might cause stack overflow for extremely large grids), while BFS uses a queue, which can be more suitable for larger grids.
Time complexity for both methods is O(m * n) where m is the number of rows and n is the number of columns in the grid.

```
