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

Let's break down this code step by step and then dry run it with an example.

### Code Explanation:

The goal of this function is to check if a given Sudoku board is valid. A valid Sudoku board means:
- Each row must contain the digits 1-9 without repetition.
- Each column must contain the digits 1-9 without repetition.
- Each of the nine 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
```
- This is the class definition with a public method `isValidSudoku` which takes a 2D vector of characters `board` as input. The function returns a `bool` (either `true` or `false`), indicating whether the Sudoku board is valid.

```cpp
        for(int i = 0 ; i < 9; i++){
            vector<bool> vi(10,false);
            vector<bool> vj(10,false);
```
- The outer `for` loop iterates over all the rows and columns (there are 9 rows and 9 columns in a 9x9 Sudoku board).
- Two vectors `vi` and `vj` of size 10 are created, initialized to `false`. These vectors will help track the digits (1-9) that appear in the current row (`vi`) and current column (`vj`). We use size 10 to directly map digits 1-9 to indices 1-9, ignoring the 0th index.

```cpp
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] != '.') {
```
- This inner `for` loop checks each element in the current row (`i`) and column (`j`). If the current element is not a dot (`.`), it represents a digit in the Sudoku board.

```cpp
                if(vi[board[i][j]- '0']) return false;
                else{
                    vi[board[i][j]- '0'] = true;
                }
```
- This checks whether the digit in the current row `i` has already appeared. If the digit has already been marked `true` in `vi`, it means it's a duplicate, so the board is invalid, and the function returns `false`.
- If it's not a duplicate, the corresponding index in `vi` is marked as `true`.

```cpp
                if(board[j][i] != '.') {
                if(vj[board[j][i] - '0']) return false;
                else{
                    vj[board[j][i]- '0'] = true;
                }
                }
```
- This checks the elements of the current column `i`. It follows the same logic as for rows. If a digit in the column has already been marked as `true` in `vj`, it's a duplicate, and the board is invalid, so return `false`. Otherwise, the corresponding position in `vj` is marked `true`.

```cpp
            }
        }
```
- This completes the first set of checks for all rows and columns.

```cpp
        for(int i = 0 ; i < 9 ; i+=3){
            for(int j = 0 ; j < 9 ; j+= 3){
```
- These two `for` loops are used to iterate over each 3x3 sub-box. The outer loop moves to the next 3x3 sub-box horizontally (`i+=3` and `j+=3`).

```cpp
                vector<bool> v(10,false);
```
- A new vector `v` of size 10 is initialized for tracking digits within the current 3x3 sub-box.

```cpp
                for(int x = 0; x < 3 ; x++){
                    for(int y = 0 ; y < 3 ; y++){
```
- These two loops iterate over the elements of the 3x3 sub-box.

```cpp
                        if(board[i+x][j+y] == '.') continue;
```
- If the current element is a dot (`.`), it skips checking for that element.

```cpp
                        if(v[board[i+x][j+y] - '0']) return false;
                        else{
                            v[board[i+x][j+y] - '0'] = true;
                        }
```
- It checks whether the digit in the current 3x3 sub-box has already appeared. If it has been marked `true` in `v`, the board is invalid, and the function returns `false`. Otherwise, the corresponding position in `v` is marked as `true`.

```cpp
                    }
                }
            }
        }
```
- This completes checking all the 3x3 sub-boxes.

```cpp
        return true;
    }
};
```
- If no duplicates were found in any row, column, or sub-box, the function returns `true`, meaning the board is valid.

---

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
