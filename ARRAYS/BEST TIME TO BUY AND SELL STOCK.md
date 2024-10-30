Stock Buy And Sell


https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solutions/

Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Examples
Example 1:
Input:
 prices = [7,1,5,3,6,4]
Output:
 5
Explanation:
 Buy on day 2 (price = 1) and 
sell on day 5 (price = 6), profit = 6-1 = 5.

Note
: That buying on day 2 and selling on day 1 
is not allowed because you must buy before 
you sell.

Example 2:
Input:
 prices = [7,6,4,3,1]
Output:
 0
Explanation:
 In this case, no transactions are 
done and the max profit = 0.



Brute Force Approach
Algorithm / Intuition

![image](https://github.com/user-attachments/assets/fbfcef94-d711-4357-96f5-bcf16010951f)

Intuition: We can simply use 2 loops and track every transaction and maintain a variable maxPro to contain the max value among all transactions.

Approach: 

Use a for loop of ‘i’ from 0 to n.
Use another for loop of j from ‘i+1’ to n.
If arr[j] > arr[i] , take the difference and compare  and store it in the maxPro variable.
Return maxPro.


```cpp

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
            maxPro = max(arr[j] - arr[i], maxPro);
            }
        }
        }

    return maxPro;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
```

Output:

Max profit is: 5


**Optimal Approach**

Algorithm / Intuition

![image](https://github.com/user-attachments/assets/ad3f6853-2989-4bc2-ba92-04f6f566c315)


Intuition: We will linearly travel the array. We can maintain a minimum from the start of the array and compare it with every element of the array, if it is greater than the minimum then take the difference and maintain it in max, otherwise update the minimum.

Approach:



Create a variable maxPro and store 0 initially.
Create a variable minPrice and store some larger value(ex: MAX_VALUE) value initially.
Run a for loop from 0 to n.
Update the minPrice if it is greater than the current element of the array
Take the difference of the minPrice with the current element of the array and compare and maintain it in maxPro.
Return the maxPro.


```cpp
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    
    return maxPro;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
```

Output: Max profit is: 5

Complexity Analysis

Time complexity: O(n)

Space Complexity: O(1)


To buy and sell stocks at the best time, you can use the following strategy, often referred to as the **"Max Profit in One Transaction"** problem:

### Formula and Concept

The goal is to maximize the difference between a selling price and a buying price such that the buying day comes before the selling day.

1. **Track Minimum Price Up to Day \(i\)**:
   - Traverse through the list of stock prices, tracking the minimum price up to that day.

2. **Calculate Maximum Profit for Each Day**:
   - For each day \(i\), calculate the potential profit if the stock was bought at the minimum price tracked so far and sold on day \(i\).
   - Keep track of the maximum profit you can achieve.

### Formula

For an array of stock prices `prices`:
1. Let `min_price` be the minimum price seen up to day \(i\).
2. `profit_i` for day \(i\) is calculated as:
   \[
   \text{profit}_i = \text{prices}[i] - \text{min\_price}
   \]
3. Update `max_profit` as:
   \[
   \text{max\_profit} = \max(\text{max\_profit}, \text{profit}_i)
   \]

### Algorithm (Pseudocode)

Here's the pseudocode to find the maximum profit:

```plaintext
Initialize min_price to a very large value
Initialize max_profit to 0

For each price in prices:
    Update min_price to be the minimum of min_price and the current price
    Calculate profit_i as current price - min_price
    Update max_profit to be the maximum of max_profit and profit_i

Return max_profit
```

### Example Code in C++

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int min_price = INT_MAX;
    int max_profit = 0;

    for (int price : prices) {
        min_price = min(min_price, price);          // Track the minimum price
        int profit = price - min_price;             // Calculate potential profit
        max_profit = max(max_profit, profit);       // Update max profit
    }

    return max_profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maxProfit(prices) << endl; // Output should be 5
    return 0;
}
```

### Explanation

- **Track Minimum Price**: `min_price` keeps track of the lowest price up to the current day.
- **Calculate Potential Profit**: For each price, calculate the profit if it were sold on that day after buying at `min_price`.
- **Update Maximum Profit**: If the calculated profit is higher than `max_profit`, update it.

This algorithm runs in \(O(n)\) time complexity and only requires \(O(1)\) additional space, making it optimal for finding the maximum profit in one transaction.
