Rotten Oranges : Min time to rot all oranges : BFS


83

8
Problem Statement: You will be given an m x n grid, where each cell has the following values : 

2  -  represents a rotten orange
1  -  represents a Fresh orange
0  -  represents an Empty Cell
Every minute, if a Fresh Orange is adjacent to a Rotten Orange in 4-direction ( upward, downwards, right, and left ) it becomes Rotten. 

Return the minimum number of minutes required such that none of the cells has a Fresh Orange. If it's not possible, return -1.

Examples:

Example 1:

Input: grid - [ [2,1,1] , [0,1,1] , [1,0,1] ]

Output: -1


Explanation:  

Table

Description automatically generated
Example 2:

Input: grid - [ [2,1,1] , [1,1,0] , [0,1,1] ] 

Output:  4


Explanation:




In these examples, we are dealing with a grid that represents the state of oranges, where each cell can have one of three values:
- **0**: an empty cell.
- **1**: a fresh orange.
- **2**: a rotten orange.

The task is to determine the minimum time required to make all the fresh oranges rot. Rotten oranges spread their rot to adjacent fresh oranges (left, right, up, down) every minute. If there is at least one fresh orange that cannot be rotten (due to isolation from all rotten oranges), we return `-1`.

Let's break down the examples.

### Example 1:

#### Input:
```cpp
grid = [
   [2, 1, 1],
   [0, 1, 1],
   [1, 0, 1]
]
```

#### Explanation:

- Initial grid:  
  ```
  [2, 1, 1]
  [0, 1, 1]
  [1, 0, 1]
  ```
  - `2` represents rotten oranges.
  - `1` represents fresh oranges.
  - `0` represents empty cells.

#### Step-by-Step Process:

- **Minute 0**: The orange at position (0, 0) is already rotten.

- **Minute 1**: The rotten orange at (0, 0) can spread the rot to its adjacent cells:
  - The orange at (0, 1) becomes rotten.
  - The grid now looks like this:
    ```
    [2, 2, 1]
    [0, 1, 1]
    [1, 0, 1]
    ```

- **Minute 2**: The newly rotten orange at (0, 1) spreads the rot to its adjacent cells:
  - The orange at (0, 2) becomes rotten.
  - The grid now looks like this:
    ```
    [2, 2, 2]
    [0, 1, 1]
    [1, 0, 1]
    ```

- **Minute 3**: The rotten orange at (0, 2) spreads the rot to its adjacent cells:
  - The orange at (1, 2) becomes rotten.
  - The grid now looks like this:
    ```
    [2, 2, 2]
    [0, 1, 2]
    [1, 0, 1]
    ```

- **Minute 4**: The rotten orange at (1, 2) spreads the rot to its adjacent cells:
  - The orange at (1, 1) becomes rotten.
  - The grid now looks like this:
    ```
    [2, 2, 2]
    [0, 2, 2]
    [1, 0, 1]
    ```

At this point, the orange at (2, 0) and (2, 2) are still fresh, but they are isolated because there is no adjacent rotten orange, and no empty cell connects them to any rotten oranges. Hence, **it is impossible to rot all oranges**, so the output is `-1`.

#### Final Output:
```cpp
-1
```

---

### Example 2:

#### Input:
```cpp
grid = [
   [2, 1, 1],
   [1, 1, 0],
   [0, 1, 1]
]
```

#### Explanation:

- Initial grid:
  ```
  [2, 1, 1]
  [1, 1, 0]
  [0, 1, 1]
  ```
  
#### Step-by-Step Process:

- **Minute 0**: The orange at position (0, 0) is already rotten.

- **Minute 1**: The rotten orange at (0, 0) spreads the rot to its adjacent cells:
  - The orange at (0, 1) becomes rotten.
  - The grid now looks like this:
    ```
    [2, 2, 1]
    [1, 1, 0]
    [0, 1, 1]
    ```

- **Minute 2**: The newly rotten orange at (0, 1) spreads the rot to its adjacent cells:
  - The orange at (0, 2) becomes rotten.
  - The orange at (1, 1) becomes rotten.
  - The grid now looks like this:
    ```
    [2, 2, 2]
    [1, 2, 0]
    [0, 1, 1]
    ```

- **Minute 3**: The rotten orange at (0, 2) and (1, 1) spread the rot to their adjacent cells:
  - The orange at (1, 0) becomes rotten.
  - The orange at (2, 1) becomes rotten.
  - The grid now looks like this:
    ```
    [2, 2, 2]
    [2, 2, 0]
    [0, 2, 1]
    ```

- **Minute 4**: The rotten orange at (2, 1) spreads the rot to its adjacent cells:
  - The orange at (2, 2) becomes rotten.
  - The grid now looks like this:
    ```
    [2, 2, 2]
    [2, 2, 0]
    [0, 2, 2]
    ```

Now, all oranges are rotten, and it took **4 minutes** for this to happen.

#### Final Output:
```cpp
4
```

---

---

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited = grid;
        //making queue in which we will fill rotten oranges
        queue<pair<int, int>> q;
        int countFreshOrange = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 2) {
                    q.push({i, j});
                }
                if (visited[i][j] == 1) {
                    countFreshOrange++;
                }
            }
        }
        //q.empty() means there is no rotten orange in the grid and countFreshOrange = 0 means we will rotten the freshoranges in 0 mins
        if (countFreshOrange == 0)
            return 0;
        if (q.empty())
            return -1;
        
        int minutes = -1;
        // we will cover four directions i.e. up, down, left, right
        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int i = x + dx;
                    int j = y + dy;
                    if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
                        visited[i][j] = 2;
                        countFreshOrange--;
                        q.push({i, j});
                    }
                }
            }
            minutes++;
        }
        
        if (countFreshOrange == 0)
            return minutes;
        return -1;
    }
};
```

---

Sure, let's go over the **mathematical calculations** for each part of the code line by line. This approach will focus on how numbers, like row/column indices or counters, change or are affected by each operation.

---

### **1. Grid Size Calculation**

```cpp
int m = grid.size();
int n = grid[0].size();
```

- **`m = grid.size()`**: The variable `m` is assigned the number of rows in the grid. If the grid is a 3x4 matrix, then `m = 3`.

- **`n = grid[0].size()`**: Similarly, `n` is assigned the number of columns in the grid. If the grid is a 3x4 matrix, `n = 4`.

### Math:

- There is no real calculation happening here, but simply reading the number of rows (`m`) and columns (`n`) of the grid.

### **2. Visited Matrix and Queue Initialization**

```cpp
vector<vector<int>> visited = grid;
queue<pair<int, int>> q;
int countFreshOrange = 0;
```

- **`visited = grid`**: This creates a copy of the grid, where each value from `grid[i][j]` is copied to `visited[i][j]`.

- **`queue<pair<int, int>> q`**: An empty queue `q` is created. We will later store the coordinates (row, column) of the rotten oranges.

- **`countFreshOrange = 0`**: This initializes a counter for fresh oranges to 0. We’ll increment this value as we find fresh oranges.

### Math:

- **Copying the grid**: Let’s say `m = 3` and `n = 4`. The number of elements copied will be `m × n = 12`.

---

### **3. Identifying Fresh and Rotten Oranges**

```cpp
for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        if (visited[i][j] == 2) {
            q.push({i, j});
        }
        if (visited[i][j] == 1) {
            countFreshOrange++;
        }
    }
}
```

- **`for (int i = 0; i < m; i++)`**: This outer loop goes over each row `i` from `0` to `m-1`. If `m = 3`, `i` will take values `0`, `1`, `2`.

- **`for (int j = 0; j < n; j++)`**: This inner loop goes over each column `j` from `0` to `n-1`. If `n = 4`, `j` will take values `0`, `1`, `2`, `3`.

- **Check for rotten oranges**:
  - **`if (visited[i][j] == 2)`**: If an orange is rotten (`2`), push its coordinates `(i, j)` to the queue `q`. For example, if `grid[0][0] = 2`, then `q.push({0, 0})` adds the pair `(0, 0)` to the queue.

- **Count fresh oranges**:
  - **`if (visited[i][j] == 1)`**: If the orange is fresh (`1`), increment the `countFreshOrange` by 1.

### Math:

- Let's say the grid is:

    ```
    [[2, 1, 1],
     [0, 1, 2],
     [0, 1, 1]]
    ```

  - For every `1` (fresh orange), increment `countFreshOrange`. If there are `5` fresh oranges, the final value of `countFreshOrange` will be `5`.
  
  - For every `2` (rotten orange), push its position into the queue. If there are `2` rotten oranges, the queue will contain `q = [(0, 0), (1, 2)]`.

---

### **4. Edge Cases: No Fresh or Rotten Oranges**

```cpp
if (countFreshOrange == 0)
    return 0;
if (q.empty())
    return -1;
```

- **`if (countFreshOrange == 0)`**: This checks if there are no fresh oranges. If this is true, the function immediately returns `0` (as no rotting is needed).

- **`if (q.empty())`**: This checks if the queue is empty, meaning no rotten oranges exist. If this is true, but there are fresh oranges (`countFreshOrange > 0`), it returns `-1`, as rotting the fresh oranges is impossible.

### Math:

- If `countFreshOrange = 0`, return `0`.
- If `q = []` (empty), return `-1` if there are fresh oranges.

---

### **5. Setup for BFS**

```cpp
int minutes = -1;
vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
```

- **`minutes = -1`**: This variable tracks how many minutes (steps) it takes to rot all the oranges. We start at `-1` since we will increment it after each round of BFS.

- **`dirs`**: This is a list of directions (up, down, left, right) used to explore the neighbors of each orange:
  - **`{1, 0}`**: Moves one step down.
  - **`{-1, 0}`**: Moves one step up.
  - **`{0, -1}`**: Moves one step left.
  - **`{0, 1}`**: Moves one step right.

### Math:

- The `dirs` vector contains 4 possible directions, which will be used to calculate neighboring cells during BFS.

---

### **6. BFS Process (Spreading Rot)**

```cpp
while (!q.empty()) {
    int size = q.size();
    while (size--) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : dirs) {
            int i = x + dx;
            int j = y + dy;
            if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
                visited[i][j] = 2;
                countFreshOrange--;
                q.push({i, j});
            }
        }
    }
    minutes++;
}
```

### **First while loop**: `while (!q.empty())`
- **Math**: This loop runs while the queue is not empty. Each round of this loop represents 1 minute of rotting time.

- **`int size = q.size()`**: The variable `size` stores the current number of rotten oranges to process for the current round.

- **Inner loop**: `while (size--)`
  - **Math**: This loop runs `size` times, i.e., once for each rotten orange in the current round.

---

### **Processing Each Rotten Orange**:
- **`auto [x, y] = q.front()`**: This retrieves the current rotten orange's coordinates `(x, y)` from the queue.

- **`q.pop()`**: After processing the current orange, remove it from the queue.

### **Spreading Rot to Neighbors**:
- **`for (auto [dx, dy] : dirs)`**: For each direction (up, down, left, right):
  - **`int i = x + dx`**: Calculate the row index of the neighboring cell.
  - **`int j = y + dy`**: Calculate the column index of the neighboring cell.

- **Bounds check**:
  - **`i >= 0 && i < m && j >= 0 && j < n`**: Ensure the neighboring cell `(i, j)` is within the grid's bounds.

- **Fresh orange check**:
  - **`if (visited[i][j] == 1)`**: If the neighboring cell contains a fresh orange (`1`), convert it to rotten (`2`), decrement the fresh orange count (`countFreshOrange--`), and push the new rotten orange into the queue (`q.push({i, j})`).

### Math:

- For each rotten orange, we check at most 4 neighbors. If a fresh orange is found, the total number of fresh oranges `countFreshOrange` decreases by 1.

- This step continues until either all oranges are rotten or the queue is empty.

---

### **7. Final Check**

```cpp
if (countFreshOrange == 0)
    return minutes;
return -1;
```

- **`if (countFreshOrange == 0)`**: If all fresh oranges have rotted, return the number of minutes (`minutes`).

- **`return -1`**: If some fresh oranges couldn’t rot (because they are isolated from all rotten oranges), return `-1`.

---

### **Mathematical Summary:**

- The code follows a **breadth-first search (BFS)** algorithm, processing all rotten oranges simultaneously at each minute.

- The calculation is based on:
  - Counting fresh oranges (`countFreshOrange`).
  - Spreading rot to neighboring fresh oranges.
  - Keeping track of time (in minutes) it takes to rot all reachable fresh oranges.

