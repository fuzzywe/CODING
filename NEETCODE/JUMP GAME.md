https://leetcode.com/problems/jump-game/description/?envType=problem-list-v2&envId=plakya4j

---

55. Jump Game
Medium
Topics
Companies
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 
Complexity
Time complexity: O(n)

Space complexity: O(1)

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }

        return goal == 0;        
    }
};

```

Let's go through this code line by line and explain its functionality with an example.

### Code:

```cpp
class Solution {
```
- **Explanation**: Declares the class `Solution`, which is a common structure used when submitting solutions on coding platforms like LeetCode.

---

```cpp
public:
```
- **Explanation**: The `public` keyword indicates that the methods inside this block can be accessed from outside the class.

---

```cpp
bool canJump(vector<int>& nums) {
```
- **Explanation**: Declares a function `canJump`, which takes a vector of integers `nums` (representing the maximum jump length at each index) and returns a boolean (`true` or `false`) indicating whether you can reach the last index starting from the first index.
- **Input Example**: If `nums = [2, 3, 1, 1, 4]`, it means at index 0, you can jump up to 2 steps, at index 1 you can jump up to 3 steps, and so on.

---

```cpp
int goal = nums.size() - 1;
```
- **Explanation**: Initializes a variable `goal` to be the last index of the vector `nums`. The goal is to check if we can reach this last index starting from the first index.
- **Example**: If `nums = [2, 3, 1, 1, 4]`, then `goal = 4` (the index of the last element).

---

```cpp
for (int i = nums.size() - 2; i >= 0; i--) {
```
- **Explanation**: This is a loop that starts from the second-to-last index (`nums.size() - 2`) and moves backward toward the first index (`i = 0`). We are checking if, starting from each index `i`, we can reach or surpass the current goal.
- **Example**: If `nums = [2, 3, 1, 1, 4]`, the loop will start at index `3` and go down to index `0`.

---

```cpp
if (i + nums[i] >= goal) {
```
- **Explanation**: This checks if we can jump from index `i` to the current goal. If `i + nums[i]` (the farthest we can jump from index `i`) is greater than or equal to `goal`, then we update the goal to the current index `i`.
- **Example**: 
    - At index `3`, `nums[3] = 1`, so `i + nums[i] = 3 + 1 = 4`, which is equal to the current goal `4`. Therefore, we can reach the goal from index `3`.
    - We now set `goal = 3`.

---

```cpp
goal = i;
```
- **Explanation**: If we can reach or surpass the current goal from index `i`, then update `goal` to be index `i`. This means that now, instead of trying to reach the last index directly, we are trying to reach index `i` (the earlier index).
- **Example**: After the previous check at index `3`, we update `goal = 3`.

---

```cpp
}
```
- **Explanation**: Ends the `if` condition and moves to the next iteration of the `for` loop (going to the previous index).

---

```cpp
return goal == 0;
```
- **Explanation**: After the loop finishes, the function checks if `goal == 0`. If true, it means we can jump all the way from the first index to the last index, so the function returns `true`. Otherwise, if the goal isn't `0`, it returns `false`.
- **Example**: If after checking all the indices, we have updated the `goal` to `0`, it means we can reach the last index from the start, so the function returns `true`.

---

### Example:

Let's dry run the function with an example input:

**Input**:  
`nums = [2, 3, 1, 1, 4]`

1. **Initialization**:  
   - `goal = 4` (index of the last element).

2. **Loop Iteration**:
   - **i = 3**: `nums[3] = 1`, `i + nums[i] = 3 + 1 = 4`. Since `4 >= goal`, update `goal = 3`.
   - **i = 2**: `nums[2] = 1`, `i + nums[i] = 2 + 1 = 3`. Since `3 >= goal`, update `goal = 2`.
   - **i = 1**: `nums[1] = 3`, `i + nums[i] = 1 + 3 = 4`. Since `4 >= goal`, update `goal = 1`.
   - **i = 0**: `nums[0] = 2`, `i + nums[i] = 0 + 2 = 2`. Since `2 >= goal`, update `goal = 0`.

3. **Final Check**:  
   - `goal == 0` is `true`, so the function returns `true`.

**Output**:  
`true` (We can jump to the last index).

### Summary:
- This algorithm starts from the end of the list and checks if we can reach the goal (initially the last index). If we can jump to or beyond the current goal from any earlier index, we update the goal to that index and continue checking. The function returns `true` if we can eventually set the goal to the first index, indicating that it's possible to reach the last index from the start.
