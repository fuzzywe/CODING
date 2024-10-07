45. Jump Game II
Medium
Topics
Companies
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2

Complexity
Time complexity: O(n)
Space complexity: O(1)

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int near = 0, far = 0, jumps = 0;

        while (far < nums.size() - 1) {
            int farthest = 0;
            for (int i = near; i <= far; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            near = far + 1;
            far = farthest;
            jumps++;
        }

        return jumps;        
    }
};
```
Let's go through the code line by line, explaining what each part does, and then dry-run the function with an example.

### Code:

```cpp
class Solution {
```
- **Explanation**: This declares the class `Solution`, where the function `jump()` will be defined.

---

```cpp
public:
```
- **Explanation**: This declares the functions and variables inside the `public` block, which means they can be accessed from outside the class.

---

```cpp
int jump(vector<int>& nums) {
```
- **Explanation**: This declares a function `jump()` that takes a reference to a vector of integers `nums` as input. The function will return an integer that represents the minimum number of jumps required to reach the last index of the array.
- **Input Example**: Suppose `nums = [2, 3, 1, 1, 4]`. Each element in the array represents how far you can jump from that index.

---

```cpp
int near = 0, far = 0, jumps = 0;
```
- **Explanation**: Initializes three variables:
  - `near`: The starting point of the current range we are exploring.
  - `far`: The farthest point we can reach in the current jump.
  - `jumps`: The number of jumps taken so far.
- **Example**: 
    - Initially, `near = 0`, `far = 0`, `jumps = 0`.

---

```cpp
while (far < nums.size() - 1) {
```
- **Explanation**: This `while` loop continues running until we can reach the last index of the array (when `far >= nums.size() - 1`). The goal is to explore the range between `near` and `far` to find the farthest point we can reach with the next jump.
- **Example**: 
    - For `nums = [2, 3, 1, 1, 4]`, the loop runs until `far >= 4`.

---

```cpp
int farthest = 0;
```
- **Explanation**: Initializes a variable `farthest` to keep track of the farthest index we can reach with the current set of jumps.

---

```cpp
for (int i = near; i <= far; i++) {
```
- **Explanation**: A `for` loop that explores all the indices between `near` and `far`. For each index `i`, we calculate how far we can jump from that index.
- **Example**: 
    - Initially, `near = 0` and `far = 0`, so the loop will only consider the first index (`i = 0`).

---

```cpp
farthest = max(farthest, i + nums[i]);
```
- **Explanation**: Updates `farthest` to the maximum possible distance we can jump from the current index `i`. We calculate `i + nums[i]`, which gives the farthest index reachable from `i`. If that is greater than the current `farthest`, we update `farthest`.
- **Example**: 
    - If `nums = [2, 3, 1, 1, 4]` and `i = 0`, `i + nums[0] = 0 + 2 = 2`. Therefore, `farthest = 2`.

---

```cpp
near = far + 1;
```
- **Explanation**: After processing the current range, we update `near` to be just beyond `far`, indicating the start of the next range to explore.
- **Example**: 
    - Initially, `far = 0`, so after the first iteration, `near = 1`.

---

```cpp
far = farthest;
```
- **Explanation**: Updates `far` to `farthest`, meaning the farthest point we can reach with the next jump.
- **Example**: 
    - After the first iteration, `farthest = 2`, so `far = 2`.

---

```cpp
jumps++;
```
- **Explanation**: Increments the `jumps` counter since we have made a new jump.
- **Example**: 
    - After the first jump, `jumps = 1`.

---

```cpp
}
```
- **Explanation**: Ends the `while` loop when we can reach or surpass the last index.

---

```cpp
return jumps;
```
- **Explanation**: Returns the total number of jumps required to reach the last index.
- **Example**: 
    - If we can reach the last index after 2 jumps, the function will return `2`.

---

### Example:

Let's dry-run this code with the input:

```cpp
nums = [2, 3, 1, 1, 4]
```

1. **Initialization**:
   - `near = 0`, `far = 0`, `jumps = 0`
   
2. **First iteration of `while (far < nums.size() - 1)`**:
   - `farthest = 0`
   - Loop through `i = 0` (since `near = 0`, `far = 0`):
     - `farthest = max(0, 0 + nums[0]) = max(0, 0 + 2) = 2`
   - Update `near = far + 1 = 1`
   - Update `far = farthest = 2`
   - Increment `jumps = 1`

3. **Second iteration of `while (far < nums.size() - 1)`**:
   - `farthest = 0`
   - Loop through `i = 1` and `i = 2` (since `near = 1`, `far = 2`):
     - For `i = 1`: `farthest = max(0, 1 + nums[1]) = max(0, 1 + 3) = 4`
     - For `i = 2`: `farthest = max(4, 2 + nums[2]) = max(4, 2 + 1) = 4`
   - Update `near = far + 1 = 3`
   - Update `far = farthest = 4`
   - Increment `jumps = 2`

4. **Exit the `while` loop**:
   - Now `far = 4`, which is equal to `nums.size() - 1`, so the loop terminates.

5. **Return**:
   - The function returns `jumps = 2`, meaning it takes 2 jumps to reach the last index.

### Summary:
- The algorithm works by exploring the range of indices you can jump to, starting from the first index. It finds the farthest point you can jump to within the current range and then makes a jump to that range. This process continues until the farthest point includes or surpasses the last index. The function returns the minimum number of jumps required to reach the last index.
