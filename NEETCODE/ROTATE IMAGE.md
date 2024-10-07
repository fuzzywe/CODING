48. Rotate Image
Medium
Topics
Companies
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        for(int i=0;i<row;i++){
            for(int j=0;j<=i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }

        }
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
```
One of the best solution I saw so far. The animation helped a lot! Upvoted for the animation 🔥
https://leetcode.com/problems/rotate-image/solutions/3440564/animation-understand-in-30-seconds/?envType=problem-list-v2&envId=plakya4j&difficulty=MEDIUM&status=TO_DO

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> copy(n, vector<int>(n));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                copy[i][n - 1 - j] = matrix[j][i];
            }
        }
        matrix = copy;
    }
};
```
Actually your solution is not meeting the requirement of this problem statement. in the statement "You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation." this is required. but you have used another 2d vector copy which is requiring extra space, this was not the requirement of this problem


Let's break down the `rotate` function and then do a dry run with an example. This function rotates an `n x n` matrix 90 degrees clockwise.

### Code Explanation:

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        vector<vector<int>> copy(n, vector<int>(n));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                copy[i][n - 1 - j] = matrix[j][i];
            }
        }
        matrix = copy;
    }
};
```

#### 1. `int n = matrix.size();`
- **Purpose**: Determines the size of the matrix (`n x n`).
- **Example**: If `matrix` is a 3x3 matrix, `n` will be `3`.

#### 2. `vector<vector<int>> copy(n, vector<int>(n));`
- **Purpose**: Creates a new matrix `copy` of the same size (`n x n`) initialized with zeros.
- **Example**: If `n = 3`, `copy` will be a 3x3 matrix filled with zeros:
  ```
  copy = [[0, 0, 0],
          [0, 0, 0],
          [0, 0, 0]]
  ```

#### 3. `for(int i = 0; i < n; ++i)`
- **Purpose**: Iterates through each row of the matrix.
- **Example**: When `n = 3`, `i` will take values `0, 1, 2`, corresponding to the rows of the matrix.

#### 4. `for(int j = 0; j < n; ++j)`
- **Purpose**: Iterates through each column of the matrix.
- **Example**: For each `i`, `j` will take values `0, 1, 2`, corresponding to the columns of the matrix.

#### 5. `copy[i][n - 1 - j] = matrix[j][i];`
- **Purpose**: Rotates the matrix elements by 90 degrees.
- **Explanation**: 
  - `matrix[j][i]` accesses the element in the `j`th row and `i`th column of the original matrix.
  - `copy[i][n - 1 - j]` assigns that element to the new matrix `copy` at position `i, n - 1 - j`.
  - This rearranges elements from the original matrix into their new rotated positions.

#### 6. `matrix = copy;`
- **Purpose**: Updates the original matrix `matrix` with the values of the rotated `copy`.

### Example for Dry Run:

Let's take a `3x3` matrix:

```
matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]
```

- **Step 1**: Initialize `copy` as a 3x3 matrix of zeros.
  ```
  copy = [[0, 0, 0],
          [0, 0, 0],
          [0, 0, 0]]
  ```

- **Step 2**: Start the iteration with `i = 0`:
  - For `j = 0`: `copy[0][2] = matrix[0][0] = 1`
    ```
    copy = [[0, 0, 1],
            [0, 0, 0],
            [0, 0, 0]]
    ```
  - For `j = 1`: `copy[0][1] = matrix[1][0] = 4`
    ```
    copy = [[0, 4, 1],
            [0, 0, 0],
            [0, 0, 0]]
    ```
  - For `j = 2`: `copy[0][0] = matrix[2][0] = 7`
    ```
    copy = [[7, 4, 1],
            [0, 0, 0],
            [0, 0, 0]]
    ```

- **Step 3**: Move to `i = 1`:
  - For `j = 0`: `copy[1][2] = matrix[0][1] = 2`
    ```
    copy = [[7, 4, 1],
            [0, 0, 2],
            [0, 0, 0]]
    ```
  - For `j = 1`: `copy[1][1] = matrix[1][1] = 5`
    ```
    copy = [[7, 4, 1],
            [0, 5, 2],
            [0, 0, 0]]
    ```
  - For `j = 2`: `copy[1][0] = matrix[2][1] = 8`
    ```
    copy = [[7, 4, 1],
            [8, 5, 2],
            [0, 0, 0]]
    ```

- **Step 4**: Move to `i = 2`:
  - For `j = 0`: `copy[2][2] = matrix[0][2] = 3`
    ```
    copy = [[7, 4, 1],
            [8, 5, 2],
            [0, 0, 3]]
    ```
  - For `j = 1`: `copy[2][1] = matrix[1][2] = 6`
    ```
    copy = [[7, 4, 1],
            [8, 5, 2],
            [0, 6, 3]]
    ```
  - For `j = 2`: `copy[2][0] = matrix[2][2] = 9`
    ```
    copy = [[7, 4, 1],
            [8, 5, 2],
            [9, 6, 3]]
    ```

- **Final Step**: Update `matrix` with `copy`:
  ```
  matrix = [[7, 4, 1],
            [8, 5, 2],
            [9, 6, 3]]
  ```

This completes the 90-degree clockwise rotation of the matrix.
