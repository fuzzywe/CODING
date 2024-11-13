54. Spiral Matrix
Medium
Topics
Companies
Hint
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:

https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/

https://leetcode.com/problems/spiral-matrix/description/?envType=problem-list-v2&envId=plakya4j&difficulty=MEDIUM&status=TO_DO

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


 Intuition
Just read the code and you will understand it.
But make sure to draw a 5X5 Matrix positions on paper.
like this-
00 01 02 03 04
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 44

Approach
keep the above position matrix in mind then read the code.

First traverse the row left to right.
then last column.
then last row from right to left.
and then first column from bottom to top.

just visulize the spiral format traversal.

Complexity
Time complexity:O(row*column)
Space complexity:O(row*column)


```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size(),column=matrix[0].size();

        int start_row=0;
        int start_column=0;
        int end_row=row-1;
        int end_column=column-1;
        
        int cnt=0;
        
        vector<int> answer;

        while(cnt < row*column)
        {
            for(int i=start_column;i<=end_column ;i++)
            {
                answer.push_back(matrix[start_row][i]);
                cnt++;
            }
            start_row++;
            
            for(int i=start_row;i<=end_row ;i++)
            {
                answer.push_back(matrix[i][end_column]);
                cnt++;
            }
            end_column--;
            
            for(int i=end_column;i>=start_column && cnt<row*column;i--)
            {
                answer.push_back(matrix[end_row][i]);
                cnt++;
            }
            end_row--;
        
            for(int i=end_row;i>=start_row && cnt<row*column;i--)
            {
                answer.push_back(matrix[i][start_column]);
                cnt++;
            }
            start_column++;
        
        }

        return answer;    
    }
};
```

Let's break down the `spiralOrder` function and walk through a dry run example of the spiral matrix traversal.

### Code Explanation:

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), column = matrix[0].size();
        int start_row = 0;
        int start_column = 0;
        int end_row = row - 1;
        int end_column = column - 1;
        int cnt = 0;
        vector<int> answer;

        while(cnt < row * column) {
            for(int i = start_column; i <= end_column; i++) {
                answer.push_back(matrix[start_row][i]);
                cnt++;
            }
            start_row++;

            for(int i = start_row; i <= end_row; i++) {
                answer.push_back(matrix[i][end_column]);
                cnt++;
            }
            end_column--;

            for(int i = end_column; i >= start_column && cnt < row * column; i--) {
                answer.push_back(matrix[end_row][i]);
                cnt++;
            }
            end_row--;

            for(int i = end_row; i >= start_row && cnt < row * column; i--) {
                answer.push_back(matrix[i][start_column]);
                cnt++;
            }
            start_column++;
        }

        return answer;    
    }
};
```

### Line-by-Line Explanation:

#### 1. `int row = matrix.size(), column = matrix[0].size();`
- **Purpose**: Determines the number of rows (`row`) and columns (`column`) in the matrix.
- **Example**: For a matrix `[[1, 2, 3], [4, 5, 6], [7, 8, 9]]`, `row = 3`, `column = 3`.

#### 2. `int start_row = 0;`
- **Purpose**: Tracks the starting row index for the current spiral layer.
- **Example**: Initialized to `0` because we start from the top-left corner.

#### 3. `int start_column = 0;`
- **Purpose**: Tracks the starting column index for the current spiral layer.

#### 4. `int end_row = row - 1;`
- **Purpose**: Tracks the ending row index for the current spiral layer.
- **Example**: For `row = 3`, `end_row` is initially `2`, which is the last row.

#### 5. `int end_column = column - 1;`
- **Purpose**: Tracks the ending column index for the current spiral layer.
- **Example**: For `column = 3`, `end_column` is initially `2`.

#### 6. `int cnt = 0;`
- **Purpose**: Keeps track of how many elements have been added to the result list (`answer`).
- **Example**: We have `row * column = 9` elements in total, so `cnt` will be used to stop once we've added 9 elements.

#### 7. `vector<int> answer;`
- **Purpose**: Stores the elements in spiral order.

#### 8. `while(cnt < row * column)`
- **Purpose**: Continues the spiral traversal until all elements are added to the `answer` vector.

#### 9. `for(int i = start_column; i <= end_column; i++)`
- **Purpose**: Traverses from left to right along the current top row (`start_row`) and adds the elements to `answer`.
- **Example**: For the first row (`start_row = 0`), it adds elements from `matrix[0][0]` to `matrix[0][2]`.

#### 10. `start_row++;`
- **Purpose**: After completing the top row, move the `start_row` down to the next row for the next traversal.

#### 11. `for(int i = start_row; i <= end_row; i++)`
- **Purpose**: Traverses from top to bottom along the current rightmost column (`end_column`) and adds the elements to `answer`.
- **Example**: For `end_column = 2`, it adds elements from `matrix[1][2]` to `matrix[2][2]`.

#### 12. `end_column--;`
- **Purpose**: After completing the rightmost column, move the `end_column` left to exclude it in the next traversal.

#### 13. `for(int i = end_column; i >= start_column && cnt < row * column; i--)`
- **Purpose**: Traverses from right to left along the current bottom row (`end_row`) and adds the elements to `answer`. The condition `cnt < row * column` ensures we stop if we've already added all elements.
- **Example**: For `end_row = 2`, it adds elements from `matrix[2][1]` to `matrix[2][0]`.

#### 14. `end_row--;`
- **Purpose**: After completing the bottom row, move the `end_row` up to exclude it in the next traversal.

#### 15. `for(int i = end_row; i >= start_row && cnt < row * column; i--)`
- **Purpose**: Traverses from bottom to top along the current leftmost column (`start_column`) and adds the elements to `answer`.
- **Example**: For `start_column = 0`, it adds elements from `matrix[1][0]`.

#### 16. `start_column++;`
- **Purpose**: After completing the leftmost column, move the `start_column` right to exclude it in the next traversal.

#### 17. `return answer;`
- **Purpose**: Returns the vector `answer` containing the elements of the matrix in spiral order.

---

### Example for Dry Run:

Let's take an example of a 3x3 matrix:

```
matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]
```

1. **Initial values**:
   - `start_row = 0, end_row = 2`
   - `start_column = 0, end_column = 2`
   - `cnt = 0`

2. **First pass (left to right across top row)**:
   - Traverse `matrix[0][0]`, `matrix[0][1]`, `matrix[0][2]`: Add `1, 2, 3` to `answer`.
   - `cnt = 3`
   - Increment `start_row` to `1`.

3. **Second pass (top to bottom along right column)**:
   - Traverse `matrix[1][2]`, `matrix[2][2]`: Add `6, 9` to `answer`.
   - `cnt = 5`
   - Decrement `end_column` to `1`.

4. **Third pass (right to left across bottom row)**:
   - Traverse `matrix[2][1]`, `matrix[2][0]`: Add `8, 7` to `answer`.
   - `cnt = 7`
   - Decrement `end_row` to `1`.

5. **Fourth pass (bottom to top along left column)**:
   - Traverse `matrix[1][0]`: Add `4` to `answer`.
   - `cnt = 8`
   - Increment `start_column` to `1`.

6. **Final pass (left to right across middle row)**:
   - Traverse `matrix[1][1]`: Add `5` to `answer`.
   - `cnt = 9`

Now all elements are added to `answer` in spiral order:

```
answer = [1, 2, 3, 6, 9, 8, 7, 4, 5]
```

The function returns `[1, 2, 3, 6, 9, 8, 7, 4, 5]`.
