https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=median-in-a-row-wise-sorted-matrix

![BS-27  Median in a Row Wise Sorted Matrix 2-6 screenshot (1)](https://github.com/user-attachments/assets/cc676cf5-d3ce-4388-ab8b-518252fe48d0)

![BS-27  Median in a Row Wise Sorted Matrix 9-12 screenshot](https://github.com/user-attachments/assets/7c99367b-59f7-4df2-bb42-ce4d504b9c75)

![BS-27  Median in a Row Wise Sorted Matrix 11-29 screenshot](https://github.com/user-attachments/assets/1810b2e9-932a-41d6-ae3c-809746b37d26)

sort the array first


Median of Row Wise Sorted Matrix


73

6
Problem Statement: Given a row-wise sorted matrix of size MXN, where M is no. of rows and N is no. of columns, find the median in the given matrix.

Note: MXN is odd.

Examples
Example 1:
Input Format:M = 3, N = 3, matrix[][] =

                    1 4 9 
                    2 5 6
                    3 8 7
                    
Result: 5
Explanation:  If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5
Example 2:
Input Format:M = 3, N = 3, matrix[][] =

                    1 3 8 
                    2 3 4
                    1 2 5
                    
Result: 3
Explanation:  If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 7 8. So, median = 3


BRUTE FORCE 


```cpp
vector<int> v;
        int n= R*C;
        for(int i= 0; i<R;i++){
           for(int j=0;j<C; j++){
               v.push_back(matrix[i][j]);
           } 
        }
        sort(v.begin(), v.end());
        return v[n/2];
    }

```

---

OPTIMAL 

```cpp

class Solution {
public:
    int upperBound(vector<int> mat, int num) {
        int n = mat.size();
        int low = 0;
        int high = n - 1;
        int cnt = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mat[mid] > num) {
                cnt = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return cnt;
    }

    int NoOfSmallerNum(vector<vector<int>> &mat, int num) {
        int n = mat.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upperBound(mat[i], num);
        }
        return cnt;
    }

    int median(vector<vector<int>> &mat, int R, int C) {
        int low = INT_MAX;
        int high = INT_MIN;

        for (int i = 0; i < R; i++) {
            if (mat[i][0] < low) {
                low = mat[i][0];
            }
            if (mat[i][C - 1] > high) {
                high = mat[i][C - 1];
            }
        }

        int req = (R * C) / 2;

        int ans = -1; 
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int smallernum = NoOfSmallerNum(mat, mid);

            if (smallernum > req) {
                ans = mid; 
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return low;
    }
};

```

No problem! Let’s simplify the explanation further and focus on the key concepts step-by-step, using visuals to make it clearer.

### Step-by-Step Breakdown

Let's use the same matrix as an example:

```
1  3  5
2  6  9
3  6  9
```

### 1. Understanding the Goal

The goal is to find the **median** of all elements in the matrix. For our 3x3 matrix, there are **9 elements**:

```
1, 2, 3, 3, 5, 6, 6, 9, 9
```

- The **median** is the middle element, which is the 5th element when sorted.
- For 9 elements, the median is at position `(9 / 2)`, which is 4 (using zero-based indexing).

### 2. Finding the Range for the Median

To efficiently find the median without sorting the entire array, we use `low` and `high`:

- **`low`**: The smallest possible value that could be the median.
- **`high`**: The largest possible value that could be the median.

### 3. Initializing `low` and `high`

#### Step 1: Initialize `low` and `high`

- Start with:
  - `low = INT_MAX` (very high value, initially)
  - `high = INT_MIN` (very low value, initially)

#### Step 2: Find `low`

We look for the smallest value in the **first column**:

```
| Row | First Element |
|-----|---------------|
| 1   | 1             |
| 2   | 2             |
| 3   | 3             |
```

- Compare:
  - Row 1: `1 < INT_MAX` → Set `low = 1`
  - Row 2: `2 < 1` → No change
  - Row 3: `3 < 1` → No change

**Final `low` value**: `1`

#### Step 3: Find `high`

Now we look for the largest value in the **last column**:

```
| Row | Last Element |
|-----|--------------|
| 1   | 5            |
| 2   | 9            |
| 3   | 9            |
```

- Compare:
  - Row 1: `5 > INT_MIN` → Set `high = 5`
  - Row 2: `9 > 5` → Set `high = 9`
  - Row 3: `9 > 9` → No change

**Final `high` value**: `9`

### 4. The Range of Possible Median Values

Now we have:

- **`low = 1`**
- **`high = 9`**

This means the potential median must be between `1` and `9`:

```
Range for median: [1, 9]
```

### 5. Why This Matters

This range helps us:

- **Focus our search**: We won’t look for medians outside of this range. 
- **Use binary search**: We will check middle values (like 5) and count how many elements are less than or equal to that middle value.

### Visual Summary

- **Possible Values**:
  
```
1, 2, 3, 3, 5, 6, 6, 9, 9
```

- **Range for Median**:

```
|----|-----------|-------|
low: 1           mid: 5   high: 9
```

- The median will be found by checking values in the range `[1, 9]` and determining how many numbers fall below each candidate.

### Conclusion

The initialization of `low` and `high` provides a clear and efficient way to search for the median. It narrows down the potential candidates based on the values in the matrix, allowing for faster calculations.

If you still have questions or if there's a specific part that needs more clarification, let me know, and I’ll be happy to help!
