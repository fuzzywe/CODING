
322. Coin Change
Solved
Medium
Topics
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0

Complexity
Time complexity: O(a∗c)
a is number of amount and c is number of coins

Space complexity: O(a)
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minCoins(amount + 1, amount + 1);
        minCoins[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    minCoins[i] = min(minCoins[i], 1 + minCoins[i - coins[j]]);
                }
            }
        }

        return minCoins[amount] != amount + 1 ? minCoins[amount] : -1;        
    }
};
```

### Problem Description:
The problem is a dynamic programming problem where you're given a list of coin denominations (`coins`) and a target amount (`amount`). The goal is to determine the minimum number of coins needed to make the target amount. If it is not possible to make the amount with the given coin denominations, return `-1`.

### Input:
```cpp
coins = [1, 2, 5];
amount = 11;
```
This means you can use coins of denominations 1, 2, and 5, and you need to make the amount 11.

### Code Breakdown:

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
```
- **Line 1-3**: This defines a class `Solution` with a public function `coinChange`. The function takes a vector `coins` (list of coin denominations) and an integer `amount` (target amount).

---

```cpp
vector<int> minCoins(amount + 1, amount + 1);
```
- **Line 4**: A dynamic programming array `minCoins` is initialized with a size of `amount + 1`. All values are set to `amount + 1` (which is an arbitrarily large value) because initially, we assume it is impossible to reach each amount.
    - Example: If `amount = 11`, then `minCoins` is initialized as:
      ```cpp
      minCoins = [12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12]
      ```
      We use `amount + 1` as an arbitrary large value since the minimum number of coins needed will never exceed `amount` (if all were 1s).

---

```cpp
minCoins[0] = 0;
```
- **Line 5**: We set `minCoins[0] = 0` because no coins are needed to make an amount of `0`. It's a base case.
    - After this step:
      ```cpp
      minCoins = [0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12]
      ```

---

```cpp
for (int i = 1; i <= amount; i++) {
```
- **Line 6**: This starts a loop from `1` to `amount`. For each amount `i`, we want to calculate the minimum number of coins needed to make that amount.

---

```cpp
for (int j = 0; j < coins.size(); j++) {
```
- **Line 7**: For each amount `i`, we iterate over each coin in the `coins` list to check if that coin can be used to make the current amount `i`.

---

```cpp
if (i - coins[j] >= 0) {
```
- **Line 8**: We check if the coin can be subtracted from `i` (i.e., `i - coins[j] >= 0`). This ensures we are not using a coin that is larger than the current amount `i`.

---

```cpp
minCoins[i] = min(minCoins[i], 1 + minCoins[i - coins[j]]);
```
- **Line 9**: We update `minCoins[i]`. We compare the current value of `minCoins[i]` with `1 + minCoins[i - coins[j]]`, where `minCoins[i - coins[j]]` represents the number of coins needed to make the amount `i - coins[j]`. By adding `1`, we include the current coin `coins[j]` in the count.
    - Example: Suppose `i = 5` and the current coin is `coins[j] = 2`. Then `minCoins[5]` is updated by checking `minCoins[5]` vs `1 + minCoins[5 - 2] = 1 + minCoins[3]`.

---

```cpp
return minCoins[amount] != amount + 1 ? minCoins[amount] : -1;
```
- **Line 11**: After the loop finishes, we return `minCoins[amount]`. If `minCoins[amount]` is still equal to `amount + 1`, it means it's impossible to make that amount with the given coins, so we return `-1`. Otherwise, we return the value in `minCoins[amount]` as the result.

---

### Dry Run:

Let's dry run the code with an example:

#### Example:
```cpp
coins = [1, 2, 5];
amount = 11;
```

#### Step 1: Initialize the `minCoins` array:
```cpp
minCoins = [0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12]
```

#### Step 2: Loop through each amount from `1` to `11`:

- For `i = 1`:
  - Using `coin = 1`: 
    ```cpp
    minCoins[1] = min(12, 1 + minCoins[1 - 1]) = min(12, 1 + 0) = 1
    ```
  - `minCoins` becomes:
    ```cpp
    minCoins = [0, 1, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12]
    ```

- For `i = 2`:
  - Using `coin = 1`:
    ```cpp
    minCoins[2] = min(12, 1 + minCoins[2 - 1]) = min(12, 1 + 1) = 2
    ```
  - Using `coin = 2`:
    ```cpp
    minCoins[2] = min(2, 1 + minCoins[2 - 2]) = min(2, 1 + 0) = 1
    ```
  - `minCoins` becomes:
    ```cpp
    minCoins = [0, 1, 1, 12, 12, 12, 12, 12, 12, 12, 12, 12]
    ```

- For `i = 3`:
  - Using `coin = 1`:
    ```cpp
    minCoins[3] = min(12, 1 + minCoins[3 - 1]) = min(12, 1 + 1) = 2
    ```
  - Using `coin = 2`:
    ```cpp
    minCoins[3] = min(2, 1 + minCoins[3 - 2]) = min(2, 1 + 1) = 2
    ```
  - `minCoins` becomes:
    ```cpp
    minCoins = [0, 1, 1, 2, 12, 12, 12, 12, 12, 12, 12, 12]
    ```

Continue similarly for `i = 4` to `11`...

- For `i = 11`:
  - Using `coin = 1`:
    ```cpp
    minCoins[11] = min(12, 1 + minCoins[11 - 1]) = min(12, 1 + 3) = 4
    ```
  - Using `coin = 2`:
    ```cpp
    minCoins[11] = min(4, 1 + minCoins[11 - 2]) = min(4, 1 + 3) = 4
    ```
  - Using `coin = 5`:
    ```cpp
    minCoins[11] = min(4, 1 + minCoins[11 - 5]) = min(4, 1 + 2) = 3
    ```
  - Final `minCoins` becomes:
    ```cpp
    minCoins = [0, 1, 1, 2, 2, 1, 2, 2, 3, 3, 2, 3]
    ```

#### Step 3: Return the result:
- `minCoins[11] = 3`, so the minimum number of coins required to make `11` is `3` (using coins `[5, 5, 1]`).

### Output:
```cpp
3
```
