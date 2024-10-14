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

```cpp

Time complexity: O((m + n) \log D), where D is the value range in the matrix.
Space complexity: O(1).

class Solution { // 20 ms, faster than 98.92%
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
