https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

378. Kth Smallest Element in a Sorted Matrix

Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5

```cpp
Complexity:
Time: O(M * N * logK), where M <= 300 is the number of rows, N <= 300 is the number of columns.
Space: O(K), space for heap which stores up to k elements.


class Solution { 
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(); // For general, the matrix need not be a square
        priority_queue<int> maxHeap;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                maxHeap.push(matrix[r][c]);
                if (maxHeap.size() > k) maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};

```


```cpp

class Solution {
public:
    int solve(vector<vector<int>>& matrix, int mid){
        int count = 0, n = matrix.size(), i = n-1, j = 0;
        while(i >= 0 && j < n){
            if(matrix[i][j] > mid) i--;
            else{
                count += (i+1);
                j++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), i = matrix[0][0], j = matrix[n-1][n-1];
        while(i < j){
            int mid = i + (j-i)/2;
            int posi = solve(matrix, mid);
            if(posi < k) i = mid+1;
            else j = mid;
        }
        return i;
    }  
};
```
Let's break down the `solve` function visually and explain how it works step by step. The purpose of this function is to count how many elements in a sorted matrix are less than or equal to a given value (`mid`). This is done efficiently using a technique that navigates through the matrix.

### Matrix Example

Consider the following sorted matrix:

```
matrix = [
    [ 1,  5,  9 ],
    [10, 11, 13],
    [12, 13, 15]
]
```

---

### Function Overview

The function `solve` works with two pointers:

- `i`: Starts at the **bottom-left** of the matrix (initially `n-1`, which is the last row).
- `j`: Starts at the **top-left** of the matrix (initially `0`, which is the first column).

The goal is to count how many elements are less than or equal to `mid`. 

---

### Step-by-Step Execution

1. **Initialization**:
   - Set `count = 0` to keep track of the number of elements ≤ `mid`.
   - `n = matrix.size()` to get the number of rows.
   - Set `i = n - 1` (the last row) and `j = 0` (the first column).

#### Visual Representation of Initialization:

```
Start:
  j=0
  i=2
matrix = [
    [ 1,  5,  9 ],  <- row 0
    [10, 11, 13],  <- row 1
    [12, 13, 15]   <- row 2 (initial position for i)
]
```

---

2. **Entering the while loop**: 
   The loop continues as long as `i >= 0` (within the bounds of rows) and `j < n` (within the bounds of columns).

3. **First Comparison**:
   - Check if `matrix[i][j] > mid`.
   - If true, move up (`i--`) to check the element above.
   - If false, add `(i + 1)` to `count` (because all elements in that column from row `0` to row `i` are ≤ `mid`) and move right (`j++`).

#### Example Walkthrough with `mid = 10`

Let's set `mid = 10` for this example. 

- **Iteration 1**:
  - Check `matrix[2][0] = 12 > 10` → **true** → Move up: `i--` → `i = 1`.

```
Current Position:
    j=0
    i=2
Count: 0
matrix = [
    [ 1,  5,  9 ],  
    [10, 11, 13],
    [12, 13, 15]   <- Check this value (12 > 10)
]
```

- **Iteration 2**:
  - Check `matrix[1][0] = 10 > 10` → **false** → Count the elements.
    - Add `i + 1 = 2` to `count` (we can count two elements: `10` and `1` from the first column).
    - Move right: `j++` → `j = 1`.

```
Current Position:
    j=0
    i=1
Count: 2 (1 from row 0, 10 from row 1)
matrix = [
    [ 1,  5,  9 ],  
    [10, 11, 13]   <- Check this value (10 is not greater than 10)
]
```

- **Iteration 3**:
  - Now check `matrix[1][1] = 11 > 10` → **true** → Move up: `i--` → `i = 0`.

```
Current Position:
    j=1
    i=1
Count: 2
matrix = [
    [ 1,  5,  9 ],  
    [10, 11, 13] 
] <- Check this value (11 > 10)
```

- **Iteration 4**:
  - Check `matrix[0][1] = 5 > 10` → **false** → Count elements.
    - Add `i + 1 = 1` to `count` (we can count `1` and `5` from the first column).
    - Move right: `j++` → `j = 2`.

```
Current Position:
    j=1
    i=0
Count: 3 (1 from row 0, 5 from row 0)
matrix = [
    [ 1,  5,  9 ] <- Check this value (5 is not greater than 10)
]
```

- **Iteration 5**:
  - Check `matrix[0][2] = 9 > 10` → **false** → Count elements.
    - Add `i + 1 = 1` to `count` (counting `1`, `5`, and `9`).
    - Move right: `j++` → `j = 3` (out of bounds for `j`).

```
Current Position:
    j=2
    i=0
Count: 4 (1 from row 0, 5 from row 0, 9 from row 0)
matrix = [
    [ 1,  5,  9 ]
] <- Check this value (9 is not greater than 10)
```

### End of the Loop

Now that `j` is equal to `n`, we exit the while loop.

### Final Count

- The count of elements less than or equal to `mid = 10` is **4** (`1`, `5`, `9`, `10`).

### Summary

The function `solve` efficiently counts the number of elements less than or equal to `mid` by:
- Starting from the bottom-left corner of the matrix.
- Moving up if the current element is greater than `mid`.
- Counting all elements in that column (from the top row to the current row) if the current element is less than or equal to `mid` and moving to the next column.

This approach takes advantage of the sorted nature of the matrix, allowing us to traverse it efficiently without checking every element.


```cpp

Time complexity: O((m + n) \log D), where D is the value range in the matrix.
Space complexity: O(1).

class Solution { 
public:
    int m, n;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size(), n = matrix[0].size(); // For general, the matrix need not be a square
        int left = matrix[0][0], right = matrix[m-1][n-1], ans = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (countLessOrEqual(matrix, mid) >= k) {
                ans = mid;
                right = mid - 1; // try to looking for a smaller value in the left side
            } else left = mid + 1; // try to looking for a bigger value in the right side
        }
        return ans;
    }
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int cnt = 0, c = n - 1; // start with the rightmost column
        for (int r = 0; r < m; ++r) {
            while (c >= 0 && matrix[r][c] > x) --c;  // decrease column until matrix[r][c] <= x
            cnt += (c + 1);
        }
        return cnt;
    }
};
```

Both expressions are used to calculate the **midpoint** in binary search, but they differ slightly in terms of readability and performance. Here's a detailed breakdown:

### 1. **Expression 1: `int mid = i + (j - i) / 2;`**

This is a common and safe way to calculate the midpoint between two integers `i` and `j`. Let's break it down:

- **`i + (j - i) / 2`** ensures that there is no overflow when adding `i` and `j`.
- By calculating `(j - i) / 2`, you're determining the difference between `j` and `i`, halving it, and then adding it to `i`. This gives the middle point.

#### Why is this used?
- **Avoids overflow**: In cases where `i` and `j` are very large, directly adding them (`i + j`) could result in an integer overflow. For example, if both `i` and `j` are close to the maximum value of an integer, adding them could exceed the limit of `int`, causing unexpected results.
  
#### Example:
If `i = 1,000,000,000` and `j = 2,000,000,000`:
- Direct sum: `i + j = 3,000,000,000`, which could overflow if `int` can only hold values up to `2,147,483,647` (in a 32-bit system).
- Using `i + (j - i) / 2`, we first compute `j - i = 1,000,000,000`, then `1,000,000,000 / 2 = 500,000,000`. Adding it to `i`, we get `i + 500,000,000 = 1,500,000,000`, which avoids overflow.

### 2. **Expression 2: `int mid = (left + right) >> 1;`**

This expression uses **bitwise shifting** to calculate the midpoint. The right-shift operator (`>> 1`) divides the sum of `left` and `right` by 2, effectively calculating the midpoint. Let's break it down:

- **`(left + right) >> 1`** first adds `left` and `right` and then divides by 2 using the bitwise right-shift operator. Right-shifting by 1 is equivalent to dividing by 2.

#### Why is this used?
- **Bitwise operations are fast**: Bitwise shifts are faster than arithmetic operations like division, so this is often used when performance is critical. However, modern compilers are generally optimized to perform division efficiently, so the performance gain may be negligible in most cases.
  
#### Example:
If `left = 10` and `right = 30`:
- Direct sum: `left + right = 40`
- Right-shift by 1: `40 >> 1 = 20` (which is the same as `40 / 2`).

#### Potential issue:
- **Overflow risk**: Unlike the first method, this approach does not protect against integer overflow. If `left + right` exceeds the maximum value that can be stored in an `int`, it could lead to an overflow and result in incorrect values.

### Key Differences:

| Aspect                | `i + (j - i) / 2`                                        | `(left + right) >> 1`                                  |
|-----------------------|----------------------------------------------------------|--------------------------------------------------------|
| **Overflow Protection**| Safeguards against overflow by subtracting first.         | Can overflow if `left + right` exceeds `int` capacity.  |
| **Performance**        | Slightly slower (but safer) due to extra arithmetic.      | Bitwise operation is fast, but modern compilers often optimize both. |
| **Readability**        | More intuitive for general understanding and usage.       | More compact, but less intuitive unless familiar with bitwise shifts. |

### Conclusion:
- **Use `i + (j - i) / 2` when you're concerned about large values and potential overflow.** This method is safer and should be your default choice.
- **Use `(left + right) >> 1` if you're confident there won't be overflow** and you need slightly better performance, especially in competitive programming or performance-critical scenarios.

In modern compilers, the difference in performance is often negligible, and they might optimize both approaches similarly.
