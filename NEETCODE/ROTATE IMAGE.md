48. Rotate Image
Medium
Topics
Companies
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        for(int i=0;i<row;i++){
            for(int j=0;j<=i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }

        }
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
```
One of the best solution I saw so far. The animation helped a lot! Upvoted for the animation 🔥
https://leetcode.com/problems/rotate-image/solutions/3440564/animation-understand-in-30-seconds/?envType=problem-list-v2&envId=plakya4j&difficulty=MEDIUM&status=TO_DO

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> copy(n, vector<int>(n));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                copy[i][n - 1 - j] = matrix[j][i];
            }
        }
        matrix = copy;
    }
};
```
Actually your solution is not meeting the requirement of this problem statement. in the statement "You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation." this is required. but you have used another 2d vector copy which is requiring extra space, this was not the requirement of this problem
