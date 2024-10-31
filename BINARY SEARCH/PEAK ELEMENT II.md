https://leetcode.com/problems/find-a-peak-element-ii/solutions/3190868/best-c-2-solution-ever-binary-search-brute-force-optimize-one-stop-solution/

/*

    Time Complexity : O(N*M), where N is the number of row and M is number of column of matrix(mat). Here two
    nested loops create time complexity because in worst case we will visit all the cells of the matrix(mat).

    Space Complexity : O(1), Constant space.

    Solved using Matrix.

*/


/***************************************** Approach 1 *****************************************/
```cpp
class Solution {
private: 
    bool isPeakElement(vector<vector<int>>& mat, int row, int col){
        int n = mat.size();
        int m = mat[0].size();
        int dxdy[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int i=0; i<4; i++){
            int newrow = row + dxdy[i][0];
            int newcol = col + dxdy[i][1];
            if(newrow >= 0 && newcol >= 0 && newrow < n && newcol < m && mat[newrow][newcol] > mat[row][col]){
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isPeakElement(mat, i, j)){
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};


```



/*

    Time Complexity : O(NlogM), where N is the number of row and M is number of column of matrix(mat). Here we
    are doing N work logM times which creates the time complexity.

    Space Complexity : O(1), Constant space.

    Solved using Matrix + Binary Search.

*/


--- Approach 2 ---

```cpp

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
       int low = 0;
       int high = m-1; 
       while(low <= high)
       {
        int mid = low+(high-low)/2;
        int max_row =0;

        for(int row =0;row<n;row++)
        {
            if(mat[max_row][mid] < mat[row][mid])
            {
               max_row = row;
            }
        }

        if((mid ==0 || mat[max_row][mid] > mat[max_row][mid-1]) 
        && (mid == m-1 || mat[max_row][mid]>mat[max_row][mid+1])) 
        return {max_row,mid};
        else if(mid >0 && mat[max_row][mid-1] >mat[max_row][mid]) high = mid-1;
    else low = mid +1;
       }return {-1,-1};
    }
};


```
![31 10 2024_17 40 37_REC](https://github.com/user-attachments/assets/6d5d7b46-940a-43ae-9687-a2d31d5e2468)

![31 10 2024_17 42 27_REC](https://github.com/user-attachments/assets/e254a8dc-f80b-4518-a401-6f5358434de0)


![31 10 2024_17 42 57_REC](https://github.com/user-attachments/assets/f1da36bb-d575-4b7a-988b-215411d59fdf)




Great question! The conditions `mid == 0` and `mid == m - 1` in the code are used to handle edge cases when checking if the maximum element at `matrix[max_row][mid]` is a peak. Let's break down what each condition means:

### Explanation of Conditions

1. **`mid == 0`**:
   - This condition checks if the current column (`mid`) is the first column of the matrix.
   - If `mid` is `0`, it means there is no left neighbor to compare with. Thus, the left neighbor check (`matrix[max_row][mid] > matrix[max_row][mid - 1]`) is not applicable, so we can skip it.
   - In this case, we only need to ensure that the maximum element is greater than its right neighbor, if it exists.

2. **`mid == m - 1`**:
   - This condition checks if the current column (`mid`) is the last column of the matrix.
   - If `mid` is `m - 1`, it means there is no right neighbor to compare with. Thus, the right neighbor check (`matrix[max_row][mid] > matrix[max_row][mid + 1]`) is not applicable, so we can skip it.
   - Here, we only need to ensure that the maximum element is greater than its left neighbor, if it exists.

### Combined Check

The entire condition checks both sides of the maximum element:
```cpp
if ((mid == 0 || matrix[max_row][mid] > matrix[max_row][mid - 1]) && 
    (mid == m - 1 || matrix[max_row][mid] > matrix[max_row][mid + 1]))
```
- **Left Condition (`mid == 0 || ...`)**: 
  - If `mid == 0`, we don't have a left neighbor, so we only consider the right neighbor.
  - If `mid > 0`, we check if the maximum is greater than the left neighbor.

- **Right Condition (`mid == m - 1 || ...`)**: 
  - If `mid == m - 1`, we don't have a right neighbor, so we only consider the left neighbor.
  - If `mid < m - 1`, we check if the maximum is greater than the right neighbor.

### Conclusion

This approach ensures that the peak-checking logic works correctly at the boundaries of the matrix, preventing any out-of-bounds access and allowing for accurate peak identification regardless of the position of the maximum element. 

If you have further questions or need more clarification, feel free to ask!


Sure! Let's go through the entire process of finding a peak element in a 2D matrix in detail, including the concepts, the algorithm, and a visual breakdown of each step.

### Concept of a Peak Element

A **peak element** in a 2D matrix is defined as an element that is greater than or equal to its neighbors. The neighbors are defined as the elements directly adjacent to it (up, down, left, right). For edge elements, we only compare with the existing neighbors.

### Example Matrix

Let's consider the following 2D matrix:

```
[
  [1, 4, 3],
  [3, 2, 4],
  [2, 1, 5]
]
```

### Steps to Find a Peak Element

#### Step 1: Initialization

1. **Define the Matrix Dimensions**:
   - Let `n` be the number of rows (3).
   - Let `m` be the number of columns (3).

2. **Set Search Boundaries**:
   - Initialize two pointers: `lo` (0) and `hi` (2).
   - These will represent the current column boundaries we are searching within.

#### Step 2: Start Binary Search

**The idea is to repeatedly halve the search space until we find a peak.**

1. **Calculate the Mid Column**:
   - `mid = (lo + hi) / 2` gives us the middle column index.
   - In the first iteration, `mid` will be `1`.

#### Step 3: Find Maximum in the Mid Column

2. **Find the Maximum Element in Column 1**:
   - We will check each row in column 1 to find the maximum element.
   - For the matrix:
   ```
   Row 0: 4
   Row 1: 2
   Row 2: 1
   ```
   - The maximum value in Column 1 is `4`, located at position `(0, 1)`.

#### Step 4: Check Peak Conditions

3. **Check If the Maximum Is a Peak**:
   - We need to verify if this maximum is a peak:
     - **Left Neighbor (Column 0)**: The value is `1`. Check if `4 > 1` (True).
     - **Right Neighbor (Column 2)**: The value is `3`. Check if `4 > 3` (True).
   - Since both conditions are true, `4` is a peak.

#### Step 5: Return the Result

4. **Return the Position**:
   - We found a peak at position `(0, 1)` and can return this result.

### Visual Breakdown of Each Step

Here’s a visual breakdown for clarity:

1. **Initial Matrix**:
```
       0     1     2
     +-----+-----+-----+
   0 |  1  |  4  |  3  |
     +-----+-----+-----+
   1 |  3  |  2  |  4  |
     +-----+-----+-----+
   2 |  2  |  1  |  5  |
     +-----+-----+-----+
```

2. **Mid Calculation**:
   - Starting with `lo = 0` and `hi = 2`, we calculate `mid = 1`.

3. **Finding Maximum in Column 1**:
   - Check each row in column 1:
   ```
   Maximum in Column 1:
       0     1     2
     +-----+-----+-----+
   0 |  1  |  *4* |  3  |
     +-----+-----+-----+
   1 |  3  |  2  |  4  |
     +-----+-----+-----+
   2 |  2  |  1  |  5  |
     +-----+-----+-----+
   ```

4. **Check Neighbors**:
   - Left: `1` (yes, `4 > 1`)
   - Right: `3` (yes, `4 > 3`)
   - Since both conditions are satisfied, we confirm `4` is a peak.

5. **Final Result**:
   - We return the peak's coordinates: `(0, 1)`.

### Alternative Scenarios

If the maximum element in the mid column were not a peak, we would adjust the search space:

- If the left neighbor is greater, we know a peak must exist in the left half. So we set `hi = mid - 1`.
- If the right neighbor is greater, we search the right half by setting `lo = mid + 1`.

### Complexity Analysis

- **Time Complexity**: The algorithm runs in \(O(n \log m)\) time, where \(n\) is the number of rows and \(m\) is the number of columns. This is because, in each iteration, we are searching through the rows to find the maximum element in a column, and we're halving the number of columns in each iteration.
  
- **Space Complexity**: The space complexity is \(O(1)\) since we're only using a constant amount of extra space.

### Conclusion

This approach efficiently finds a peak element in a 2D matrix using a combination of binary search and row-wise maximum searching. If you have any more questions about any part of the process, feel free to ask!
