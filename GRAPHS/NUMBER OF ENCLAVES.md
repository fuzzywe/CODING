1020. Number of Enclaves

https://leetcode.com/problems/number-of-enclaves/

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:
![image](https://github.com/user-attachments/assets/08b042f5-7088-4b93-b3d7-904914f036c2)


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:

![image](https://github.com/user-attachments/assets/c3771b60-56cf-465c-85c3-c1feb5613e52)

Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.

---No problem! Let’s simplify it even further step by step.

### What is the problem asking?

- You have a **grid** (a table of rows and columns) made up of **`1`s and `0`s**:
  - **`1`** represents **land**.
  - **`0`** represents **water**.
  
- You need to count how many land cells (`1`s) are **completely surrounded by water**, meaning they cannot reach the **boundary** of the grid (the edges of the grid) by walking **up, down, left, or right**.

### What does "cannot walk off the boundary" mean?

It means that the land cells you are counting should not be able to reach the edge of the grid. If you can somehow walk from a land cell (`1`) to the edge of the grid using other land cells, that cell is **not enclosed** and should **not be counted**.

### Let’s look at an example to understand better.

#### Example 1:

**Input**:  
```
grid = [[0, 0, 0, 0], 
        [1, 0, 1, 0], 
        [0, 1, 1, 0], 
        [0, 0, 0, 0]]
```

The grid looks like this:

```
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
```

Now let's analyze this grid:

- The **1s** (land) are located at:
  - (1,0)
  - (1,2)
  - (2,1)
  - (2,2)
  
- We need to figure out which of these **1s** are **completely surrounded by water**.

Let’s check each `1`:

1. The land cell at `(1,0)`:
   - This cell is **on the boundary of the grid**, meaning it can "reach the edge."
   - **Not enclosed**.

2. The land cell at `(1,2)`:
   - This cell is **not on the boundary**, but let’s check if it can reach the boundary by moving through other `1`s.
   - It is surrounded by `0`s (water) on all sides.
   - **This cell is enclosed**.

3. The land cell at `(2,1)`:
   - This cell is connected to the land cell at `(2,2)` and is surrounded by `0`s.
   - **This cell is enclosed**.

4. The land cell at `(2,2)`:
   - This cell is connected to the land cell at `(2,1)` and is also surrounded by `0`s.
   - **This cell is enclosed**.

So, the **enclosed land cells** (which cannot reach the edge) are `(1,2)`, `(2,1)`, and `(2,2)`.

**Output**: The number of enclosed land cells is `3`.

---

#### Example 2:

**Input**:  
```
grid = [[0, 1, 1, 0], 
        [0, 0, 1, 0], 
        [0, 0, 1, 0], 
        [0, 0, 0, 0]]
```

The grid looks like this:

```
0 1 1 0
0 0 1 0
0 0 1 0
0 0 0 0
```

Now let’s analyze this grid:

- The **1s** (land) are located at:
  - (0,1), (0,2), (1,2), (2,2)
  
- Let’s check each `1`:

1. The land cell at `(0,1)`:
   - This cell is on the **boundary of the grid**.
   - **Not enclosed**.

2. The land cell at `(0,2)`:
   - This cell is on the **boundary of the grid**.
   - **Not enclosed**.

3. The land cell at `(1,2)`:
   - This cell is connected to the boundary land cell at `(0,2)`.
   - **Not enclosed**.

4. The land cell at `(2,2)`:
   - This cell is connected to the boundary land cell at `(1,2)`.
   - **Not enclosed**.

**Output**: Since **none of the land cells are enclosed**, the output is `0`.

---

### How do you solve this problem?

1. **Check the boundary first**: Any land cell (`1`) that is on the **edge** of the grid can reach the boundary. We start by marking these cells and all the cells connected to them.

2. **Mark all reachable land cells**: You can use a method like **DFS (Depth-First Search)** or **BFS (Breadth-First Search)** to mark all the land cells that are connected to the boundary.

3. **Count the enclosed cells**: After marking the boundary-connected cells, any remaining land cells that are not marked are **enclosed** and cannot reach the edge. Count these cells.

---

### Summary:
- The problem asks you to find land cells (`1`s) that are surrounded by water (`0`s) and cannot walk to the edge of the grid.
- If a land cell can reach the edge, it's not counted as enclosed.
- You need to count only the land cells that are completely surrounded by water.

I hope this makes the problem clearer! Let me know if you need further clarification.

---

```cpp

class Solution {
public:
    void dfs(vector<vector<int>>& a, int i, int j) {
        if (i < 0 || j < 0 || i == a.size() || j == a[i].size() || a[i][j] != 1) return;
        a[i][j] = 0;
        dfs(a, i + 1, j);
        dfs(a, i - 1, j);
        dfs(a, i, j + 1);
        dfs(a, i, j - 1);
    }

    int numEnclaves(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();

        // To make all enclaves connected to edges visited
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 || j == 0 || i == n-1 || j == m-1)
                {
                    if(a[i][j] == 1)
                    dfs(a,i,j);
                }
            }
        }

        // To calculate number of unvisited enclaves
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] == 1)
                cnt++;
            }
        }

        return cnt;
    }
};

```
 
