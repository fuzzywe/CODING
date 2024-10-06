. Valid Sudoku
Medium
Topics
Companies
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9; i++){
            vector<bool> vi(10,false);
            vector<bool> vj(10,false);
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] != '.') {
                    
                if(vi[board[i][j]- '0']) return false;
                else{
                    vi[board[i][j]- '0'] = true;
                }
                }
                if(board[j][i] != '.') {

                if(vj[board[j][i] - '0']) return false;
                else{
                    vj[board[j][i]- '0'] = true;
                }
                }
            }
        }
        for(int i = 0 ; i < 9 ; i+=3){
            for(int j = 0 ; j < 9 ; j+= 3){

                vector<bool> v(10,false);
                for(int x = 0; x < 3 ; x++){
                    for(int y = 0 ; y < 3 ; y++){
                        if(board[i+x][j+y] == '.') continue;
                        if(v[board[i+x][j+y] - '0']) return false;
                        else{
                            v[board[i+x][j+y] - '0'] = true;
                        } 
                    }
                }
            }
        }
        return true;
    }
};
```

Sure! I'll explain **each line** of the code with a detailed explanation and an **example** for every step. Let's go line by line:

### Code:

```cpp
class Solution {
```
- **Explanation**: This declares a class named `Solution` which contains the method `isValidSudoku`.
- **Example**: In C++, this is a standard way to define a class. It will allow us to group our solution in an object-oriented way.

```cpp
public:
```
- **Explanation**: The `public` keyword makes the following members (in this case, the function `isValidSudoku`) accessible from outside the class.
- **Example**: If we create an object of `Solution`, we can call the method `isValidSudoku` from outside the class.

```cpp
    bool isValidSudoku(vector<vector<char>>& board) {
```
- **Explanation**: This is the method definition. It takes a 2D vector of characters (`vector<vector<char>>`) representing the Sudoku board and returns a boolean (`bool`), `true` if the board is valid and `false` if it’s not.
- **Example**: If you call this function with a 9x9 board like this:
  
  ```cpp
  Solution sol;
  vector<vector<char>> board = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
  };
  bool result = sol.isValidSudoku(board);
  ```

```cpp
        for(int i = 0 ; i < 9; i++){
```
- **Explanation**: A `for` loop that iterates from `i = 0` to `i = 8` (inclusive), iterating through all rows and columns of the Sudoku board since it’s a 9x9 grid.
- **Example**: For the first iteration (`i = 0`), this loop processes the first row (`5, 3, ., ., 7, ., ., ., .`) and the first column (`5, 6, ., 8, 4, 7, ., ., .`).

```cpp
            vector<bool> vi(10, false);
            vector<bool> vj(10, false);
```
- **Explanation**: Two vectors `vi` and `vj` of size 10 are initialized to `false`. `vi` will keep track of whether a digit has been seen in the current row, and `vj` will do the same for the current column.
  - Why size 10? This vector uses indices `1-9` to represent digits, and the extra space at index `0` is unused.
- **Example**: If you are checking the first row and column, initially, both `vi` and `vj` will look like this:
  ```cpp
  vi = {false, false, false, false, false, false, false, false, false, false}
  vj = {false, false, false, false, false, false, false, false, false, false}
  ```

```cpp
            for(int j = 0; j < 9; j++){
```
- **Explanation**: A nested loop that iterates over all columns (`j = 0` to `j = 8`), checking each element in the current row and column.
- **Example**: In the first iteration (`i = 0`), this loop will check all elements in the first row (`5, 3, ., ., 7, ., ., ., .`) and the first column (`5, 6, ., 8, 4, 7, ., ., .`).

```cpp
                if(board[i][j] != '.'){
```
- **Explanation**: This checks whether the current element in row `i` and column `j` is not a dot (`.`), meaning it’s a digit (1-9).
- **Example**: If we are in the first row, for `board[0][0]`, this condition will be true because `board[0][0]` is `'5'`.

```cpp
                if(vi[board[i][j] - '0']) return false;
```
- **Explanation**: This checks if the digit at `board[i][j]` has already been seen in the current row. The character `board[i][j]` is converted to its numeric value by subtracting `'0'` (ASCII difference), and if `vi` at that index is `true`, it means the digit has already been seen, and the board is invalid.
- **Example**: If `board[0][0]` is `'5'`, `vi[5]` will be checked. If `vi[5]` is `true`, it means the digit `5` has already appeared in the current row, and the function will return `false`. If not, the loop continues.

```cpp
                else {
                    vi[board[i][j] - '0'] = true;
                }
```
- **Explanation**: If the digit has not been seen in the current row, this line marks the corresponding index in `vi` as `true`, indicating that the digit has been encountered.
- **Example**: After processing `board[0][0]` (which is `'5'`), `vi` becomes:
  ```cpp
  vi = {false, false, false, false, false, true, false, false, false, false}
  ```

```cpp
                if(board[j][i] != '.'){
```
- **Explanation**: Similar to the previous check, but this checks the current column instead of the row. It ensures that the element in the column is not a dot (`.`).
- **Example**: For the first column (`i = 0`), this will check each value in column 0 (`5, 6, ., 8, 4, 7, ., ., .`).

```cpp
                if(vj[board[j][i] - '0']) return false;
                else {
                    vj[board[j][i] - '0'] = true;
                }
```
- **Explanation**: This checks whether the digit in the current column has been seen before (using `vj`). If it has, it returns `false`. If not, it marks it as seen by setting the corresponding index of `vj` to `true`.
- **Example**: After processing the first column (`5, 6, ., 8, 4, 7, ., ., .`), `vj` will look like:
  ```cpp
  vj = {false, false, false, false, true, true, true, true, true, false}
  ```

```cpp
            }
        }
```
- **Explanation**: This ends the nested `for` loops that check all rows and columns. After this, all rows and columns have been checked for duplicate digits.

```cpp
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
```
- **Explanation**: These two loops are used to iterate over the top-left corners of each 3x3 sub-box. The increments `i+=3` and `j+=3` move from one sub-box to the next. There are 9 sub-boxes in total, and we are checking each one.
- **Example**: For `i = 0` and `j = 0`, it checks the top-left 3x3 sub-box:
  ```
  5 3 .
  6 . .
  . 9 8
  ```

```cpp
                vector<bool> v(10, false);
```
- **Explanation**: This vector `v` is used to track which digits have been seen in the current 3x3 sub-box. Like before, it’s of size 10 to map digits 1-9.
- **Example**: When processing the first sub-box (`5 3 ., 6 . ., . 9 8`), `v` will start like:
  ```cpp
  v = {false, false, false, false, false, false, false, false, false, false}
  ```

```cpp
                for(int x = 0; x < 3; x++) {
                    for(int y = 0; y < 3; y++) {
```
- **Explanation**: These loops go through each element of the current 3x3 sub-box. The loop variables `x` and `y` are used to index into the 3x3 sub-box.
- **Example**: When processing the top-left 3x3 sub-box, for the first element (`board[0][0]`), `x = 0` and `y = 0`.

```cpp
                        if(board[i+x][j+y] == '.') continue;
```
- **Explanation**: If the current element

 in the 3x3 sub-box is a dot (`.`), the code skips it (continues to the next iteration).
- **Example**: For `board[0][2]` (which is `.`), the loop skips this position.

```cpp
                        if(v[board[i+x][j+y] - '0']) return false;
                        else {
                            v[board[i+x][j+y] - '0'] = true;
                        }
```
- **Explanation**: Similar to the row and column checks, this checks if a digit has already been seen in the current 3x3 sub-box. If it has, the function returns `false`, otherwise, it marks the digit as seen by setting the corresponding index in `v` to `true`.
- **Example**: When processing `5`, `v[5]` is set to `true`, and after processing the first sub-box, `v` might look like:
  ```cpp
  v = {false, false, false, false, false, true, true, false, true, true}
  ```

```cpp
                    }
                }
            }
        }
```
- **Explanation**: These end the loops for checking all 3x3 sub-boxes. At this point, all rows, columns, and sub-boxes have been checked.

```cpp
        return true;
    }
};
```
- **Explanation**: If no invalid conditions were found, the function returns `true`, indicating the Sudoku board is valid.
- **Example**: If you input a valid Sudoku board, it will return `true`.


### Dry Run with Example:

Let's dry run the code with the following example Sudoku board:

```cpp
vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};
```

**Step-by-step dry run:**

1. **Checking rows and columns:**
    - `i = 0`: 
        - Row check: `vi = {false, false, false, false, false, true, false, false, false, false}` after processing '5'.
        - Column check: `vj = {false, false, false, false, false, true, false, false, false, false}` after processing '5'.
        - No duplicates found.
    - Continue similarly for all other rows and columns. No duplicates in any row or column.

2. **Checking 3x3 sub-boxes:**
    - First 3x3 sub-box (top-left):
        - Sub-box check: `v = {false, false, false, false, false, true, true, false, true, true}` after processing digits '5', '3', '6', '9', '8'.
        - No duplicates.
    - Continue similarly for all other 3x3 sub-boxes. No duplicates in any sub-box.

Since no duplicates were found, the function will return `true`, indicating the Sudoku board is valid.
