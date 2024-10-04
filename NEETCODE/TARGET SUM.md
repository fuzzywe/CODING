
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 
brute:
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int index = nums.size() - 1;
        int curr_sum = 0;
        return dp(nums, S, index, curr_sum);
    }
    
    int dp(vector<int>& nums, int target, int index, int curr_sum) {
        // Base cases
        if (index < 0 && curr_sum == target) {
            return 1;
        }
        if (index < 0) {
            return 0;
        }
        
        // Decisions
        int positive = dp(nums, target, index - 1, curr_sum + nums[index]);
        int negative = dp(nums, target, index - 1, curr_sum - nums[index]);
        
        return positive + negative;
    }
};

Let’s dry run this code step by step to see how it works for a simple example.

### Code Breakdown:
This code is trying to find how many ways we can assign `+` and `-` signs to the elements of the array `nums` to make their sum equal to the target `S`.

The approach uses **recursion** and explores two options at each step:
1. Add the current number (`+nums[index]`).
2. Subtract the current number (`-nums[index]`).

### Example Input:
Let's take a simple input:
```python
nums = [1, 1, 1, 1, 1]
S = 3
```
We want to find how many ways we can assign `+` or `-` to the elements of `nums` such that the sum equals `3`.

### Initial Call:
```python
findTargetSumWays([1, 1, 1, 1, 1], 3)
```
- The `index` starts at `len(nums) - 1`, which is `4` (because the last index of the array is `4`).
- `curr_sum` is initialized to `0`.

The first call to the helper function `dp` looks like this:
```python
dp([1, 1, 1, 1, 1], 3, 4, 0)
```

Now, let’s dry run the code step by step.

---

### Step 1: First Call (`index = 4`)
```python
dp([1, 1, 1, 1, 1], 3, 4, 0)
```
We have two decisions:
1. Add `+nums[4]` (i.e., `+1`): 
   ```python
   dp([1, 1, 1, 1, 1], 3, 3, 1)
   ```
2. Subtract `-nums[4]` (i.e., `-1`):
   ```python
   dp([1, 1, 1, 1, 1], 3, 3, -1)
   ```

---

### Step 2: Call with `index = 3` and `curr_sum = 1`
We explore the first branch with `curr_sum = 1`:
```python
dp([1, 1, 1, 1, 1], 3, 3, 1)
```
Two decisions again:
1. Add `+nums[3]`:
   ```python
   dp([1, 1, 1, 1, 1], 3, 2, 2)
   ```
2. Subtract `-nums[3]`:
   ```python
   dp([1, 1, 1, 1, 1], 3, 2, 0)
   ```

---

### Step 3: Call with `index = 2` and `curr_sum = 2`
Now we move forward with `curr_sum = 2`:
```python
dp([1, 1, 1, 1, 1], 3, 2, 2)
```
Again, two decisions:
1. Add `+nums[2]`:
   ```python
   dp([1, 1, 1, 1, 1], 3, 1, 3)
   ```
2. Subtract `-nums[2]`:
   ```python
   dp([1, 1, 1, 1, 1], 3, 1, 1)
   ```

---

### Step 4: Call with `index = 1` and `curr_sum = 3`
We continue with `curr_sum = 3`:
```python
dp([1, 1, 1, 1, 1], 3, 1, 3)
```
Two decisions:
1. Add `+nums[1]`:
   ```python
   dp([1, 1, 1, 1, 1], 3, 0, 4)
   ```
2. Subtract `-nums[1]`:
   ```python
   dp([1, 1, 1, 1, 1], 3, 0, 2)
   ```

---

### Step 5: Base Cases
We now reach the base cases:
- If `index < 0` and `curr_sum == target`, return `1`.
- If `index < 0` and `curr_sum != target`, return `0`.

#### For `dp([1, 1, 1, 1, 1], 3, 0, 4)`:
- This results in `index = -1` and `curr_sum = 4`. Since `curr_sum != 3`, return `0`.

#### For `dp([1, 1, 1, 1, 1], 3, 0, 2)`:
- This results in `index = -1` and `curr_sum = 3`. Since `curr_sum == target`, return `1`.

---

### Continuing Recursion
The recursion will backtrack and continue exploring the other branches. The total number of ways will be calculated by summing up the results of the recursive calls.

### Final Result
The final result will be the total number of ways to assign `+` and `-` signs such that the sum of the array equals `S`.

For the input `[1, 1, 1, 1, 1]` and `S = 3`, there are **5 ways** to achieve the target sum.


optimized:

```
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = accumulate(nums.begin() , nums.end() , 0);

        if((total_sum - target) % 2 == 1){ // think why?
            return 0;
        }
        int req_sum = (total_sum - target)/2 + target;
        if(req_sum < 0){ // think why
            return 0;
        }

        vector<int>dp(req_sum + 1 , 0);
        dp[0] = 1;
        for(int i : nums){
            for(int j = req_sum ; j >= i; j--){
                dp[j] += dp[j - i];
            }
        }

        return dp[req_sum];
    }
}; 
```

Let's go through the code line by line, explain its logic, and also provide a dry run to help you understand how it works.

### Code Explanation

```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
```
- **Explanation**: This line calculates the total sum of all elements in the `nums` array. The `accumulate` function from the C++ standard library is used to sum all elements of the array.
- **Purpose**: We need to know the total sum to find how to partition the array into subsets that satisfy the target sum condition.

---

```cpp
        if ((total_sum - target) % 2 == 1) {
            return 0;
        }
```
- **Explanation**: This condition checks whether `(total_sum - target)` is odd. If it is odd, the function returns 0 because it's impossible to divide an odd number into two equal subsets.
- **Purpose**: For the problem to be valid, the difference between `total_sum` and `target` must be even, so that it can be split into two integer partitions.

---

```cpp
        int req_sum = (total_sum - target) / 2 + target;
```
- **Explanation**: This calculates the `req_sum`, which represents the sum of one subset in a partition of the numbers. The idea here is to reformulate the original problem into a "subset sum" problem.
- **Purpose**: This sum is the required sum for which we will later count the number of ways subsets of `nums` can be formed.

---

```cpp
        if (req_sum < 0) {
            return 0;
        }
```
- **Explanation**: This condition checks if the required sum (`req_sum`) is negative. If it is, return 0 because we can't form subsets with a negative sum.
- **Purpose**: Negative sums are not possible in this problem, so we handle that case early.

---

```cpp
        vector<int> dp(req_sum + 1, 0);
        dp[0] = 1;
```
- **Explanation**: A dynamic programming (DP) array `dp` is created with a size of `req_sum + 1`. Initially, all values are set to 0, and `dp[0] = 1` because there is exactly one way to form the sum 0 (by choosing no elements).
- **Purpose**: The `dp` array will store the number of ways to form every possible sum from `0` to `req_sum` using elements from `nums`.

---

```cpp
        for (int i : nums) {
            for (int j = req_sum; j >= i; j--) {
                dp[j] += dp[j - i];
            }
        }
```
- **Explanation**: This nested loop iterates over each number `i` in `nums` and tries to update the `dp` array. For each `i`, it updates the possible sums that can be formed from `req_sum` down to `i`. The inner loop ensures we don't reuse elements more than once.
- **Purpose**: The DP formula `dp[j] += dp[j - i]` says that the number of ways to make sum `j` includes all the ways to make sum `j - i`, plus the current number of ways already stored in `dp[j]`.

---

```cpp
        return dp[req_sum];
    }
};
```
- **Explanation**: Finally, the function returns the value `dp[req_sum]`, which represents the number of ways to form the sum `req_sum` using the elements of `nums`.
- **Purpose**: This is the solution to the problem. It gives the number of ways to assign `+` or `-` signs to numbers in `nums` to reach the target sum.

---

### Dry Run

Consider the input:

```cpp
nums = {1, 1, 1, 1, 1}, target = 3
```

1. **Step 1**: Calculate `total_sum`:
   ```
   total_sum = 1 + 1 + 1 + 1 + 1 = 5
   ```

2. **Step 2**: Check if `(total_sum - target)` is odd:
   ```
   (5 - 3) % 2 = 2 % 2 = 0 → valid
   ```

3. **Step 3**: Calculate `req_sum`:
   ```
   req_sum = (total_sum - target) / 2 + target
           = (5 - 3) / 2 + 3
           = 1 + 3
           = 4
   ```

4. **Step 4**: Initialize the `dp` array:
   ```
   dp = {1, 0, 0, 0, 0}  // dp[0] = 1
   ```

5. **Step 5**: Update the `dp` array for each number in `nums`:

   - For the first `1`:
     ```
     dp[4] += dp[3]  → dp = {1, 0, 0, 0, 0}
     dp[3] += dp[2]  → dp = {1, 0, 0, 0, 0}
     dp[2] += dp[1]  → dp = {1, 0, 0, 0, 0}
     dp[1] += dp[0]  → dp = {1, 1, 0, 0, 0}
     ```

   - For the second `1`:
     ```
     dp[4] += dp[3]  → dp = {1, 1, 0, 0, 0}
     dp[3] += dp[2]  → dp = {1, 1, 0, 0, 0}
     dp[2] += dp[1]  → dp = {1, 1, 1, 0, 0}
     dp[1] += dp[0]  → dp = {1, 2, 1, 0, 0}
     ```

   - For the third `1`:
     ```
     dp[4] += dp[3]  → dp = {1, 2, 1, 0, 0}
     dp[3] += dp[2]  → dp = {1, 2, 1, 1, 0}
     dp[2] += dp[1]  → dp = {1, 2, 3, 1, 0}
     dp[1] += dp[0]  → dp = {1, 3, 3, 1, 0}
     ```

   - For the fourth `1`:
     ```
     dp[4] += dp[3]  → dp = {1, 3, 3, 1, 1}
     dp[3] += dp[2]  → dp = {1, 3, 3, 4, 1}
     dp[2] += dp[1]  → dp = {1, 3, 6, 4, 1}
     dp[1] += dp[0]  → dp = {1, 4, 6, 4, 1}
     ```

   - For the fifth `1`:
     ```
     dp[4] += dp[3]  → dp = {1, 4, 6, 4, 5}
     dp[3] += dp[2]  → dp = {1, 4, 6, 10, 5}
     dp[2] += dp[1]  → dp = {1, 4, 10, 10, 5}
     dp[1] += dp[0]  → dp = {1, 5, 10, 10, 5}
     ```

6. **Step 6**: Return `dp[4]`:
   ```
   dp[4] = 5
   ```

So, there are 5 ways to assign `+` and `-` signs to the numbers in `nums` to achieve the target sum `3`.
