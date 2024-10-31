Search in a sorted 2D matrix

https://leetcode.com/problems/search-a-2d-matrix/description/



Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

Examples
Example 1:
Input Format:
 N = 3, M = 4, target = 8,
mat[] = 
1 2 3 4
5 6 7 8 
9 10 11 12
Result:
 true
Explanation:
 The ‘target’  = 8 exists in the 'mat' at index (1, 3).

Example 2:
Input Format:
 N = 3, M = 3, target = 78,
mat[] = 
1 2 4
6 7 8 
9 10 34
Result:
 false
Explanation:
 The ‘target' = 78 does not exist in the 'mat'. Therefore in the output, we see 'false'.

  #include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}

Output: true

Complexity Analysis
Time Complexity: O(N X M), where N = given row number, M = given column number.
Reason: In order to traverse the matrix, we are using nested loops running for n and m times respectively.

Space Complexity: O(1) as we are not using any extra space.

  #include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
            return binarySearch(matrix[i], target);
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}

Output: true

Complexity Analysis
Time Complexity: O(N + logM), where N = given row number, M = given column number.
Reason: We are traversing all rows and it takes O(N) time complexity. But for all rows, we are not applying binary search rather we are only applying it once for a particular row. That is why the time complexity is O(N + logM) instead of O(N*logM).

Space Complexity: O(1) as we are not using any extra space.

 Sure! Let's break down that specific piece of code step by step and understand the logic and math behind it.

### Context

The goal of this code is to find a target value in a 2D matrix where each row is sorted in ascending order. The matrix is structured so that the first element of each row is less than or equal to the last element of that row.

### Code Breakdown

```cpp
for (int i = 0; i < n; i++) {
    if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
        return binarySearch(matrix[i], target);
    }
}
```

### Detailed Explanation

1. **Loop Through Rows**:
   - The loop `for (int i = 0; i < n; i++)` iterates through each row of the matrix. Here, `n` is the number of rows.

2. **Condition Check**:
   - The condition `if (matrix[i][0] <= target && target <= matrix[i][m - 1])` is the key part. It checks whether the target value can possibly be found in the current row `i`.
     - **`matrix[i][0]`**: This is the first element of row `i`.
     - **`matrix[i][m - 1]`**: This is the last element of row `i`.
     - **`target`**: This is the value we are searching for.

### Mathematical Logic

- **First Element**: `matrix[i][0] <= target`
  - This checks if the first element of the row is less than or equal to the target. If this is false, it means the target is less than the smallest element in that row, so it cannot exist in that row.

- **Last Element**: `target <= matrix[i][m - 1]`
  - This checks if the target is less than or equal to the last element of the row. If this is false, it means the target is greater than the largest element in that row, so it cannot exist in that row.

### Combined Condition

By combining these two conditions with `&&` (logical AND), you ensure that the target falls within the range of the current row's first and last elements:

- If both conditions are true, it means the target **could** potentially exist in the current row, and we can safely perform a binary search on that row.

### Example

Consider the following matrix:

```
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9, 10, 11, 12]
]
```

If the target is `6`, the process will be:

- For **Row 0** (`[1, 2, 3, 4]`):
  - First element: `1` (not greater than `6`)
  - Last element: `4` (not less than `6`)
  - **Condition fails**: Move to next row.

- For **Row 1** (`[5, 6, 7, 8]`):
  - First element: `5` (less than or equal to `6`)
  - Last element: `8` (greater than or equal to `6`)
  - **Condition passes**: We perform binary search on this row.

- For **Row 2** (`[9, 10, 11, 12]`):
  - First element: `9` (greater than `6`)
  - **Condition fails**: No need to check further.

### Conclusion

This conditional check efficiently narrows down which rows need to be searched, significantly reducing the number of binary searches performed. It uses the properties of the sorted rows to determine if the target could possibly exist in that row based on its boundaries.

If you have any more questions or need further clarification, feel free to ask!
