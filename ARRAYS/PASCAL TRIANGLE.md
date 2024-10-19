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

### Summary:
- The first loop initializes each row with `1`s.
- The second loop computes the inner elements (non-edge) of Pascal's Triangle using the sum of the two numbers directly above it.
- The result is a correctly constructed Pascal’s Triangle.

- Both the **time complexity** and **space complexity** of the code are **O(numRows²)**. Here’s a quick recap:

### Time Complexity:

- The two loops together iterate over every element of the Pascal’s Triangle exactly once, and since the total number of elements in the triangle is proportional to the sum \(1 + 2 + 3 + \dots + \text{numRows}\), which is \(\frac{\text{numRows} \times (\text{numRows} + 1)}{2}\), the overall time complexity is:
  \[
  \boxed{O(\text{numRows}^2)}
  \]

### Space Complexity:

- The space required to store the result (Pascal’s Triangle) is proportional to the number of elements in the triangle, which again follows the sum \(1 + 2 + 3 + \dots + \text{numRows}\), giving:
  \[
  \boxed{O(\text{numRows}^2)}
  \]
- Other than the `ans` vector, no significant additional space is used, so auxiliary space is \(O(1)\).
