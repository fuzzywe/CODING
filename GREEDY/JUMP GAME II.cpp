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


Let's break down the logic of this code step by step to understand how the algorithm works to find the minimum number of jumps required to reach the last index of the array `nums`.

### Problem Overview
The `jump` function aims to determine the minimum number of jumps needed to reach the last index of the `nums` array, where each element represents the maximum number of steps that can be taken from that index.

### Code Walkthrough

#### Function Definition
```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        // Initialize variables to track the range of indices for the current jump
        int near = 0, far = 0, jumps = 0;
```
- `near`: This tracks the starting index of the current jump.
- `far`: This tracks the farthest index that can be reached in the current jump.
- `jumps`: Counts the number of jumps required to reach the last index.

#### Main Logic Loop
```cpp
        while (far < nums.size() - 1) {
```
- This `while` loop continues until `far` (the farthest reachable index) reaches or exceeds the last index (`nums.size() - 1`). This ensures we stop when the last index is reachable.

#### Finding the Farthest Reach
```cpp
            int farthest = 0;
            for (int i = near; i <= far; i++) {
                farthest = max(farthest, i + nums[i]);
            }
```
- `farthest`: This variable calculates the maximum reachable index for the next jump.
  - The `for` loop iterates from the current starting index `near` to the farthest index reachable in the current jump (`far`).
  - For each index `i`, `i + nums[i]` calculates how far we can jump from index `i`. `farthest` keeps track of the maximum value of this.
  
#### Updating Variables for the Next Jump
```cpp
            near = far + 1;
            far = farthest;
            jumps++;
```
- Once the `for` loop determines the `farthest` index for the next jump, the variables are updated:
  - `near` is moved to `far + 1`, indicating the starting point for the next jump.
  - `far` is updated to the newly calculated `farthest` index.
  - The `jumps` counter is incremented to reflect that we have made another jump.

#### Returning the Total Number of Jumps
```cpp
        return jumps;        
    }
};
```
- Once the `while` loop terminates (when `far` reaches or exceeds the last index), the function returns the total number of `jumps`.

### Dry Run Example

Let’s dry run the code with an example:

```cpp
vector<int> nums = {2, 3, 1, 1, 4};
```

- **Initial values**: `near = 0`, `far = 0`, `jumps = 0`.

#### First Loop:
- Current range: `near = 0`, `far = 0`
  - In the `for` loop, `i = 0`. The maximum reach from index `0` is `0 + nums[0] = 0 + 2 = 2`.
  - `farthest = 2`.
- Update: `near = 1`, `far = 2`, `jumps = 1`.

#### Second Loop:
- Current range: `near = 1`, `far = 2`
  - In the `for` loop, `i = 1`. The maximum reach from index `1` is `1 + nums[1] = 1 + 3 = 4`.
  - `farthest = 4`.
  - In the `for` loop, `i = 2`. The maximum reach from index `2` is `2 + nums[2] = 2 + 1 = 3`.
  - `farthest` remains `4` because `4 > 3`.
- Update: `near = 3`, `far = 4`, `jumps = 2`.

#### End:
- Now, `far = 4`, which is the last index (`nums.size() - 1`), so the loop exits, and the function returns `jumps = 2`.

### Conclusion
For the input `{2, 3, 1, 1, 4}`, the function calculates that the minimum number of jumps to reach the last index is `2`.

Let's dry-run the given code step by step with an example to understand how it works. Suppose the input is:

```cpp
vector<int> nums = {2, 3, 1, 1, 4};
```

The goal is to find the minimum number of jumps needed to reach the last index.

### Initial Setup:
- **near**: The start of the range where we are currently considering jumps.
- **far**: The farthest index we can reach with the current jumps.
- **jumps**: The total number of jumps made.

### Dry Run of the Code:

#### Initial State:
```cpp
near = 0, far = 0, jumps = 0
```
- We haven't made any jumps yet.
- We are considering the range starting from index `0`.

#### First Iteration of `while`:
```cpp
while (far < nums.size() - 1)
```
- `far` is 0, and `nums.size() - 1` is 4, so we proceed with the loop.

#### First `for` Loop (finding the farthest index):
```cpp
for (int i = near; i <= far; i++)
```
- Range of `i`: `0` (since `near = 0` and `far = 0`).
- `nums[0] = 2` means from index `0`, we can jump to index `0 + 2 = 2`.

```cpp
farthest = max(farthest, i + nums[i])
```
- Initially, `farthest = 0`.
- For `i = 0`, `farthest = max(0, 0 + 2) = 2`.

#### Update `near`, `far`, and `jumps`:
```cpp
near = far + 1;  // near = 1
far = farthest;  // far = 2
jumps++;         // jumps = 1
```
- We've made 1 jump, and now we consider the range from `near = 1` to `far = 2`.

#### Second Iteration of `while`:
```cpp
while (far < nums.size() - 1)
```
- `far = 2`, and `nums.size() - 1 = 4`, so we continue.

#### Second `for` Loop:
```cpp
for (int i = near; i <= far; i++)
```
- Range of `i`: `1` to `2`.
- `nums[1] = 3` means from index `1`, we can jump to index `1 + 3 = 4`.
- `nums[2] = 1` means from index `2`, we can jump to index `2 + 1 = 3`.

```cpp
farthest = max(farthest, i + nums[i])
```
- Initially, `farthest = 0`.
- For `i = 1`, `farthest = max(2, 1 + 3) = 4`.
- For `i = 2`, `farthest = max(4, 2 + 1) = 4`.

#### Update `near`, `far`, and `jumps`:
```cpp
near = far + 1;  // near = 3
far = farthest;  // far = 4
jumps++;         // jumps = 2
```
- We've made 2 jumps, and now we consider the range from `near = 3` to `far = 4`.

#### Third Iteration of `while`:
```cpp
while (far < nums.size() - 1)
```
- `far = 4`, which is equal to `nums.size() - 1 = 4`, so the loop terminates.

### Final Output:
```cpp
return jumps;  // returns 2
```
- The minimum number of jumps required to reach the last index is `2`.

### Summary of Jumps:
1. Jump from index `0` to index `1`.
2. Jump from index `1` to index `4` (final index).

The dry run demonstrates that the solution efficiently finds the minimum number of jumps to reach the last index.

  
Step by Step Algorithm
Initialization:

near = far = jumps = 0
near: This variable represents the start of the current range of indices we are considering for jumps.
far: This variable represents the end of the current range of indices we are considering for jumps.
jumps: This variable keeps track of the number of jumps made.
While Loop:

while far < len(nums) - 1:
The loop continues until the far index reaches or exceeds the last index of the array (len(nums) - 1).
Initialization of Farthest:

farthest = 0
farthest: This variable will store the farthest index we can reach from the current range of indices (near to far).
For Loop:

for i in range(near, far + 1):
    farthest = max(farthest, i + nums[i])
This loop iterates through the current range of indices from near to far.
For each index i, it calculates i + nums[i] which is the farthest index we can reach by jumping from index i.
It updates farthest to be the maximum of its current value and i + nums[i].
Update Near and Far:

near = far + 1
far = farthest
jumps += 1
near: Update the start of the next range to be one index after the current far.
far: Update the end of the next range to be farthest calculated in the for loop.
jumps: Increment the number of jumps made by 1.
Return Statement:

return jumps
After exiting the while loop, the function returns the total number of jumps made to reach the last index.


  Let's see one by one.

Input: nums = [2,3,1,1,4]

near = 0
far = 0
jumps = 0
First of all, the range betwee near and far is 0, so we check only index 0. The farthest position should be

farthest position = current index + maximum jump
= 0 + 2
= 2
We check all positions in the range.

Next, before we move to the next range, we should update near, far and jumps.

This question guarantee that we can definitely reach the last index, so at least, we must move forward from the current range, so

The next near position should be

far + 1
Because far position is the most right position of current range.

The next far position should be

far = current farthest we found = 2
Of course, add +1 to jump times

jumps += 1
In the end,

   n f
[2,3,1,1,4]

jumps = 1
Next we check between index 1 and index 2.

From index 1, the farthest position should

farthest = 1 + 3 = 4
From index 2, the farthest position should

farthest = 2 + 1 = 3
We take index 4. Then update near, far and jumps.

near = far + 1 = 3
far = farthest = 4
jumps = 1 + 1 = 2
In the end,

       n f
[2,3,1,1,4]

jumps = 2
We will repeat the same algorithm. And now far position is reach the last index, so we stop iteration.

return 2(= jumps)
