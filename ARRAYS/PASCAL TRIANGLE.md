118. Pascal's Triangle
Easy
Topics
Companies
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]

```cpp

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; ++i)
      ans.push_back(vector<int>(i + 1, 1));

    for (int i = 2; i < numRows; ++i)
      for (int j = 1; j < ans[i].size() - 1; ++j)
        ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];

    return ans;
  }
};

```

The code provided is a C++ solution to generate **Pascal's Triangle** for a given number of rows (`numRows`). Here's a **step-by-step dry run** and explanation of each part:

### Code Breakdown and Dry Run:

#### 1. **Function Definition:**
   - **`vector<vector<int>> generate(int numRows)`**:
     - This function generates Pascal's Triangle with `numRows` rows and returns a 2D vector (`ans`).

---

#### 2. **First `for` loop:**
   ```cpp
   for (int i = 0; i < numRows; ++i)
     ans.push_back(vector<int>(i + 1, 1));
   ```
   - **Purpose**: Initializes each row of the Pascal's Triangle.
   - For each row `i` (starting from `i = 0` to `i = numRows - 1`):
     - A new vector of size `i + 1` is created, with all elements initialized to `1`. This ensures that the first and last elements of each row are always `1` in Pascal’s Triangle.

   **Dry Run Example for `numRows = 5`:**
   - For `i = 0`: `ans` becomes `[[1]]` (1st row).
   - For `i = 1`: `ans` becomes `[[1], [1, 1]]` (2nd row).
   - For `i = 2`: `ans` becomes `[[1], [1, 1], [1, 1, 1]]` (3rd row).
   - For `i = 3`: `ans` becomes `[[1], [1, 1], [1, 1, 1], [1, 1, 1, 1]]` (4th row).
   - For `i = 4`: `ans` becomes `[[1], [1, 1], [1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1, 1]]` (5th row).

---

#### 3. **Second `for` loop (starting at `i = 2`):**
   ```cpp
   for (int i = 2; i < numRows; ++i)
     for (int j = 1; j < ans[i].size() - 1; ++j)
       ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
   ```
   - **Purpose**: Fills in the inner elements of each row of Pascal’s Triangle, starting from the 3rd row (`i = 2`).
   - **Inner Loop** (`j` loop):
     - Skips the first and last elements (`1`s) of each row.
     - For each inner element (`ans[i][j]`), it computes the sum of the two elements directly above it from the previous row (`ans[i-1][j-1]` and `ans[i-1][j]`).

   **Dry Run for `numRows = 5`:**
   - **For `i = 2`** (3rd row):
     - `ans[2][1] = ans[1][0] + ans[1][1] = 1 + 1 = 2`.
     - So, `ans` becomes `[[1], [1, 1], [1, 2, 1]]`.

   - **For `i = 3`** (4th row):
     - `ans[3][1] = ans[2][0] + ans[2][1] = 1 + 2 = 3`.
     - `ans[3][2] = ans[2][1] + ans[2][2] = 2 + 1 = 3`.
     - So, `ans` becomes `[[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]`.

   - **For `i = 4`** (5th row):
     - `ans[4][1] = ans[3][0] + ans[3][1] = 1 + 3 = 4`.
     - `ans[4][2] = ans[3][1] + ans[3][2] = 3 + 3 = 6`.
     - `ans[4][3] = ans[3][2] + ans[3][3] = 3 + 1 = 4`.
     - So, `ans` becomes `[[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]`.

---

#### 4. **Return the final result:**
   ```cpp
   return ans;
   ```
   - After the loops are finished, the fully constructed Pascal’s Triangle (`ans`) is returned.

---

### **Visualization of Pascal's Triangle for `numRows = 5`:**
```
[
  [1],
  [1, 1],
  [1, 2, 1],
  [1, 3, 3, 1],
  [1, 4, 6, 4, 1]
]
```


- The first loop initializes each row with `1`s.
- The second loop computes the inner elements (non-edge) of Pascal's Triangle using the sum of the two numbers directly above it.
- The result is a correctly constructed Pascal’s Triangle.

- Both the **time complexity** and **space complexity** of the code are **O(numRows²)**. Here’s a quick recap:
---------------------------------------------------------------------------------------------------------------------
Example 1:
Input Format:
 N = 5, r = 5, c = 3
Result:
 6 (for variation 1)
1 4 6 4 1 (for variation 2)

1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1    (for variation 3)

Explanation:
 There are 5 rows in the output matrix. Each row is formed using the logic of Pascal’s triangle.

Example 2:
Input Format:
 N = 1, r = 1, c = 1
Result:
 1 (for variation 1)
    1 (for variation 2)
    1  (for variation 3)
Explanation:
 The output matrix has only 1 row.


 ---------------------------

```cpp

#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: "
            << element << "n";
    return 0;
}
        

```

Complexity Analysis
Time Complexity: O(c), where c = given column number.
Reason: We are running a loop for r times, where r is c-1.

Space Complexity: O(1) as we are not using any extra space.
--------------------------------------------------------------------------------------------------------------
NAVIE APPROACH:

Naive Approach
In this approach, for every column from 1 to n, we will calculate the element (n, c)(where n is the given row number and c is the column number that will vary from 1 to n) using the previous method. Thus, we will print the row.  

Algorithm / Intuition
In this approach, for every column from 1 to n, we will calculate the element (n, c)(where n is the given row number and c is the column number that will vary from 1 to n) using the previous method. Thus, we will print the row.  

Approach:
The steps are as follows:

We will use a loop(say c) to iterate over each column i.e. from 1 to n. And for each column, we will do the following steps:
First, we will consider n-1 as n and c-1 as r.
After that, we will simply calculate the value of the combination using a loop. 
The loop will run from 0 to r. And in each iteration, we will multiply (n-i) with the result and divide the result by (i+1).
Finally, we will print the element.
Finally, the entire row will be printed.
Note: For a better understanding of intuition, please watch the video at the bottom of the page.

```cpp

#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void pascalTriangle(int n) {
    // printing the entire row n:
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "n";
}

int main()
{
    int n = 5;
    pascalTriangle(n);
    return 0;
}
Output: 1 4 6 4 1

```

Complexity Analysis
Time Complexity: O(n*r), where n is the given row number, and r is the column index which can vary from 0 to n-1.
Reason: We are calculating the element for each column. Now, there are total n columns, and for each column, the calculation of the element takes O(r) time where r is the column index.

Space Complexity: O(1) as we are not using any extra space.
