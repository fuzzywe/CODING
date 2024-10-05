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

Approach
DP (Bottom Up Approach) + Space Optimization

Complexity
Time complexity:


Code

```cpp
class Solution {
public:
    int solve(vector<int>& coins, int n, int target, vector<vector<int>>& dp,
               int index) {

        // base case
        if (target == 0) {
            return 1;
        }

        if (index >= n) {
            return 0;
        }

        if (target < 0) {
            return 0;
        }

        // check in dp
        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        // possibilities
        int include =
            solve(coins, n, target - coins[index], dp, index);
        int exclude = solve(coins, n, target, dp, index + 1);

        // populate in dp
        return dp[index][target] = include + exclude;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        return solve(coins, n, amount, dp, 0);
    }
};
```
### Code Breakdown and Explanation

This code solves the **"Coin Change II"** problem using **recursion with memoization** (top-down dynamic programming). The goal is to find how many ways you can make up the `amount` using the given `coins`. Let's go through each part of the code in detail.

---

### 1. **Function Definition**

```cpp
class Solution {
public:
    int solve(vector<int>& coins, int n, int target, vector<vector<int>>& dp, int index) {
```

- **Function `solve`**:
  - The recursive function to calculate the number of ways to form the `target` using `coins`.
  - **Parameters**:
    - `coins`: The array of coin denominations.
    - `n`: The number of coins.
    - `target`: The remaining amount that we are trying to form.
    - `dp`: The memoization table (for storing previously calculated results to avoid recomputation).
    - `index`: The current coin index in the `coins` array.

---

### 2. **Base Cases**

```cpp
// base case
if (target == 0) {
    return 1;
}
```

- **Base case 1**:
  - If the `target` amount is exactly `0`, return `1`, because forming an amount of `0` can only be done in **1 way** (by not using any coins).
  
  **Example**: 
  - Suppose you're trying to make an amount of `0`. The answer is always `1`, because the "empty set" (not using any coins) is a valid way to make up `0`.

---

```cpp
if (index >= n) {
    return 0;
}
```

- **Base case 2**:
  - If the `index` exceeds the number of coins (`n`), return `0`. This means we have used all the coins and haven't reached the target, so it's impossible to form the amount.

  **Example**:
  - Suppose there are only 3 coins and `index` becomes `3`, i.e., you’ve used all the available coins. If the target is still greater than 0, it's impossible to make up that amount, so return `0`.

---

```cpp
if (target < 0) {
    return 0;
}
```

- **Base case 3**:
  - If `target` becomes negative, return `0`. This means it's impossible to make a negative amount with any combination of coins.

  **Example**:
  - If you're trying to make an amount of `5` and you subtract a coin of `10`, the remaining target becomes negative (`-5`), which is impossible, so return `0`.

---

### 3. **Memoization (Using dp)**

```cpp
if (dp[index][target] != -1) {
    return dp[index][target];
}
```

- **Memoization Check**:
  - Before performing any further calculations, check if the solution for this particular `index` and `target` is already stored in the `dp` table. If it is, return the stored value.
  
  This avoids recomputation, improving efficiency.

  **Example**:
  - Suppose you've already calculated the number of ways to make an amount of `7` using the first 2 coins. If you encounter the same subproblem later, the stored result will be reused.

---

### 4. **Recursion (Including/Excluding a Coin)**

```cpp
int include = solve(coins, n, target - coins[index], dp, index);
```

- **Including the Current Coin**:
  - Subtract the value of the current coin (`coins[index]`) from `target` and make a recursive call to `solve` with the same coin (`index` remains the same). This allows us to use the same coin multiple times.

  **Example**:
  - If you're trying to make an amount of `5` and you have a coin of `2`, subtract `2` from `5` and now try to make `3` using the same coin (`2`).

---

```cpp
int exclude = solve(coins, n, target, dp, index + 1);
```

- **Excluding the Current Coin**:
  - Skip the current coin by moving to the next coin (`index + 1`), and try to form the same `target` without including the current coin.

  **Example**:
  - If you're trying to make `5` and you have a coin of `2`, you can choose not to use it and try the next coin.

---

### 5. **Store Result in dp Table**

```cpp
return dp[index][target] = include + exclude;
```

- **Store Result**:
  - The number of ways to make the `target` using the current coin (`coins[index]`) is the sum of:
    - **`include`**: The number of ways when you include the current coin.
    - **`exclude`**: The number of ways when you exclude the current coin.
  
  Store this result in the `dp` table to reuse it later.

---

### 6. **Wrapper Function (change)**

```cpp
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    return solve(coins, n, amount, dp, 0);
}
```

- **change Function**:
  - Initializes the memoization table `dp` with size `(n + 1) x (amount + 1)` and sets all entries to `-1` (indicating uncomputed states).
  - Calls the recursive `solve` function starting with the first coin (`index = 0`) and the full `amount`.

---

### Dry Run Example

#### Input:
- `amount = 5`
- `coins = [1, 2, 5]`

#### Step-by-Step Dry Run:

1. **Initial Call**:
   - `solve(coins, 3, 5, dp, 0)`
   - We start with `target = 5` and `index = 0` (coin = 1).

2. **Including Coin 1**:
   - Call `solve(coins, 3, 4, dp, 0)` (after subtracting 1 from the target).
   - Now `target = 4` and `index = 0`.

3. **Keep Including Coin 1** until `target` becomes `0`. 
   - `solve(coins, 3, 0, dp, 0)` returns `1` since `target == 0` (one valid solution found).
   
4. **Backtrack and Exclude Coin 1**:
   - After the include path is done, start excluding coin 1.
   - Call `solve(coins, 3, 5, dp, 1)` (move to the next coin, `2`).
   
5. **Repeat for Coin 2 and Coin 5**:
   - Recursively include and exclude coins until all possible combinations are checked.

#### Final Output:
- The total number of ways to make `5` with coins `[1, 2, 5]` is `4`.
