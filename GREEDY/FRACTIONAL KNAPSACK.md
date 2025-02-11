Fractional Knapsack Problem : Greedy Approach


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



#include <bits/stdc++.h>

using namespace std;

struct Item {
   int value;
   int weight;
};
class Solution {
   public:
      bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }
   // function to return fractionalweights
   double fractionalKnapsack(int W, Item arr[], int n) {

      sort(arr, arr + n, comp);

      int curWeight = 0;
      double finalvalue = 0.0;

      for (int i = 0; i < n; i++) {

         if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
         } else {
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
            break;
         }
      }

      return finalvalue;

   }
};
int main() {
   int n = 3, weight = 50;
   Item arr[n] = { {100,20},{60,10},{120,30} };
   Solution obj;
   double ans = obj.fractionalKnapsack(weight, arr, n);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}
Output:

The maximum value is 240.00

Time Complexity: O(n log n + n). O(n log n) to sort the items and O(n) to iterate through all the items for calculating the answer.

Space Complexity: O(1), no additional data structure has been used.

Let's walk through the code line by line with a detailed dry run to understand how it works step by step. The code is solving the **Fractional Knapsack Problem**, where the goal is to maximize the value in the knapsack by including fractional items if needed.

### Code Overview:
- The input consists of an array of items, each with a value and weight.
- The function calculates the maximum value that can be placed in the knapsack of a given capacity by choosing items in descending order of value-to-weight ratio.

### Input:
- `n = 3` (number of items)
- `weight = 50` (capacity of the knapsack)
- `Items` array: `{{100, 20}, {60, 10}, {120, 30}}`

---

### Dry Run:

1. **Step 1: Struct Definition**
   ```cpp
   struct Item {
      int value;
      int weight;
   };
   ```
   - This defines a structure `Item` with two fields: `value` and `weight` representing the value and weight of each item.

2. **Step 2: Class Solution**
   - Inside this class, there is a comparison function `comp` and a function to solve the fractional knapsack problem `fractionalKnapsack`.

3. **Step 3: Comparator Function**
   ```cpp
   bool static comp(Item a, Item b) {
      double r1 = (double) a.value / (double) a.weight;
      double r2 = (double) b.value / (double) b.weight;
      return r1 > r2;
   }
   ```
   - This function compares two `Item` objects based on their value-to-weight ratio.
   - For example, for `Item a = {100, 20}` and `Item b = {60, 10}`:
     - `r1 = 100 / 20 = 5.0`
     - `r2 = 60 / 10 = 6.0`
     - `r2 > r1`, so `Item b` has a higher value-to-weight ratio.
   - The function sorts the items in descending order of their ratios to prioritize items with higher ratios.
The `comp` function is a **custom comparator** used to sort the items in descending order based on their **value-to-weight ratio**. Let's break it down:

### What the Comparator Does:
- The goal of the knapsack problem is to **maximize the total value** of items in the knapsack.
- For the fractional knapsack, we want to include items (or parts of them) that provide the **most value per unit of weight** first.
- The `comp` function is used to compare two items by calculating their **value-to-weight ratio** and determining which one should come first in the sorted list.

### Detailed Breakdown:

```cpp
bool static comp(Item a, Item b) {
    double r1 = (double) a.value / (double) a.weight; // r1 is the value-to-weight ratio of item 'a'
    double r2 = (double) b.value / (double) b.weight; // r2 is the value-to-weight ratio of item 'b'
    return r1 > r2; // Return true if the ratio of 'a' is greater than the ratio of 'b'
}
```

### Steps Inside `comp`:

1. **Calculate the value-to-weight ratio for Item `a`:**
   ```cpp
   double r1 = (double) a.value / (double) a.weight;
   ```
   - The ratio `r1` tells how much value we get for each unit of weight in item `a`.
   - For example, if `a.value = 100` and `a.weight = 20`, then:
     - `r1 = 100 / 20 = 5.0`
     - This means for every unit of weight (1 kg), you get 5 units of value.

2. **Calculate the value-to-weight ratio for Item `b`:**
   ```cpp
   double r2 = (double) b.value / (double) b.weight;
   ```
   - The ratio `r2` tells how much value we get for each unit of weight in item `b`.
   - For example, if `b.value = 60` and `b.weight = 10`, then:
     - `r2 = 60 / 10 = 6.0`
     - This means for every unit of weight, you get 6 units of value.

3. **Return the comparison result:**
   ```cpp
   return r1 > r2;
   ```
   - This line returns `true` if the value-to-weight ratio of `a` is greater than the value-to-weight ratio of `b`.
   - If `r1 > r2`, it means `a` provides more value per unit of weight than `b`, so `a` should come before `b` in the sorted array.

### Purpose:
- This function helps **sort the items in descending order** based on their value-to-weight ratio. After sorting, items that provide the **most value per unit of weight** will be considered first when filling the knapsack.

### Example:

Consider two items:
- Item `a`: `value = 100`, `weight = 20` → `r1 = 5.0`
- Item `b`: `value = 60`, `weight = 10` → `r2 = 6.0`

Since `r2 > r1`, the function will return `false`, meaning `Item b` (with a higher ratio) should come before `Item a` in the sorted list.


     you are checking only item a and b only what about remaining elements 


You're right! The comparison function `comp` checks two items at a time, but it's used within the sorting process for all elements in the array.

### Here's how the full process works:

1. **Sorting Function**: In the code, the `comp` function is passed to the `sort` function:
   ```cpp
   sort(arr, arr + n, comp);
   ```
   - The `sort` function from the C++ Standard Library will call the `comp` function multiple times to sort the entire array of items.
   - It compares **every pair of elements** in the array (not just two items) using the `comp` function, arranging them in descending order of their value-to-weight ratio.
   
2. **Comparison Across All Items**:
   - The sorting algorithm used by `sort` is likely a variation of **quick sort** or **merge sort**, depending on the implementation. These algorithms work by repeatedly dividing and comparing items.
   - For each comparison, the `comp` function is invoked to compare two items' value-to-weight ratios.
   - The sorting algorithm will keep rearranging the items based on these comparisons until the entire array is sorted.

### Example with 3 Items:

Let's say we have three items:
- `Item 1`: `value = 100, weight = 20` → `ratio = 5.0`
- `Item 2`: `value = 60, weight = 10` → `ratio = 6.0`
- `Item 3`: `value = 120, weight = 30` → `ratio = 4.0`

The `sort` function compares these items as follows:

1. First, it compares `Item 1` and `Item 2`:
   - `comp(Item 1, Item 2)` → `5.0 < 6.0`, so `Item 2` should come before `Item 1`.

2. Next, it compares `Item 1` and `Item 3`:
   - `comp(Item 1, Item 3)` → `5.0 > 4.0`, so `Item 1` should come before `Item 3`.

3. Finally, it compares `Item 2` and `Item 3`:
   - `comp(Item 2, Item 3)` → `6.0 > 4.0`, so `Item 2` should come before `Item 3`.

After sorting, the items are arranged in this order:
1. `Item 2` (ratio = 6.0)
2. `Item 1` (ratio = 5.0)
3. `Item 3` (ratio = 4.0)

Now the knapsack will take the highest-value-to-weight items first, maximizing the total value.

### Key Points:
- The `comp` function is **invoked multiple times** as part of the sorting process to compare different pairs of items.
- The `sort` function uses the results of these comparisons to reorder the entire array of items.
- After sorting, the array will be in **descending order** of value-to-weight ratio, ensuring the best items are selected first for the knapsack.

This way, **all items** are considered during the sorting process, not just two.

After calling sort(arr, arr + 3, comp), the items will be sorted based on their value-to-weight ratio.

The ratios are calculated as follows:

For Item {100, 20}: Ratio = 
100
20
=
5.0
20
100
​
 =5.0
For Item {60, 10}: Ratio = 
60
10
=
6.0
10
60
​
 =6.0
For Item {120, 30}: Ratio = 
120
30
=
4.0
30
120
​
 =4.0
Thus, after sorting, the order of the items in arr will be:

arr[0] = {60, 10} (ratio = 6.0)
arr[1] = {100, 20} (ratio = 5.0)
arr[2] = {120, 30} (ratio = 4.0)
Conclusion:
Without a custom comparator, sort(arr, arr + 3) will lead to a compilation error.

                


4. **Step 4: Function to Solve Fractional Knapsack**
   ```cpp
   double fractionalKnapsack(int W, Item arr[], int n)
   ```
   - This function takes the capacity `W` of the knapsack, the array of items `arr[]`, and the number of items `n`.

5. **Step 5: Sort Items**
   ```cpp
   sort(arr, arr + n, comp);
   ```
   - The array of items is sorted based on the value-to-weight ratio using the `comp` function.
   - The sorted array will look like:
     - `arr[0] = {60, 10}` → Ratio = `6.0`
     - `arr[1] = {100, 20}` → Ratio = `5.0`
     - `arr[2] = {120, 30}` → Ratio = `4.0`
   - Items are sorted in descending order of their ratios.

6. **Step 6: Initialize Variables**
   ```cpp
   int curWeight = 0;
   double finalvalue = 0.0;
   ```
   - `curWeight` keeps track of the current weight in the knapsack.
   - `finalvalue` keeps track of the total value accumulated in the knapsack.

7. **Step 7: Start Iterating through the Sorted Items**
   ```cpp
   for (int i = 0; i < n; i++) {
   ```
   - This loop iterates over each item to decide whether to add it fully or partially to the knapsack.

#### Iteration 1:
   ```cpp
   if (curWeight + arr[i].weight <= W)
   ```
   - For `arr[0] = {60, 10}`:
     - Current weight = `0`, Capacity = `50`.
     - `0 + 10 <= 50` → True.
     - The item can be added fully.
   ```cpp
   curWeight += arr[i].weight;  // curWeight = 10
   finalvalue += arr[i].value;  // finalvalue = 60
   ```
   - The current weight becomes `10`, and the total value becomes `60`.

#### Iteration 2:
   - For `arr[1] = {100, 20}`:
     - Current weight = `10`, Capacity = `50`.
     - `10 + 20 <= 50` → True.
     - The item can be added fully.
   ```cpp
   curWeight += arr[i].weight;  // curWeight = 30
   finalvalue += arr[i].value;  // finalvalue = 160
   ```
   - The current weight becomes `30`, and the total value becomes `160`.

#### Iteration 3:
   - For `arr[2] = {120, 30}`:
     - Current weight = `30`, Capacity = `50`.
     - `30 + 30 <= 50` → False.
     - The full item cannot be added, so add a fraction of it.
   ```cpp
   int remain = W - curWeight;  // remain = 50 - 30 = 20
   finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
   // finalvalue += (120 / 30) * 20 = 4 * 20 = 80
   ```
   - A fraction of `20` weight is added from the third item, contributing `80` to the total value.
   - The final value becomes `160 + 80 = 240`.

8. **Step 8: Return Final Value**
   ```cpp
   return finalvalue;  // 240.0
   ```
   - The total value of items in the knapsack is `240.0`.

### Final Output:
```cpp
The maximum value is 240.00
```

### Summary of Values:
- First item added fully: Value = `60`
- Second item added fully: Value = `100`
- Third item added partially (20/30): Value = `80`
- Total value: `240`

