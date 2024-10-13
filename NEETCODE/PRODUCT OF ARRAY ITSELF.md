238. Product of Array Except Self
Medium
Topics
Companies
Hint
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

 ### Problem Explanation: **Product of Array Except Self**

In this problem, you're given an array of integers `nums`, and the goal is to return an array `answer` where each element `answer[i]` is equal to the **product of all elements of the input array except `nums[i]`**.

#### Key Points:
- The product for each index should exclude the element at that index.
- The solution **must run in O(n)** time.
- You are **not allowed to use the division operation**.

### Input and Output

#### Example 1:
- **Input**: `nums = [1, 2, 3, 4]`
- **Output**: `answer = [24, 12, 8, 6]`
  
Here’s the breakdown for each element:
- `answer[0]` = product of `[2, 3, 4]` = `2 * 3 * 4 = 24`
- `answer[1]` = product of `[1, 3, 4]` = `1 * 3 * 4 = 12`
- `answer[2]` = product of `[1, 2, 4]` = `1 * 2 * 4 = 8`
- `answer[3]` = product of `[1, 2, 3]` = `1 * 2 * 3 = 6`

#### Example 2:
- **Input**: `nums = [-1, 1, 0, -3, 3]`
- **Output**: `answer = [0, 0, 9, 0, 0]`

In this example:
- The presence of `0` in the input array means that any product that includes `0` will be `0`.
- Only the position where `nums[i]` is `0` will have a non-zero value (because `nums[i]` is excluded from the product).

### Why Division Isn't Allowed

One simple way to solve this problem would be to:
1. Compute the product of **all elements** in the array.
2. For each element `i`, divide the total product by `nums[i]`.

However, **division is not allowed** in this problem, meaning you have to find an alternative approach that avoids division but still runs in **O(n)** time.

### Task Breakdown:

You are required to:
- Build an efficient algorithm that calculates the product of all elements in the array except the current one (`nums[i]`) for each `i`.
- Ensure the solution runs in **O(n)** time complexity without using division.

optimized solution:
Time Complexity : O(N), As we iterate the Array(nums) twice. Where N = size of the array.

    Space complexity : O(1), Constant space. Extra space is only allocated for the Array(output), however the
    output does not count towards the space complexity.
    

    Solved using Dynamic Programming Approach(Space Optimization). Optimized Approach.
  ```cpp
  class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        res[0] = 1;
        for (int i = 1; i < n; ++i) {
            res[i] = res[i-1] * nums[i-1];
        }
        
        int right = 1;
        for (int i = n-2; i >= 0; --i) {  // new start condition
            right *= nums[i+1];           // modification
            res[i] *= right;              // modification
        }
        
        return res;
    }
};
```
