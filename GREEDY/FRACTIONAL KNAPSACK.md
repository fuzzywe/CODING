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

I totally understand, and I’m here to help! 😊 Let’s **slow down** and **explain each part even more simply**. Imagine I’m sitting beside you, explaining this as a friend.  

---

## **💡 Step 1: Understanding the Problem First (Forget the Code!)**
Imagine you are a **thief**. You have a **bag** (knapsack) that can hold up to a certain **weight**.  

You have some **items**, and each item has:
- A **value** (how much money it’s worth)
- A **weight** (how heavy it is)  

Your **goal**: Pick **items** in a way that **gets the most value** **without exceeding the weight limit**.

---

### **📝 Example:**
You have **3 items**:

| Item | Value 💰 | Weight ⚖️ |
|------|--------|---------|
| 1    | 60     | 10      |
| 2    | 100    | 20      |
| 3    | 120    | 30      |

Your **bag can hold max weight = 50**.  
**What is the most value you can get?**  

---

## **💻 Now Let's Understand the Code!**

### **Step 2: Understanding DP Table (Forget the Code for a Moment)**
Since we need to **try all possible combinations** of items, we use **Dynamic Programming (DP)** to store answers **to subproblems**.

Think of it like a **table** that helps us **remember past calculations** so we don’t repeat them.

📌 **DP Table Idea:**  
- **Rows = Items** (0 to n-1)
- **Columns = Weight limits** (0 to W)
- **Each cell = Best value we can achieve with that weight**

---

## **Step 3: Now Let's Go Line by Line**
Now, let's **finally break down the code line by line**.

---

### **🔹 Step 1: Function Definition**
```cpp
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
```
✅ **What this does:**  
- We are writing a function `maxProfit` that will **find the maximum profit we can get**.
- It takes:
  - `values` → List of item values 💰 **(e.g., [60, 100, 120])**
  - `weights` → List of item weights ⚖️ **(e.g., [10, 20, 30])**
  - `n` → Number of items **(e.g., 3)**
  - `w` → Maximum weight the bag can hold **(e.g., 50)**

---

### **🔹 Step 2: Create DP Table**
```cpp
vector<vector<int>> dp(n, vector<int>(w + 1, 0));
```
✅ **What this does:**  
- Creates a **2D table (`dp`)** with:
  - **Rows = Items** (we have `n` items).
  - **Columns = Weights** (from `0` to `w`).
  - **Fills everything with `0` initially**.

📌 **Think of the DP Table like this:**
```
   0   1   2  ... 10  11 ... 50   ← (Weight limit)
---------------------------------
0 | 0   0   0  ...  0   0  ...  0  ← (Item 1)
1 | 0   0   0  ...  0   0  ...  0  ← (Item 2)
2 | 0   0   0  ...  0   0  ...  0  ← (Item 3)
```
---

### **🔹 Step 3: Fill First Row (Only Item 1)**
```cpp
for (int i = weights[0]; i <= w; i++) {
    dp[0][i] = values[0];
}
```
✅ **What this does:**  
- **First item has weight = 10 and value = 60.**
- If the **bag capacity is less than 10**, we **can’t take Item 1** → Value stays `0`.
- If the **bag capacity is 10 or more**, we **take Item 1** → Value becomes `60`.

📌 **Updated DP Table After This Step**
```
   0   1   2  ...  9   10  11 ... 50   ← (Weight)
---------------------------------
0 | 0   0   0  ...  0   60  60 ... 60  ← (Item 1)
1 | 0   0   0  ...  0    0   0  ...  0  ← (Item 2)
2 | 0   0   0  ...  0    0   0  ...  0  ← (Item 3)
```
---

### **🔹 Step 4: Fill DP Table for Remaining Items**
```cpp
for (int i = 1; i < n; i++) {
```
✅ **What this does:**  
- Loops through **each item** (starting from item 2).
- We will **decide whether to take or skip each item**.

---

### **🔹 Step 5: Loop Through Each Weight Capacity**
```cpp
    for (int wt = 0; wt <= w; wt++) {
```
✅ **What this does:**  
- Loops through each **possible weight** (from 0 to `w`).
- We will **decide whether to take or skip the item**.

---

### **🔹 Step 6: Case 1 - Not Taking the Item**
```cpp
      int not_take = dp[i - 1][wt];
```
✅ **What this does:**  
- **If we don’t take the item**, the **value remains the same** as the previous row.

📌 **Example** (For Item 2, weight 20, value 100, at `wt = 15`)  
- We **can't take Item 2** because its weight (20) is **more than 15**.
- So, `dp[1][15] = dp[0][15] = 60`.

---

### **🔹 Step 7: Case 2 - Taking the Item**
```cpp
      int take = 0;

      if (weights[i] <= wt)
          take = values[i] + dp[i - 1][wt - weights[i]];
```
✅ **What this does:**  
- **If the item fits**, we calculate the **new value** by:
  - Adding the **current item’s value**.
  - Adding the **best value from the remaining weight**.

📌 **Example** (For Item 2, weight 20, value 100, at `wt = 30`):
- We **can take Item 2**.
- The remaining weight = `30 - 20 = 10`.
- `dp[1][30] = values[1] + dp[0][10] = 100 + 60 = 160`.

---

### **🔹 Step 8: Take the Maximum Value**
```cpp
      dp[i][wt] = max(not_take, take);
```
✅ **What this does:**  
- Stores the **maximum** of:
  - **Not taking** the item.
  - **Taking** the item.

📌 **Example** (At `wt = 30` for Item 2):
- `dp[1][30] = max(60, 160) = 160`.

---

### **🔹 Step 9: Return Final Answer**
```cpp
return dp[n - 1][w];
```
✅ **What this does:**  
- The **last row, last column** contains the **final answer**.

📌 **Final Answer:** **220 (Best value with weight ≤ 50)**.

---

## **🎉 Final Summary**
- We create a **table** (`dp`) to **store best values**.
- We **loop through items** and **possible weights**.
- At each step, we **decide to take or skip** an item.
- The **last row, last column** gives the **final answer**.

---

🎯 **Did this explanation help?** 😊 Let me know which part is confusing, and I’ll simplify it even more! 🚀

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

