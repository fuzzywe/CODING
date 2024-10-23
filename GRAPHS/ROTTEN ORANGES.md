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

### Summary of Logic:
- At each minute, rotten oranges infect all adjacent fresh oranges.
- The task is to find how many minutes it takes to infect all oranges.
- If any fresh orange remains uninfected and isolated, the result is `-1`.

Let me know if you need further clarification!
