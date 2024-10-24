Number of Distinct Islands
Difficulty: MediumAccuracy: 62.29%Submissions: 84K+Points: 4
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

Example 2:

Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

Your Task:

You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)

---
No worries! Let's break it down in a simpler way to help you understand the problem.

### What is the problem asking?

You are given a **grid** (a 2D matrix) made up of `1`s and `0`s:
- **1** = Land
- **0** = Water

Your task is to find how many **distinct islands** are present in this grid. An **island** is a group of connected `1`s. The connection can be made either **horizontally** or **vertically**. 

Two islands are considered **distinct** if their shapes are **different**. Even if two islands are located in different parts of the grid, if their shapes are the same, they are considered the **same island shape**.

### Example 1 (Simplified)

Consider this grid:

```
grid = [[1, 1, 0, 0, 0],
        [1, 1, 0, 0, 0],
        [0, 0, 0, 1, 1],
        [0, 0, 0, 1, 1]]
```

- The **first island** is at the top left corner, made up of four `1`s, which are connected like this:

  ```
  1 1
  1 1
  ```

- The **second island** is at the bottom right corner, made up of four `1`s, which are also connected like this:

  ```
  1 1
  1 1
  ```

- The two islands have the **same shape**, even though they are in different locations.

**Answer**: Since there is only one distinct shape of islands, the output is `1`.

### Example 2 (Simplified)

Now, consider this grid:

```
grid = [[1, 1, 0, 1, 1],
        [1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1],
        [1, 1, 0, 1, 1]]
```

Here, we have **4 islands**:

1. **First island**: Three connected `1`s on the top left:

   ```
   1 1
   1
   ```

2. **Second island**: Two connected `1`s on the top right:

   ```
   1 1
   ```

3. **Third island**: A single `1` in the middle of the grid.

4. **Fourth island**: Three connected `1`s on the bottom right:

   ```
   1 1
   1
   ```

- The first and fourth islands have the **same shape** (they look like an "L").
- The second island has a different shape (just two `1`s in a row).
- The third island is just one `1`, which is also distinct.

**Answer**: Since there are 3 different island shapes, the output is `3`.

### Key Points:

1. **Island**: A group of connected `1`s.
2. **Distinct Islands**: Two islands are distinct if their shapes are different.
3. **Connection**: `1`s are connected only if they are next to each other horizontally or vertically (not diagonally).
4. **Shapes**: We care about the shape of the islands. Two islands are the same if their shapes are exactly the same.

### What You Need to Do:

- **Traverse the grid**: For every `1` in the grid, explore the whole island it belongs to (find all the connected `1`s).
- **Record the shape**: For each island, record its shape based on the relative positions of its `1`s.
- **Check for distinct shapes**: Count how many unique shapes (islands) exist.

### Why Do We Care About Shapes?

Even though islands may be in different parts of the grid, they might have the same shape, which means they are not considered distinct. Only islands with different shapes are counted as distinct.

---

Does this help clarify the problem a bit more? Let me know if you have any specific questions!
---
DFS
 ```cpp
class Solution {
  private:
    void dfs(int row ,int col ,vector<vector<int>>& grid ,
    vector<vector<int>>& vis ,vector<pair<int,int>> &vec ,
    int row0 , int col0 ){
        
        vis[row][col] = 1;
        vec.push_back({row- row0 , col- col0});
        
        int m = grid.size();
        int n = grid[0].size();
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        for(int i = 0 ; i < 4 ; i++){
            int nrow = row +delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n
            && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow , ncol , grid , vis , vec , row0 , col0);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // we use dfs for this problem.
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        // make set of vector of pairs.
        set<vector<pair<int,int>>> st;
        
        for(int i = 0 ; i < m ; i++ ){
            for(int j = 0 ; j < n ; j++){
                vector<pair<int,int>> vec ;
                if(grid[i][j] == 1 && !vis[i][j]){
                    dfs(i , j , grid ,vis , vec, i ,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
        
        
    }
};
```
---

BFS

```cpp
class Solution {
    private:
    void bfs(int row,int col,vector<vector<int>>& grid,vector<pair<int,int>>& v,vector<vector<bool>>& vis){
        queue<pair<int,int>> q;
        q.push({row,col});
        v.push_back({0,0});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int n=grid.size(),m=grid[0].size();
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;++i){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=true;
                    q.push({nrow,ncol});
                    v.push_back({nrow-row,ncol-col});
                }
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> v;
                    bfs(i,j,grid,v,vis);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};

```
