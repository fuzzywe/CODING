994. Rotting Oranges
Medium
Topics
Companies
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        
        vector<int> dir={-1,0,1,0,-1}; //used for finding all 4 adjacent coordinates
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh=0; //To keep track of all fresh oranges left
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        int ans=-1; //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int r=p.first+dir[i];
                    int c=p.second+dir[i+1];
                    if(r>=0 && r<m && c>=0 && c<n &&grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--; // decrement by 1 foreach fresh orange that now is rotten
                    }
                    
                }
            }
            ans++; //incremented after each minute passes
        }
        if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
        
    }
};
```

Let's go through each line of the code step-by-step and apply an example for better understanding. We will use a simple grid:

### Initial Example Grid:

```
[
  [2, 1, 1],
  [1, 1, 0],
  [0, 1, 1]
]
```

### Code Breakdown with Example:

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
```
- **Explanation**: We define a class `Solution` with a method `orangesRotting` that takes a 2D grid as input. This grid represents a farm of oranges.
- **Example**: The grid is:
  ```
  [
    [2, 1, 1],
    [1, 1, 0],
    [0, 1, 1]
  ]
  ```

---

```cpp
vector<int> dir={-1, 0, 1, 0, -1}; // Used for finding all 4 adjacent coordinates.
```
- **Explanation**: The `dir` array helps in checking the four adjacent cells (up, down, left, and right) of any cell in the grid. For example, if a rotten orange is at (1, 1), we can use `dir` to check its neighbors.
- **Example**: Given a point `(1, 1)`, the four adjacent cells are:
  - Up: `(0, 1)` (with coordinates `dir[0], dir[1]`)
  - Down: `(2, 1)` (with coordinates `dir[2], dir[3]`)
  - Left: `(1, 0)` (with coordinates `dir[1], dir[0]`)
  - Right: `(1, 2)` (with coordinates `dir[3], dir[2]`)

---

```cpp
int m = grid.size();
int n = grid[0].size();
```
- **Explanation**: `m` and `n` store the number of rows and columns in the grid.
- **Example**: In our case, `m = 3` and `n = 3`.

---

```cpp
queue<pair<int, int>> q;
int fresh = 0;
```
- **Explanation**: We declare a queue `q` to hold the coordinates of rotten oranges. `fresh` keeps track of the number of fresh oranges.
- **Example**: The queue `q` is initially empty, and `fresh` is `0`.

---

```cpp
for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2) {
            q.push({i, j});
        }
        if (grid[i][j] == 1) {
            fresh++;
        }
    }
}
```
- **Explanation**: We iterate over every cell in the grid:
  - If a cell contains a rotten orange (`2`), we add its coordinates to the queue.
  - If a cell contains a fresh orange (`1`), we increment the `fresh` counter.
- **Example**:
  - Rotten orange at `(0, 0)` is added to `q`.
  - Fresh oranges are found at `(0, 1)`, `(0, 2)`, `(1, 0)`, `(1, 1)`, `(2, 1)`, and `(2, 2)`, so `fresh = 6`.

Queue (`q`) after this step:
```
q = [(0, 0)]
```

---

```cpp
int ans = -1;
```
- **Explanation**: We initialize the answer `ans` to `-1`. This is because we increment `ans` for each minute that passes, and we want to start counting time from 0.
- **Example**: `ans = -1` (initial state).

---

```cpp
while (!q.empty()) {
```
- **Explanation**: The outer loop runs as long as there are rotten oranges in the queue. This loop ensures that we keep processing rotten oranges until no more can spread the rot.
- **Example**: The queue initially contains the rotten orange `(0, 0)`.

---

```cpp
int sz = q.size();
```
- **Explanation**: `sz` holds the number of rotten oranges at the current time. We process each of these oranges in the current minute.
- **Example**: `sz = 1` since there is only one rotten orange `(0, 0)` in the queue.

---

```cpp
while (sz--) {
```
- **Explanation**: We use a `while` loop to process all rotten oranges at the current minute. This ensures that all oranges from the previous minute rot adjacent fresh oranges in the same minute.
- **Example**: We process the rotten orange `(0, 0)`.

---

```cpp
pair<int, int> p = q.front();
q.pop();
```
- **Explanation**: `p` stores the coordinates of the current rotten orange, and we remove it from the queue.
- **Example**: `p = (0, 0)`, so the orange at `(0, 0)` is the one we will process in this iteration. We remove it from the queue.

Queue after this step:
```
q = []
```

---

```cpp
for (int i = 0; i < 4; i++) {
    int r = p.first + dir[i];
    int c = p.second + dir[i+1];
```
- **Explanation**: The `for` loop checks the four adjacent cells of the current rotten orange (`p`) using the `dir` array.
- **Example**:
  - For `i = 0`: `(r, c) = (-1, 0)` (out of bounds).
  - For `i = 1`: `(r, c) = (0, 1)` (valid, fresh orange).
  - For `i = 2`: `(r, c) = (1, 0)` (valid, fresh orange).
  - For `i = 3`: `(r, c) = (0, -1)` (out of bounds).

---

```cpp
if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
    grid[r][c] = 2;
    q.push({r, c});
    fresh--;
}
```
- **Explanation**: For each adjacent cell `(r, c)`, we check if it's within the grid bounds and contains a fresh orange (`1`). If so, we rot the fresh orange (`grid[r][c] = 2`), add it to the queue, and decrement the fresh count.
- **Example**:
  - At `(0, 1)`: Fresh orange turns rotten, and it’s added to the queue. Fresh count decreases to 5.
  - At `(1, 0)`: Fresh orange turns rotten, and it’s added to the queue. Fresh count decreases to 4.

Queue after this step:
```
q = [(0, 1), (1, 0)]
```

---

```cpp
ans++;
```
- **Explanation**: After processing all rotten oranges in this minute, we increment the time (`ans`).
- **Example**: `ans = 0` after the first minute.

---

```cpp
if (fresh > 0) return -1;
```
- **Explanation**: If there are still fresh oranges left after the process, it means that not all oranges could be rotted, and we return `-1`.
- **Example**: In this case, there are still fresh oranges left (`fresh = 4`), so we continue processing.

---

```cpp
if (ans == -1) return 0;
```
- **Explanation**: If no fresh oranges were present at all initially, we return `0` minutes, because no rotting was needed.
- **Example**: This condition is skipped since we had fresh oranges at the start.

---

```cpp
return ans;
```
- **Explanation**: Finally, after all fresh oranges are rotted, we return the total time (`ans`).
- **Example**: The process continues until all fresh oranges rot. For this grid, it will take `4` minutes.

---

### Dry Run for the Example:

1. **Initial Grid**:
   ```
   [
     [2, 1, 1],
     [1, 1, 0],
     [0, 1, 1]
   ]
   ```
   Queue: `[(0, 0)]`
   Fresh count: `6`
   Time: `-1`

2. **Minute 0**:
   - Process `(0, 0)`:
     - Rot `(0, 1)` → Queue: `[(0, 1)]`, Fresh: `5`
     - Rot `(1, 0)` → Queue: `[(0, 1), (1, 0)]`, Fresh: `4`
   - Time: `0`

3. **Minute 1**:
   - Process `(0, 1)`:
     - Rot `(0, 2)` → Queue: `[(1, 0), (0, 2)]`, Fresh: `3`
     - Rot `(1, 1)` → Queue: `[(1, 0), (0, 2), (1, 1)]`, Fresh: `2`
   - Process `(1, 0)`:
     - No more fresh oranges adjacent to `(1,

 0)`.
   - Time: `1`

4. **Minute 2**:
   - Process `(0, 2)` and `(1, 1)`:
     - Rot `(2, 1)` → Queue: `[(2, 1)]`, Fresh: `1`
   - Time: `2`

5. **Minute 3**:
   - Process `(2, 1)`:
     - Rot `(2, 2)` → Queue: `[(2, 2)]`, Fresh: `0`
   - Time: `3`

6. **Final Time**: `4`

Thus, all fresh oranges rot in 4 minutes.
