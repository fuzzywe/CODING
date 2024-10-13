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
  Time Complexity : O(N^2), Where N is the size of the Array(nums). Here Two nested loop creates the time 
    complexity.

    Space complexity : O(1), Constant space. Extra space is only allocated for the Array(output), however the
    output does not count towards the space complexity.

    Solved using Array(Two Nested Loop). Brute Force Approach.

    Note : This will give TLE.

*/


/***************************************** Approach 1 *****************************************/
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        for(int i=0; i<n; i++){
            int product = 1;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                product *= nums[j];
            }
            output.push_back(product);
        }
        return output;
    }
};
```
### Problem: **Product of Array Except Self**

The goal is to return an array `res` where each element at index `i` is the product of all elements in the array except `nums[i]`. We cannot use division, and the solution should run in O(n) time complexity.

### Code Breakdown and Dry Run:

Let's walk through the code step by step, with an example and explanation for each line.

#### Example:
Input: `nums = [1, 2, 3, 4]`
Expected Output: `[24, 12, 8, 6]`

---

### Code Walkthrough:

```cpp
int n = nums.size();
```
- We store the size of the input array `nums` in the variable `n`.
- **For `nums = [1, 2, 3, 4]`, n = 4.**

```cpp
vector<int> res(n);
```
- We initialize a result vector `res` of size `n` to store the final output.
- **For `n = 4`, `res = [0, 0, 0, 0]`.**

---

### First Pass: Left-to-Right to Compute Left Products
This loop calculates the product of all elements to the **left** of the current element.

```cpp
res[0] = 1;
```
- Set the first element of `res` to 1 because there are no elements to the left of `nums[0]`.
- **Now, `res = [1, 0, 0, 0]`.**

```cpp
for (int i = 1; i < n; ++i) {
    res[i] = res[i-1] * nums[i-1];
}
```
- This loop calculates the product of all elements to the left of the current index `i`. Each element `res[i]` stores the cumulative product of elements before `i` in `nums`.
  
- **Iteration 1**: `i = 1`
  - `res[1] = res[0] * nums[0] = 1 * 1 = 1`
  - **Now, `res = [1, 1, 0, 0]`.**
  
- **Iteration 2**: `i = 2`
  - `res[2] = res[1] * nums[1] = 1 * 2 = 2`
  - **Now, `res = [1, 1, 2, 0]`.**
  
- **Iteration 3**: `i = 3`
  - `res[3] = res[2] * nums[2] = 2 * 3 = 6`
  - **Now, `res = [1, 1, 2, 6]`.**

At the end of this loop, `res[i]` contains the product of all elements to the left of index `i`.

---

### Second Pass: Right-to-Left to Compute Right Products
This loop calculates the product of all elements to the **right** of the current element and multiplies it with the left products already stored in `res`.

```cpp
int right = 1;
```
- We initialize `right` to 1, which will store the product of elements to the right of the current index.

```cpp
for (int i = n-2; i >= 0; --i) {
    right *= nums[i+1];
    res[i] *= right;
}
```
- This loop starts from the second last element (`i = n-2`) and moves to the first element (`i = 0`).
  
- **Iteration 1**: `i = 2`
  - `right = right * nums[3] = 1 * 4 = 4`
  - `res[2] = res[2] * right = 2 * 4 = 8`
  - **Now, `res = [1, 1, 8, 6]`.**
  
- **Iteration 2**: `i = 1`
  - `right = right * nums[2] = 4 * 3 = 12`
  - `res[1] = res[1] * right = 1 * 12 = 12`
  - **Now, `res = [1, 12, 8, 6]`.**
  
- **Iteration 3**: `i = 0`
  - `right = right * nums[1] = 12 * 2 = 24`
  - `res[0] = res[0] * right = 1 * 24 = 24`
  - **Now, `res = [24, 12, 8, 6]`.**

### Final Result:
- After both passes, the final array `res = [24, 12, 8, 6]` is returned, which contains the product of all elements except the element at each respective index.

---

### Time and Space Complexity:

- **Time Complexity**: O(n), because we traverse the array twice (once for left products and once for right products).
- **Space Complexity**: O(1) additional space (since the output array `res` doesn't count as extra space).

This is an efficient solution that meets the problem's requirements.
