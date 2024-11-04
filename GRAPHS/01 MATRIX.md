542. 01 Matrix

https://leetcode.com/problems/01-matrix/solutions/1369741/c-java-python-bfs-dp-solutions-with-picture-clean-concise-o-1-space/

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

![image](https://github.com/user-attachments/assets/dd0942ab-5616-4602-a24a-2d7cf5724d89)

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:

![image](https://github.com/user-attachments/assets/21ee8238-fdb1-4635-b0a2-26c16a68cf24)


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

---

✔️ Solution 1: BFS on zero cells first

For convinience, let's call the cell with value 0 as zero-cell, the cell has with value 1 as one-cell, the distance of the nearest 0 of a cell as distance.

Firstly, we can see that the distance of all zero-cells are 0.

Same idea with Topology Sort, we process zero-cells first, then we use queue data structure to keep the order of

processing cells, so that cells which have the smaller distance will be processed first. Then we expand the 

unprocessed neighbors of the current processing cell and push into our queue.

Afterall, we can achieve the minimum distance of all cells in our matrix.

![image](https://github.com/user-attachments/assets/109007e1-b377-43aa-ad42-3d88a2525386)


```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty())
            return {};

        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> queue;
        int MAX_VALUE = m * n;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    queue.push({i, j});
                } else {
                    mat[i][j] = MAX_VALUE;
                }
            }
        }
        
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!queue.empty()) {
            auto [row, col] = queue.front(); queue.pop();
            for (auto [dr, dc] : directions) {
                int r = row + dr, c = col + dc;
                if (r >= 0 && r < m && c >= 0 && c < n && mat[r][c] > mat[row][col] + 1) {
                    queue.push({r, c});
                    mat[r][c] = mat[row][col] + 1;
                }
            }
        }
        
        return mat;
    }
};
```

Complexity

Time: O(M * N), where M is number of rows, N is number of columns in the matrix.
Space: O(M * N), space for the queue.

Problem Understanding
In the "01 Matrix Distance" problem, we are given a binary matrix, where each cell contains either a 0 or a 1. The task is to transform this matrix such that each cell contains the shortest distance to a cell with a 0.

For instance, given the matrix:

mat= 
⎣
⎡
​
  
0
0
1
​
  
0
1
1
​
  
0
0
1
​
  
⎦
⎤
​
 

The output should be:

output= 
⎣
⎡
​
  
0
0
1
​
  
0
1
2
​
  
0
0
1
​
  
⎦
⎤
​
 

Live Coding BFS?


Approach: Multi-source BFS
To solve the "01 Matrix Distance" problem, we employ a multi-source BFS approach, starting our traversal from all the cells containing 0s and updating the distances of all adjacent cells.

Key Data Structures:
Matrix: Represents the given binary matrix.
Queue: Used to hold cells for BFS traversal.
Enhanced Breakdown:
Initialization:

Create a queue and initialize it with all cells containing 0s. These will be our BFS starting points.
Set all cells containing 1s to a large value which acts as a placeholder indicating that the cell hasn't been visited yet.
BFS Traversal:

Dequeue a cell and explore its neighboring cells (top, down, left, right).
If the distance to the current cell plus one is less than the value in the neighboring cell, update the neighboring cell's distance and enqueue it for further processing.
Wrap-up:

Once all cells have been visited and updated, return the transformed matrix.
Example:
We'll use the example:

mat= 
⎣
⎡
​
  
0
0
1
​
  
0
1
1
​
  
0
0
1
​
  
⎦
⎤
​
 

We want to debug the function to visualize how the matrix gets updated at each step.

Initialization:
First, we determine the size of the matrix:

m=3 (rows) and n=3 (columns).

MAX_VALUE is set to m×n=9.

Next, we iterate over the matrix. For every cell that has a 1, we set it to MAX_VALUE (i.e., 9). Every cell with a 0 gets appended to the queue.

At this point, the matrix looks like:

⎣
⎡
​
  
0
0
9
​
  
0
9
9
​
  
0
0
9
​
  
⎦
⎤
​
 

And the queue contains: [(0,0), (0,1), (0,2), (1,0), (1,2)].

BFS Traversal:
We start the BFS traversal by dequeuing the first element in the queue, which is (0,0).

We then check its neighboring cells in the directions [(1, 0), (-1, 0), (0, 1), (0, -1)].

For (0,0), the valid neighbors are (1,0) and (0,1).

Since (1,0) has a value of 0, we don't need to update its value or enqueue it. Similarly, (0,1) already has a value of 0, so it's not enqueued or updated either.

The matrix, at this point, looks like:

⎣
⎡
​
  
0
0
9
​
  
0
9
9
​
  
0
0
9
​
  
⎦
⎤
​
 

And the queue is: [(0,1), (0,2), (1,0), (1,2)].

The process continues, dequeuing (0,1) and checking its neighbors.

(1,1) will be updated to 1 (from 9) and enqueued.

This BFS process continues until the queue is empty.

Final State:
After processing all the elements in the queue, the matrix is transformed to:

⎣
⎡
​
0
0
1
​
  
0
1
2
​
  
0
0
1
​
  
⎦
⎤
​
 

This matrix represents the shortest distance of each cell to the nearest 0.

Complexity:
Time Complexity:

O(m×n) - Since each cell in the matrix is processed once.
Space Complexity:

O(m×n) - In the worst case, all cells might be added to the queue.
✔️ Solution 2: Dynamic Programming

For convinience, let's call the cell with value 0 as zero-cell, the cell has with value 1 as one-cell, the distance of

the nearest 0 of a cell as distance.

Firstly, we can see that the distance of all zero-cells are 0, so we skip zero-cells, we process one-cells only.

In DP, we can only use prevous values if they're already computed.

In this problem, a cell has at most 4 neighbors that are left, top, right, bottom. If we use dynamic programming to 

compute the distance of the current cell based on 4 neighbors simultaneously, it's impossible because we are not sure

if distance of neighboring cells is already computed or not.

That's why, we need to compute the distance one by one:

Firstly, for a cell, we restrict it to only 2 directions which are left and top. Then we iterate cells from top to 

bottom, and from left to right, we calculate the distance of a cell based on its left and top neighbors.

Secondly, for a cell, we restrict it only have 2 directions which are right and bottom. Then we iterate cells from

bottom to top, and from right to left, we update the distance of a cell based on its right and bottom neighbors.



![image](https://github.com/user-attachments/assets/ffc98ccd-096c-49de-a4a6-2b21a4b9504b)

![image](https://github.com/user-attachments/assets/0113c586-13be-43a8-a544-03187c50d7bf)


```cpp
class Solution { // 48 ms, faster than 99.64%
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size(), INF = m + n; // The distance of cells is up to (M+N)
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 0) continue;
                int top = INF, left = INF;
                if (r - 1 >= 0) top = mat[r - 1][c];
                if (c - 1 >= 0) left = mat[r][c - 1];
                mat[r][c] = min(top, left) + 1;
            }
        }
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (mat[r][c] == 0) continue;
                int bottom = INF, right = INF;
                if (r + 1 < m) bottom = mat[r + 1][c];
                if (c + 1 < n) right = mat[r][c + 1];
                mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
            }
        }
        return mat;
    }
};

```

Complexity

Time: O(M * N), where M is number of rows, N is number of columns in the matrix.
Space: O(1)


To provide a thorough dry run and visual explanation of each line in this `updateMatrix` function, let’s walk through every line with an example matrix and explain how each part of the code works. The algorithm uses dynamic programming to calculate the minimum distance of each cell from the nearest zero in a two-pass approach.

Here's an example 3x3 matrix we'll use for the dry run:

\[
\text{mat} = 
\begin{bmatrix}
0 & 1 & 1 \\
1 & 1 & 1 \\
1 & 0 & 1 \\
\end{bmatrix}
\]

This matrix has cells with values `1` and `0`. We need to find the minimum distance from each cell containing `1` to the nearest cell containing `0`.

### Explanation of Code Line by Line

#### Step 1: Initialize Variables

```cpp
int m = mat.size(), n = mat[0].size(), INF = m + n;
```

- **`m`**: The number of rows in the matrix (in this example, \( m = 3 \)).
- **`n`**: The number of columns in the matrix (in this example, \( n = 3 \)).
- **`INF`**: Set to a large value \( m + n \) (in this example, \( INF = 6 \)) to represent cells that haven't been updated yet. This is large enough to exceed any possible distance in the matrix.

#### Step 2: First Pass (Top-Left to Bottom-Right)

The purpose of the first pass is to calculate minimum distances from the top and left neighbors for each cell, moving from the top-left corner to the bottom-right.

```cpp
for (int r = 0; r < m; r++) {
    for (int c = 0; c < n; c++) {
        if (mat[r][c] == 0) continue;
        int top = INF, left = INF;
        if (r - 1 >= 0) top = mat[r - 1][c];
        if (c - 1 >= 0) left = mat[r][c - 1];
        mat[r][c] = min(top, left) + 1;
    }
}
```

- **Outer Loop (rows)**: Iterates through each row from top to bottom.
- **Inner Loop (columns)**: Iterates through each column from left to right.

For each cell, if the cell contains `0`, we skip it (since its distance is already zero). For cells containing `1`, we update the distance based on its top and left neighbors.

Let’s go through this process cell-by-cell for our example matrix.

##### First Pass Visual Representation

1. **Cell (0,0)**: Contains `0`, so we skip it.

2. **Cell (0,1)**: 
   - `mat[0][1] = 1`
   - `top = INF` (no row above)
   - `left = mat[0][0] = 0`
   - Update: `mat[0][1] = min(INF, 0) + 1 = 1`

3. **Cell (0,2)**: 
   - `mat[0][2] = 1`
   - `top = INF` (no row above)
   - `left = mat[0][1] = 1`
   - Update: `mat[0][2] = min(INF, 1) + 1 = 2`

4. **Cell (1,0)**: 
   - `mat[1][0] = 1`
   - `top = mat[0][0] = 0`
   - `left = INF` (no column to the left)
   - Update: `mat[1][0] = min(0, INF) + 1 = 1`

5. **Cell (1,1)**: 
   - `mat[1][1] = 1`
   - `top = mat[0][1] = 1`
   - `left = mat[1][0] = 1`
   - Update: `mat[1][1] = min(1, 1) + 1 = 2`

6. **Cell (1,2)**: 
   - `mat[1][2] = 1`
   - `top = mat[0][2] = 2`
   - `left = mat[1][1] = 2`
   - Update: `mat[1][2] = min(2, 2) + 1 = 3`

7. **Cell (2,0)**: 
   - `mat[2][0] = 1`
   - `top = mat[1][0] = 1`
   - `left = INF` (no column to the left)
   - Update: `mat[2][0] = min(1, INF) + 1 = 2`

8. **Cell (2,1)**: Contains `0`, so we skip it.

9. **Cell (2,2)**: 
   - `mat[2][2] = 1`
   - `top = mat[1][2] = 3`
   - `left = mat[2][1] = 0`
   - Update: `mat[2][2] = min(3, 0) + 1 = 1`

**Matrix after First Pass:**

\[
\begin{bmatrix}
0 & 1 & 2 \\
1 & 2 & 3 \\
2 & 0 & 1 \\
\end{bmatrix}
\]

#### Step 3: Second Pass (Bottom-Right to Top-Left)

The second pass refines the distances by checking the bottom and right neighbors for each cell, moving from the bottom-right corner to the top-left.

```cpp
for (int r = m - 1; r >= 0; r--) {
    for (int c = n - 1; c >= 0; c--) {
        if (mat[r][c] == 0) continue;
        int bottom = INF, right = INF;
        if (r + 1 < m) bottom = mat[r + 1][c];
        if (c + 1 < n) right = mat[r][c + 1];
        mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
    }
}
```

Let’s continue with our example.

##### Second Pass Visual Representation

1. **Cell (2,2)**: Contains `1`
   - `bottom = INF` (no row below)
   - `right = INF` (no column to the right)
   - Update: `mat[2][2]` remains `1` as `min(1, INF + 1) = 1`

2. **Cell (2,1)**: Contains `0`, so we skip it.

3. **Cell (2,0)**: 
   - `mat[2][0] = 2`
   - `bottom = INF` (no row below)
   - `right = mat[2][1] = 0`
   - Update: `mat[2][0] = min(2, 0 + 1) = 1`

4. **Cell (1,2)**: 
   - `mat[1][2] = 3`
   - `bottom = mat[2][2] = 1`
   - `right = INF` (no column to the right)
   - Update: `mat[1][2] = min(3, 1 + 1) = 2`

5. **Cell (1,1)**: 
   - `mat[1][1] = 2`
   - `bottom = mat[2][1] = 0`
   - `right = mat[1][2] = 2`
   - Update: `mat[1][1] = min(2, 0 + 1) = 1`

6. **Cell (1,0)**: 
   - `mat[1][0] = 1`
   - `bottom = mat[2][0] = 1`
   - `right = mat[1][1] = 1`
   - Update: `mat[1][0]` remains `1` as `min(1, 1 + 1) = 1`

7. **Cell (0,2)**: 
   - `mat[0][2] = 2`
   - `bottom = mat[1][2] = 2`
   - `right = INF` (no column to the right)
   - Update: `mat[0][2]` remains `2` as `min(2, 2 + 1) = 2`

8. **Cell (0,1)**: 
   - `mat[0][1] = 1`
   - `bottom = mat[1][1] = 1`
   - `right = mat[0][2] = 2`
   - Update: `mat[0][1]` remains `1` as `min(1, 1 + 1) = 1`

9. **Cell (0,0)**: Contains `0`, so we skip it.

**Final Matrix after Second Pass:**

\[
\begin{bmatrix}
0 & 1 & 2 \\
1 & 1 & 2 \\
1 & 0 & 1 \\
\end

{bmatrix}
\]

Each cell now contains the minimum distance to the nearest zero in the matrix.
