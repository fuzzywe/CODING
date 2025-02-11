Fractional Knapsack Problem : Greedy Approach

https://www.naukri.com/code360/problems/0-1-knapsack_1072980?interviewBundleRedirection=true&leftPanelTabValue=DISCUSS

https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card



---

Example:

Input: N = 3, W = 50, values[] = {100,60,120}, weight[] = {20,10,30}.

Output: 240.00

Explanation: The first and second items  are taken as a whole  while only 20 units of the third item is taken. Total value = 100 + 60 + 80 = 240.00

  Examples :

Input: n = 3, w = 50, value[] = [60,100,120], weight[] = [10,20,30]
Output: 240.000000
Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 
Input: n = 2, w = 50, value[] = [60,100], weight[] = [10,20]
Output: 160.000000
Explanation: Take both the items completely, without breaking. Total maximum value of item we can have is 160.00 from the given capacity of sack.

---
Some 0/1 knapsack problems :


->Subset sum
->Equal sum partition
->Count of subsets sum with a given sum
->Minimum subset sum difference
->Count the number of subset with a given difference
->Target sum

---
```cpp

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {

  vector<vector<int>> dp(n, vector<int>(w + 1, 0));

 

  for (int i = weights[0]; i <= w; i++) {

    dp[0][i] = values[0];

  }

 

  for (int i = 1; i < n; i++) {

    for (int wt = 0; wt <= w; wt++) {

      int not_take = dp[i - 1][wt];

      int take = 0;

      if (weights[i] <= wt)

        take = values[i] + dp[i - 1][wt - weights[i]];

      dp[i][wt] = max(not_take, take);

    }

  }

 

  return dp[n - 1][w];

}

```
---

Let's break down the **0/1 Knapsack** solution **step by step**, so you can explain it confidently in your interview.  

---

## **📌 Understanding the Problem**
We have `n` items, each with:
- **Value** (`values[i]`)
- **Weight** (`weights[i]`)  

We also have a **knapsack with capacity `w`**.  
**Goal:** Find the maximum total value we can obtain without exceeding `w`.

---

## **📌 Step-by-Step Explanation of Code**
### **1️⃣ Initialize the DP Table**
```cpp
vector<vector<int>> dp(n, vector<int>(w + 1, 0));
```
- We create a **2D DP table `dp[i][wt]`**, where:
  - `i` → Items considered (0 to `n-1`).
  - `wt` → Knapsack weight capacity (0 to `w`).
- **Initialization**:  
  - Every `dp[i][wt]` is initialized to `0`, meaning if we don’t pick any items, the profit is `0`.

---

### **2️⃣ Fill the First Row (Base Case)**
```cpp
for (int i = weights[0]; i <= w; i++) {
    dp[0][i] = values[0];
}
```
- This means:
  - If we can fit the **first item (`weights[0]`)** into the knapsack, we take its value `values[0]`.
  - Example:
    ```
    weights = [2, 3, 4]
    values = [4, 5, 6]
    w = 5
    ```
    - If `w = 1`, we **cannot** take `weights[0] = 2` → `dp[0][1] = 0`
    - If `w = 2`, we **can** take `values[0] = 4` → `dp[0][2] = 4`
    - If `w = 3`, we **can** take `values[0] = 4` → `dp[0][3] = 4`
    - If `w = 4`, we **can** take `values[0] = 4` → `dp[0][4] = 4`
    - If `w = 5`, we **can** take `values[0] = 4` → `dp[0][5] = 4`

---

### **3️⃣ Process the Remaining Items**
```cpp
for (int i = 1; i < n; i++) {
    for (int wt = 0; wt <= w; wt++) {
```
- We loop through **each item (`i`)** and **each weight (`wt`)**.

---

### **4️⃣ Two Choices: Take or Not Take**
For each `dp[i][wt]`, we have two choices:
#### **🔹 Case 1: Not Taking the Current Item (`not_take`)**
```cpp
int not_take = dp[i - 1][wt];
```
- If we don’t take item `i`, the profit remains **same as the previous row**.

#### **🔹 Case 2: Taking the Current Item (`take`)**
```cpp
int take = 0;
if (weights[i] <= wt)
    take = values[i] + dp[i - 1][wt - weights[i]];
```
- If the **current item’s weight `weights[i]` is ≤ available weight `wt`**, we have the option to take it.
- If we take it:
  - We gain `values[i]` (profit from this item).
  - We also add the profit from the **remaining weight** (`wt - weights[i]`).

---

### **5️⃣ Select the Maximum Profit**
```cpp
dp[i][wt] = max(not_take, take);
```
- We store the **maximum** of `take` or `not_take` in `dp[i][wt]`.

---

### **6️⃣ Final Answer**
```cpp
return dp[n - 1][w];
```
- The **last cell `dp[n-1][w]`** contains the maximum profit.

---

## **📌 Dry Run Example**
### **Example Input**
```cpp
values  = {60, 100, 120}
weights = {10, 20, 30}
n = 3, w = 50
```
### **DP Table Construction**
| Items | Weight = 0 | 10  | 20  | 30  | 40  | 50  |
|--------|------|-----|-----|-----|-----|-----|
| Item 1 (60, 10) | 0 | 60  | 60  | 60  | 60  | 60  |
| Item 2 (100, 20) | 0 | 60  | 100 | 100 | 160 | 160 |
| Item 3 (120, 30) | 0 | 60  | 100 | 120 | 160 | 180 |

**Final Answer** = `dp[2][50] = 180` (max profit)

---

## **📌 Time Complexity**
- **O(n * w)** → Looping through `n` items and `w` weight capacities.

---

## **📌 Space Optimization (1D Array)**
Since we only use the **previous row**, we can optimize to **O(w) space**.


---

geeks for geeks

---

```cpp

class Solution {
public:
    // Function to return max value that can be put in knapsack of given capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &weights) {
        int n = val.size(); // Number of items
        
        // Create DP table
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        // Base case: If we have only the first item, we can take it if it fits
        for (int i = weights[0]; i <= capacity; i++) {
            dp[0][i] = val[0];
        }

        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int wt = 0; wt <= capacity; wt++) {
                int not_take = dp[i - 1][wt];  // Not taking current item
                int take = 0;

                if (weights[i] <= wt) {
                    take = val[i] + dp[i - 1][wt - weights[i]]; // Taking item i
                }

                dp[i][wt] = max(not_take, take);
            }
        }

        // The last cell contains the answer
        return dp[n - 1][capacity];
    }
};

```

