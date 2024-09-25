Find minimum number of coins



Examples:

Example 1:

Input: V = 70

Output: 2

Explaination: We need a 50 Rs note and a 20 Rs note.

Example 2:

Input: V = 121

Output: 3

Explaination: We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.

#include<bits/stdc++.h>


using namespace std;
int main() {
  int V = 49;
  vector < int > ans;
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = 9;
  for (int i = n - 1; i >= 0; i--) {
    while (V >= coins[i]) {
      V -= coins[i];
      ans.push_back(coins[i]);
    }
  }
  cout<<"The minimum number of coins is "<<ans.size()<<endl;
  cout<<"The coins are "<<endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
Output:

The minimum number of coins is 5
The coins are
20 20 5 2 2

Time Complexity:O(V)

Space Complexity:O(1)


  Let’s perform a **dry run** of the code line by line using the value `V = 49`. The goal is to find the minimum number of coins needed to make `49` using the available denominations: `{1, 2, 5, 10, 20, 50, 100, 500, 1000}`.

### Initial Setup:
```cpp
int V = 49;  
vector<int> ans;  
int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};  
int n = 9;  
```
- **`V = 49`:** The amount we need to break down into coins.
- **`ans`:** An empty vector that will store the selected coins.
- **`coins[]`:** Available coin denominations, sorted in ascending order.
- **`n = 9`:** The number of available coin denominations.

### Loop Through Denominations:
```cpp
for (int i = n - 1; i >= 0; i--) {
```
- We start from the largest denomination (`coins[8] = 1000`) and work our way down to the smallest (`coins[0] = 1`).
  
### Iterations:

#### 1st Iteration (`i = 8`):
- Current denomination: `coins[8] = 1000`.
- Since `1000 > 49`, we skip this iteration without doing anything.

#### 2nd Iteration (`i = 7`):
- Current denomination: `coins[7] = 500`.
- Since `500 > 49`, we skip this iteration as well.

#### 3rd Iteration (`i = 6`):
- Current denomination: `coins[6] = 100`.
- Since `100 > 49`, we skip this iteration.

#### 4th Iteration (`i = 5`):
- Current denomination: `coins[5] = 50`.
- Since `50 > 49`, we skip this iteration too.

#### 5th Iteration (`i = 4`):
- Current denomination: `coins[4] = 20`.
  ```cpp
  while (V >= coins[i]) {
      V -= coins[i];
      ans.push_back(coins[i]);
  }
  ```
- **`V = 49`** and **`coins[4] = 20`**.
- Since `V >= 20`, we subtract `20` from `V`:
  - `V = 49 - 20 = 29`.
  - Push `20` into the `ans` vector: `ans = {20}`.
- Since `V >= 20` again, subtract `20` from `V`:
  - `V = 29 - 20 = 9`.
  - Push `20` into the `ans` vector: `ans = {20, 20}`.

#### 6th Iteration (`i = 3`):
- Current denomination: `coins[3] = 10`.
- **`V = 9`** and **`coins[3] = 10`**.
- Since `10 > 9`, we skip this iteration.

#### 7th Iteration (`i = 2`):
- Current denomination: `coins[2] = 5`.
  ```cpp
  while (V >= coins[i]) {
      V -= coins[i];
      ans.push_back(coins[i]);
  }
  ```
- **`V = 9`** and **`coins[2] = 5`**.
- Since `V >= 5`, we subtract `5` from `V`:
  - `V = 9 - 5 = 4`.
  - Push `5` into the `ans` vector: `ans = {20, 20, 5}`.

#### 8th Iteration (`i = 1`):
- Current denomination: `coins[1] = 2`.
  ```cpp
  while (V >= coins[i]) {
      V -= coins[i];
      ans.push_back(coins[i]);
  }
  ```
- **`V = 4`** and **`coins[1] = 2`**.
- Since `V >= 2`, we subtract `2` from `V`:
  - `V = 4 - 2 = 2`.
  - Push `2` into the `ans` vector: `ans = {20, 20, 5, 2}`.
- Since `V >= 2` again, subtract `2` from `V`:
  - `V = 2 - 2 = 0`.
  - Push `2` into the `ans` vector: `ans = {20, 20, 5, 2, 2}`.

#### 9th Iteration (`i = 0`):
- Current denomination: `coins[0] = 1`.
- **`V = 0`**, so we skip this iteration since no further subtraction is required.

### Final Output:
After all iterations are complete, we have broken down `V = 49` into the following coins: `{20, 20, 5, 2, 2}`.

```cpp
cout << "The minimum number of coins is " << ans.size() << endl;
cout << "The coins are " << endl;
for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
}
```
- `ans.size()` gives the number of coins used, which is `5`.
- The `ans` vector contains the coins: `20, 20, 5, 2, 2`.

### Output:
```
The minimum number of coins is 5
The coins are
20 20 5 2 2 
```

### Conclusion:
The Greedy Algorithm starts by selecting the largest possible coins and continues until the value `V` is reduced to `0`. This ensures that we use the minimum number of coins to make the given amount.
