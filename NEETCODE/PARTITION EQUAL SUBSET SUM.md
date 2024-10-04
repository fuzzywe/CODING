
https://leetcode.com/problems/partition-equal-subset-sum/solutions/462699/whiteboard-editorial-all-approaches-explained/?envType=problem-list-v2&envId=plakya4j&difficulty=MEDIUM&status=TO_DO


Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0), halfSum = totalSum / 2;
        if(totalSum & 1) return false;
        bool dp[halfSum+1]; memset(dp, false, sizeof dp);
        dp[0] = true;                              // 0 sum is always achievable
        for(int num : nums) 
            for(int j = halfSum; j >= num; j--)    // essential to start right to left
                if(dp[j - num])                    // if j - num was previously achievable
                    dp[j] = true;                  // we can add num to it and make j achievable as well
            
        return dp[halfSum];
    }
};
 ```

Certainly! This code implements a solution to the **Partition Equal Subset Sum Problem** using a dynamic programming approach. The goal is to determine whether an array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

### **Code Explanation:**

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
```
- **Class Definition**: This defines a class named `Solution`.
- **Function Definition**: The `canPartition` function takes a vector of integers (`nums`) as input and returns a boolean indicating whether the array can be partitioned into two equal-sum subsets.

#### Example Input:
- `nums = {1, 5, 11, 5}`

---

```cpp
int totalSum = accumulate(begin(nums), end(nums), 0), halfSum = totalSum / 2;
```
- **Explanation**:
  - `totalSum`: Calculates the total sum of the elements in the `nums` array using the `accumulate` function.
  - `halfSum`: This is half of the `totalSum`. The target for each subset will be `halfSum` if the partition is possible.

#### Example Calculation:
- For `nums = {1, 5, 11, 5}`:
  - `totalSum = 1 + 5 + 11 + 5 = 22`
  - `halfSum = totalSum / 2 = 22 / 2 = 11`

---

```cpp
if(totalSum & 1) return false;
```
- **Explanation**: This checks if `totalSum` is odd using bitwise AND. If it's odd, it cannot be partitioned into two equal subsets, so the function immediately returns `false`.

#### Example:
- Here, `totalSum = 22`, which is even, so we proceed.

---

```cpp
bool dp[halfSum + 1]; memset(dp, false, sizeof dp);
```
- **Explanation**:
  - `dp` is a boolean array of size `halfSum + 1` (in this case, size `12`) used to store whether a specific sum is achievable with the given numbers.
  - `memset(dp, false, sizeof dp)`: Initializes all elements of the `dp` array to `false`.

#### Example Initialization:
- After this line, `dp` is initialized as:
  - `dp = {false, false, false, false, false, false, false, false, false, false, false, false}`

---

```cpp
dp[0] = true; // 0 sum is always achievable
```
- **Explanation**: Sets `dp[0]` to `true` because a sum of 0 can always be achieved by not selecting any elements.

#### Example State:
- After this line:
  - `dp = {true, false, false, false, false, false, false, false, false, false, false, false}`

---

```cpp
for(int num : nums) 
```
- **Explanation**: This loop iterates over each number (`num`) in the `nums` array to update the `dp` array.

#### Example Iteration:
- For `nums = {1, 5, 11, 5}`, this will loop through `1`, `5`, `11`, and `5`.

---

```cpp
for(int j = halfSum; j >= num; j--) // essential to start right to left
```
- **Explanation**: This inner loop iterates backwards from `halfSum` to `num`. The backward iteration is essential to ensure that each number is only used once in determining the sums.

#### Example Iteration for `num = 1`:
- When `num = 1`, the inner loop runs with `j` from `11` down to `1`:
  - `j = 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1`

---

```cpp
if(dp[j - num]) // if j - num was previously achievable
```
- **Explanation**: This condition checks if the sum `j - num` was previously achievable. If `dp[j - num]` is `true`, it means we can form the sum `j` by adding `num` to some previously achievable sum.

#### Example Check for `num = 1` and `j = 1`:
- At `j = 1`, we check `dp[1 - 1]`, which is `dp[0]`. Since `dp[0]` is `true`, we can achieve `j = 1`.

---

```cpp
dp[j] = true; // we can add num to it and make j achievable as well
```
- **Explanation**: If `j - num` was achievable, set `dp[j]` to `true`, indicating that the sum `j` can now also be achieved by including `num`.

#### Example State Update:
- For `num = 1`:
  - Update `dp[1]` to `true`:
  - Now, `dp = {true, true, false, false, false, false, false, false, false, false, false, false}`

---

### **Full Inner Loop Example:**
Let's see the inner workings when processing all numbers in `nums = {1, 5, 11, 5}`.

1. **Processing `num = 1`**:
   - Update `dp` to:
     - `dp = {true, true, false, false, false, false, false, false, false, false, false, false}`

2. **Processing `num = 5`**:
   - Update `dp`:
     - For `j = 11`, check `dp[11 - 5] = dp[6]` (false).
     - For `j = 10`, check `dp[10 - 5] = dp[5]` (false).
     - For `j = 9`, check `dp[9 - 5] = dp[4]` (false).
     - For `j = 8`, check `dp[8 - 5] = dp[3]` (false).
     - For `j = 7`, check `dp[7 - 5] = dp[2]` (false).
     - For `j = 6`, check `dp[6 - 5] = dp[1]` (true). Update `dp[6] = true`.
     - For `j = 5`, check `dp[5 - 5] = dp[0]` (true). Update `dp[5] = true`.

   - After processing `num = 5`, `dp` becomes:
     - `dp = {true, true, false, false, false, true, true, false, false, false, false, false}`

3. **Processing `num = 11`**:
   - For `j` values, it will check and update if `j - num` is achievable. For `num = 11`, `dp[11]` can be achieved.

   - After processing `num = 11`, `dp` becomes:
     - `dp = {true, true, false, false, false, true, true, false, false, false, false, true}`

4. **Processing `num = 5` again**: 
   - Similar checks will be performed. It will try to find combinations with the previous `true` values.

---

### **Final Check:**
```cpp
return dp[halfSum];
```
- **Explanation**: Finally, the function returns `dp[halfSum]`. If it’s `true`, it means we can achieve `halfSum` with the numbers in the array, implying that we can partition the array into two equal subsets.

#### Example Result:
- After processing the above, for `halfSum = 11`, if `dp[11]` is `true`, the function returns `true`, indicating that the partition is possible.

### **Conclusion:**
- This approach uses dynamic programming to efficiently solve the problem by leveraging previously computed results to build up the solution iteratively.
- The complexity of this approach is:
  - **Time Complexity**: \(O(n \cdot \text{halfSum})\), where \(n\) is the number of elements in the array.
  - **Space Complexity**: \(O(\text{halfSum})\) due to the dp array.

