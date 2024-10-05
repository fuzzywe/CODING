518. Coin Change II
Medium
Topics
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1

space optimization technique:

Approach
DP (Bottom Up Approach) + Space Optimization

Complexity
Time complexity:
O(n∗amount)

Space complexity:
O(amount)

Code

```cpp

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector <int> prev(amount+1, 0), cur(amount+1, 0);
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                prev[i] = 1;
            else
                prev[i] = 0;    
        }
        for (int idx = 1; idx < n; idx++) {
            for (int target = 0; target <= amount; target++) {
                int notTaken = prev[target];
                int taken = 0;
                if (coins[idx] <= target)
                    taken = cur[target-coins[idx]];
                cur[target] = notTaken + taken;  
            }
            prev = cur;
        }
        return prev[amount];    
    }
};
```
Let's break down the code step by step and explain the logic behind each line. The code implements a dynamic programming solution to solve the **Coin Change 2 problem**, where we need to find the number of different ways to make up a given amount using a set of coins.

### Problem Understanding
- Given an `amount` and a list of `coins`, we need to determine how many different ways we can use the coins to sum up to `amount`.
- Each coin can be used an unlimited number of times.
  
### Code Breakdown

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
```
- **Explanation:** 
  - The `change` function is part of the `Solution` class.
  - It takes two arguments:
    - `amount`: the total amount we need to sum up to using the coins.
    - `coins`: a vector of integers representing the available denominations of coins.

---

### Step 1: Initialize `n` and two DP arrays `prev` and `cur`
```cpp
int n = coins.size();
vector<int> prev(amount+1, 0), cur(amount+1, 0);
```
- **Explanation:**
  - `n` is the number of coins in the `coins` vector.
  - `prev` and `cur` are dynamic programming (DP) arrays of size `amount + 1`, initialized to 0.
  - These arrays are used to store the number of ways to form different amounts from 0 to `amount`.
  - `prev` represents the previous state, and `cur` represents the current state during the DP iteration.

---

### Step 2: Base case initialization for `prev`
```cpp
for (int i = 0; i <= amount; i++) {
    if (i % coins[0] == 0)
        prev[i] = 1;
    else
        prev[i] = 0;    
}
```
- **Explanation:**
  - This loop initializes the `prev` array for the first coin (`coins[0]`).
  - It iterates through all possible amounts from `0` to `amount`.
  - If the current amount `i` is divisible by `coins[0]`, `prev[i] = 1` (meaning there's exactly one way to form the amount using only this coin). Otherwise, `prev[i] = 0` (no way to form the amount).

- **Example:**
  - If `coins = [1, 2, 5]` and `amount = 5`, then for the first coin (`1`):
    - `i = 0`: `0 % 1 == 0` → `prev[0] = 1` (One way to form 0, which is using no coins).
    - `i = 1`: `1 % 1 == 0` → `prev[1] = 1` (One way to form 1 using the 1 coin).
    - `i = 2`: `2 % 1 == 0` → `prev[2] = 1` (One way to form 2 using two 1 coins).
    - And so on until `i = 5`, where `prev[5] = 1` (Five ways to form 5 using five 1 coins).

---

### Step 3: Dynamic Programming Iteration
```cpp
for (int idx = 1; idx < n; idx++) {
    for (int target = 0; target <= amount; target++) {
        int notTaken = prev[target];
        int taken = 0;
        if (coins[idx] <= target)
            taken = cur[target-coins[idx]];
        cur[target] = notTaken + taken;  
    }
    prev = cur;
}
```
- **Explanation:**
  - The outer loop iterates over each coin starting from the second one (`idx = 1`).
  - The inner loop iterates over each `target` (from `0` to `amount`) to compute the number of ways to form that amount.
  - For each amount `target`:
    - `notTaken`: The number of ways to form the amount without using the current coin (`prev[target]`).
    - `taken`: The number of ways to form the amount using the current coin. This is calculated by looking at how many ways we can form `target - coins[idx]` (using the current DP array `cur`).
    - `cur[target] = notTaken + taken`: This updates the DP array with the total number of ways to form `target` by considering both options (taking and not taking the current coin).
  - At the end of each iteration, `prev` is updated to `cur`, effectively moving to the next step.

- **Example:**
  - For `coins = [1, 2, 5]` and `amount = 5`:
    - At `idx = 1` (coin 2):
      - For `target = 2`: 
        - `notTaken = prev[2] = 1` (one way using coin 1).
        - `taken = cur[2 - 2] = cur[0] = 1` (one way using coin 2).
        - So, `cur[2] = 1 + 1 = 2` (two ways: two 1-coins, or one 2-coin).
      - Continue for other targets.
    - At `idx = 2` (coin 5):
      - For `target = 5`:
        - `notTaken = prev[5] = 3` (three ways using coins 1 and 2).
        - `taken = cur[5 - 5] = cur[0] = 1` (one way using coin 5).
        - So, `cur[5] = 3 + 1 = 4`.

---

### Step 4: Return the final result
```cpp
return prev[amount];
```
- **Explanation:**
  - After the loops, the `prev` array contains the number of ways to form each amount from `0` to `amount` using all the coins.
  - `prev[amount]` gives the final result: the number of ways to form `amount`.

---

### Dry Run Example

Let's do a dry run for `coins = [1, 2, 5]` and `amount = 5`:

1. **Initialization for `coins[0] = 1`:**
   - `prev = [1, 1, 1, 1, 1, 1]`
   - This means there's one way to form each amount using only the 1-coin.

2. **For `coins[1] = 2`:**
   - `cur[0] = 1` (no change).
   - `cur[1] = 1` (no change).
   - `cur[2] = prev[2] + cur[0] = 1 + 1 = 2` (two ways: two 1-coins or one 2-coin).
   - `cur[3] = prev[3] + cur[1] = 1 + 1 = 2`.
   - `cur[4] = prev[4] + cur[2] = 1 + 2 = 3`.
   - `cur[5] = prev[5] + cur[3] = 1 + 2 = 3`.
   - `prev` is updated to `cur = [1, 1, 2, 2, 3, 3]`.

3. **For `coins[2] = 5`:**
   - `cur[0] = 1`.
   - `cur[1] = 1`.
   - `cur[2] = 2`.
   - `cur[3] = 2`.
   - `cur[4] = 3`.
   - `cur[5] = prev[5] + cur[0] = 3 + 1 = 4`.
   - `prev` is updated to `cur = [1, 1, 2, 2, 3, 4]`.

Final result: `prev[5] = 4`.

### Conclusion
For `coins = [1, 2, 5]` and `amount = 5`, there are `4` ways to make the amount:
1. (1,1,1,1,1)
2. (1,1,1,2)
3. (1,2,2)
4. (5)
